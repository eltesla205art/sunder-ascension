// SUNDER: Ascension II — a power-up falling from a destroyed enemy (the web game's pickups): a spinning diamond in its
// colour with its letter, drifting down the screen; the ship collects it by flying into it. Which kind drops, and how
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

UCLASS()
class SUNDER2_API ASunderPickup : public AActor
{
	GENERATED_BODY()

public:
	ASunderPickup();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<USphereComponent> Collision;

	/** Placeholder look: a flat diamond (swap the mesh in a Blueprint child for real pickup art). */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<UStaticMeshComponent> Gem;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pickup")
	TObjectPtr<UTextRenderComponent> Letter;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Pickup")
	ESunderPickupKind Kind = ESunderPickupKind::Power;

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

	UPROPERTY(Transient)
	TObjectPtr<UMaterialInstanceDynamic> GemMaterial;

	float Age = 0.f;
	float StartY = 0.f;
};
