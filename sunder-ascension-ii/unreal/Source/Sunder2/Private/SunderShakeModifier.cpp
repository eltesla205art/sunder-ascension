// SUNDER: Ascension II — the screen shake.
#include "SunderShakeModifier.h"

#include "Camera/PlayerCameraManager.h"
#include "Engine/World.h"

bool USunderShakeModifier::ModifyCamera(float DeltaTime, FMinimalViewInfo& InOutPOV)
{
	Super::ModifyCamera(DeltaTime, InOutPOV);
	const UWorld* World = CameraOwner ? CameraOwner->GetWorld() : nullptr;
	if (Shake <= 0.f || !World || World->IsPaused()) { return false; }   // a paused frame holds still
	Shake = FMath::Max(Shake - DeltaTime, 0.f);
	const float Reach = Shake * UnitsPerShake;
	// Top-down: up the screen is +X, across it +Y, so the jolt moves the view across the play plane.
	InOutPOV.Location.X += FMath::FRandRange(-0.5f, 0.5f) * 2.f * Reach;
	InOutPOV.Location.Y += FMath::FRandRange(-0.5f, 0.5f) * 2.f * Reach;
	return false;
}
