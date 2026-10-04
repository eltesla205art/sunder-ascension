// SUNDER: Ascension II — one Hour's sound: its theme (three layers that build as the stage nears its Keeper), the
// ambience of the place, and four cues: Start (the gate opens), Wave (a formation arrives), Down (an enemy falls) and
// Clear (the Keeper is beaten). The web game's stage_audio.js, rendered to WAV by unreal/Tools/render_web_audio.cjs;
// DA_StageAudio_<Hour> assets are made by create_stage_audio.py. A wave set (or one wave of it) names its stage audio.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SunderStageAudio.generated.h"

class USoundBase;

UENUM(BlueprintType)
enum class ESunderStageCue : uint8
{
	Start,   // the stage begins (the music steps back under it)
	Wave,    // a formation arrives (at most every 1.5 s)
	Down,    // an enemy falls, over its burst (at most every 0.12 s)
	Clear    // the Keeper is beaten
};

UCLASS(BlueprintType)
class SUNDER2_API USunderStageAudio : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage")
	FString StageName;

	/** Layers 1–3, same-length loops: 1 at the start, 3 as the Keeper nears. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage")
	TArray<TObjectPtr<USoundBase>> MusicLayers;

	/** A looping bed for the whole stage, Keeper fight included. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage")
	TObjectPtr<USoundBase> Ambience;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage|Cues")
	TObjectPtr<USoundBase> StartSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage|Cues")
	TObjectPtr<USoundBase> WaveSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage|Cues")
	TObjectPtr<USoundBase> DownSound;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Stage|Cues")
	TObjectPtr<USoundBase> ClearSound;
};
