// SUNDER: Ascension II — the story mode's content: the web game's words (exported by unreal/Tools/export_story_text.cjs),
// its twelve Hours (each with its stage sound, Keeper and art), and the music and cues of the story screens and the hour
// map (web/story_audio.js, rendered by unreal/Tools/render_web_audio.cjs). DA_StoryData is made by create_story_level.py.
#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "SunderStoryData.generated.h"

class ASunderKeeper;
class USoundBase;
class USunderStageAudio;
class USunderWaveSet;
class UTexture2D;

USTRUCT(BlueprintType)
struct FSunderStoryHour
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	FString Name;

	/** Its act and time of night, e.g. "Act I — Dusk". */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	FString Subtitle;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	FString KeeperName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour", meta = (MultiLine = true))
	FString Quote;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour", meta = (MultiLine = true))
	FString Brief;

	/** "The western gate falls open…": shown when it is survived. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour", meta = (MultiLine = true))
	FString ClearLine;

	/** A new act begins after this Hour: its interlude (with its own bell and theme); empty for most Hours. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour", meta = (MultiLine = true))
	FString Interlude;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	FLinearColor Tint = FLinearColor::White;

	/** Its theme, ambience and cues (the briefing plays over its ambience). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	TObjectPtr<USunderStageAudio> StageAudio;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	TSubclassOf<ASunderKeeper> Keeper;

	/** This Hour's enemy waves and difficulty (DA_Waves_HourNN_*); empty = the story's shared EnemyWaves. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	TObjectPtr<USunderWaveSet> Waves;

	/** The stage's backdrop and the Keeper's portrait, behind the briefing. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	TObjectPtr<UTexture2D> Backdrop;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Hour")
	TObjectPtr<UTexture2D> KeeperPortrait;
};

UCLASS(BlueprintType)
class SUNDER2_API USunderStoryData : public UPrimaryDataAsset
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TArray<FString> Opening;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TArray<FString> Victory;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story", meta = (MultiLine = true))
	FString DefeatTag;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TArray<FSunderStoryHour> Hours;

	/** The enemy waves for an Hour with no Waves of its own (its Keeper wave is added from Hours). */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TObjectPtr<USunderWaveSet> EnemyWaves;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Levels")
	FName StoryLevel = TEXT("L_SunderStory");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Levels")
	FName ArenaLevel = TEXT("L_SunderArena");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Levels")
	FName TitleLevel = TEXT("L_SunderTitle");

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story")
	TObjectPtr<UTexture2D> MapBackdrop;

	// ---- sound (web/story_audio.js). Screens with ambience are SunderStageAudio assets; the rest are theme layers.
	/** The crawl: a slow desert lament over its own ambience. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TObjectPtr<USunderStageAudio> OpeningAudio;

	/** The hour map: its theme builds act by act on the road to dawn. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TObjectPtr<USunderStageAudio> MapAudio;

	/** A watchful drone over the coming Hour's own ambience. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TArray<TObjectPtr<USoundBase>> BriefingMusic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TArray<TObjectPtr<USoundBase>> InterludeMusic;

	/** Dawn breaks: the hero's theme in a major key. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TArray<TObjectPtr<USoundBase>> VictoryMusic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio")
	TArray<TObjectPtr<USoundBase>> DefeatMusic;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> BeginSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> MapSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> GateSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> BriefingSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> InterludeSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> DawnSound;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Story|Audio|Cues") TObjectPtr<USoundBase> DeniedSound;
};
