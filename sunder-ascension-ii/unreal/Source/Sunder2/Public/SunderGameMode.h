// SUNDER: Ascension II — game mode for the arena: the ship as the default pawn, score, lives, respawns, the wave
// banner, and DAWN DENIED (then a restart) when the last life is lost. BP_SunderGameMode points the pawn at BP_SunderShip.
// It flies the ship and mode chosen in the hangar (SunderLoadoutSubsystem, or ?Ship= / ?Mode= on the level URL): the
// ship's loadout from Ships (the web game's three ships), and Swarm (no Keepers, endless, faster and faster) or the
// Hours.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SunderShipPawn.h"
#include "SunderGameMode.generated.h"

class ASunderKeeper;
class ASunderPickup;

UCLASS()
class SUNDER2_API ASunderGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	ASunderGameMode();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder")
	int32 StartingLives = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder")
	float RespawnDelay = 2.f;

	/** Seconds on DAWN DENIED before the level restarts. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder")
	float RestartDelay = 4.f;

	/** After DAWN DENIED, go to this level (the title screen, L_SunderTitle) instead of restarting the arena; None = restart.
	 *  In story mode, DAWN DENIED always goes to the story level instead. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sunder")
	FName MenuLevel;

	/** The hangar's ships as the arena flies them (defaults: the web game's Sunborn, Scarab and Ibis in Unreal units). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Ships")
	TArray<FSunderShipLoadout> Ships;

	/** What a destroyed enemy drops (ASunderPickup or a Blueprint child with real art). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Pickups")
	TSubclassOf<ASunderPickup> PickupClass;

	/** Odds of each kind, in ESunderPickupKind order: Spread, Laser, Power, Bomb, Shield, Life (the web game's). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Pickups")
	TArray<float> PickupWeights = { 0.28f, 0.24f, 0.16f, 0.12f, 0.12f, 0.08f };

	/** An enemy shot down (the web game's "boom"; web/game.html sfx(), rendered to SFX_Game_Boom). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Sounds")
	TObjectPtr<class USoundBase> ExplosionSound;

	/** A Keeper's final burst, or the ship destroyed (the web game's "bigboom"). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Sounds")
	TObjectPtr<class USoundBase> BigExplosionSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Sounds")
	float ExplosionVolume = 1.f;

	/** Play an explosion: big for Keepers and the ship. A bomb's many kills in one frame play one boom, not dozens. */
	void PlayExplosion(bool bBig);

	/** Drop a pickup here with this chance (called by an enemy as it is destroyed). */
	void TrySpawnPickup(const FVector& Location, float Chance);

	/** The ship flying this time (from the hangar's choice; the first of Ships if the id isn't known). */
	const FSunderShipLoadout* GetShipLoadout() const;

	/** Swarm mode: no Keepers, the waves loop forever and come faster and faster. */
	UFUNCTION(BlueprintPure, Category = "Sunder") bool IsSwarm() const { return bSwarm; }

	/** Seconds survived in Swarm (stops at DAWN DENIED). */
	UFUNCTION(BlueprintPure, Category = "Sunder") float GetSwarmTime() const;
	/** When the last life was lost (DAWN DENIED). */
	UFUNCTION(BlueprintPure, Category = "Sunder") float GetGameOverAt() const { return GameOverAt; }

	virtual void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage) override;
	virtual APawn* SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform) override;

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AddScore(int32 Points);

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AnnounceWave(int32 Number, const FString& Name);

	/** A Keeper has arrived: its banner, its taunt and the boss bar. */
	void AnnounceKeeper(ASunderKeeper* Keeper, const FString& Title, const FString& KeeperTaunt);

	/** A Keeper is gone: the boss bar goes. */
	void ClearKeeper(ASunderKeeper* Keeper);

	/** A Keeper is beaten: the clear card (the web game's STAGE_CLEAR banner: HOUR N SURVIVED, GATE OPEN, its line). */
	void AnnounceKeeperFallen(const ASunderKeeper* Keeper);

	UFUNCTION(BlueprintPure, Category = "Sunder") float GetKeeperFallenAt() const { return FallenAt; }
	UFUNCTION(BlueprintPure, Category = "Sunder") int32 GetFallenHour() const { return FallenHour; }
	/** The Hour's name, or the Keeper's when it has none. */
	UFUNCTION(BlueprintPure, Category = "Sunder") FString GetFallenName() const { return FallenName; }
	UFUNCTION(BlueprintPure, Category = "Sunder") FString GetFallenLine() const { return FallenLine; }
	UFUNCTION(BlueprintPure, Category = "Sunder") bool HasFallenHourName() const { return bFallenHourName; }
	/** The last Keeper fell: the night is over. */
	UFUNCTION(BlueprintPure, Category = "Sunder") bool WasFinalKeeper() const { return bFallenFinal; }
	UFUNCTION(BlueprintPure, Category = "Sunder") FLinearColor GetFallenTint() const { return FallenTint; }

	UFUNCTION(BlueprintPure, Category = "Sunder") ASunderKeeper* GetActiveKeeper() const;   // in the .cpp: needs the full class
	UFUNCTION(BlueprintPure, Category = "Sunder") FString GetKeeperTitle() const { return KeeperTitle; }
	UFUNCTION(BlueprintPure, Category = "Sunder") FString GetKeeperTaunt() const { return KeeperTaunt; }
	UFUNCTION(BlueprintPure, Category = "Sunder") float GetKeeperAnnouncedAt() const { return KeeperAnnouncedAt; }

	/** Called by the ship when its hull is gone. */
	void OnShipDestroyed(ASunderShipPawn* Ship);

	UFUNCTION(BlueprintPure, Category = "Sunder") int32 GetScore() const { return Score; }
	UFUNCTION(BlueprintPure, Category = "Sunder") int32 GetLives() const { return Lives; }
	UFUNCTION(BlueprintPure, Category = "Sunder") bool IsGameOver() const { return bGameOver; }
	UFUNCTION(BlueprintPure, Category = "Sunder") int32 GetWaveNumber() const { return WaveNumber; }
	UFUNCTION(BlueprintPure, Category = "Sunder") FString GetWaveName() const { return WaveName; }
	UFUNCTION(BlueprintPure, Category = "Sunder") float GetWaveAnnouncedAt() const { return WaveAnnouncedAt; }

protected:
	virtual void BeginPlay() override;

private:
	void RestartArena();

	FString ShipId;
	float LastExplosionAt = -100.f;
	bool bSwarm = false;
	float SwarmStartedAt = 0.f;
	float SwarmEndedAt = -1.f;
	float GameOverAt = -100.f;
	FTimerHandle RespawnTimer;
	FTimerHandle RestartTimer;
	TWeakObjectPtr<ASunderKeeper> ActiveKeeper;
	FString KeeperTitle;
	FString KeeperTaunt;
	float KeeperAnnouncedAt = -100.f;
	float FallenAt = -100.f;
	int32 FallenHour = 0;
	FString FallenName;
	FString FallenLine;
	bool bFallenHourName = false;
	bool bFallenFinal = false;
	FLinearColor FallenTint = FLinearColor(1.f, 0.25f, 0.6f);
	FString WaveName;
	float WaveAnnouncedAt = -100.f;
	int32 WaveNumber = 0;
	int32 Score = 0;
	int32 Lives = 3;
	bool bGameOver = false;
};
