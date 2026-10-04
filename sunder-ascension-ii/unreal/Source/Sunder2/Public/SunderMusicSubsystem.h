// SUNDER: Ascension II — layered music, like the web game's keeper_audio.js engine.
// A theme is up to three same-length loops (the renders in unreal/Content/Audio/Keepers/Music: layer 1 held back,
// 2 full, 3 doubled) started together; only the chosen layer is heard, and changing layer crossfades in step.
// Voices duck the music (Duck) the way the web game's cues do. One theme at a time; starting another fades the old out.
// It also carries the current stage's sound (SetStage): its ambience bed, its theme (PlayStageMusic) and its cues.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "SunderStageAudio.h"
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

	/** Enter a stage: its ambience fades in (the old one out). Its theme and cues are then played by the calls below. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void SetStage(USunderStageAudio* Stage);

	UFUNCTION(BlueprintPure, Category = "Sunder|Music")
	USunderStageAudio* GetStage() const { return Stage; }

	/** The stage's theme at this layer: started if another theme (or none) is playing, else crossfaded to the layer. */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void PlayStageMusic(int32 InLayer);

	/** One of the stage's cues (rate-limited like the web game's; Start ducks the music). */
	UFUNCTION(BlueprintCallable, Category = "Sunder|Music")
	void PlayStageCue(ESunderStageCue Cue);

	/** Ambience level (the renders already carry the web game's 0.65 ambience bus). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float AmbienceVolume = 1.f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float CueVolume = 1.f;

	UFUNCTION(BlueprintPure, Category = "Sunder|Music")
	int32 GetLayer() const { return Layer; }

	/** Music level (the renders already carry the web game's 0.85 music bus, so 1 matches it). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float MusicVolume = 1.f;

	/** Level while ducked, as a fraction of MusicVolume (the web game's 0.4 of 0.85). */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sunder|Music")
	float DuckLevel = 0.47f;

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

	UPROPERTY(Transient)
	TObjectPtr<USunderStageAudio> Stage;

	UPROPERTY(Transient)
	TObjectPtr<UAudioComponent> AmbienceComponent;

	TWeakObjectPtr<USoundBase> CurrentTheme;        // first layer of the playing theme
	float LastCueTime[4] = { -100.f, -100.f, -100.f, -100.f };
	TArray<FTrack> Current;
	TArray<FTrack> Fading;                          // the previous theme, fading out
	int32 Layer = 1;
	float StartDelay = 0.f;
	bool bStarted = false;
	float DuckGain = 1.f;
	float DuckHold = 0.f;
};
