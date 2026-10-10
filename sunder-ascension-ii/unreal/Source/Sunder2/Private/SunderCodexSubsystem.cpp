// SUNDER: Ascension II — the Codex's unlocks.
#include "SunderCodexSubsystem.h"

#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "Misc/ConfigCacheIni.h"

namespace { const TCHAR* Section = TEXT("SunderCodex"); }

void USunderCodexSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	if (!GConfig) { return; }
	GConfig->GetInt(Section, TEXT("Reached"), Reached, GGameUserSettingsIni);
	GConfig->GetInt(Section, TEXT("Met"), Met, GGameUserSettingsIni);
	GConfig->GetInt(Section, TEXT("Beaten"), Beaten, GGameUserSettingsIni);
}

void USunderCodexSubsystem::Save() const
{
	if (!GConfig) { return; }
	GConfig->SetInt(Section, TEXT("Reached"), Reached, GGameUserSettingsIni);
	GConfig->SetInt(Section, TEXT("Met"), Met, GGameUserSettingsIni);
	GConfig->SetInt(Section, TEXT("Beaten"), Beaten, GGameUserSettingsIni);
	GConfig->Flush(false, GGameUserSettingsIni);
}

void USunderCodexSubsystem::Mark(int32& Mask, int32 Hour)
{
	if (Hour < 1 || Hour > 30 || Has(Mask, Hour)) { return; }
	Mask |= 1 << Hour;
	Save();
}

void USunderCodexSubsystem::MarkReached(int32 Hour) { Mark(Reached, Hour); }
void USunderCodexSubsystem::MarkMet(int32 Hour) { Mark(Reached, Hour); Mark(Met, Hour); }
void USunderCodexSubsystem::MarkBeaten(int32 Hour) { MarkMet(Hour); Mark(Beaten, Hour); }

USunderCodexSubsystem* USunderCodexSubsystem::Get(const UObject* WorldContext)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	return GI ? GI->GetSubsystem<USunderCodexSubsystem>() : nullptr;
}
