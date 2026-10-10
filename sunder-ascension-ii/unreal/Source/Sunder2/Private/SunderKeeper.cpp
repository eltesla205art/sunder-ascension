// SUNDER: Ascension II — a Keeper (boss). Movement and patterns follow the web game's bossFirePattern / updateBoss.
#include "SunderKeeper.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "ImpactFXSubsystem.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "ProjectilePoolSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderGameMode.h"
#include "SunderMusicSubsystem.h"
#include "SunderProjectile.h"
#include "SunderSettingsSubsystem.h"
#include "SunderCodexSubsystem.h"

ASunderKeeper::ASunderKeeper()
{
	MaxHealth = 2300.f;
	ScoreValue = 4000;
	ContactDamage = 1.f;
	bDiesOnContact = false;
	bPlaysDownCue = false;                                   // its stage plays Clear instead
	bDropsPickups = false;
	bBigExplosion = true;                                    // its final burst: the web game's "bigboom"
	FireInterval = 1.3f;
	FirstShotDelay = 0.6f;
	BodyRotation = FRotator(0.f, 90.f, 0.f);   // Blender's down-screen (-Y) to Unreal's (-X); adjust if a model faces the wrong way
	BodyScale = FVector(1.f);
	DeathColor = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);
	Patterns = { ESunderBossPattern::AimedVolley };

	Aura = CreateDefaultSubobject<UNiagaraComponent>(TEXT("Aura"));
	Aura->SetupAttachment(Collision);                        // on the root, so the mesh's hit swell doesn't scale it
	Aura->SetAutoActivate(false);
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
		Mode->AnnounceKeeper(this, KeeperName, Taunt);
		if (USunderCodexSubsystem* Codex = USunderCodexSubsystem::Get(this)) { Codex->MarkMet(Hour); }   // its Codex page opens
	}
	if (USunderMusicSubsystem* M = Music(); M && MusicLayers.Num() > 0)
	{
		TArray<USoundBase*> Layers(MusicLayers);
		M->PlayLayered(Layers, 1);
	}
	PlayVoice(IntroSound, 0.f, LastCryVoice, true);
	if (AuraFX && AuraFX->GetEmitterHandles().Num() > 0)
	{
		Aura->SetAsset(AuraFX);
		SetFXParams(Aura, 1.f, 0.f);
		Aura->SetTranslucentSortPriority(5);                     // behind the shots and impacts
		Aura->Activate(true);
	}
}

USunderMusicSubsystem* ASunderKeeper::Music() const
{
	return GetWorld() ? GetWorld()->GetSubsystem<USunderMusicSubsystem>() : nullptr;
}

void ASunderKeeper::PlayVoice(USoundBase* Sound, float MinGap, float& LastPlayed, bool bDuck)
{
	if (!Sound) { return; }
	const float Now = GetWorld()->GetTimeSeconds();
	if (MinGap > 0.f && Now - LastPlayed < MinGap) { return; }   // a barrage mustn't turn into noise
	LastPlayed = Now;
	UGameplayStatics::PlaySound2D(this, Sound, VoiceVolume * USunderSettingsSubsystem::EffectsGain(this));
	if (bDuck)
	{
		if (USunderMusicSubsystem* M = Music()) { M->Duck(Sound->GetDuration() * 0.7f); }   // the web game's duck length
	}
}

void ASunderKeeper::Gloat()
{
	PlayVoice(PhaseSound, 0.f, LastCryVoice, true);
}

void ASunderKeeper::SetFXParams(UNiagaraComponent* FX, float Scale, float Duration) const
{
	FX->SetVariableLinearColor(TEXT("KeeperColor"), KeeperColor);
	FX->SetVariableLinearColor(TEXT("AccentColor"), AccentColor);
	FX->SetVariableFloat(TEXT("Size"), BodyRadius() * Scale);
	FX->SetVariableFloat(TEXT("Phase"), bDying ? 4.f : (float)Phase);
	FX->SetVariableFloat(TEXT("Duration"), Duration);
}

UNiagaraComponent* ASunderKeeper::SpawnFX(UNiagaraSystem* System, const FVector& Location, float Scale, float Duration)
{
	if (!System || System->GetEmitterHandles().Num() == 0) { return nullptr; }   // unset, or not built yet: use the fallbacks
	// Pooled: back to the pool by itself when its emitters finish, even after the Keeper is gone.
	UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), System, Location, FRotator::ZeroRotator,
		FVector(1.f), /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, /*bPreCullCheck*/ false);
	if (FX)
	{
		SetFXParams(FX, Scale, Duration);
		FX->SetTranslucentSortPriority(15);
	}
	return FX;
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
	if (bDying) { TickDying(DeltaTime); return; }
	BossTime += DeltaTime;
	// Keepers keep their own materials, so the hit flash is a quick swell instead of a colour change.
	Mesh->SetRelativeScale3D(BaseMeshScale * (1.f + 0.05f * HitFlash));
}

void ASunderKeeper::Move(float DeltaTime)
{
	if (bDying) { return; }
	if (bEntering && IntroTime < IntroHold)
	{
		IntroTime += DeltaTime;                               // its intro card first, then the Gate opens and it descends
		return;
	}
	FVector P = GetActorLocation();
	const float HoldX = ArenaCenter.X + ArenaHalfExtents.X * (1.f - 2.f * HoldDepth);
	if (bEntering && !bArrivalShown)
	{
		// The Gate opens where it will hold (here, not in BeginPlay: the arena is only known after Setup).
		bArrivalShown = true;
		SpawnFX(ArrivalFX, FVector(HoldX, P.Y, P.Z), 1.f, FMath::Max(P.X - HoldX, 0.f) / FMath::Max(EnterSpeed, 1.f));
	}
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
	if (bEntering || bDying || !ShotClass || Patterns.Num() == 0) { return; }
	PatternClock += DeltaTime;
	if (PatternClock >= PatternSwitchTime)
	{
		PatternClock = 0.f;
		PatternIndex = (PatternIndex + 1) % Patterns.Num();
		if (Patterns.Num() > 1) { SpawnFX(MuzzleFX, MuzzleLocation(), 2.f); }   // a new attack: a bigger flare
	}
	FireCooldown -= DeltaTime;
	if (FireCooldown > 0.f) { return; }
	FirePattern(Patterns[PatternIndex % Patterns.Num()]);
	SpawnFX(MuzzleFX, MuzzleLocation(), 1.f);
	PlayVoice(AttackSound, 0.45f, LastAttackVoice, false);
	FireCooldown = FireInterval * (1.f - Phase * 0.12f) / FireRateScale;   // each phase fires faster
}

void ASunderKeeper::Shoot(const FVector& Direction, float SpeedScale)
{
	ShootFrom(MuzzleLocation(), Direction, SpeedScale);
}

void ASunderKeeper::ShootFrom(const FVector& Origin, const FVector& Direction, float SpeedScale)
{
	if (UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>())
	{
		ASunderProjectile* Shot = Pool->Acquire(ShotClass, Origin, Direction, this, this, BulletSpeed * SpeedScale);
		FLinearColor SafeEnemy, SafePlayer;
		if (Shot && USunderSettingsSubsystem::BulletPalette(this, SafeEnemy, SafePlayer)) { Shot->SetShotColor(SafeEnemy); }   // colourblind-safe
		else if (Shot && bTintShots) { Shot->SetShotColor(KeeperColor); }
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
		const int32 Gap = FMath::RandRange(0, 5);
		for (int32 i = 0; i < 8; ++i)
		{
			if (i == Gap || i == Gap + 1) { continue; }          // the way through
			const float Across = (60.f + i * 50.f - 240.f) / 240.f;   // the web game's columns across its 480-px canvas
			const FVector From(GetActorLocation().X - 60.f, ArenaCenter.Y + Across * ArenaHalfExtents.Y * 0.95f, GetActorLocation().Z);
			ShootFrom(From, FVector::BackwardVector, 1.f);
		}
		break;
	}
	}
}

float ASunderKeeper::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (bEntering) { return 0.f; }                           // untouchable until it has taken its position
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (bDead || bDying) { return Applied; }
	if (Applied > 0.f) { PlayVoice(HurtSound, 0.1f, LastHurtVoice, false); }
	const float Fraction = GetHealthFraction();
	const int32 NewPhase = Fraction <= 0.33f ? 3 : (Fraction <= 0.66f ? 2 : 1);
	if (NewPhase > Phase)
	{
		Phase = NewPhase;
		PlayVoice(PhaseSound, 0.f, LastCryVoice, true);
		if (USunderMusicSubsystem* M = Music())
		{
			if (Phase == 3 && FinalFormMusicLayers.Num() > 0)
			{
				TArray<USoundBase*> Layers(FinalFormMusicLayers);
				M->PlayLayered(Layers, 3);                      // Apep's final form has its own theme
			}
			else
			{
				M->SetLayer(Phase);                              // the theme builds with each phase
			}
		}
		const bool bNewForm = Phase == 3 && PhaseThreeMesh;
		if (bNewForm)
		{
			Mesh->SetStaticMesh(PhaseThreeMesh);                 // the final form
			FitToScreen(PhaseThreeMesh);
		}
		if (Aura->IsActive())
		{
			Aura->SetVariableFloat(TEXT("Phase"), (float)Phase);
			Aura->SetVariableFloat(TEXT("Size"), BodyRadius());
		}
		if (!SpawnFX(PhaseShiftFX, GetActorLocation(), bNewForm ? 1.6f : 1.f))
		{
			if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
			{
				Impacts->QueueImpact(GetActorLocation(), FVector::BackwardVector, DeathColor);   // it cracks
			}
		}
	}
	return Applied;
}

void ASunderKeeper::Die(bool bAwardScore)
{
	if (bDead || bDying) { return; }
	if (USunderMusicSubsystem* M = Music()) { M->StopMusic(bAwardScore ? 2.5f : 1.f); }
	if (bAwardScore) { PlayVoice(DeathSound, 0.f, LastCryVoice, true); }
	if (!bAwardScore || DeathDuration <= 0.f)
	{
		FinishDying(bAwardScore);
		return;
	}
	// Beaten: stop, shudder and crack apart for DeathDuration, then burst (TickDying → FinishDying).
	bDying = true;
	DyingTime = 0.f;
	NextDeathPop = 0.f;
	SetActorEnableCollision(false);                          // no more hits, no ramming, the beam passes through
	MeshRest = Mesh->GetRelativeLocation();
	if (Aura->IsActive()) { Aura->SetVariableFloat(TEXT("Phase"), 4.f); }
	SpawnFX(DeathFX, GetActorLocation(), 1.f, DeathDuration);
}

void ASunderKeeper::TickDying(float DeltaTime)
{
	DyingTime += DeltaTime;
	const float T = FMath::Clamp(DyingTime / DeathDuration, 0.f, 1.f);
	// A shudder that grows, and a slow swell as it comes apart.
	const float Shake = 6.f + 22.f * T;
	Mesh->SetRelativeLocation(MeshRest + FVector(FMath::FRandRange(-Shake, Shake), FMath::FRandRange(-Shake, Shake), 0.f));
	Mesh->SetRelativeScale3D(BaseMeshScale * (1.f + 0.08f * T));
	// Bursts popping across the body, faster and faster, in its two colours.
	if (DyingTime >= NextDeathPop)
	{
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
		{
			const FVector2D Spot = FMath::RandPointInCircle(BodyRadius() * 0.8f);
			Impacts->QueueImpact(GetActorLocation() + FVector(Spot.X, Spot.Y, 0.f), FVector::BackwardVector,
				(DeathPops++ % 2 == 0) ? KeeperColor : AccentColor);
		}
		NextDeathPop = DyingTime + FMath::Lerp(0.22f, 0.05f, T);
	}
	if (DyingTime >= DeathDuration) { FinishDying(true); }
}

void ASunderKeeper::FinishDying(bool bAwardScore)
{
	if (bAwardScore)
	{
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
		{
			// The final burst across the whole body: spread out so they don't merge into one.
			const float R = HitRadius * 1.6f;
			for (int32 i = 0; i < 7; ++i)
			{
				const float A = UE_TWO_PI * i / 7;
				const FVector Offset = i == 0 ? FVector::ZeroVector : FVector(FMath::Cos(A) * R, FMath::Sin(A) * R, 0.f);
				Impacts->QueueImpact(GetActorLocation() + Offset, FVector::BackwardVector, DeathColor);
				Impacts->QueueImpact(GetActorLocation() + Offset, FVector::BackwardVector, i % 2 ? KeeperColor : AccentColor);
			}
		}
	}
	bDying = false;
	if (bAwardScore)
	{
		if (USunderMusicSubsystem* M = Music()) { M->PlayStageCue(ESunderStageCue::Clear); }   // the Hour is won
		if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>())
		{
			Mode->AnnounceKeeperFallen(this);
			if (USunderCodexSubsystem* Codex = USunderCodexSubsystem::Get(this)) { Codex->MarkBeaten(Hour); }   // its full lore
			Mode->AddShake(0.6f);                                // the web game's onBossDefeated
		}
	}
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->ClearKeeper(this); }
	Super::Die(bAwardScore);
}
