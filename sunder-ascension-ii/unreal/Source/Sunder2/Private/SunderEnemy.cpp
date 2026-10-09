// SUNDER: Ascension II — an enemy craft.
#include "SunderEnemy.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "GameFramework/DamageType.h"
#include "ImpactFXSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "ProjectilePoolSubsystem.h"
#include "SunderGameMode.h"
#include "SunderMusicSubsystem.h"
#include "SunderProjectile.h"
#include "SunderShipPawn.h"
#include "UObject/ConstructorHelpers.h"

ASunderEnemy::ASunderEnemy()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::Disabled;                 // pattern-driven; no AI controller needed

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(45.f);
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);   // the beam's trace stops on enemies
	Collision->SetGenerateOverlapEvents(true);
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cone(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (Cone.Succeeded()) { BodyMesh = Cone.Object; }
}

void ASunderEnemy::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	// Apply the Blueprint's look (so each enemy type shows correctly in the editor too).
	if (BodyMesh) { Mesh->SetStaticMesh(BodyMesh); }
	Mesh->SetRelativeScale3D(BodyScale);
	Mesh->SetRelativeRotation(BodyRotation);
	Collision->SetSphereRadius(HitRadius);
}

void ASunderEnemy::BeginPlay()
{
	Super::BeginPlay();
	Health = MaxHealth;
	SpawnLocation = GetActorLocation();
	FireCooldown = FirstShotDelay;
	BodyMaterial = Mesh->CreateDynamicMaterialInstance(0);
	if (BodyMaterial) { BodyMaterial->SetVectorParameterValue(TEXT("Color"), BodyColor); }
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASunderEnemy::OnBodyOverlap);
}

void ASunderEnemy::Setup(const FVector& InArenaCenter, const FVector2D& InArenaHalfExtents, float HealthScale,
	float SpeedScale, float InFireRateScale, float InShotSpeedScale, float ScoreScale)
{
	ArenaCenter = InArenaCenter;
	ArenaHalfExtents = InArenaHalfExtents;
	MaxHealth *= HealthScale;
	Health = MaxHealth;
	Speed *= SpeedScale;
	FireRateScale = FMath::Max(InFireRateScale, 0.1f);
	ShotSpeedScale = FMath::Max(InShotSpeedScale, 0.1f);
	ScoreValue = FMath::RoundToInt(ScoreValue * FMath::Max(ScoreScale, 0.f));
	SpawnLocation = GetActorLocation();
}

bool ASunderEnemy::SpawnExplosion()
{
	if (!ExplosionFX || ExplosionFX->GetEmitterHandles().Num() == 0) { return false; }   // unset, or not built yet
	// Pooled: back to the pool by itself when its emitters finish, long after this enemy is gone.
	UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionFX, GetActorLocation(),
		FRotator::ZeroRotator, FVector(1.f), /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease,
		/*bPreCullCheck*/ false);
	if (!FX) { return false; }
	FX->SetVariableLinearColor(TEXT("Color"), DeathColor);
	FX->SetVariableFloat(TEXT("Size"), ExplosionSize > 0.f ? ExplosionSize : HitRadius);
	FX->SetVariableFloat(TEXT("Big"), bBigBurst ? 1.f : 0.f);
	FX->SetTranslucentSortPriority(12);
	return true;
}

FVector ASunderEnemy::PlayerLocation() const
{
	const APawn* Player = UGameplayStatics::GetPlayerPawn(this, 0);
	return Player ? Player->GetActorLocation() : GetActorLocation() - FVector(1000.f, 0.f, 0.f);
}

void ASunderEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bDead) { return; }
	Age += DeltaTime;
	Move(DeltaTime);
	TryFire(DeltaTime);

	HitFlash = FMath::Max(HitFlash - DeltaTime * 10.f, 0.f);
	if (BodyMaterial) { BodyMaterial->SetVectorParameterValue(TEXT("Color"), FMath::Lerp(BodyColor, FLinearColor::White, HitFlash)); }

	// Gone off the bottom or the sides: leave quietly (no score).
	const FVector P = GetActorLocation();
	if (P.X < ArenaCenter.X - ArenaHalfExtents.X - 250.f || FMath::Abs(P.Y - ArenaCenter.Y) > ArenaHalfExtents.Y + 500.f
		|| (Age > 3.f && P.X > ArenaCenter.X + ArenaHalfExtents.X + 600.f))
	{
		Die(false);
	}
}

void ASunderEnemy::Move(float DeltaTime)
{
	FVector P = GetActorLocation();
	switch (MovePattern)
	{
	case ESunderMovePattern::Straight:
		P.X -= Speed * DeltaTime;
		break;

	case ESunderMovePattern::Weave:
		P.X -= Speed * DeltaTime;
		P.Y = SpawnLocation.Y + WeaveAmplitude * FMath::Sin(Age * WeaveFrequency * UE_TWO_PI);
		break;

	case ESunderMovePattern::Dive:
		if (!bDiving && Age >= DiveDelay)
		{
			bDiving = true;
			const FVector ToPlayer = PlayerLocation() - P;
			DiveDirection = FVector(ToPlayer.X, ToPlayer.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::BackwardVector);
			if (DiveDirection.X > -0.3f) { DiveDirection = (DiveDirection + FVector(-1.f, 0.f, 0.f)).GetSafeNormal(); }   // always downward
		}
		P += bDiving ? DiveDirection * Speed * 1.6f * DeltaTime : FVector(-Speed * 0.35f * DeltaTime, 0.f, 0.f);
		break;

	case ESunderMovePattern::Strafe:
	{
		const float HoldX = ArenaCenter.X + ArenaHalfExtents.X * (1.f - 2.f * StrafeHoldDepth);
		if (P.X > HoldX && StrafeClock == 0.f)
		{
			P.X = FMath::Max(P.X - Speed * DeltaTime, HoldX);  // drop into position
		}
		else if (StrafeClock < StrafeTime)
		{
			StrafeClock += DeltaTime;
			const float Reach = FMath::Min(ArenaHalfExtents.Y * 0.8f, WeaveAmplitude * 3.f);
			P.Y = FMath::Clamp(SpawnLocation.Y + Reach * FMath::Sin(StrafeClock * WeaveFrequency * UE_TWO_PI),
				ArenaCenter.Y - ArenaHalfExtents.Y * 0.9f, ArenaCenter.Y + ArenaHalfExtents.Y * 0.9f);
		}
		else
		{
			P.X -= Speed * 1.4f * DeltaTime;                  // done: leave down the screen
		}
		break;
	}

	case ESunderMovePattern::Zigzag:
		ZigzagTimer += DeltaTime;
		if (ZigzagTimer >= ZigzagInterval) { ZigzagTimer = 0.f; ZigzagSign = -ZigzagSign; }
		P.X -= Speed * DeltaTime;
		P.Y += ZigzagSign * Speed * 0.9f * DeltaTime;
		if (FMath::Abs(P.Y - ArenaCenter.Y) > ArenaHalfExtents.Y * 0.9f) { ZigzagSign = -FMath::Sign(P.Y - ArenaCenter.Y); }
		break;
	}
	SetActorLocation(P);
}

void ASunderEnemy::TryFire(float DeltaTime)
{
	if (FirePattern == ESunderFirePattern::None || !ShotClass) { return; }
	if (GetActorLocation().X > ArenaCenter.X + ArenaHalfExtents.X) { return; }   // hold fire until on screen
	FireCooldown -= DeltaTime;
	if (FireCooldown > 0.f) { return; }
	FireCooldown = FireInterval / FireRateScale;
	FireVolley();
}

void ASunderEnemy::FireVolley()
{
	UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>();
	if (!Pool) { return; }
	const FVector Origin = GetActorLocation();
	const int32 N = FMath::Max(ShotCount, 1);

	// The Hour's bullet speed: the shot's own speed × the wave set's ShotSpeedScale (0 = the shot's own, unscaled).
	const float ShotSpeed = ShotSpeedScale != 1.f ? ShotClass->GetDefaultObject<ASunderProjectile>()->Speed * ShotSpeedScale : 0.f;
	auto Fire = [&](const FVector& Dir) { Pool->Acquire(ShotClass, Origin, Dir, this, this, ShotSpeed); };

	switch (FirePattern)
	{
	case ESunderFirePattern::Aimed:
	{
		const FVector ToPlayer = PlayerLocation() - Origin;
		const FVector Aim = FVector(ToPlayer.X, ToPlayer.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::BackwardVector);
		for (int32 i = 0; i < N; ++i) { Fire(Aim.RotateAngleAxis((i - (N - 1) * 0.5f) * 12.f, FVector::UpVector)); }
		break;
	}
	case ESunderFirePattern::Spread:
		for (int32 i = 0; i < N; ++i)
		{
			const float T = N > 1 ? (float)i / (N - 1) - 0.5f : 0.f;
			Fire(FVector::BackwardVector.RotateAngleAxis(T * SpreadAngle, FVector::UpVector));
		}
		break;
	case ESunderFirePattern::Radial:
		RadialTurn += 360.f / N * 0.37f;                         // each ring turns a little so gaps move
		for (int32 i = 0; i < N; ++i) { Fire(FVector::BackwardVector.RotateAngleAxis(RadialTurn + i * 360.f / N, FVector::UpVector)); }
		break;
	default:
		break;
	}
}

float ASunderEnemy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (bDead || DamageAmount <= 0.f) { return 0.f; }
	Health -= DamageAmount;
	HitFlash = 1.f;
	if (Health <= 0.f) { Die(true); }
	return DamageAmount;
}

void ASunderEnemy::OnBodyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASunderShipPawn* Ship = Cast<ASunderShipPawn>(OtherActor);
	if (bDead || !Ship || !Ship->IsAlive()) { return; }
	UGameplayStatics::ApplyDamage(Ship, ContactDamage, nullptr, this, UDamageType::StaticClass());
	if (bDiesOnContact) { Die(true); }                        // small craft break up on the hull
}

void ASunderEnemy::Die(bool bAwardScore)
{
	if (bDead) { return; }
	bDead = true;
	if (bAwardScore)
	{
		UImpactFXSubsystem* Impacts = SpawnExplosion() ? nullptr : GetWorld()->GetSubsystem<UImpactFXSubsystem>();
		if (Impacts)   // no explosion system yet: the shared plasma impacts
		{
			Impacts->QueueImpact(GetActorLocation(), FVector::BackwardVector, DeathColor);
			if (MaxHealth >= 100.f) { Impacts->QueueImpact(GetActorLocation(), FVector::BackwardVector, DeathColor); }   // big ones burst bigger
		}
		if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>())
		{
			Mode->AddScore(ScoreValue);
			Mode->PlayExplosion(bBigExplosion);
			if (bDropsPickups) { Mode->TrySpawnPickup(GetActorLocation(), DropChance); }
		}
		if (bPlaysDownCue)
		{
			if (USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>()) { Music->PlayStageCue(ESunderStageCue::Down); }
		}
	}
	SetActorEnableCollision(false);
	Destroy();
}
