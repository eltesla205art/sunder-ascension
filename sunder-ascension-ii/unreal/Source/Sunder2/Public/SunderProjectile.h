// SUNDER: Ascension II — a pooled plasma projectile (see unreal/WEAPON_VFX.md §3.4).
// Never destroyed in play: on a hit or timeout it queues its impact and goes back to UProjectilePoolSubsystem.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunderProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;
class UNiagaraComponent;
class UStaticMeshComponent;

UCLASS()
class SUNDER2_API ASunderProjectile : public AActor
{
	GENERATED_BODY()

public:
	ASunderProjectile();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	TObjectPtr<USphereComponent> Collision;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	TObjectPtr<UProjectileMovementComponent> Movement;

	/** Placeholder look (a small sphere) until the trail system carries the visuals; swap or hide it in the Blueprint. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	TObjectPtr<UStaticMeshComponent> Visual;

	/** Optional trail (assign a Niagara system on the component in the Blueprint subclass). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Projectile")
	TObjectPtr<UNiagaraComponent> Trail;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	float Damage = 10.f;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	float Speed = 2200.f;

	/** Seconds before an unspent shot returns to the pool (it has left the screen). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	float MaxLifetime = 2.5f;

	/** HDR colour handed to the impact effect; the default is plasma magenta. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Projectile")
	FLinearColor PlasmaColor = FLinearColor(4.0f, 0.6f, 2.6f, 1.f);

	/** Called by the pool: place, aim and launch. Direction is flattened onto the XY play plane. */
	void Fire(const FVector& Location, const FVector& Direction, AActor* InOwner, APawn* InInstigator, float SpeedOverride = 0.f);

	/** Recolour this shot (impact and trail, via the trail's User.ShotColor); the pool resets it when the shot is parked. */
	UFUNCTION(BlueprintCallable, Category = "Projectile")
	void SetShotColor(const FLinearColor& Color);

	/** Called by the pool: hide, stop and park. */
	void Park();

	bool IsParked() const { return bParked; }

	/** Back to the pool at once, with no impact (a bomb wiping the screen). */
	void Recall() { ReturnToPool(); }

	/** Fired by an enemy (decided when fired, so it holds even after the enemy is destroyed). */
	bool IsFromEnemy() const { return bFromEnemy; }

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void Expire();
	void ReturnToPool();

	FTimerHandle LifetimeTimer;
	bool bParked = true;
	bool bFromEnemy = false;
};
