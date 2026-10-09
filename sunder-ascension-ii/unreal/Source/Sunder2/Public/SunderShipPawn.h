// SUNDER: Ascension II — the player's ship: eight-way movement inside the arena, a held beam and held plasma shots.
// Input is built at runtime with Enhanced Input (no input assets to create):
//   move  W A S D / left stick      beam  Space / right trigger      shots  J / left mouse / gamepad A
//   bomb  X / K / gamepad Y or right bumper
// Power-ups (SunderPickup) follow the web game's rules: Spread / Laser weapons (the same one again powers up, the
// other switches and keeps the level), Power (+1 level, max 3: each level is a new form of the ship with more guns),
// Bomb (+1, max 9), Shield (+1, max 3: each soaks a whole hit), Life (+1 hull, up to 2 over full). A hull hit costs a
// power level. Damage per shot = (base + Laser bonus) × power level (the web game's battle math #1).
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
class UNiagaraComponent;
class UStaticMesh;
class USoundBase;
class ASunderProjectile;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;

/** The two weapons the pickups give (the web game's red "S" and blue "L"). */
UENUM(BlueprintType)
enum class ESunderWeapon : uint8
{
	Spread,   // the ship's own shots, in its colour
	Laser     // +LaserBonusDamage per shot and 15 % faster fire, in blue
};

/** What a falling pickup gives (SunderPickup). */
UENUM(BlueprintType)
enum class ESunderPickupKind : uint8
{
	Spread,
	Laser,
	Power,
	Bomb,
	Shield,
	Life
};

/** The ship's power-up state, carried from one story Hour to the next. */
USTRUCT(BlueprintType)
struct FSunderShipState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship") ESunderWeapon Weapon = ESunderWeapon::Spread;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship") int32 Power = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship") int32 Bombs = 3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship") int32 Shield = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship") float Health = 5.f;
};

/** How a ship fires its plasma shots (the web game's ship styles; more guns at each power level). */
UENUM(BlueprintType)
enum class ESunderShotStyle : uint8
{
	TwinSpread,    // two shots fanned SpreadAngle either side (Sunborn Thunder)
	HeavyCannon,   // one big, slow, hard-hitting shot (Scarab Warbringer)
	RapidStream    // one small, fast shot, very often (Ibis Phantom)
};

/** One of the hangar's ships, as the arena flies it: the web game's ship stats in Unreal units. */
USTRUCT(BlueprintType)
struct FSunderShipLoadout
{
	GENERATED_BODY()

	/** Matches the hangar's ship id (?Ship=). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") FString Id;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") FString Name;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") ESunderShotStyle Style = ESunderShotStyle::TwinSpread;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float MoveSpeed = 950.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float MaxHealth = 5.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float FireInterval = 0.09f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float ShotDamage = 10.f;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float ShotSpeed = 2200.f;
	/** Size of each shot (and its hit sphere). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float ShotScale = 1.f;
	/** TwinSpread: degrees either side of straight ahead. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float SpreadAngle = 6.f;
	/** The ship's colour (HDR): its shots and its beam. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") FLinearColor Color = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);
	/** Its HUD colour (not HDR). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") FLinearColor Tint = FLinearColor(0.79f, 0.54f, 0.08f, 1.f);
	/** The web game's form scale: the Scarab is bigger, the Ibis smaller. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") float BodyScale = 1.f;

	/** Bombs at the start (the web game's: Sunborn 3, Scarab 4, Ibis 3). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") int32 StartBombs = 3;

	/** The ship's three forms, one per power level (the web game's form names). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") TArray<FString> FormNames;

	/** Each form's size relative to the first (the web game's form scales). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship") TArray<float> FormScales;

	/** The ship's model (SM_Ship_<Id>, from blender/ships.py --fbx); empty = keep the Blueprint's mesh. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Model") TObjectPtr<UStaticMesh> Mesh;

	/** Turns the model so its nose points up the screen (+X). Yaw 90 = Blender's +Y nose through Unreal's usual FBX
	 *  axes; if a ship flies sideways or backwards, change this. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Model") FRotator MeshRotation = FRotator(0.f, 90.f, 0.f);

	/** Nose-to-tail length on screen in units, before BodyScale (the web game's ship is about 300 at its scale). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Model") float MeshLength = 300.f;
};

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

	/** Hits the hull can take before the ship is lost (enemy shots and rams do 1 each by default). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Hull", meta = (ClampMin = "1"))
	float MaxHealth = 5.f;

	/** Seconds of invulnerability after a hit, and (×3) after a respawn; the ship blinks meanwhile. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Hull")
	float HitInvulnerability = 0.6f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Hull")
	FLinearColor DeathColor = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);

	/** NS_Ship_Explosion (SHIP_VFX.md §5), one-shot and pooled. User.Event 0 = the hull takes a hit (the web game's
	 *  small gold burst), 1 = the ship is destroyed (its big one); User.Color = ExplosionColor (the sparks),
	 *  User.AccentColor = DeathColor (the ship's own colour: its debris), User.Size. Until it has emitters, plasma
	 *  impacts stand in. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Hull")
	TObjectPtr<UNiagaraSystem> ExplosionFX;

	/** The sparks' colour: the web game's gold (#FFD54A), whatever the ship. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Hull")
	FLinearColor ExplosionColor = FLinearColor(3.5f, 2.33f, 0.24f, 1.f);

	/** User.Size for a form-1 ship; it grows with the form, like the ship. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Hull", meta = (ClampMin = "1"))
	float ExplosionSize = 80.f;

	/** How the shots fire; set by ApplyLoadout from the hangar's ship. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	ESunderShotStyle ShotStyle = ESunderShotStyle::TwinSpread;

	/** Damage per shot (0 = the projectile's own). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	float ShotDamage = 0.f;

	/** Shot speed (0 = the projectile's own). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	float ShotSpeed = 0.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	float ShotScale = 1.f;

	/** TwinSpread: degrees either side of straight ahead. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	float SpreadAngle = 6.f;

	/** Shot colour (HDR); alpha 0 = the projectile's own. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Weapons")
	FLinearColor ShotColor = FLinearColor(0.f, 0.f, 0.f, 0.f);

	// ---- power-ups and bombs (the web game's rules; see the top of this file)
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	float LaserBonusDamage = 10.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	FLinearColor LaserColor = FLinearColor(0.6f, 1.6f, 4.0f, 1.f);

	/** A bomb: this much damage to every enemy on screen (the web game's 8)… */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	float BombDamage = 80.f;

	/** …and this much to a Keeper that has taken its place (the web game's 10); every enemy shot is wiped away. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	float BombKeeperDamage = 100.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	FLinearColor BombColor = FLinearColor(0.6f, 2.4f, 4.0f, 1.f);

	/** NS_Ship_Bomb (SHIP_VFX.md §7), one-shot and pooled: the blast, a shockwave that sweeps the whole arena, and a
	 *  fizzle where each wiped enemy shot was. User.Color = BombColor, User.Reach = how far the wave must travel to
	 *  cover the arena, User.WipedShots (Vector Array: offsets from the blast) and User.WipedCount. Until it has
	 *  emitters, a ring of plasma impacts stands in. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Power-ups")
	TObjectPtr<UNiagaraSystem> BombFX;

	/** Most wiped shots handed to BombFX for fizzles (the rest just vanish). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups", meta = (ClampMin = "0"))
	int32 MaxBombFizzles = 256;

	/** Seconds of invulnerability after a shield takes a hit. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	float ShieldInvulnerability = 0.8f;

	/** Fallback shield: a flat cyan disc under the ship while any shield is up, until ShieldFX has emitters. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship|Power-ups")
	TObjectPtr<UStaticMeshComponent> ShieldMesh;

	/** NS_Ship_Shield (SHIP_VFX.md §2): the looping shield around the ship. User.Layers = shields up (0–3),
	 *  User.Radius, User.ShieldColor. Runs while any shield is up; fades out (not cut off) when the last one goes. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Power-ups")
	TObjectPtr<UNiagaraSystem> ShieldFX;

	/** NS_Ship_ShieldEvent (SHIP_VFX.md §3), one-shot and pooled: User.Event 0 = a hit soaked (ripple), 1 = the last
	 *  layer breaks (shatter), 2 = a layer forms (light gathers in); plus User.Radius, User.ShieldColor, User.Layers. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship|Power-ups")
	TObjectPtr<UNiagaraSystem> ShieldEventFX;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ship|Power-ups")
	TObjectPtr<UNiagaraComponent> ShieldComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	FLinearColor ShieldColor = FLinearColor(0.6f, 2.4f, 4.0f, 1.f);

	/** The shield's radius around a form-1 ship (it grows with the ship's forms). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Power-ups")
	float ShieldRadius = 190.f;

	// ---- the game's own sounds (web/game.html sfx(), rendered by unreal/Tools/render_web_audio.cjs effects)
	/** Weapon, Power and Bomb pickups (the web game's "power"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	TObjectPtr<USoundBase> PickupSound;

	/** Life and Shield pickups (the web game's "life"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	TObjectPtr<USoundBase> LifeSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	TObjectPtr<USoundBase> BombSound;

	/** Each volley, at most every 0.09 s (the web game's "shoot"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	TObjectPtr<USoundBase> ShootSound;

	/** A shield soaking a hit, or the hull taking one (the web game's "hit"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	TObjectPtr<USoundBase> HitSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ship|Sounds")
	float SoundVolume = 1.f;

	UFUNCTION(BlueprintCallable, Category = "Ship|Power-ups")
	void CollectPickup(ESunderPickupKind Kind);

	UFUNCTION(BlueprintCallable, Category = "Ship|Power-ups")
	void UseBomb();

	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") ESunderWeapon GetWeapon() const { return State.Weapon; }
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") int32 GetPower() const { return State.Power; }
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") int32 GetBombs() const { return State.Bombs; }
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") int32 GetShield() const { return State.Shield; }
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") FString GetFormName() const;
	/** "FORM: SOLAR HORUS" for a moment after the form changes (empty otherwise). */
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") FString GetToast() const { return ToastTime > 0.f ? Toast : FString(); }

	/** The ship's state to carry to the next story Hour, and to restore it there. */
	UFUNCTION(BlueprintPure, Category = "Ship|Power-ups") FSunderShipState GetState() const;
	UFUNCTION(BlueprintCallable, Category = "Ship|Power-ups") void ApplyState(const FSunderShipState& InState);

	/** Fly as one of the hangar's ships: speed, hull, guns, colour and size. Refills the hull. */
	UFUNCTION(BlueprintCallable, Category = "Ship")
	void ApplyLoadout(const FSunderShipLoadout& Loadout);

	UFUNCTION(BlueprintPure, Category = "Ship")
	const FSunderShipLoadout& GetLoadout() const { return Loadout; }

	UFUNCTION(BlueprintPure, Category = "Ship|Hull")
	float GetHealth() const { return Health; }

	UFUNCTION(BlueprintPure, Category = "Ship|Hull")
	bool IsAlive() const { return !bDead; }

	/** Back at the start position with a full hull (called by the game mode while lives remain). */
	UFUNCTION(BlueprintCallable, Category = "Ship|Hull")
	void Respawn();

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override;

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
	void OnBombPressed(const FInputActionValue& Value);
	void SetPower(int32 NewPower);
	void PlaySound(USoundBase* Sound) const;
	/** Keep the shield's look in step with its layers (and spawn an event: 0 hit, 1 break, 2 raise; -1 none). */
	void UpdateShield(int32 Event);
	/** 0 = a hull hit, 1 = destroyed: ExplosionFX, or plasma impacts until it's built. */
	void SpawnExplosion(int32 Event);
	/** BombFX at Centre; false if it isn't set or built yet (UseBomb falls back to plasma impacts). */
	bool SpawnBombBlast(const FVector& Centre, const TArray<FVector>& Wiped);
	float ShieldRadiusNow() const { return ShieldRadius * FormScale(); }
	void UpdateBodyScale();
	float FormScale() const;

	UPROPERTY(Transient) TObjectPtr<UInputAction> MoveUpAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> MoveRightAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> BeamAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> ShootAction;
	UPROPERTY(Transient) TObjectPtr<UInputAction> BombAction;
	UPROPERTY(Transient) TObjectPtr<class UMaterialInstanceDynamic> ShieldMaterial;
	UPROPERTY(Transient) TObjectPtr<UInputMappingContext> Mapping;

	FSunderShipLoadout Loadout;
	FSunderShipState State;
	FVector FittedScale = FVector(0.6f);           // the body's size at form 1
	FString Toast;
	float ToastTime = 0.f;
	float FormFlash = 0.f;
	FVector BaseMeshScale = FVector(0.6f);
	bool bBaseScaleCaptured = false;               // the loadout can arrive before or after BeginPlay
	bool bLoadoutApplied = false;
	bool bShieldFXReady = false;
	float LastShootSound = -100.f;
	int32 ShownShield = -1;
	FVector2D MoveInput = FVector2D::ZeroVector;   // X = up the screen, Y = right
	FVector StartLocation = FVector::ZeroVector;
	float Health = 5.f;
	float Invulnerable = 0.f;
	bool bDead = false;
	bool bShooting = false;
	float ShotCooldown = 0.f;
};
