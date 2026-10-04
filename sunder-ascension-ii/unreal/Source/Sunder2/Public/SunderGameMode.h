// SUNDER: Ascension II — game mode for the arena: the ship as the default pawn, score, lives, respawns, the wave
// banner, and DAWN DENIED (then a restart) when the last life is lost. BP_SunderGameMode points the pawn at BP_SunderShip.
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SunderGameMode.generated.h"

class ASunderShipPawn;

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

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AddScore(int32 Points);

	UFUNCTION(BlueprintCallable, Category = "Sunder")
	void AnnounceWave(int32 Number, const FString& Name);

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
	FString WaveName;
	float WaveAnnouncedAt = -100.f;
	int32 WaveNumber = 0;
	int32 Score = 0;
	int32 Lives = 3;
	bool bGameOver = false;
};
