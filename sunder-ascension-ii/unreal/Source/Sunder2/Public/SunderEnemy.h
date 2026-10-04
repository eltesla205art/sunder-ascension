// SUNDER: Ascension II — an enemy craft: enters from the top of the screen, moves in one of the shmup patterns from the
// web game (straight, weave, dive, strafe, zigzag), fires aimed / spread / radial shots from the projectile pool, and
// bursts into a plasma impact when destroyed. Each enemy type is a Blueprint child with different defaults.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SunderEnemy.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UStaticMesh;
class UMaterialInstanceDynamic;
class ASunderProjectile;

UENUM(BlueprintType)
enum class ESunderMovePattern : uint8
{
	Straight,   // straight down the screen
	Weave,      // down, swaying side to side
	Dive,       // drifts in, then dives at where the player was
	Strafe,     // drops to the top band, strafes side to side while firing, then leaves
	Zigzag      // down, cutting hard left and right
};

UENUM(BlueprintType)
enum class ESunderFirePattern : uint8
{
	None,
	Aimed,      // ShotCount shots fanned 12° apart, centred on the player
	Spread,     // ShotCount shots fanned across SpreadAngle, straight down
	Radial      // ShotCount shots in a full ring, turning a little each volley
};

UCLASS()
class SUNDER2_API ASunderEnemy : public APawn
{
	GENERATED_BODY()

public:
	ASunderEnemy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	TObjectPtr<USphereComponent> Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Enemy")
	TObjectPtr<UStaticMeshComponent> Mesh;

	// ---- look
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Look")
	TObjectPtr<UStaticMesh> BodyMesh;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Look")
	FVector BodyScale = FVector(0.6f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Look")
	FRotator BodyRotation = FRotator(90.f, 0.f, 0.f);         // engine cone tip pointing down the screen

	/** Sets the "Color" parameter of the engine's basic shape material; swap the mesh and material for real art. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Look")
	FLinearColor BodyColor = FLinearColor(0.35f, 0.08f, 0.55f, 1.f);

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Look")
	FLinearColor DeathColor = FLinearColor(4.0f, 0.6f, 2.6f, 1.f);

	// ---- toughness and reward
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy")
	float MaxHealth = 20.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy")
	int32 ScoreValue = 100;

	/** Damage dealt to the ship by ramming it. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy")
	float ContactDamage = 1.f;

	/** Small craft break up when they ram the ship; Keepers don't. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy")
	bool bDiesOnContact = true;

	/** Radius of the hit sphere (shots, the beam and ramming all use it). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy", meta = (ClampMin = "1"))
	float HitRadius = 45.f;

	// ---- movement
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	ESunderMovePattern MovePattern = ESunderMovePattern::Straight;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float Speed = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float WeaveAmplitude = 180.f;

	/** Sways (Weave) or strafes (Strafe) per second. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float WeaveFrequency = 0.6f;

	/** Dive: seconds of slow drift before it commits to the dive. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float DiveDelay = 0.8f;

	/** Strafe: how far down the screen it holds (0 = top edge, 1 = bottom). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement", meta = (ClampMin = "0", ClampMax = "1"))
	float StrafeHoldDepth = 0.25f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float StrafeTime = 6.f;

	/** Zigzag: seconds between direction changes. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Movement")
	float ZigzagInterval = 0.6f;

	// ---- weapons
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons")
	ESunderFirePattern FirePattern = ESunderFirePattern::None;

	/** BP_EnemyShot (a SunderProjectile subclass); fired from the shared projectile pool. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons")
	TSubclassOf<ASunderProjectile> ShotClass;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons", meta = (ClampMin = "0.1"))
	float FireInterval = 1.6f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons")
	float FirstShotDelay = 1.0f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons", meta = (ClampMin = "1"))
	int32 ShotCount = 1;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Enemy|Weapons")
	float SpreadAngle = 50.f;

	/** Called by the wave director right after spawning: the arena to fly in, and this loop's difficulty. */
	void Setup(const FVector& InArenaCenter, const FVector2D& InArenaHalfExtents, float HealthScale, float SpeedScale, float FireRateScale);

	UFUNCTION(BlueprintPure, Category = "Enemy")
	float GetHealth() const { return Health; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION()
	void OnBodyOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	virtual void Move(float DeltaTime);
	virtual void TryFire(float DeltaTime);
	void FireVolley();
	virtual void Die(bool bAwardScore);
	FVector PlayerLocation() const;

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> BodyMaterial;

	FVector ArenaCenter = FVector::ZeroVector;
	FVector2D ArenaHalfExtents = FVector2D(600.f, 1100.f);
	FVector SpawnLocation = FVector::ZeroVector;
	FVector DiveDirection = FVector::ZeroVector;
	float Health = 0.f;
	float Age = 0.f;
	float FireCooldown = 0.f;
	float FireRateScale = 1.f;
	float HitFlash = 0.f;
	float ZigzagTimer = 0.f;
	float ZigzagSign = 1.f;
	float StrafeClock = 0.f;
	float RadialTurn = 0.f;
	bool bDiving = false;
	bool bDead = false;
};
