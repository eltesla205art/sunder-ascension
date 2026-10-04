// SUNDER: Ascension II — a Keeper: the boss of an Hour. Ported from the web game's boss logic: it descends into the top
// band (untouchable while it enters), strafes side to side, cycles its Hour's attack patterns every few seconds, and
// grows faster and angrier at 66 % and 33 % hull. In phase 3 it dashes, and a Keeper with a PhaseThreeMesh changes form
// (Apep opens its jaws). Announces itself with its taunt, shows a boss bar, and bursts hugely when beaten.
// Each Keeper is a Blueprint child made by create_keepers.py with its Hour's numbers from the web game.
#pragma once

#include "CoreMinimal.h"
#include "SunderEnemy.h"
#include "SunderKeeper.generated.h"

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

	UFUNCTION(BlueprintPure, Category = "Keeper")
	int32 GetPhase() const { return Phase; }

	UFUNCTION(BlueprintPure, Category = "Keeper")
	float GetHealthFraction() const { return MaxHealth > 0.f ? FMath::Clamp(Health / MaxHealth, 0.f, 1.f) : 0.f; }

	UFUNCTION(BlueprintPure, Category = "Keeper")
	bool IsEntering() const { return bEntering; }

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
	FVector WebDirection(float WebAngleRadians) const;

	FVector BaseMeshScale = FVector::OneVector;
	float BossTime = 0.f;
	float PatternClock = 0.f;
	float SpiralAngle = 0.f;
	float StrafeDir = 1.f;
	int32 PatternIndex = 0;
	int32 Phase = 1;
	bool bEntering = true;
};
