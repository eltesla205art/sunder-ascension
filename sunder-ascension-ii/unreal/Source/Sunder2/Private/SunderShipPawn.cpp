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
#include "ImpactFXSubsystem.h"
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
	Health = MaxHealth;
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
}

void ASunderShipPawn::OnMoveUp(const FInputActionValue& Value) { MoveInput.X = Value.Get<float>(); }
void ASunderShipPawn::OnMoveUpReleased(const FInputActionValue& Value) { MoveInput.X = 0.f; }
void ASunderShipPawn::OnMoveRight(const FInputActionValue& Value) { MoveInput.Y = Value.Get<float>(); }
void ASunderShipPawn::OnMoveRightReleased(const FInputActionValue& Value) { MoveInput.Y = 0.f; }
void ASunderShipPawn::OnBeamPressed(const FInputActionValue& Value) { if (!bDead) { BeamWeapon->StartFire(); } }
void ASunderShipPawn::OnBeamReleased(const FInputActionValue& Value) { BeamWeapon->StopFire(); }
void ASunderShipPawn::OnShootPressed(const FInputActionValue& Value) { bShooting = true; }
void ASunderShipPawn::OnShootReleased(const FInputActionValue& Value) { bShooting = false; }

void ASunderShipPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bDead) { return; }

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
			ShotCooldown += FireInterval;
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
	Health -= DamageAmount;
	Invulnerable = HitInvulnerability;
	if (Health > 0.f) { return DamageAmount; }

	bDead = true;                                             // hull gone: burst, vanish, tell the game mode
	bShooting = false;
	BeamWeapon->StopFire();
	if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
	{
		for (int32 i = 0; i < 4; ++i) { Impacts->QueueImpact(GetActorLocation(), FVector::ForwardVector, DeathColor); }
	}
	Mesh->SetVisibility(false);
	SetActorEnableCollision(false);
	if (ASunderGameMode* Mode = GetWorld()->GetAuthGameMode<ASunderGameMode>()) { Mode->OnShipDestroyed(this); }
	return DamageAmount;
}

void ASunderShipPawn::Respawn()
{
	SetActorLocation(StartLocation);
	Health = MaxHealth;
	Invulnerable = HitInvulnerability * 3.f;
	bDead = false;
	Mesh->SetVisibility(true);
	SetActorEnableCollision(true);
}

void ASunderShipPawn::FireShots()
{
	if (!ProjectileClass || bDead) { return; }
	UProjectilePoolSubsystem* Pool = GetWorld()->GetSubsystem<UProjectilePoolSubsystem>();
	if (!Pool) { return; }
	const FVector Origin = Muzzle->GetComponentLocation();
	for (const float Side : { -1.f, 1.f })
	{
		Pool->Acquire(ProjectileClass, Origin + FVector(0.f, Side * ShotSpread, 0.f), FVector::ForwardVector, this, this);
	}
}
