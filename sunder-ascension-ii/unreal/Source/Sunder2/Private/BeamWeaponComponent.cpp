// SUNDER: Ascension II — persistent trace-driven laser beam (see unreal/WEAPON_VFX.md §1).
#include "BeamWeaponComponent.h"

#include "Components/MeshComponent.h"
#include "Engine/World.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Controller.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "TimerManager.h"

UBeamWeaponComponent::UBeamWeaponComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
	PrimaryComponentTick.bStartWithTickEnabled = false;       // only ticks while the beam is on
	PrimaryComponentTick.TickGroup = TG_PrePhysics;           // trace before Niagara reads the parameters
}

void UBeamWeaponComponent::SetMuzzle(USceneComponent* InComponent, FName InSocket)
{
	MuzzleComponent = InComponent;
	MuzzleSocket = InSocket;
	if (Beam && MuzzleComponent)
	{
		Beam->AttachToComponent(MuzzleComponent, FAttachmentTransformRules::SnapToTargetNotIncludingScale, MuzzleSocket);
	}
}

void UBeamWeaponComponent::BeginPlay()
{
	Super::BeginPlay();

	AActor* Owner = GetOwner();
	if (!MuzzleComponent && Owner)
	{
		// First mesh on the owner that has the muzzle socket; otherwise the root.
		TInlineComponentArray<UMeshComponent*> Meshes(Owner);
		for (UMeshComponent* Mesh : Meshes)
		{
			if (Mesh->DoesSocketExist(MuzzleSocket)) { MuzzleComponent = Mesh; break; }
		}
		if (!MuzzleComponent) { MuzzleComponent = Owner->GetRootComponent(); }
	}

	if (BeamSystem && MuzzleComponent)
	{
		// One beam per ship, for the whole session: never pooled, never destroyed mid-game.
		Beam = UNiagaraFunctionLibrary::SpawnSystemAttached(
			BeamSystem, MuzzleComponent, MuzzleSocket, FVector::ZeroVector, FRotator::ZeroRotator,
			EAttachLocation::SnapToTarget, /*bAutoDestroy*/ false, /*bAutoActivate*/ false,
			ENCPoolMethod::None, /*bPreCullCheck*/ false);
		if (Beam)
		{
			Beam->AddTickPrerequisiteComponent(this);   // our trace runs first every frame
			Beam->SetTranslucentSortPriority(10);
			Beam->SetVariableFloat(TEXT("BeamWidth"), BeamWidth);
			Beam->SetVariableLinearColor(TEXT("BeamColor"), BeamColor);
		}
	}
	CurrentEnd = MuzzleLocation();
}

void UBeamWeaponComponent::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	if (UWorld* World = GetWorld()) { World->GetTimerManager().ClearTimer(DamageTimer); }
	if (Beam) { Beam->DestroyComponent(); Beam = nullptr; }
	Super::EndPlay(EndPlayReason);
}

FVector UBeamWeaponComponent::MuzzleLocation() const
{
	if (MuzzleComponent) { return MuzzleComponent->GetSocketLocation(MuzzleSocket); }
	return GetOwner() ? GetOwner()->GetActorLocation() : FVector::ZeroVector;
}

void UBeamWeaponComponent::StartFire()
{
	if (bFiring || !Beam) { return; }
	bFiring = true;
	IntensityTarget = 1.f;
	CurrentEnd = MuzzleLocation();                         // the beam punches outward from the gun
	Beam->SetVariableFloat(TEXT("BeamWidth"), BeamWidth);
	Beam->SetVariableLinearColor(TEXT("BeamColor"), BeamColor);
	Beam->Activate(/*bReset*/ true);                       // resets UniqueID so BeamU runs 0..1 again
	SetComponentTickEnabled(true);
	GetWorld()->GetTimerManager().SetTimer(DamageTimer, this, &UBeamWeaponComponent::ApplyBeamDamage, DamageInterval, true);
}

void UBeamWeaponComponent::StopFire()
{
	if (!bFiring) { return; }
	bFiring = false;
	IntensityTarget = 0.f;                                 // TickComponent ramps down, then shuts the beam off
	GetWorld()->GetTimerManager().ClearTimer(DamageTimer);
	HitActor.Reset();
}

void UBeamWeaponComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (!Beam) { return; }

	Intensity = FMath::FInterpConstantTo(Intensity, IntensityTarget, DeltaTime, RampSpeed);
	if (!bFiring && Intensity <= 0.01f)
	{
		Intensity = 0.f;
		Beam->DeactivateImmediate();                       // Emitter State "Inactive Response: Kill" clears the segments
		SetComponentTickEnabled(false);
		return;
	}

	const FVector Start = MuzzleLocation();
	const FVector Dir = FVector(AimDirection.X, AimDirection.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::ForwardVector);
	const FVector FarEnd = Start + Dir * MaxRange;

	FHitResult Hit;
	FCollisionQueryParams Params(SCENE_QUERY_STAT(SunderBeamTrace), /*bTraceComplex*/ false, GetOwner());
	const bool bHit = GetWorld()->SweepSingleByChannel(
		Hit, Start, FarEnd, FQuat::Identity, TraceChannel, FCollisionShape::MakeSphere(BeamRadius), Params);

	// Keep the end ON the beam axis (Hit.Distance), so a sphere contact off to one side never kinks the beam.
	const FVector TargetEnd = bHit ? Start + Dir * Hit.Distance : FarEnd;
	const bool bCloser = FVector::DistSquared(Start, TargetEnd) < FVector::DistSquared(Start, CurrentEnd);
	CurrentEnd = bCloser ? TargetEnd : FMath::VInterpConstantTo(CurrentEnd, TargetEnd, DeltaTime, ExtendSpeed);
	HitActor = bHit ? Hit.GetActor() : nullptr;

	const FVector HitNormal = bHit ? FVector(Hit.ImpactNormal.X, Hit.ImpactNormal.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, -Dir) : -Dir;
	Beam->SetVariableVec3(TEXT("BeamStart"), Start);
	Beam->SetVariableVec3(TEXT("BeamEnd"), CurrentEnd);
	Beam->SetVariableBool(TEXT("bHit"), bHit);
	Beam->SetVariableVec3(TEXT("HitNormal"), HitNormal);
	Beam->SetVariableFloat(TEXT("Intensity"), Intensity);
}

void UBeamWeaponComponent::ApplyBeamDamage()
{
	AActor* Target = HitActor.Get();
	if (!Target || Intensity < 0.5f) { return; }           // no damage while the beam is still charging
	APawn* InstigatorPawn = GetOwner() ? GetOwner()->GetInstigator() : nullptr;
	AController* InstigatorController = InstigatorPawn ? InstigatorPawn->GetController() : nullptr;
	UGameplayStatics::ApplyDamage(Target, DamagePerSecond * DamageInterval, InstigatorController, GetOwner(), UDamageType::StaticClass());
}
