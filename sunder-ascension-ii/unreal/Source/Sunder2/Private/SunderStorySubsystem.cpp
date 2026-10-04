// SUNDER: Ascension II — the story campaign across level loads.
#include "SunderStorySubsystem.h"

#include "Kismet/GameplayStatics.h"
#include "SunderKeeper.h"
#include "SunderWaveSet.h"

void USunderStorySubsystem::StartCampaign(USunderStoryData* InData)
{
	Data = InData;
	bActive = InData != nullptr;
	HourIndex = 0;
	TotalScore = 0;
	EndLayer = 1;
	Screen = ESunderStoryScreen::Opening;
}

void USunderStorySubsystem::EndCampaign()
{
	bActive = false;
}

const FSunderStoryHour* USunderStorySubsystem::GetHour() const
{
	return Data && Data->Hours.IsValidIndex(HourIndex) ? &Data->Hours[HourIndex] : nullptr;
}

void USunderStorySubsystem::AdvanceHour()
{
	if (Data) { HourIndex = FMath::Min(HourIndex + 1, FMath::Max(Data->Hours.Num() - 1, 0)); }
}

void USunderStorySubsystem::EnterHour(const UObject* WorldContext)
{
	if (!Data) { return; }
	UGameplayStatics::OpenLevel(WorldContext, Data->ArenaLevel);
}

USunderWaveSet* USunderStorySubsystem::MakeHourWaveSet(UObject* Outer) const
{
	const FSunderStoryHour* Hour = GetHour();
	if (!IsActive() || !Hour) { return nullptr; }
	USunderWaveSet* Set = NewObject<USunderWaveSet>(Outer);
	if (Data->EnemyWaves)
	{
		for (const FSunderWave& Wave : Data->EnemyWaves->Waves)
		{
			if (!Wave.Keeper) { Set->Waves.Add(Wave); }           // the story brings its own Keeper
		}
	}
	if (Hour->Keeper)
	{
		FSunderWave& KeeperWave = Set->Waves.AddDefaulted_GetRef();
		KeeperWave.WaveName = FString::Printf(TEXT("KEEPER  ·  %s"), *Hour->KeeperName.ToUpper());
		KeeperWave.Keeper = Hour->Keeper;
		KeeperWave.bWaitForClear = true;
		KeeperWave.MaxDuration = 600.f;
		KeeperWave.BreakAfter = 0.f;
	}
	Set->StageAudio = Hour->StageAudio;
	Set->bLoop = false;                                          // one pass: the Hour ends with its Keeper
	return Set;
}

void USunderStorySubsystem::ReportHourCleared(const UObject* WorldContext, int32 Score)
{
	if (!IsActive()) { return; }
	TotalScore += Score;
	Screen = HourIndex + 1 >= Data->Hours.Num() ? ESunderStoryScreen::Victory : ESunderStoryScreen::Clear;
	OpenStoryLevel(WorldContext);
}

void USunderStorySubsystem::ReportDefeat(const UObject* WorldContext, int32 Score, int32 MusicLayer)
{
	if (!IsActive()) { return; }
	TotalScore += Score;
	EndLayer = FMath::Clamp(MusicLayer, 1, 3);
	Screen = ESunderStoryScreen::Defeat;
	OpenStoryLevel(WorldContext);
}

void USunderStorySubsystem::OpenStoryLevel(const UObject* WorldContext) const
{
	UGameplayStatics::OpenLevel(WorldContext, Data->StoryLevel);
}
