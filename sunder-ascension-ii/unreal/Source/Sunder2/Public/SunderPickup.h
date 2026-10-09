// SUNDER: Ascension II — a power-up falling from a destroyed enemy (the web game's pickups): a faceted gem in its colour
// with its emblem (blender/pickups.py, set per kind in KindMeshes by create_pickup_art.py; until then a flat diamond
// with a letter), tilting as it drifts down the screen; the ship collects it by flying into it. Which kind drops, and how
// often, is the game mode's (SunderGameMode::TrySpawnPickup); what it does is the ship's (CollectPickup).
//   S  Spread (red)    L  Laser (blue)    P  Power (gold)    B  Bomb (amber)    O  Shield (cyan)    +  Life (rose)
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunderShipPawn.h"
#include "SunderPickup.generated.h"

class USphereComponent;
class UStaticMeshComponent;
class UTextRenderComponent;
class UMaterialInstanceDynamic;
class UStaticMesh;
class UNiagaraSystem;

UCLASS()
class SUNDER2_API ASunderPickup : public AActor
{
	GENERATED_BODY()

public:
	ASunderPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<USphereComponent> Collision;

	/** The gem: the kind's model from KindMeshes, or the placeholder diamond. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<UStaticMeshComponent> Gem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<UTextRenderComponent> Letter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	ESunderPickupKind Kind = ESunderPickupKind::Power;

	/** Each kind's model (SM_Pickup_<Kind>); a kind without one keeps the placeholder diamond and letter. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|Look")
	TMap<ESunderPickupKind, TObjectPtr<UStaticMesh>> KindMeshes;

	/** Turns a model so its emblem reads up the screen. Yaw 90 = Blender's +Y up through Unreal's usual FBX axes (the
	 *  same turn as the ships and Keepers); change it if the emblems read sideways. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|Look")
	FRotator MeshRotation = FRotator(0.f, 90.f, 0.f);

	/** A model's size on screen, corner to corner, in units (the web game's 28-px icon × 5 is 140). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|Look")
	float MeshSize = 140.f;

	/** NS_Pickup_Collect (PICKUP_VFX.md), one-shot and pooled, played when the ship collects it: the gem breaks into
	 *  light that's drawn into the ship. It rides on the ship, starting where the gem was. User.Color = the kind's colour
	 *  (HDR), User.Kind (0 Spread … 5 Life), User.Size = MeshSize, User.ToShip = the ship's position from the gem.
	 *  Until it has emitters, a plasma impact in the kind's colour stands in. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|Look")
	TObjectPtr<UNiagaraSystem> CollectFX;

	/** Brightest channel of the kind's colour in the collect effect (bloom does the rest). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup|Look", meta = (ClampMin = "0"))
	float CollectGlow = 4.f;

	/** Units per second down the screen (the web game's 90 px/s × 5). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	float FallSpeed = 450.f;

	/** Set the kind (its colour and letter follow). */
	UFUNCTION(BlueprintCallable, Category = "Pickup")
	void SetKind(ESunderPickupKind InKind);

	static FLinearColor KindColor(ESunderPickupKind InKind);
	static FString KindLetter(ESunderPickupKind InKind);

	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
		int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	void PlayCollect(ASunderShipPawn* Ship);

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> GemMaterial;

	UPROPERTY(Transient)
	TObjectPtr<UStaticMesh> PlaceholderMesh;

	FVector GemBaseScale = FVector(0.55f, 0.55f, 0.12f);
	FRotator GemBaseRotation = FRotator(0.f, 45.f, 0.f);
	bool bModel = false;

	float Age = 0.f;
	float StartY = 0.f;
};
