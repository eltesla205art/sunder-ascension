// SUNDER: Ascension II — layered music, like the web game's keeper_audio.js engine.
// A theme is up to three same-length loops (the renders in unreal/Content/Audio/Keepers/Music: layer 1 held back,
// 2 full, 3 doubled) started together; only the chosen layer is heard, and changing layer crossfades in step.
// Voices duck the music (Duck) the way the web game's cues do. One theme at a time; starting another fades the old out.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SunderMusicSubsystem.generated.h"

class UAudioComponent;
class USoundBase;

UCLASS()
class SUNDER2_API USunderMusicSubsystem : public UTickableWorldSubsystem
{
	GENERATED_BODY()

public:
	/** Start a layered theme (its loops must be the same length). Layer is 1-based; Delay = seconds of silence first. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void PlayLayered(const TArray<USoundBase*>& Layers, int32 Layer = 1, float Delay = 0.f);

	/** Crossfade to another layer of the playing theme (1-based, clamped to the layers it has). */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void SetLayer(int32 Layer, float Crossfade = 0.25f);

	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void StopMusic(float FadeOut = 1.5f);

	/** The music steps back to DuckLevel for Seconds, then returns over 0.6 s. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void Duck(float Seconds);

	UFUNCTION(BlueprintPure, Category = "Sunder|Music")
	bool IsPlaying() const { return Current.Num() > 0; }

	UFUNCTION(BlueprintPure, Category = "Sunder|Music")
	int32 GetLayer() const { return Layer; }

	/** Music level (the web game's music bus: 0.85). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float MusicVolume = 0.85f;

	/** Level while ducked (the web game's 0.4). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float DuckLevel = 0.4f;

	virtual void Tick(float DeltaTime) override;
	virtual TStatId GetStatId() const override;
	virtual void Deinitialize() override;

protected:
	virtual bool DoesSupportWorldType(const EWorldType::Type WorldType) const override;

private:
	struct FTrack
	{
		TObjectPtr<UAudioComponent> Component;
		float Gain = 0.f;      // this layer's own fade, 0..1
		float Target = 0.f;
		float Rate = 4.f;      // gain per second
	};

	void Apply(FTrack& Track, float DeltaTime, float Bus);
	static void Release(TArray<FTrack>& Tracks);

	UPROPERTY(Transient)
	TArray<TObjectPtr<UAudioComponent>> Owned;     // keeps the components alive between ticks

	TArray<FTrack> Current;
	TArray<FTrack> Fading;                          // the previous theme, fading out
	int32 Layer = 1;
	float StartDelay = 0.f;
	bool bStarted = false;
	float DuckGain = 1.f;
	float DuckHold = 0.f;
};
