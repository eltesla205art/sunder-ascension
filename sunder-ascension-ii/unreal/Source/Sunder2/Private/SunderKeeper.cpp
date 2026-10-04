// SUNDER: Ascension II — a Keeper (boss). Movement and patterns follow the web game's bossFirePattern / updateBoss.
#include "SunderKeeper.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "ImpactFXSubsystem.h"
#include "ProjectilePoolSubsystem.h"
#include "SunderGameMode.h"

ASunderKeeper::ASunderKeeper()
{
	MaxHealth = 2300.f;
	ScoreValue = 4000;
	ContactDamage = 1.f;
	bDiesOnContact = false;
	FireInterval = 1.3f;
	FirstShotDelay = 0.6f;
	BodyRotation = FRotator(0.f, 90.f, 0.f);   // Blender's down-screen (-Y) to Unreal's (-X); adjust if a model faces the wrong way
	BodyScale = FVector(1.f);
	DeathColor = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);
	Patterns = { ESunderBossPattern::AimedVolley };
}

void ASunderKeeper::OnConstruction(const FTransform& Transform)
{
	Super::OnConstruction(Transform);
	FitToScreen(BodyMesh);
}

void ASunderKeeper::FitToScreen(UStaticMesh* ForMesh)
{
	if (!ForMesh) { return; }
	// Size of the model as it will sit on screen (after BodyRotation), then one uniform scale to fit FitSize.
	const FBox Local = ForMesh->GetBoundingBox();
	const FVector Size = Local.TransformBy(FTransform(BodyRotation)).GetSize();
	const float Across = FMath::Max(Size.Y, 1.f), Up = FMath::Max(Size.X, 1.f);
	const float Scale = FMath::Min(FitSize.X / Across, FitSize.Y / Up) * BodyScale.X;
	BaseMeshScale = FVector(Scale);
	Mesh->SetRelativeScale3D(BaseMeshScale);
	HitRadius = 0.32f * 0.5f * (Across * Scale + Up * Scale);   // like the web game's boss radius: about a third of its size
	Collision->SetSphereRadius(HitRadius);
}

void ASunderKeeper::BeginPlay()
{
	Super::BeginPlay();
	FireCooldown = FirstShotDelay;
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>())
	{
		Mode->AnnounceKeeper(this, FString::Printf(TEXT("HOUR %d  ·  %s"), Hour, *KeeperName), Taunt);
	}
}

FVector ASunderKeeper::WebDirection(float A) const
{
	// The web game's angle (x right, y down the canvas) on the Unreal play plane (X up the screen, Y right).
	return FVector(-FMath::Sin(A), FMath::Cos(A), 0.f);
}

void ASunderKeeper::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bDead) { return; }
	BossTime += DeltaTime;
	// Keepers keep their own materials, so the hit flash is a quick swell instead of a colour change.
	Mesh->SetRelativeScale3D(BaseMeshScale * (1.f + 0.05f * HitFlash));
}

void ASunderKeeper::Move(float DeltaTime)
{
	FVector P = GetActorLocation();
	const float HoldX = ArenaCenter.X + ArenaHalfExtents.X * (1.f - 2.f * HoldDepth);
	if (bEntering)
	{
		P.X -= EnterSpeed * DeltaTime;
		if (P.X <= HoldX) { P.X = HoldX; bEntering = false; }
		SetActorLocation(P);
		return;
	}
	const float SpeedNow = StrafeSpeed + Phase * 125.f;
	const float Dash = Phase == 3 ? 1.f + FMath::Abs(FMath::Cos(BossTime * 5.f)) * 1.2f : 1.f;   // phase 3: rapid dashes
	P.Y += StrafeDir * SpeedNow * Dash * DeltaTime;
	const float Reach = ArenaHalfExtents.Y * 0.6f;
	if (P.Y < ArenaCenter.Y - Reach) { P.Y = ArenaCenter.Y - Reach; StrafeDir = 1.f; }
	else if (P.Y > ArenaCenter.Y + Reach) { P.Y = ArenaCenter.Y + Reach; StrafeDir = -1.f; }
	SetActorLocation(P);
}

void ASunderKeeper::TryFire(float DeltaTime)
{
	if (bEntering || !ShotClass || Patterns.Num() == 0) { return; }
	PatternClock += DeltaTime;
	if (PatternClock >= PatternSwitchTime)
	{
		PatternClock = 0.f;
		PatternIndex = (PatternIndex + 1) % Patterns.Num();
	}
	FireCooldown -= DeltaTime;
	if (FireCooldown > 0.f) { return; }
	FirePattern(Patterns[PatternIndex % Patterns.Num()]);
	FireCooldown = FireInterval * (1.f - Phase * 0.12f) / FireRateScale;   // each phase fires faster
}

void ASunderKeeper::Shoot(const FVector& Direction, float SpeedScale)
{
	if (UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>())
	{
		const FVector Origin = GetActorLocation() - FVector(60.f, 0.f, 0.f);
		Pool->Acquire(ShotClass, Origin, Direction, this, this, BulletSpeed * SpeedScale);
	}
}

void ASunderKeeper::FirePattern(ESunderBossPattern Pattern)
{
	switch (Pattern)
	{
	case ESunderBossPattern::AimedVolley:
	{
		const FVector ToPlayer = PlayerLocation() - GetActorLocation();
		const FVector Aim = FVector(ToPlayer.X, ToPlayer.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::BackwardVector);
		for (int32 i = -1; i <= 1; ++i) { Shoot(Aim.RotateAngleAxis(14.f * i, FVector::UpVector)); }
		break;
	}
	case ESunderBossPattern::SpreadFan:
	{
		const int32 Count = 5 + Phase * 2;
		for (int32 i = 0; i < Count; ++i)
		{
			const float T = (float)i / (Count - 1) - 0.5f;
			Shoot(WebDirection(FMath::DegreesToRadians(90.f + 70.f * T)));
		}
		break;
	}
	case ESunderBossPattern::HorizontalSweep:
	{
		const float Side = FMath::Fmod(BossTime, 2.f) < 1.f ? 1.f : -1.f;
		for (int32 i = 0; i < 6; ++i)
		{
			const FVector V(-(0.18f + i * 0.115f), Side, 0.f);   // the web game's (side·s, 40 + 25i): raking, slightly down
			Shoot(V.GetSafeNormal(), V.Size());
		}
		break;
	}
	case ESunderBossPattern::RadialBurst:
	{
		const int32 Count = 14 + Phase * 3;
		for (int32 i = 0; i < Count; ++i) { Shoot(WebDirection(UE_TWO_PI * i / Count), 0.85f); }
		break;
	}
	case ESunderBossPattern::CrossRing:
		for (int32 i = 0; i < 12; ++i) { Shoot(WebDirection(UE_TWO_PI * i / 12), 0.85f); }
		for (const float Deg : { 0.f, 90.f, 180.f, 270.f }) { Shoot(WebDirection(FMath::DegreesToRadians(Deg) + BossTime)); }
		break;
	case ESunderBossPattern::Spiral:
		SpiralAngle += 0.4f;
		for (int32 i = 0; i < 3; ++i) { Shoot(WebDirection(SpiralAngle + UE_TWO_PI * i / 3)); }
		break;
	case ESunderBossPattern::DualSpiral:
		SpiralAngle += 0.5f;
		Shoot(WebDirection(SpiralAngle));
		Shoot(WebDirection(-SpiralAngle + UE_PI));
		break;
	case ESunderBossPattern::WallBarrage:
	{
		UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>();
		if (!Pool) { break; }
		const int32 Gap = FMath::RandRange(0, 5);
		for (int32 i = 0; i < 8; ++i)
		{
			if (i == Gap || i == Gap + 1) { continue; }          // the way through
			const float Across = (60.f + i * 50.f - 240.f) / 240.f;   // the web game's columns across its 480-px canvas
			const FVector From(GetActorLocation().X - 60.f, ArenaCenter.Y + Across * ArenaHalfExtents.Y * 0.95f, GetActorLocation().Z);
			Pool->Acquire(ShotClass, From, FVector::BackwardVector, this, this, BulletSpeed);
		}
		break;
	}
	}
}

float ASunderKeeper::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bEntering) { return 0.f; }                           // untouchable until it has taken its position
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (bDead) { return Applied; }
	const float Fraction = GetHealthFraction();
	const int32 NewPhase = Fraction <= 0.33f ? 3 : (Fraction <= 0.66f ? 2 : 1);
	if (NewPhase > Phase)
	{
		Phase = NewPhase;
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
		{
			Impacts->QueueImpact(GetActorLocation(), FVector::BackwardVector, DeathColor);   // it cracks
		}
		if (Phase == 3 && PhaseThreeMesh)
		{
			Mesh->SetStaticMesh(PhaseThreeMesh);                 // the final form
			FitToScreen(PhaseThreeMesh);
		}
	}
	return Applied;
}

void ASunderKeeper::Die(bool bAwardScore)
{
	if (bDead) { return; }
	if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
	{
		// A burst across the whole body: spread out so they don't merge into one.
		const float R = HitRadius * 1.6f;
		for (int32 i = 0; i < 7; ++i)
		{
			const float A = UE_TWO_PI * i / 7;
			const FVector Offset = i == 0 ? FVector::ZeroVector : FVector(FMath::Cos(A) * R, FMath::Sin(A) * R, 0.f);
			Impacts->QueueImpact(GetActorLocation() + Offset, FVector::BackwardVector, DeathColor);
			Impacts->QueueImpact(GetActorLocation() + Offset, FVector::BackwardVector, DeathColor);
		}
	}
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->ClearKeeper(this); }
	Super::Die(bAwardScore);
}
