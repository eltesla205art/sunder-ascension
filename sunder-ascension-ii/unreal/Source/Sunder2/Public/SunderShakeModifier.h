// SUNDER: Ascension II — the web game's screen shake (G.shake): a jolt that decays by one per second, the view thrown
// by up to ±(shake × 9) px each frame, here ±(shake × 45) units across the play plane. A camera modifier, so it works
// with the arena's ortho CameraActor as it is. Scaled by Settings → SCREEN SHAKE (off / low / full).
#pragma once

#include "CoreMinimal.h"
#include "Camera/CameraModifier.h"
#include "SunderShakeModifier.generated.h"

UCLASS()
class SUNDER2_API USunderShakeModifier : public UCameraModifier
{
	GENERATED_BODY()

public:
	/** A new jolt; the strongest one wins, as in the web game's Math.max(G.shake, …). */
	void Kick(float Amount) { Shake = FMath::Max(Shake, Amount); }

	/** Units the view moves at shake 1, either way (the web game's 9 px × 5). */
	UPROPERTY(EditAnywhere, Category = "Shake")
	float UnitsPerShake = 45.f;

protected:
	virtual bool ModifyCamera(float DeltaTime, FMinimalViewInfo& InOutPOV) override;

private:
	float Shake = 0.f;
};
