// SUNDER: Ascension II — a pooled plasma projectile (see unreal/WEAPON_VFX.md §3.4).
#include "SunderProjectile.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/Controller.h"
#include "GameFramework/DamageType.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "ImpactFXSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "NiagaraComponent.h"
#include "ProjectilePoolSubsystem.h"
#include "SunderEnemy.h"
#include "SunderShipPawn.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

ASunderProjectile::ASunderProjectile()
{
	PrimaryActorTick.bCanEverTick = false;

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(10.f);
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));   // set your own projectile profile here
	Collision->SetGenerateOverlapEvents(true);
	RootComponent = Collision;

	Movement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Movement"));
	Movement->UpdatedComponent = Collision;
	Movement->ProjectileGravityScale = 0.f;
	Movement->bRotationFollowsVelocity = true;
	Movement->bConstrainToPlane = true;                               // shmup: stay on the XY play plane
	Movement->SetPlaneConstraintNormal(FVector::UpVector);
	Movement->bAutoActivate = false;

	Visual = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Visual"));
	Visual->SetupAttachment(Collision);
	Visual->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Visual->SetRelativeScale3D(FVector(0.18f, 0.08f, 0.08f));         // a short bolt along its flight
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Sphere(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (Sphere.Succeeded()) { Visual->SetStaticMesh(Sphere.Object); }

	Trail = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Trail"));
	Trail->SetupAttachment(Collision);
	Trail->SetAutoActivate(false);
}

void ASunderProjectile::BeginPlay()
{
	Super::BeginPlay();
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASunderProjectile::OnOverlap);
	if (bParked) { Park(); }                                         // spawned by the pool: start parked
}

void ASunderProjectile::Fire(const FVector& Location, const FVector& Direction, AActor* InOwner, APawn* InInstigator)
{
	bParked = false;
	bFromEnemy = InOwner && InOwner->IsA<ASunderEnemy>();
	SetOwner(InOwner);
	SetInstigator(InInstigator);
	const FVector Dir = FVector(Direction.X, Direction.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::ForwardVector);
	SetActorLocationAndRotation(Location, Dir.Rotation(), /*bSweep*/ false, nullptr, ETeleportType::ResetPhysics);
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);

	Movement->SetUpdatedComponent(Collision);
	Movement->Velocity = Dir * Speed;
	Movement->Activate(/*bReset*/ true);
	Movement->SetComponentTickEnabled(true);

	if (Trail->GetAsset()) { Trail->ResetSystem(); }                 // restarts the trail from the muzzle
	GetWorldTimerManager().SetTimer(LifetimeTimer, this, &ASunderProjectile::Expire, MaxLifetime, false);
}

void ASunderProjectile::Park()
{
	bParked = true;
	GetWorldTimerManager().ClearTimer(LifetimeTimer);
	Movement->StopMovementImmediately();
	Movement->SetComponentTickEnabled(false);
	Movement->Deactivate();
	Trail->DeactivateImmediate();
	SetActorEnableCollision(false);
	SetActorHiddenInGame(true);
}

void ASunderProjectile::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (bParked || !OtherActor || OtherActor == this || OtherActor == GetOwner() || OtherActor == GetInstigator()) { return; }
	if (OtherActor->IsA<ASunderProjectile>()) { return; }               // shots pass through each other
	if (bFromEnemy != OtherActor->IsA<ASunderShipPawn>()) { return; }  // enemy shots hit only the ship; ours never do

	const FVector Dir = Movement->Velocity.GetSafeNormal(UE_SMALL_NUMBER, GetActorForwardVector());
	const FVector Point = bFromSweep ? FVector(SweepResult.ImpactPoint) : GetActorLocation();
	const FVector Normal = bFromSweep ? FVector(SweepResult.ImpactNormal) : -Dir;
	if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
	{
		Impacts->QueueImpact(Point, Normal, PlasmaColor);
	}

	AController* InstigatorController = GetInstigator() ? GetInstigator()->GetController() : nullptr;
	UGameplayStatics::ApplyDamage(OtherActor, Damage, InstigatorController, this, UDamageType::StaticClass());
	ReturnToPool();
}

void ASunderProjectile::Expire()
{
	ReturnToPool();
}

void ASunderProjectile::ReturnToPool()
{
	if (bParked) { return; }                                          // already returned (e.g. two overlaps in one frame)
	if (UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>())
	{
		Pool->Release(this);
	}
	else
	{
		Park();
	}
}
