// SUNDER: Ascension II — persistent trace-driven laser beam (see unreal/WEAPON_VFX.md §1).
// Drives the NS_Laser_Beam Niagara system: BeamStart/BeamEnd follow a sphere trace every frame,
// Intensity ramps in and out, damage is applied on a fixed interval.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Engine/EngineTypes.h"
#include "BeamWeaponComponent.generated.h"

class UNiagaraSystem;
class UNiagaraComponent;

UCLASS(ClassGroup = (Sunder), meta = (BlueprintSpawnableComponent))
class SUNDER2_API UBeamWeaponComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UBeamWeaponComponent();

	/** NS_Laser_Beam (user params: BeamStart, BeamEnd, BeamWidth, BeamColor, Intensity, bHit, HitNormal). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Beam")
	TObjectPtr<UNiagaraSystem> BeamSystem;

	/** Socket the beam starts from. Found on the first mesh of the owner that has it, unless SetMuzzle is called. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Beam")
	FName MuzzleSocket = TEXT("Muzzle");

	/** Direction the beam fires in, in world space (flattened onto the XY play plane). +X is up the screen. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam")
	FVector AimDirection = FVector::ForwardVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam", meta = (ClampMin = "0"))
	float MaxRange = 2400.f;

	/** Sphere-trace radius: keep it near half the visible beam width so hits match what the player sees. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam", meta = (ClampMin = "0"))
	float BeamRadius = 14.f;

	/** Visibility works out of the box; switch to a custom PlayerWeapon channel once the project defines one. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam")
	TEnumAsByte<ECollisionChannel> TraceChannel = ECC_Visibility;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam")
	float BeamWidth = 28.f;

	/** HDR colour; the default is Sunborn gold. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam")
	FLinearColor BeamColor = FLinearColor(3.0f, 2.1f, 0.6f, 1.f);

	/** How fast the beam grows toward a farther end (units/s). Shortening is always instant. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam", meta = (ClampMin = "0"))
	float ExtendSpeed = 9000.f;

	/** Intensity ramp speed (per second); 12 is a ~0.08 s charge-up and shut-down. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Beam", meta = (ClampMin = "0"))
	float RampSpeed = 12.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0"))
	float DamagePerSecond = 140.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage", meta = (ClampMin = "0.01"))
	float DamageInterval = 0.05f;

	UFUNCTION(BlueprintCallable, Category = "Beam")
	void StartFire();

	UFUNCTION(BlueprintCallable, Category = "Beam")
	void StopFire();

	/** Override where the beam starts (e.g. a specific mesh and socket). */
	UFUNCTION(BlueprintCallable, Category = "Beam")
	void SetMuzzle(USceneComponent* InComponent, FName InSocket);

	UFUNCTION(BlueprintPure, Category = "Beam")
	bool IsFiring() const { return bFiring; }

	UFUNCTION(BlueprintPure, Category = "Beam")
	FVector GetBeamEnd() const { return CurrentEnd; }

	UFUNCTION(BlueprintPure, Category = "Beam")
	AActor* GetBeamTarget() const { return HitActor.Get(); }

	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
	void ApplyBeamDamage();
	FVector MuzzleLocation() const;

	UPROPERTY(Transient)
	TObjectPtr<UNiagaraComponent> Beam;

	UPROPERTY(Transient)
	TObjectPtr<USceneComponent> MuzzleComponent;

	TWeakObjectPtr<AActor> HitActor;
	FTimerHandle DamageTimer;
	FVector CurrentEnd = FVector::ZeroVector;
	float Intensity = 0.f;
	float IntensityTarget = 0.f;
	bool bFiring = false;
};
