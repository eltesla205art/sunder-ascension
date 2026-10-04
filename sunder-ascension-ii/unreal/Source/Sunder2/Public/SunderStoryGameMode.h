// SUNDER: Ascension II — the story screens and the hour map, with the web game's words and sound (story_audio.js):
// the opening crawl (a desert lament over the wind), the hour map (its theme building act by act), each Hour's briefing
// (a watchful drone over that Hour's own ambience), the Hour survived (its fanfare played in the arena; between acts a
// bell and the interlude theme), the dawn ending, and DAWN DENIED. The campaign itself lives in SunderStorySubsystem.
// BP_SunderStoryGameMode and L_SunderStory are made by create_story_level.py; drawing is SunderStoryHUD.
#pragma once

#include "CoreMinimal.h"
#include "SunderFrontEndGameMode.h"
#include "SunderStorySubsystem.h"
#include "SunderStoryGameMode.generated.h"

UCLASS()
class SUNDER2_API ASunderStoryGameMode : public ASunderFrontEndGameMode
{
	GENERATED_BODY()

public:
	ASunderStoryGameMode();

	/** Used when the level is played on its own (no campaign started from the hangar). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Story")
	TObjectPtr<USunderStoryData> StoryData;

	virtual void Confirm() override;
	virtual void Back() override;

	UFUNCTION(BlueprintPure, Category = "Story")
	ESunderStoryScreen GetScreen() const { return Screen; }

	USunderStorySubsystem* Story() const;

protected:
	virtual void BeginPlay() override;

private:
	void Enter(ESunderStoryScreen InScreen);
	void ToTitle();
	/** The hour map's layer: 1 in Act I, 2 in Act II, 3 from Act III on (the web game's mapLayer). */
	int32 MapLayer() const;

	ESunderStoryScreen Screen = ESunderStoryScreen::Opening;
};
