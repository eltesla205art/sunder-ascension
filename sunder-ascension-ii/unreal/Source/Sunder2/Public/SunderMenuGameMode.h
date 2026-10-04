// SUNDER: Ascension II — the title screen and the hangar, with the web game's sound (menu_audio.js, rendered by
// unreal/Tools/render_web_audio.cjs): the title's slow hero theme over the wind at the crystal gate, the hangar's
// groove over machinery and the base PA, the interface cues, and each ship's engine revving when you pick it and when
// you launch. Title → (Start) → Hangar: choose a ship and Story / Swarm → (Launch) → the arena level.
// Story mode opens the story level (the opening crawl and the hour map) when StoryLevel is set; Swarm flies the arena.
// BP_SunderMenuGameMode and L_SunderTitle are made by create_menu_level.py. Input: SunderMenuController; drawing:
// SunderMenuHUD.
#pragma once

#include "CoreMinimal.h"
#include "SunderFrontEndGameMode.h"
#include "SunderMenuGameMode.generated.h"

class USoundBase;
class USunderStageAudio;
class UTexture2D;

UENUM(BlueprintType)
enum class ESunderMenuScreen : uint8
{
	Title,
	Hangar,
	Launching
};

USTRUCT(BlueprintType)
struct FSunderMenuShip
{
	GENERATED_BODY()

	/** Passed to the arena as ?Ship=<Id>. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	FString Id;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	FString Name;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	FString ShipClass;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	FLinearColor Tint = FLinearColor::White;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<UTexture2D> Sprite;

	/** Its engine: on the pad when chosen, and at launch. */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Ship")
	TObjectPtr<USoundBase> RevSound;
};

UCLASS()
class SUNDER2_API ASunderMenuGameMode : public ASunderFrontEndGameMode
{
	GENERATED_BODY()

public:
	ASunderMenuGameMode();

	// ---- the screens' sound: theme layers + ambience (DA_MenuAudio_Title / _Hangar, SunderStageAudio assets)
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USunderStageAudio> TitleAudio;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USunderStageAudio> HangarAudio;

	/** Which layer of the menu themes plays (1 = as the web game plays them; 2–3 fuller). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio", meta = (ClampMin = "1", ClampMax = "3"))
	int32 MusicLayer = 1;

	/** The gate surges open (title → hangar; the music ducks). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USoundBase> StartSound;

	/** The bay turns to the next ship. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USoundBase> MoveSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USoundBase> ModeSound;

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USoundBase> BackSound;

	/** Launch (the music ducks, then fades as the level loads). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu|Audio")
	TObjectPtr<USoundBase> LaunchSound;

	// ---- the hangar
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	TArray<FSunderMenuShip> Ships;

	/** Full-screen art behind both screens (title_bg). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	TObjectPtr<UTexture2D> Backdrop;

	/** The level Launch opens, with ?Ship=<id>?Mode=Story|Swarm. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	FName ArenaLevel = TEXT("L_SunderArena");

	/** Story mode launches into this level (L_SunderStory: the opening crawl, then the hour map); None = the arena. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	FName StoryLevel;

	/** The story's words, music and Hours, for starting a campaign (DA_StoryData). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	TObjectPtr<class USunderStoryData> StoryData;

	/** Seconds from Launch to the level opening (the launch roar plays out). */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Menu")
	float LaunchDelay = 1.8f;

	virtual void Confirm() override;
	virtual void Back() override;
	virtual void Navigate(int32 X, int32 Y) override;
	void MoveShip(int32 Direction);
	void ToggleMode();

	UFUNCTION(BlueprintPure, Category = "Menu") ESunderMenuScreen GetScreen() const { return Screen; }
	UFUNCTION(BlueprintPure, Category = "Menu") int32 GetShipIndex() const { return ShipIndex; }
	/** 0 = Story, 1 = Swarm. */
	UFUNCTION(BlueprintPure, Category = "Menu") int32 GetModeIndex() const { return ModeIndex; }
protected:
	virtual void BeginPlay() override;

private:
	void EnterTitle();
	void EnterHangar();
	void QueueRev(float Delay);
	void PlayRev();
	void OpenArena();

	ESunderMenuScreen Screen = ESunderMenuScreen::Title;
	int32 ShipIndex = 0;
	int32 ModeIndex = 0;
	float LastMoveCue = -100.f;
	FTimerHandle RevTimer;
	FTimerHandle LaunchTimer;
};
