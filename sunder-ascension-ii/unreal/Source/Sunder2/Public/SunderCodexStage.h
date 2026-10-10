// SUNDER: Ascension II — the Codex's Keeper viewer: the web Codex's 3D stage (keepers.html) for Unreal.
// An actor spawned out of sight that holds one Keeper's model under the web viewer's lights (warm key, blue rim, cool
// fill, a hemisphere's sky and ground, a practical light in the Keeper's accent colour) in front of an indigo backdrop
// with a violet horizon glow, slowly turning (OrbitControls' autoRotate 0.6), hovering, and growing in when it changes,
// moving through its own animation loop (DA_KeeperAnim_<Id>, the web GLB's loop) when it has one.
// A scene capture renders it to a texture that FSunderCodexPanel draws in the Codex. Its parts are seen only by that
// capture, and its lights reach only them (their own lighting channels), so the level never sees it. It renders while
// the game is paused, and only when the Codex asks (Render), so it costs nothing while the Codex is closed.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SunderCodexStage.generated.h"

class UDirectionalLightComponent;
class UPointLightComponent;
class USceneCaptureComponent2D;
class UStaticMeshComponent;
class UTextureRenderTarget2D;
class USunderKeeperAnim;

UCLASS(NotBlueprintable)
class SUNDER2_API ASunderCodexStage : public AActor
{
	GENERATED_BODY()

public:
	ASunderCodexStage();

	/** The stage for this world: found, or spawned out of sight. */
	static ASunderCodexStage* Get(UWorld* World);

	/** Put this Keeper on the stage (Id as in BP_Keeper_<Id>); a no-op if it is already there. False if it has no model. */
	bool Show(const FString& Id, const FLinearColor& Accent, float Now);

	/** Pose it for this moment (real seconds, so it turns in the pause) and capture; the texture to draw. */
	UTextureRenderTarget2D* Render(float Now);

	/** The longest side of a Keeper on the stage, in units, and the capture's field of view (the web camera's 36°). */
	UPROPERTY(EditDefaultsOnly, Category = "Codex") float FitSize = 300.f;
	UPROPERTY(EditDefaultsOnly, Category = "Codex") float FieldOfView = 36.f;
	UPROPERTY(EditDefaultsOnly, Category = "Codex") int32 Resolution = 512;

private:
	UPROPERTY() TObjectPtr<USceneComponent> Rig;        // turns: the Keeper and its lights, as the web camera orbits
	UPROPERTY() TObjectPtr<USceneComponent> Hover;      // the bob and the grow-in
	UPROPERTY() TObjectPtr<UStaticMeshComponent> Body;
	UPROPERTY() TObjectPtr<UDirectionalLightComponent> Key;
	UPROPERTY() TObjectPtr<UDirectionalLightComponent> RimLight;
	UPROPERTY() TObjectPtr<UDirectionalLightComponent> Fill;
	UPROPERTY() TObjectPtr<UDirectionalLightComponent> SkyLight;      // the hemisphere light's two halves
	UPROPERTY() TObjectPtr<UDirectionalLightComponent> GroundLight;
	UPROPERTY() TObjectPtr<UPointLightComponent> Practical;
	UPROPERTY() TObjectPtr<UStaticMeshComponent> Backdrop;
	UPROPERTY() TObjectPtr<UPointLightComponent> Horizon;
	UPROPERTY() TObjectPtr<USceneCaptureComponent2D> Capture;
	UPROPERTY() TObjectPtr<UTextureRenderTarget2D> Target;
	UPROPERTY() TObjectPtr<USunderKeeperAnim> Anim;                      // the shown Keeper's loop, if imported
	UPROPERTY() TArray<TObjectPtr<UStaticMeshComponent>> Parts;          // its moving parts, reused between Keepers

	UStaticMeshComponent* PartComponent(int32 i);

	FString ShownId;
	float ShownAt = 0.f;
	float Distance = 600.f;
};
