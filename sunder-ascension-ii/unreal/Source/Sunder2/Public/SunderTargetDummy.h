// SUNDER: Ascension II — a target to test weapons against: drifts across the arena, takes beam and shot damage,
// bursts with a plasma impact when destroyed and comes back after a moment.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunderTargetDummy.generated.h"

class UStaticMeshComponent;

UCLASS()
class SUNDER2_API ASunderTargetDummy : public AActor
{
	GENERATED_BODY()

public:
	ASunderTargetDummy();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Target")
	TObjectPtr<UStaticMeshComponent> Mesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target", meta = (ClampMin = "1"))
	float MaxHealth = 400.f;

	/** Side-to-side drift across the screen (Y), in units. 0 holds still. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float DriftAmplitude = 250.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float DriftSpeed = 1.2f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	float RespawnDelay = 1.5f;

	/** HDR colour of the burst when it is destroyed (Sunborn gold). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target")
	FLinearColor DeathColor = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);

	UFUNCTION(BlueprintPure, Category = "Target")
	float GetHealth() const { return Health; }

	virtual float TakeDamage(float DamageAmount, struct FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override;
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void Respawn();

	FVector Home = FVector::ZeroVector;
	FVector BaseScale = FVector::OneVector;
	FTimerHandle RespawnTimer;
	float Health = 0.f;
	float DriftTime = 0.f;
	float HitPulse = 0.f;
	bool bAlive = true;
};
