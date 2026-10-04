// SUNDER: Ascension II — impact effects that merge and throttle (see unreal/WEAPON_VFX.md §3.2).
// Projectiles call QueueImpact; once per frame the queue is drained: hits landing on the same spot merge into one
// bigger burst, the first MaxFullImpactsPerFrame get the full effect and the rest the lite one, all pooled.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "Subsystems/WorldSubsystem.h"
#include "ImpactFXSubsystem.generated.h"

class UNiagaraSystem;

/** Project Settings → Game → Sunder Impact FX. */
UCLASS(Config = Game, DefaultConfig, meta = (DisplayName = "Sunder Impact FX"))
class SUNDER2_API UImpactFXSettings : public UDeveloperSettings
{
	GENERATED_BODY()

public:
	/** NS_PlasmaBurst_Impact (user params: ImpactNormal, PlasmaColor, Scale). */
	UPROPERTY(Config, EditAnywhere, Category = "Impacts")
	TSoftObjectPtr<UNiagaraSystem> ImpactFX;

	/** Flash + a few sparks, used once the full-effect budget for the frame is spent. */
	UPROPERTY(Config, EditAnywhere, Category = "Impacts")
	TSoftObjectPtr<UNiagaraSystem> ImpactFXLite;

	/** Hits closer than this (in the play plane) in the same frame become one bigger burst. */
	UPROPERTY(Config, EditAnywhere, Category = "Impacts", meta = (ClampMin = "0"))
	float MergeRadius = 40.f;

	UPROPERTY(Config, EditAnywhere, Category = "Impacts", meta = (ClampMin = "0"))
	int32 MaxFullImpactsPerFrame = 10;

	UPROPERTY(Config, EditAnywhere, Category = "Impacts", meta = (ClampMin = "1"))
	float MaxMergedScale = 2.f;

	UPROPERTY(Config, EditAnywhere, Category = "Impacts")
	int32 TranslucencySortPriority = 20;

	virtual FName GetCategoryName() const override { return TEXT("Game"); }
};

UCLASS()
class SUNDER2_API UImpactFXSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	/** Queue a plasma impact; it spawns at the end of this frame's subsystem tick. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Impacts")
	void QueueImpact(FVector Location, FVector Normal, FLinearColor Color);

	/** Impacts queued and not yet spawned (for debugging and tests). */
	UFUNCTION(BlueprintPure, Category = "Sunder|Impacts")
	int32 GetPendingCount() const { return Pending.Num(); }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;
	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;

protected:
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	struct FPendingImpact
	{
		FVector Location;
		FVector Normal;
		FLinearColor Color;
		float Scale = 1.f;
	};

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraSystem> ImpactFX;

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraSystem> ImpactFXLite;

	TArray<FPendingImpact> Pending;
	float MergeRadius = 40.f;
	float MaxMergedScale = 2.f;
	int32 MaxFullImpactsPerFrame = 10;
	int32 SortPriority = 20;
};
