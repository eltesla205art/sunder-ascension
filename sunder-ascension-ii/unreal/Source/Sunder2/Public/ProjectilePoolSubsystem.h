// SUNDER: Ascension II — projectile actor pool (see unreal/WEAPON_VFX.md §3.4).
// Acquire instead of SpawnActor, Release instead of Destroy. Prewarm at level start so firing never allocates.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "ProjectilePoolSubsystem.generated.h"

class ASunderProjectile;

USTRUCT()
struct FSunderProjectileFreeList
{
	GENERATED_BODY()

	UPROPERTY()
	TArray<TObjectPtr<ASunderProjectile>> Items;
};

UCLASS()
class SUNDER2_API UProjectilePoolSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	/** Fire a projectile of this class from Location along Direction, reusing a parked one when there is one.
	 *  SpeedOverride > 0 replaces the class's Speed for this shot (Keepers fire at their Hour's bullet speed). */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Projectiles", meta = (DeterminesOutputType = "ProjectileClass"))
	ASunderProjectile* Acquire(TSubclassOf<ASunderProjectile> ProjectileClass, FVector Location, FVector Direction,
		AActor* Owner, APawn* Instigator, float SpeedOverride = 0.f);

	/** Park a projectile and keep it for reuse. Safe to call twice. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Projectiles")
	void Release(ASunderProjectile* Projectile);

	/** Spawn Count parked projectiles up front (call from BeginPlay of the level or game mode). */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Projectiles")
	void Prewarm(TSubclassOf<ASunderProjectile> ProjectileClass, int32 Count);

	UFUNCTION(BlueprintPure, Category = "Sunder|Projectiles")
	int32 GetParkedCount(TSubclassOf<ASunderProjectile> ProjectileClass) const;

	/** Every projectile this pool has ever made (parked or flying); should plateau during a stress test. */
	UFUNCTION(BlueprintPure, Category = "Sunder|Projectiles")
	int32 GetTotalCreated() const { return TotalCreated; }

protected:
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	ASunderProjectile* SpawnParked(TSubclassOf<ASunderProjectile> ProjectileClass);

	UPROPERTY(Transient)
	TMap<TObjectPtr<UClass>, FSunderProjectileFreeList> Free;

	int32 TotalCreated = 0;
};
