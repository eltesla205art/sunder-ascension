// SUNDER: Ascension II — the player's ship: eight-way movement inside the arena, a held beam and held plasma shots.
// Input is built at runtime with Enhanced Input (no input assets to create):
//   move  W A S D / left stick      beam  Space / right trigger      shots  J / left mouse / gamepad A
// The camera is the level's ortho CameraActor (Auto Activate for Player 0), looking straight down: +X is up the
// screen, +Y is right.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SunderShipPawn.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UBeamWeaponComponent;
class UNiagaraSystem;
class ASunderProjectile;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

UCLASS()
class SUNDER2_API ASunderShipPawn : public APawn
{
	GENERATED_BODY()

public:
	ASunderShipPawn();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<USphereComponent> Collision;

	/** Placeholder cone until the ship mesh is imported; swap it in the Blueprint. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<UStaticMeshComponent> Mesh;

	/** Where the beam and shots leave the ship. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<USceneComponent> Muzzle;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<UBeamWeaponComponent> BeamWeapon;

	/** NS_Laser_Beam; handed to the beam component before it starts. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Weapons")
	TObjectPtr<UNiagaraSystem> BeamSystem;

	/** BP_PlasmaShot (a SunderProjectile subclass), fired from the projectile pool. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Weapons")
	TSubclassOf<ASunderProjectile> ProjectileClass;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons", meta = (ClampMin = "0.02"))
	float FireInterval = 0.09f;

	/** Twin shots this far either side of the muzzle. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	float ShotSpread = 22.f;

	/** Shots parked in the pool at BeginPlay, so firing never spawns actors. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	int32 PrewarmShots = 120;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Movement")
	float MoveSpeed = 950.f;

	/** The arena the ship can fly in, centred on ArenaCenter (X up the screen, Y across it). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Movement")
	FVector ArenaCenter = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Movement")
	FVector2D ArenaHalfExtents = FVector2D(600.f, 1100.f);

	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

protected:
	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;

private:
	void FireShots();

	void OnMoveUp(const FInputActionValue& Value);
	void OnMoveUpReleased(const FInputActionValue& Value);
	void OnMoveRight(const FInputActionValue& Value);
	void OnMoveRightReleased(const FInputActionValue& Value);
	void OnBeamPressed(const FInputActionValue& Value);
	void OnBeamReleased(const FInputActionValue& Value);
	void OnShootPressed(const FInputActionValue& Value);
	void OnShootReleased(const FInputActionValue& Value);

	UPROPERTY(Transient) TObjectPtr<UInputAction> MoveUpAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> MoveRightAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> BeamAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> ShootAction;
	UPROPERTY(Transient) TObjectPtr<UInputMappingContext> Mapping;

	FVector2D MoveInput = FVector2D::ZeroVector;   // X = up the screen, Y = right
	bool bShooting = false;
	float ShotCooldown = 0.f;
};
