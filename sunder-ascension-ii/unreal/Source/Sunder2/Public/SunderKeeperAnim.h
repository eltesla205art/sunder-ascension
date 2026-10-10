// SUNDER: Ascension II — a Keeper's animation loop as rigid parts, for the Codex viewer.
// The same loop the web Codex plays from its GLB (blender/keepers.py export_glb): blender/keepers.py --fbx-anim writes
// the fixed body, each moving part about its own pivot and each part's transform for every frame of one loop;
// Scripts/create_keeper_anim.py imports them into DA_KeeperAnim_<Id>. Frames are in the Keeper model's own space (the
// space of SM_Keeper_<Id>), and the last frame repeats the first, so the loop wraps cleanly.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SunderKeeperAnim.generated.h"

class UStaticMesh;

USTRUCT(BlueprintType)
struct FSunderKeeperAnimPart
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	TObjectPtr<UStaticMesh> Mesh;

	/** Its transform in the model's space, frame by frame (FramesPerSecond). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	TArray<FTransform> Frames;
};

UCLASS(BlueprintType)
class SUNDER2_API USunderKeeperAnim : public UDataAsset
{
	GENERATED_BODY()

public:
	/** Everything that holds still. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	TObjectPtr<UStaticMesh> Body;

	/** Apep: the body posed at every frame of the loop, for his coil wave, which bends the mesh where rigid parts can't.
	 *  The viewer flips through them in place of Body, as the web GLB blends its wave morph targets. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	TArray<TObjectPtr<UStaticMesh>> BodyFrames;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	TArray<FSunderKeeperAnimPart> Parts;

	/** keepers.py's LOOP: 32 frames a second, one loop a second, as in the game. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Keeper Anim")
	float FramesPerSecond = 32.f;

	/** Part i at Time seconds into the loop: neighbouring frames blended, as glTF's LINEAR keys play. */
	FTransform Sample(int32 Part, float Time) const;

	/** The body at Time seconds into the loop: its frame from BodyFrames, or Body. */
	UStaticMesh* BodyAt(float Time) const;
};
