// SUNDER: Ascension II — a Keeper: the boss of an Hour. Ported from the web game's boss logic: it descends into the top
// band (untouchable while it enters), strafes side to side, cycles its Hour's attack patterns every few seconds, and
// grows faster and angrier at 66 % and 33 % hull. In phase 3 it dashes, and a Keeper with a PhaseThreeMesh changes form
// (Apep opens its jaws). Announces itself with its taunt, shows a boss bar, and when beaten it shudders and cracks apart
// for a couple of seconds before it bursts. Its Niagara effects (aura, arrival gate, muzzle flares, phase shockwave,
// death) are all optional: see unreal/KEEPER_VFX.md. Without them it falls back to the shared plasma impacts.
// Its battle theme (three layers that build with the phases) and its voice (intro, attack, phase, hurt, death) are the
// web game's, rendered to WAV by unreal/Tools/render_keeper_audio.cjs and set by create_keeper_audio.py.
// Each Keeper is a Blueprint child made by create_keepers.py with its Hour's numbers from the web game.
#pragma once

#include "CoreMinimal.h"
#include "SunderEnemy.h"
#include "SunderKeeper.generated.h"

class UNiagaraComponent;
class UNiagaraSystem;
class USoundBase;

/** The web game's boss attack patterns. */
UENUM(BlueprintType)
enum class ESunderBossPattern : uint8
{
	AimedVolley,      // three shots 14° apart at the ship
	SpreadFan,        // 5 + 2×phase shots fanned 70° straight down
	HorizontalSweep,  // six shots raking sideways, alternating sides each second
	RadialBurst,      // a ring of 14 + 3×phase
	CrossRing,        // a ring of 12 plus a turning cross of 4
	Spiral,           // three arms, turning
	DualSpiral,       // two arms turning opposite ways
	WallBarrage       // a wall across the screen with a two-shot gap
};

UCLASS()
class SUNDER2_API ASunderKeeper : public ASunderEnemy
{
	GENERATED_BODY()

public:
	ASunderKeeper();

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper")
	FString KeeperName;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper")
	FString Taunt;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper")
	int32 Hour = 1;

	/** Attack patterns, cycled in order every PatternSwitchTime seconds. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Attack")
	TArray<ESunderBossPattern> Patterns;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Attack")
	float PatternSwitchTime = 3.5f;

	/** Bullet speed in Unreal units/s (the web game's px/s × 5). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Attack")
	float BulletSpeed = 950.f;

	/** Strafe speed in units/s; each phase adds 125. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Movement")
	float StrafeSpeed = 300.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Movement")
	float EnterSpeed = 260.f;

	/** How far down the screen it holds (0 = top edge, 1 = bottom). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Movement", meta = (ClampMin = "0", ClampMax = "1"))
	float HoldDepth = 0.2f;

	/** The model is scaled to fit this box on screen: X = across the screen, Y = up it (units). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Look")
	FVector2D FitSize = FVector2D(720.f, 520.f);

	/** Final-phase form (Apep's open jaws); leave empty to keep one form. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Look")
	TObjectPtr<UStaticMesh> PhaseThreeMesh;

	// ---- effects (KEEPER_VFX.md). Each gets User.KeeperColor, User.AccentColor, User.Size (body radius in units),
	// User.Phase and User.Duration; all are pooled except the aura, which lives on the Keeper.

	/** Looping glow that rides on the Keeper; User.Phase rises with each phase and is 4 while it dies. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraComponent> Aura;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraSystem> AuraFX;

	/** The Gate opening where the Keeper will hold; User.Duration = seconds until it arrives there. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraSystem> ArrivalFX;

	/** A flare at the muzzle on every volley (User.Size × 1), and a bigger one when the attack pattern changes (× 2). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraSystem> MuzzleFX;

	/** The hull cracking at 66 % and 33 %; User.Phase is the phase it has just entered. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraSystem> PhaseShiftFX;

	/** The whole death: rumble and cracks for User.Duration seconds, then the final burst. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	TObjectPtr<UNiagaraSystem> DeathFX;

	/** This Keeper's glow (HDR): its Hour's colour. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	FLinearColor KeeperColor = FLinearColor(3.4f, 1.3f, 0.45f, 1.f);

	/** Second colour: crystal, fire, heart, void (HDR). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	FLinearColor AccentColor = FLinearColor(4.0f, 0.6f, 2.6f, 1.f);

	/** Colour each shot (its trail's User.ShotColor and its impact) with KeeperColor. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX")
	bool bTintShots = true;

	/** Seconds it shudders and cracks apart before the final burst (0 = burst at once). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|FX", meta = (ClampMin = "0"))
	float DeathDuration = 2.2f;

	// ---- audio (the web game's keeper_audio.js, rendered)

	/** Battle theme: layers 1–3, same-length loops; the layer heard follows the phase. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TArray<TObjectPtr<USoundBase>> MusicLayers;

	/** A new theme for phase 3 (Apep's final form), started at its layer 3; leave empty to keep building MusicLayers. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TArray<TObjectPtr<USoundBase>> FinalFormMusicLayers;

	/** As it arrives (the music ducks under it). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TObjectPtr<USoundBase> IntroSound;

	/** Each volley, at most every 0.45 s. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TObjectPtr<USoundBase> AttackSound;

	/** Each phase change (ducks the music); also its gloat when the last life is lost. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TObjectPtr<USoundBase> PhaseSound;

	/** Each hit, at most every 0.1 s. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TObjectPtr<USoundBase> HurtSound;

	/** Beaten (ducks the music, which then fades out). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	TObjectPtr<USoundBase> DeathSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Keeper|Audio")
	float VoiceVolume = 1.f;

	/** The Keeper gloats (its phase cry): called by the game mode when the player's last life goes. */
	UFUNCTION(BlueprintCallable, Category = "Keeper")
	void Gloat();

	UFUNCTION(BlueprintPure, Category = "Keeper")
	int32 GetPhase() const { return Phase; }

	UFUNCTION(BlueprintPure, Category = "Keeper")
	float GetHealthFraction() const { return MaxHealth > 0.f ? FMath::Clamp(Health / MaxHealth, 0.f, 1.f) : 0.f; }

	UFUNCTION(BlueprintPure, Category = "Keeper")
	bool IsEntering() const { return bEntering; }

	UFUNCTION(BlueprintPure, Category = "Keeper")
	bool IsDying() const { return bDying; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override;
	virtual void Tick(float DeltaTime) override;
	virtual void OnConstruction(const FTransform& Transform) override;

protected:
	virtual void BeginPlay() override;
	virtual void Move(float DeltaTime) override;
	virtual void TryFire(float DeltaTime) override;
	virtual void Die(bool bAwardScore) override;

private:
	void FitToScreen(UStaticMesh* ForMesh);
	void FirePattern(ESunderBossPattern Pattern);
	void Shoot(const FVector& Direction, float SpeedScale = 1.f);
	void ShootFrom(const FVector& Origin, const FVector& Direction, float SpeedScale);
	float BodyRadius() const { return HitRadius / 0.32f; }
	FVector MuzzleLocation() const { return GetActorLocation() - FVector(60.f, 0.f, 0.f); }
	UNiagaraComponent* SpawnFX(UNiagaraSystem* System, const FVector& Location, float Scale = 1.f, float Duration = 0.f);
	void SetFXParams(UNiagaraComponent* FX, float Scale, float Duration) const;
	void TickDying(float DeltaTime);
	/** Play a voice cue: skipped if the same cue played less than MinGap s ago; bDuck steps the music back under it. */
	void PlayVoice(USoundBase* Sound, float MinGap, float& LastPlayed, bool bDuck);
	class USunderMusicSubsystem* Music() const;
	void FinishDying(bool bAwardScore);
	FVector WebDirection(float WebAngleRadians) const;

	FVector BaseMeshScale = FVector::OneVector;
	float BossTime = 0.f;
	float PatternClock = 0.f;
	float SpiralAngle = 0.f;
	float StrafeDir = 1.f;
	int32 PatternIndex = 0;
	int32 Phase = 1;
	bool bEntering = true;
	bool bArrivalShown = false;
	bool bDying = false;
	float DyingTime = 0.f;
	float NextDeathPop = 0.f;
	int32 DeathPops = 0;
	FVector MeshRest = FVector::ZeroVector;
	float LastAttackVoice = -100.f;
	float LastHurtVoice = -100.f;
	float LastCryVoice = -100.f;                         // intro, phase, death, gloat: never rate-limited (gap 0)
};
