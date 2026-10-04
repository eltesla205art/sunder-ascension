// SUNDER: Ascension II — the story screens and the hour map. Cue and music timings follow web/game.html.
#include "SunderStoryGameMode.h"

#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderMusicSubsystem.h"
#include "SunderStageAudio.h"
#include "SunderStoryHUD.h"

ASunderStoryGameMode::ASunderStoryGameMode()
{
	HUDClass = ASunderStoryHUD::StaticClass();
}

USunderStorySubsystem* ASunderStoryGameMode::Story() const
{
	return GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
}

void ASunderStoryGameMode::BeginPlay()
{
	Super::BeginPlay();
	USunderStorySubsystem* S = Story();
	if (!S) { return; }
	if (!S->IsActive()) { S->StartCampaign(StoryData); }      // played on its own: begin at the crawl
	Enter(S->GetScreen());
}

int32 ASunderStoryGameMode::MapLayer() const
{
	const int32 Next = Story() ? Story()->GetHourIndex() : 0;
	return Next < 3 ? 1 : Next < 6 ? 2 : 3;
}

void ASunderStoryGameMode::Enter(ESunderStoryScreen InScreen)
{
	USunderStorySubsystem* S = Story();
	USunderStoryData* Data = S ? S->GetData() : nullptr;
	USunderMusicSubsystem* M = Music();
	if (!S || !Data) { return; }
	Screen = InScreen;
	S->SetScreen(InScreen);
	MarkScreenOpened();
	CancelCues();
	const FSunderStoryHour* Hour = S->GetHour();

	switch (Screen)
	{
	case ESunderStoryScreen::Opening:
		if (M) { M->SetStage(Data->OpeningAudio); M->PlayStageMusic(1); }
		PlayCue(Data->BeginSound, true);
		break;
	case ESunderStoryScreen::Map:
		if (M) { M->SetStage(Data->MapAudio); M->PlayStageMusic(MapLayer()); }
		PlayCue(Data->MapSound, false);
		break;
	case ESunderStoryScreen::Briefing:
		if (M)
		{
			M->SetStage(Hour ? Hour->StageAudio.Get() : nullptr);   // the coming Hour's own ambience…
			TArray<USoundBase*> Layers(Data->BriefingMusic);
			M->PlayLayered(Layers, 1);                         // …under a watchful drone
		}
		PlayCue(Data->BriefingSound, false);
		break;
	case ESunderStoryScreen::Clear:
		// The Hour's fanfare played in the arena as its Keeper fell; here, silence, and between acts a bell and the
		// interlude (the web game's 2.4 / 2.6 s after the fanfare, less the time the level took to open).
		if (M) { M->StopMusic(0.5f); M->SetStage(nullptr); }
		if (Hour && !Hour->Interlude.IsEmpty())
		{
			PlayCue(Data->InterludeSound, false, 0.6f);
			if (M) { TArray<USoundBase*> Layers(Data->InterludeMusic); M->PlayLayered(Layers, 3, 0.8f); }
		}
		break;
	case ESunderStoryScreen::Victory:
		if (M) { M->SetStage(nullptr); TArray<USoundBase*> Layers(Data->VictoryMusic); M->PlayLayered(Layers, 3, 1.2f); }
		PlayCue(Data->DawnSound, true, 0.6f);                  // dawn breaks; the hero's theme in a major key
		break;
	case ESunderStoryScreen::Defeat:
		if (M) { M->SetStage(nullptr); TArray<USoundBase*> Layers(Data->DefeatMusic); M->PlayLayered(Layers, S->GetEndLayer(), 2.4f); }
		PlayCue(Data->DeniedSound, true, 0.6f);
		break;
	}
}

void ASunderStoryGameMode::Confirm()
{
	USunderStorySubsystem* S = Story();
	if (!S || !S->GetData()) { return; }
	switch (Screen)
	{
	case ESunderStoryScreen::Opening:
		Enter(ESunderStoryScreen::Map);
		break;
	case ESunderStoryScreen::Map:
		Enter(ESunderStoryScreen::Briefing);
		PlayCue(S->GetData()->GateSound, false);              // the gate opens over the briefing's own cue
		break;
	case ESunderStoryScreen::Briefing:
		if (USunderMusicSubsystem* M = Music()) { M->StopMusic(0.3f); }
		S->EnterHour(this);
		break;
	case ESunderStoryScreen::Clear:
		S->AdvanceHour();
		Enter(ESunderStoryScreen::Map);
		break;
	case ESunderStoryScreen::Victory:
		ToTitle();
		break;
	case ESunderStoryScreen::Defeat:
		S->StartCampaign(S->GetData());                       // as in the web game: the night begins again
		Enter(ESunderStoryScreen::Opening);
		break;
	}
}

void ASunderStoryGameMode::Back()
{
	if (Screen == ESunderStoryScreen::Opening || Screen == ESunderStoryScreen::Map || Screen == ESunderStoryScreen::Defeat
		|| Screen == ESunderStoryScreen::Victory)
	{
		ToTitle();
	}
}

void ASunderStoryGameMode::ToTitle()
{
	USunderStorySubsystem* S = Story();
	const FName Title = S && S->GetData() ? S->GetData()->TitleLevel : FName(TEXT("L_SunderTitle"));
	if (S) { S->EndCampaign(); }
	UGameplayStatics::OpenLevel(this, Title);
}
