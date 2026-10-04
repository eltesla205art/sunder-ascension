// SUNDER: Ascension II — game mode for the arena: the ship as the default pawn, score, lives, respawns, the wave
// banner, and DAWN DENIED (then a restart) when the last life is lost. BP_SunderGameMode points the pawn at BP_SunderShip.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SunderGameMode.generated.h"

class ASunderShipPawn;
class ASunderKeeper;

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

	/** After DAWN DENIED, go to this level (the title screen, L_SunderTitle) instead of restarting the arena; None = restart. */
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Sunder")
	FName MenuLevel;

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AddScore(int32 Points);

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AnnounceWave(int32 Number, const FString& Name);

	/** A Keeper has arrived: its banner, its taunt and the boss bar. */
	void AnnounceKeeper(ASunderKeeper* Keeper, const FString& Title, const FString& KeeperTaunt);

	/** A Keeper is gone: the boss bar goes. */
	void ClearKeeper(ASunderKeeper* Keeper);

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

	FTimerHandle RespawnTimer;
	FTimerHandle RestartTimer;
	TWeakObjectPtr<ASunderKeeper> ActiveKeeper;
	FString KeeperTitle;
	FString KeeperTaunt;
	float KeeperAnnouncedAt = -100.f;
	FString WaveName;
	float WaveAnnouncedAt = -100.f;
	int32 WaveNumber = 0;
	int32 Score = 0;
	int32 Lives = 3;
	bool bGameOver = false;
};
