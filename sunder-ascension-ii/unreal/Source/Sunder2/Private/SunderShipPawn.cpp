// SUNDER: Ascension II — the player's ship.
#include "SunderShipPawn.h"

#include "BeamWeaponComponent.h"
#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/LocalPlayer.h"
#include "Engine/StaticMesh.h"
#include "Engine/DamageEvents.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "GameFramework/PlayerController.h"
#include "InputAction.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "InputModifiers.h"
#include "EngineUtils.h"
#include "GameFramework/DamageType.h"
#include "ImpactFXSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "NiagaraComponent.h"
#include "NiagaraDataInterfaceArrayFunctionLibrary.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"
#include "SunderEnemy.h"
#include "SunderKeeper.h"
#include "ProjectilePoolSubsystem.h"
#include "SunderGameMode.h"
#include "SunderProjectile.h"
#include "UObject/ConstructorHelpers.h"

ASunderShipPawn::ASunderShipPawn()
{
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Disabled;          // the game mode possesses it

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(40.f);
	Collision->SetCollisionProfileName(TEXT("Pawn"));
	RootComponent = Collision;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Collision);
	Mesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cone(TEXT("/Engine/BasicShapes/Cone.Cone"));
	if (Cone.Succeeded())
	{
		Mesh->SetStaticMesh(Cone.Object);
		Mesh->SetRelativeRotation(FRotator(-90.f, 0.f, 0.f)); // tip pointing up the screen (+X)
		Mesh->SetRelativeScale3D(FVector(0.6f));
	}

	Muzzle = CreateDefaultSubobject<USceneComponent>(TEXT("Muzzle"));
	Muzzle->SetupAttachment(Collision);
	Muzzle->SetRelativeLocation(FVector(60.f, 0.f, 0.f));

	BeamWeapon = CreateDefaultSubobject<UBeamWeaponComponent>(TEXT("BeamWeapon"));

	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("ShieldMesh"));
	ShieldMesh->SetupAttachment(Collision);
	ShieldMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	ShieldMesh->SetRelativeLocation(FVector(0.f, 0.f, -30.f));          // under the ship, seen from above
	ShieldMesh->SetVisibility(false);
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Disc(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if (Disc.Succeeded()) { ShieldMesh->SetStaticMesh(Disc.Object); }

	ShieldComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("ShieldComponent"));
	ShieldComponent->SetupAttachment(Collision);
	ShieldComponent->SetAutoActivate(false);
}

void ASunderShipPawn::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	// Before the beam component's BeginPlay, so it attaches to our muzzle with our system.
	if (BeamSystem) { BeamWeapon->BeamSystem = BeamSystem; }
	BeamWeapon->SetMuzzle(Muzzle, NAME_None);
}

void ASunderShipPawn::BeginPlay()
{
	Super::BeginPlay();
	ArenaCenter.Z = GetActorLocation().Z;                    // the play plane is wherever the ship starts
	StartLocation = GetActorLocation();
	if (!bBaseScaleCaptured) { BaseMeshScale = Mesh->GetRelativeScale3D(); FittedScale = BaseMeshScale; bBaseScaleCaptured = true; }   // the Blueprint's size
	if (!bLoadoutApplied) { Health = MaxHealth; }              // a loadout applied before BeginPlay has set it
	ShieldMaterial = ShieldMesh->CreateDynamicMaterialInstance(0);
	if (ShieldMaterial) { ShieldMaterial->SetVectorParameterValue(TEXT("Color"), FLinearColor(0.1f, 0.55f, 0.8f)); }
	// The Niagara shield, once NS_Ship_Shield has emitters; until then the disc stands in.
	bShieldFXReady = ShieldFX && ShieldFX->GetEmitterHandles().Num() > 0;
	if (bShieldFXReady)
	{
		ShieldComponent->SetAsset(ShieldFX);
		ShieldComponent->SetTranslucentSortPriority(4);         // under the shots and impacts
	}
	ShownShield = -1;
	UpdateShield(-1);
	if (ProjectileClass)
	{
		if (UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>())
		{
			Pool->Prewarm(ProjectileClass, PrewarmShots);
		}
	}
}

void ASunderShipPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(PlayerInputComponent);
	if (!Input)
	{
		UE_LOG(LogTemp, Error, TEXT("SunderShipPawn needs Enhanced Input (Project Settings → Input → Default Input Component Class)."));
		return;
	}

	auto MakeAction = [this](const TCHAR* Name, EInputActionValueType Type)
	{
		UInputAction* Action = NewObject<UInputAction>(this, Name);
		Action->ValueType = Type;
		return Action;
	};
	MoveUpAction = MakeAction(TEXT("IA_MoveUp"), EInputActionValueType::Axis1D);
	MoveRightAction = MakeAction(TEXT("IA_MoveRight"), EInputActionValueType::Axis1D);
	BeamAction = MakeAction(TEXT("IA_Beam"), EInputActionValueType::Boolean);
	ShootAction = MakeAction(TEXT("IA_Shoot"), EInputActionValueType::Boolean);
	BombAction = MakeAction(TEXT("IA_Bomb"), EInputActionValueType::Boolean);

	Mapping = NewObject<UInputMappingContext>(this, TEXT("IMC_Ship"));
	auto MapNegated = [this](UInputAction* Action, const FKey& Key)
	{
		FEnhancedActionKeyMapping& KeyMapping = Mapping->MapKey(Action, Key);
		KeyMapping.Modifiers.Add(NewObject<UInputModifierNegate>(Mapping));
	};
	Mapping->MapKey(MoveUpAction, EKeys::W);
	MapNegated(MoveUpAction, EKeys::S);
	Mapping->MapKey(MoveUpAction, EKeys::Gamepad_LeftY);
	Mapping->MapKey(MoveRightAction, EKeys::D);
	MapNegated(MoveRightAction, EKeys::A);
	Mapping->MapKey(MoveRightAction, EKeys::Gamepad_LeftX);
	Mapping->MapKey(BeamAction, EKeys::SpaceBar);
	Mapping->MapKey(BeamAction, EKeys::Gamepad_RightTrigger);
	Mapping->MapKey(ShootAction, EKeys::J);
	Mapping->MapKey(ShootAction, EKeys::LeftMouseButton);
	Mapping->MapKey(ShootAction, EKeys::Gamepad_FaceButton_Bottom);
	Mapping->MapKey(BombAction, EKeys::X);
	Mapping->MapKey(BombAction, EKeys::K);
	Mapping->MapKey(BombAction, EKeys::Gamepad_FaceButton_Top);
	Mapping->MapKey(BombAction, EKeys::Gamepad_RightShoulder);

	if (APlayerController* PC = Cast<APlayerController>(GetController()))
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(PC->GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Mapping, 0);
		}
	}

	Input->BindAction(MoveUpAction, ETriggerEvent::Triggered, this, &ASunderShipPawn::OnMoveUp);
	Input->BindAction(MoveUpAction, ETriggerEvent::Completed, this, &ASunderShipPawn::OnMoveUpReleased);
	Input->BindAction(MoveRightAction, ETriggerEvent::Triggered, this, &ASunderShipPawn::OnMoveRight);
	Input->BindAction(MoveRightAction, ETriggerEvent::Completed, this, &ASunderShipPawn::OnMoveRightReleased);
	Input->BindAction(BeamAction, ETriggerEvent::Started, this, &ASunderShipPawn::OnBeamPressed);
	Input->BindAction(BeamAction, ETriggerEvent::Completed, this, &ASunderShipPawn::OnBeamReleased);
	Input->BindAction(ShootAction, ETriggerEvent::Started, this, &ASunderShipPawn::OnShootPressed);
	Input->BindAction(ShootAction, ETriggerEvent::Completed, this, &ASunderShipPawn::OnShootReleased);
	Input->BindAction(BombAction, ETriggerEvent::Started, this, &ASunderShipPawn::OnBombPressed);
}

void ASunderShipPawn::OnMoveUp(const FInputActionValue& Value) { MoveInput.X = Value.Get<float>(); }
void ASunderShipPawn::OnMoveUpReleased(const FInputActionValue& Value) { MoveInput.X = 0.f; }
void ASunderShipPawn::OnMoveRight(const FInputActionValue& Value) { MoveInput.Y = Value.Get<float>(); }
void ASunderShipPawn::OnMoveRightReleased(const FInputActionValue& Value) { MoveInput.Y = 0.f; }
void ASunderShipPawn::OnBeamPressed(const FInputActionValue& Value) { if (!bDead) { BeamWeapon->StartFire(); } }
void ASunderShipPawn::OnBeamReleased(const FInputActionValue& Value) { BeamWeapon->StopFire(); }
void ASunderShipPawn::OnShootPressed(const FInputActionValue& Value) { bShooting = true; }
void ASunderShipPawn::OnShootReleased(const FInputActionValue& Value) { bShooting = false; }
void ASunderShipPawn::OnBombPressed(const FInputActionValue& Value) { UseBomb(); }

void ASunderShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	ToastTime = FMath::Max(ToastTime - DeltaTime, 0.f);
	if (bDead) { return; }

	if (FormFlash > 0.f) { FormFlash = FMath::Max(FormFlash - DeltaTime, 0.f); UpdateBodyScale(); }
	if (State.Shield != ShownShield) { UpdateShield(State.Shield > ShownShield && ShownShield >= 0 ? 2 : -1); }
	// The fallback shield: a disc under the ship, bigger with each layer, breathing.
	if (!bShieldFXReady && State.Shield > 0)
	{
		const float R = (1.5f + 0.25f * State.Shield) * (1.f + 0.05f * FMath::Sin(GetWorld()->GetTimeSeconds() * 5.f));
		ShieldMesh->SetRelativeScale3D(FVector(R, R, 0.03f));
	}

	if (Invulnerable > 0.f)                                   // blink while invulnerable
	{
		Invulnerable = FMath::Max(Invulnerable - DeltaTime, 0.f);
		Mesh->SetVisibility(Invulnerable <= 0.f || FMath::Fmod(Invulnerable * 12.f, 1.f) < 0.6f);
	}

	FVector Move(MoveInput.X, MoveInput.Y, 0.f);
	if (Move.SizeSquared() > 1.f) { Move.Normalize(); }    // diagonals no faster than straight lines
	FVector Location = GetActorLocation() + Move * MoveSpeed * DeltaTime;
	Location.X = FMath::Clamp(Location.X, ArenaCenter.X - ArenaHalfExtents.X, ArenaCenter.X + ArenaHalfExtents.X);
	Location.Y = FMath::Clamp(Location.Y, ArenaCenter.Y - ArenaHalfExtents.Y, ArenaCenter.Y + ArenaHalfExtents.Y);
	Location.Z = ArenaCenter.Z;
	SetActorLocation(Location);

	if (bShooting)
	{
		ShotCooldown -= DeltaTime;
		int32 Volleys = 0;
		while (ShotCooldown <= 0.f && Volleys++ < 4)          // catch up after a long frame, but never flood
		{
			FireShots();
			const float Now = GetWorld()->GetTimeSeconds();
			if (Now - LastShootSound >= 0.09f) { LastShootSound = Now; PlaySound(ShootSound); }   // the web game's limit
			ShotCooldown += FireInterval * (State.Weapon == ESunderWeapon::Laser ? 0.85f : 1.f);   // the Laser fires faster
		}
		ShotCooldown = FMath::Max(ShotCooldown, 0.f);
	}
	else
	{
		ShotCooldown = FMath::Max(ShotCooldown - DeltaTime, 0.f);
	}
}

float ASunderShipPawn::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (bDead || Invulnerable > 0.f || DamageAmount <= 0.f) { return 0.f; }
	if (State.Shield > 0)
	{
		// A shield soaks the whole hit: no hull lost, no power lost.
		--State.Shield;
		Invulnerable = ShieldInvulnerability;
		PlaySound(HitSound);
		UpdateShield(State.Shield == 0 ? 1 : 0);              // the last layer shatters; others ripple
		return 0.f;
	}
	Health -= DamageAmount;
	Invulnerable = HitInvulnerability;
	PlaySound(HitSound);
	if (State.Power > 1 && Health > 0.f) { SetPower(State.Power - 1); }   // the form falls back a step (a respawn resets it)
	if (Health > 0.f)
	{
		SpawnExplosion(0);                                    // the web game's small gold burst on a hull hit
		return DamageAmount;
	}

	bDead = true;                                             // hull gone: burst, vanish, tell the game mode
	bShooting = false;
	BeamWeapon->StopFire();
	SpawnExplosion(1);
	Mesh->SetVisibility(false);
	SetActorEnableCollision(false);
	UpdateShield(-1);
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->OnShipDestroyed(this); }
	return DamageAmount;
}

void ASunderShipPawn::Respawn()
{
	SetActorLocation(StartLocation);
	Health = MaxHealth;
	SetPower(1);                                             // back to the first form, with a shield and the ship's bombs
	State.Bombs = FMath::Max(State.Bombs, Loadout.StartBombs);
	// The warp-in: light gathers at the start point, then the ship appears (FinishRespawn). Without the system, at once.
	float Warp = 0.f;
	if (RespawnFX && RespawnFX->GetEmitterHandles().Num() > 0)
	{
		if (UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAttached(RespawnFX, GetRootComponent(), NAME_None,
			FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, /*bAutoDestroy*/ false,
			/*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, /*bPreCullCheck*/ false))
		{
			Warp = RespawnWarpTime;
			FX->SetVariableLinearColor(TEXT("Color"), DeathColor);
			FX->SetVariableLinearColor(TEXT("AccentColor"), FormColor);
			FX->SetVariableFloat(TEXT("Size"), FormFXSize * FormScale());
			FX->SetVariableFloat(TEXT("WarpTime"), Warp);
			FX->SetVariableFloat(TEXT("Shimmer"), HitInvulnerability * 3.f);
			FX->SetTranslucentSortPriority(15);
		}
	}
	if (Warp > 0.f) { GetWorldTimerManager().SetTimer(RespawnTimer, this, &ASunderShipPawn::FinishRespawn, Warp, false); }
	else { FinishRespawn(); }
}

void ASunderShipPawn::FinishRespawn()
{
	State.Shield = FMath::Max(State.Shield, 1);              // its shield gathers as it appears (UpdateShield, event 2)
	Invulnerable = HitInvulnerability * 3.f;
	bDead = false;
	Mesh->SetVisibility(true);
	SetActorEnableCollision(true);
}

void ASunderShipPawn::ApplyLoadout(const FSunderShipLoadout& InLoadout)
{
	Loadout = InLoadout;
	bLoadoutApplied = true;
	MoveSpeed = InLoadout.MoveSpeed;
	MaxHealth = FMath::Max(InLoadout.MaxHealth, 1.f);
	Health = MaxHealth;
	State = FSunderShipState();
	State.Bombs = InLoadout.StartBombs;
	State.Health = Health;
	FireInterval = FMath::Max(InLoadout.FireInterval, 0.02f);
	ShotStyle = InLoadout.Style;
	ShotDamage = InLoadout.ShotDamage;
	ShotSpeed = InLoadout.ShotSpeed;
	ShotScale = InLoadout.ShotScale;
	SpreadAngle = InLoadout.SpreadAngle;
	ShotColor = InLoadout.Color;
	if (BeamWeapon) { BeamWeapon->BeamColor = InLoadout.Color; }   // picked up the next time the beam starts
	DeathColor = InLoadout.Color;
	FormColor = InLoadout.Accent;
	if (!bBaseScaleCaptured) { BaseMeshScale = Mesh->GetRelativeScale3D(); bBaseScaleCaptured = true; }
	if (InLoadout.Mesh)
	{
		// The ship's own model: turned nose-up, sized to MeshLength × BodyScale, the guns moved to its nose.
		Mesh->SetStaticMesh(InLoadout.Mesh);
		Mesh->SetRelativeRotation(InLoadout.MeshRotation);
		const FBox Turned = InLoadout.Mesh->GetBoundingBox().TransformBy(FTransform(InLoadout.MeshRotation));
		const float Length = FMath::Max(Turned.GetSize().X, 1.f);
		const float Scale = InLoadout.MeshLength * InLoadout.BodyScale / Length;
		FittedScale = FVector(Scale);
		Muzzle->SetRelativeLocation(FVector(Turned.Max.X * Scale, 0.f, 0.f));
	}
	else
	{
		FittedScale = BaseMeshScale * InLoadout.BodyScale;
	}
	UpdateBodyScale();
}

void ASunderShipPawn::UpdateShield(int32 Event)
{
	ShownShield = State.Shield;
	const bool bUp = State.Shield > 0 && !bDead;
	ShieldMesh->SetVisibility(bUp && !bShieldFXReady);
	if (bShieldFXReady)
	{
		ShieldComponent->SetVariableFloat(TEXT("Layers"), (float)State.Shield);
		ShieldComponent->SetVariableFloat(TEXT("Radius"), ShieldRadiusNow());
		ShieldComponent->SetVariableLinearColor(TEXT("ShieldColor"), ShieldColor);
		if (bUp && !ShieldComponent->IsActive()) { ShieldComponent->Activate(true); }
		else if (!bUp && ShieldComponent->IsActive()) { ShieldComponent->Deactivate(); }   // let it fade, don't cut it
	}
	if (Event < 0) { return; }
	if (ShieldEventFX && ShieldEventFX->GetEmitterHandles().Num() > 0)
	{
		if (UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ShieldEventFX, GetActorLocation(),
			FRotator::ZeroRotator, FVector(1.f), /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, false))
		{
			FX->SetVariableFloat(TEXT("Event"), (float)Event);
			FX->SetVariableFloat(TEXT("Layers"), (float)State.Shield);
			FX->SetVariableFloat(TEXT("Radius"), ShieldRadiusNow());
			FX->SetVariableLinearColor(TEXT("ShieldColor"), ShieldColor);
			FX->SetTranslucentSortPriority(14);
		}
	}
	else if (Event != 2)                                       // fallback for a hit or a break: a plasma burst
	{
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
		{
			Impacts->QueueImpact(GetActorLocation(), FVector::ForwardVector, ShieldColor);
		}
	}
}

void ASunderShipPawn::SpawnExplosion(int32 Event)
{
	if (ExplosionFX && ExplosionFX->GetEmitterHandles().Num() > 0)
	{
		// Pooled: it plays out in place while the ship is gone, and goes back to the pool when it finishes.
		if (UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), ExplosionFX, GetActorLocation(),
			FRotator::ZeroRotator, FVector(1.f), /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, false))
		{
			FX->SetVariableFloat(TEXT("Event"), (float)Event);
			FX->SetVariableLinearColor(TEXT("Color"), ExplosionColor);
			FX->SetVariableLinearColor(TEXT("AccentColor"), DeathColor);
			FX->SetVariableFloat(TEXT("Size"), ExplosionSize * FormScale());
			FX->SetTranslucentSortPriority(16);
			return;
		}
	}
	if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())   // not built yet
	{
		if (Event == 1) { for (int32 i = 0; i < 4; ++i) { Impacts->QueueImpact(GetActorLocation(), FVector::ForwardVector, DeathColor); } }
		else { Impacts->QueueImpact(GetActorLocation(), FVector::ForwardVector, ExplosionColor); }
	}
}

float ASunderShipPawn::FormScale() const
{
	const TArray<float>& Scales = Loadout.FormScales;
	return Scales.IsValidIndex(State.Power - 1) ? Scales[State.Power - 1] : 1.f;
}

void ASunderShipPawn::UpdateBodyScale()
{
	Mesh->SetRelativeScale3D(FittedScale * FormScale() * (1.f + FormFlash * 0.6f));   // the web game's form-change swell
	if (bShieldFXReady) { ShieldComponent->SetVariableFloat(TEXT("Radius"), ShieldRadiusNow()); }   // the shield grows with the form
}

FString ASunderShipPawn::GetFormName() const
{
	return Loadout.FormNames.IsValidIndex(State.Power - 1) ? Loadout.FormNames[State.Power - 1] : FString();
}

void ASunderShipPawn::SetPower(int32 NewPower)
{
	NewPower = FMath::Clamp(NewPower, 1, 3);
	if (NewPower == State.Power) { return; }
	const bool bUp = NewPower > State.Power;
	State.Power = NewPower;
	FormFlash = bUp ? 0.4f : 0.f;
	if (!GetFormName().IsEmpty())
	{
		Toast = TEXT("FORM: ") + GetFormName().ToUpper();
		ToastTime = bUp ? 2.2f : 1.6f;
	}
	PlayFormChange(bUp);
	UpdateBodyScale();
}

void ASunderShipPawn::PlayFormChange(bool bUp)
{
	if (bDead) { return; }                                     // a respawn resets the form quietly
	if (FormFX && FormFX->GetEmitterHandles().Num() > 0)
	{
		// Rides on the ship: the rings and the light stay around it as it flies.
		if (UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAttached(FormFX, GetRootComponent(), NAME_None,
			FVector::ZeroVector, FRotator::ZeroRotator, EAttachLocation::SnapToTarget, /*bAutoDestroy*/ false,
			/*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, /*bPreCullCheck*/ false))
		{
			FX->SetVariableFloat(TEXT("Up"), bUp ? 1.f : 0.f);
			FX->SetVariableFloat(TEXT("Form"), (float)State.Power);
			FX->SetVariableLinearColor(TEXT("Color"), FormColor);
			FX->SetVariableFloat(TEXT("Size"), FormFXSize * FormScale());
			FX->SetTranslucentSortPriority(15);
			return;
		}
	}
	if (bUp)
	{
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())   // not built yet
		{
			Impacts->QueueImpact(GetActorLocation(), FVector::ForwardVector, FormColor);
		}
	}
}

void ASunderShipPawn::PlaySound(USoundBase* Sound) const
{
	if (Sound) { UGameplayStatics::PlaySound2D(this, Sound, SoundVolume); }
}

void ASunderShipPawn::CollectPickup(ESunderPickupKind Kind)
{
	if (bDead) { return; }
	// The web game's sounds: a rising chime for guns, power and bombs; a softer, higher one for life and shields.
	PlaySound(Kind == ESunderPickupKind::Life || Kind == ESunderPickupKind::Shield ? LifeSound : PickupSound);
	switch (Kind)
	{
	case ESunderPickupKind::Spread:
	case ESunderPickupKind::Laser:
	{
		const ESunderWeapon Weapon = Kind == ESunderPickupKind::Laser ? ESunderWeapon::Laser : ESunderWeapon::Spread;
		if (State.Weapon == Weapon) { SetPower(State.Power + 1); }
		else { State.Weapon = Weapon; }                      // switching keeps the power level (Sunder rules)
		break;
	}
	case ESunderPickupKind::Power:  SetPower(State.Power + 1); break;
	case ESunderPickupKind::Bomb:   State.Bombs = FMath::Min(State.Bombs + 1, 9); break;
	case ESunderPickupKind::Shield: State.Shield = FMath::Min(State.Shield + 1, 3); break;
	case ESunderPickupKind::Life:   Health = FMath::Min(Health + 1.f, MaxHealth + 2.f); break;   // up to 2 over full
	}
}

void ASunderShipPawn::UseBomb()
{
	if (bDead || State.Bombs <= 0) { return; }
	--State.Bombs;
	PlaySound(BombSound);
	UWorld* World = GetWorld();
	// Every enemy shot is wiped away (where they were, for the blast's fizzles)…
	TArray<FVector> Wiped;
	for (TActorIterator<ASunderProjectile> It(World); It; ++It)
	{
		if (It->IsFromEnemy() && !It->IsParked())
		{
			if (Wiped.Num() < MaxBombFizzles) { Wiped.Add(It->GetActorLocation()); }
			It->Recall();
		}
	}
	// …and everything on screen takes the blast (a Keeper only once it has taken its place).
	TArray<ASunderEnemy*> Targets;
	for (TActorIterator<ASunderEnemy> It(World); It; ++It) { Targets.Add(*It); }
	for (ASunderEnemy* Enemy : Targets)
	{
		const bool bKeeper = Enemy->IsA<ASunderKeeper>();
		UGameplayStatics::ApplyDamage(Enemy, bKeeper ? BombKeeperDamage : BombDamage, GetController(), this, UDamageType::StaticClass());
	}
	// The blast is 100 px up the screen from the ship in the web game: 500 units here.
	const FVector Centre = GetActorLocation() + FVector(500.f, 0.f, 0.f);
	if (SpawnBombBlast(Centre, Wiped)) { return; }
	if (UImpactFXSubsystem* Impacts = World->GetSubsystem<UImpactFXSubsystem>())   // not built yet: a ring of bursts
	{
		Impacts->QueueImpact(Centre, FVector::ForwardVector, BombColor);
		for (int32 i = 0; i < 10; ++i)
		{
			const float A = UE_TWO_PI * i / 10;
			Impacts->QueueImpact(Centre + FVector(FMath::Cos(A), FMath::Sin(A), 0.f) * 380.f, FVector::ForwardVector, BombColor);
		}
	}
}

bool ASunderShipPawn::SpawnBombBlast(const FVector& Centre, const TArray<FVector>& Wiped)
{
	if (!BombFX || BombFX->GetEmitterHandles().Num() == 0) { return false; }
	UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), BombFX, Centre, FRotator::ZeroRotator,
		FVector(1.f), /*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, false);
	if (!FX) { return false; }
	// The wave travels until it has covered the arena's farthest corner from the blast.
	float Reach = 0.f;
	for (const float SX : { -1.f, 1.f })
	{
		for (const float SY : { -1.f, 1.f })
		{
			const FVector Corner = ArenaCenter + FVector(SX * ArenaHalfExtents.X, SY * ArenaHalfExtents.Y, 0.f);
			Reach = FMath::Max(Reach, FVector::Dist2D(Centre, Corner));
		}
	}
	TArray<FVector> Offsets;
	Offsets.Reserve(Wiped.Num());
	for (const FVector& Spot : Wiped) { Offsets.Add(FVector(Spot.X - Centre.X, Spot.Y - Centre.Y, 0.f)); }
	FX->SetVariableLinearColor(TEXT("Color"), BombColor);
	FX->SetVariableFloat(TEXT("Reach"), Reach);
	FX->SetVariableInt(TEXT("WipedCount"), Offsets.Num());
	UNiagaraDataInterfaceArrayFunctionLibrary::SetNiagaraArrayVector(FX, TEXT("WipedShots"), Offsets);
	FX->SetTranslucentSortPriority(17);
	return true;
}

FSunderShipState ASunderShipPawn::GetState() const
{
	FSunderShipState Out = State;
	Out.Health = Health;
	return Out;
}

void ASunderShipPawn::ApplyState(const FSunderShipState& InState)
{
	State.Weapon = InState.Weapon;
	State.Bombs = FMath::Clamp(InState.Bombs, 0, 9);
	State.Shield = FMath::Clamp(InState.Shield, 0, 3);
	Health = FMath::Clamp(InState.Health, 1.f, MaxHealth + 2.f);
	State.Power = FMath::Clamp(InState.Power, 1, 3);
	FormFlash = 0.f;
	UpdateBodyScale();
}

void ASunderShipPawn::FireShots()
{
	if (!ProjectileClass || bDead) { return; }
	UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>();
	if (!Pool) { return; }
	const FVector Origin = Muzzle->GetComponentLocation();
	const bool bLaser = State.Weapon == ESunderWeapon::Laser;
	// Battle math #1: (base + Laser bonus) × power level.
	const float Damage = ShotDamage > 0.f ? (ShotDamage + (bLaser ? LaserBonusDamage : 0.f)) * State.Power : 0.f;
	const FLinearColor Color = bLaser ? LaserColor : ShotColor;
	auto Fire = [&](float OffsetY, float AngleDeg)
	{
		const FVector Dir = FVector::ForwardVector.RotateAngleAxis(AngleDeg, FVector::UpVector);
		ASunderProjectile* Shot = Pool->Acquire(ProjectileClass, Origin + FVector(0.f, OffsetY, 0.f), Dir, this, this, ShotSpeed);
		if (!Shot) { return; }
		// Only the ship fires this class, so setting these on each shot keeps every pooled one right.
		if (Damage > 0.f) { Shot->Damage = Damage; }
		Shot->SetActorScale3D(FVector(ShotScale));
		if (Color.A > 0.f) { Shot->SetShotColor(Color); }
	};
	// The web game's guns per form (power 1 / 2 / 3); its pixels × 5 for the offsets.
	const int32 P = FMath::Clamp(State.Power, 1, 3);
	const float Fan = SpreadAngle / 6.f;                       // the loadout's spread, relative to the web game's ±6°
	switch (ShotStyle)
	{
	case ESunderShotStyle::TwinSpread:
	{
		static const TArray<float> Angles[3] = { { -6.f, 6.f }, { -10.f, 0.f, 10.f }, { -16.f, -5.f, 5.f, 16.f } };
		for (const float A : Angles[P - 1]) { Fire(0.f, A * Fan); }
		break;
	}
	case ESunderShotStyle::HeavyCannon:
	{
		static const TArray<float> Offsets[3] = { { 0.f }, { -70.f, 70.f }, { -90.f, 0.f, 90.f } };
		for (const float O : Offsets[P - 1]) { Fire(O, 0.f); }
		break;
	}
	case ESunderShotStyle::RapidStream:
	{
		static const TArray<float> Offsets[3] = { { 0.f }, { -40.f, 40.f }, { -60.f, 0.f, 60.f } };
		for (const float O : Offsets[P - 1]) { Fire(O, 0.f); }
		break;
	}
	}
}
