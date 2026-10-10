// SUNDER: Ascension II — what the Codex has unlocked (DESIGN.md: "lore entries for every Keeper, ship and Hour,
// unlocked as you play"): each Hour reached, each Keeper met and beaten. Kept across sessions in
// GameUserSettings.ini under [SunderCodex]. The Codex itself is FSunderCodexPanel.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "SunderCodexSubsystem.generated.h"

UCLASS()
class SUNDER2_API USunderCodexSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	/** Hours are 1–12. Reaching an Hour opens its page; meeting its Keeper shows the Keeper; beating it, the full lore. */
	void MarkReached(int32 Hour);
	void MarkMet(int32 Hour);
	void MarkBeaten(int32 Hour);
	bool IsReached(int32 Hour) const { return Has(Reached, Hour); }
	bool IsMet(int32 Hour) const { return Has(Met, Hour); }
	bool IsBeaten(int32 Hour) const { return Has(Beaten, Hour); }

	static USunderCodexSubsystem* Get(const UObject* WorldContext);

private:
	static bool Has(int32 Mask, int32 Hour) { return Hour >= 1 && Hour <= 30 && (Mask & (1 << Hour)) != 0; }
	void Mark(int32& Mask, int32 Hour);
	void Save() const;

	int32 Reached = 0;
	int32 Met = 0;
	int32 Beaten = 0;
};
