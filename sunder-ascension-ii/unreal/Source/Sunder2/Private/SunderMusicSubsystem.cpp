// SUNDER: Ascension II — layered music.
#include "SunderMusicSubsystem.h"

#include "Components/AudioComponent.h"
#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundBase.h"
#include "SunderSettingsSubsystem.h"

namespace
{
	constexpr float SilentGain = 0.001f;   // -60 dB: unheard, but never zero so a silent layer keeps playing in step
}

bool USunderMusicSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

TStatId USunderMusicSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(USunderMusicSubsystem, STATGROUP_Tickables);
}

void USunderMusicSubsystem::PlayLayered(const TArray<USoundBase*>& Layers, int32 InLayer, float Delay)
{
	// The old theme fades out quickly underneath.
	for (FTrack& Track : Current) { Track.Target = 0.f; Track.Rate = 1.f / 0.3f; Fading.Add(Track); }
	Current.Reset();

	Layer = FMath::Clamp(InLayer, 1, FMath::Max(Layers.Num(), 1));
	CurrentTheme = Layers.Num() > 0 ? Layers[0] : nullptr;
	for (int32 i = 0; i < Layers.Num(); ++i)
	{
		if (!Layers[i]) { continue; }
		UAudioComponent* Component = UGameplayStatics::CreateSound2D(this, Layers[i], 1.f, 1.f, 0.f, nullptr,
			/*bPersistAcrossLevelTransition*/ false, /*bAutoDestroy*/ false);
		if (!Component) { continue; }
		Component->SetVolumeMultiplier(SilentGain);
		Owned.Add(Component);
		FTrack Track;
		Track.Component = Component;
		Track.Gain = i + 1 == Layer ? 1.f : 0.f;          // starts on its layer at once, like the web game
		Track.Target = Track.Gain;
		Current.Add(Track);
	}
	StartDelay = FMath::Max(Delay, 0.f);
	bStarted = false;
	if (StartDelay <= 0.f) { Tick(0.f); }               // start every layer in this same frame, so they stay in step
}

void USunderMusicSubsystem::SetLayer(int32 InLayer, float Crossfade)
{
	if (Current.Num() == 0) { return; }
	Layer = FMath::Clamp(InLayer, 1, Current.Num());
	for (int32 i = 0; i < Current.Num(); ++i)
	{
		Current[i].Target = i + 1 == Layer ? 1.f : 0.f;
		Current[i].Rate = 1.f / FMath::Max(Crossfade, 0.01f);
	}
}

void USunderMusicSubsystem::StopMusic(float FadeOut)
{
	CurrentTheme.Reset();
	for (FTrack& Track : Current) { Track.Target = 0.f; Track.Rate = 1.f / FMath::Max(FadeOut, 0.01f); Fading.Add(Track); }
	Current.Reset();
}

void USunderMusicSubsystem::SetStage(USunderStageAudio* InStage)
{
	if (InStage == Stage) { return; }
	Stage = InStage;
	if (AmbienceComponent)
	{
		AmbienceComponent->bAutoDestroy = true;                 // fades out, then cleans itself up
		AmbienceComponent->FadeOut(0.8f, 0.f);
		AmbienceComponent = nullptr;
	}
	if (Stage && Stage->Ambience)
	{
		AmbienceComponent = UGameplayStatics::CreateSound2D(this, Stage->Ambience, AmbienceVolume, 1.f, 0.f, nullptr,
			/*bPersistAcrossLevelTransition*/ false, /*bAutoDestroy*/ false);
		if (AmbienceComponent) { AmbienceComponent->FadeIn(1.5f, AmbienceVolume); }   // the web game's 1.5 s bed fade
	}
}

void USunderMusicSubsystem::PlayStageMusic(int32 InLayer)
{
	if (!Stage || Stage->MusicLayers.Num() == 0) { return; }
	if (Current.Num() > 0 && CurrentTheme.Get() == Stage->MusicLayers[0].Get())
	{
		if (InLayer != Layer) { SetLayer(InLayer); }
		return;
	}
	TArray<USoundBase*> Layers(Stage->MusicLayers);
	PlayLayered(Layers, InLayer);
}

void USunderMusicSubsystem::PlayStageCue(ESunderStageCue Cue)
{
	if (!Stage) { return; }
	USoundBase* Sound = nullptr;
	float MinGap = 0.f;
	switch (Cue)
	{
	case ESunderStageCue::Start: Sound = Stage->StartSound; break;
	case ESunderStageCue::Wave:  Sound = Stage->WaveSound; MinGap = 1.5f; break;
	case ESunderStageCue::Down:  Sound = Stage->DownSound; MinGap = 0.12f; break;
	case ESunderStageCue::Clear: Sound = Stage->ClearSound; break;
	}
	if (!Sound) { return; }
	const float Now = GetWorld()->GetTimeSeconds();
	float& Last = LastCueTime[(int32)Cue];
	if (MinGap > 0.f && Now - Last < MinGap) { return; }    // a barrage of kills mustn't become noise
	Last = Now;
	UGameplayStatics::PlaySound2D(this, Sound, CueVolume * USunderSettingsSubsystem::EffectsGain(this));
	if (Cue == ESunderStageCue::Start) { Duck(Sound->GetDuration() * 0.7f); }
}

void USunderMusicSubsystem::Duck(float Seconds)
{
	DuckHold = FMath::Max(DuckHold, Seconds);
}

void USunderMusicSubsystem::Apply(FTrack& Track, float DeltaTime, float Bus)
{
	Track.Gain = FMath::FInterpConstantTo(Track.Gain, Track.Target, DeltaTime, Track.Rate);
	if (Track.Component) { Track.Component->SetVolumeMultiplier(FMath::Max(Track.Gain * Bus, SilentGain)); }
}

void USunderMusicSubsystem::Release(TArray<FTrack>& Tracks)
{
	for (FTrack& Track : Tracks) { if (Track.Component) { Track.Component->Stop(); Track.Component->DestroyComponent(); } }
	Tracks.Reset();
}

void USunderMusicSubsystem::Tick(float DeltaTime)
{
	// The duck: down to DuckLevel in 0.08 s, hold, back up over 0.6 s.
	if (DuckHold > 0.f)
	{
		DuckHold -= DeltaTime;
		DuckGain = FMath::FInterpConstantTo(DuckGain, DuckLevel, DeltaTime, 1.f / 0.08f);
	}
	else
	{
		DuckGain = FMath::FInterpConstantTo(DuckGain, 1.f, DeltaTime, 1.f / 0.6f);
	}
	const float Bus = MusicVolume * DuckGain * USunderSettingsSubsystem::MusicGain(this);   // the player's music volume
	if (AmbienceComponent) { AmbienceComponent->SetVolumeMultiplier(FMath::Max(AmbienceVolume * USunderSettingsSubsystem::MusicGain(this), SilentGain)); }

	if (!bStarted && Current.Num() > 0)
	{
		StartDelay -= DeltaTime;
		if (StartDelay <= 0.f)
		{
			bStarted = true;
			for (FTrack& Track : Current) { if (Track.Component) { Track.Component->Play(); } }
		}
	}
	for (FTrack& Track : Current) { Apply(Track, DeltaTime, Bus); }

	for (FTrack& Track : Fading) { Apply(Track, DeltaTime, Bus); }
	TArray<FTrack> Done;
	Fading.RemoveAll([&Done](const FTrack& Track) { if (Track.Gain <= 0.f) { Done.Add(Track); return true; } return false; });
	for (const FTrack& Track : Done) { Owned.Remove(Track.Component); }
	Release(Done);
}

void USunderMusicSubsystem::Deinitialize()
{
	Release(Current);
	Release(Fading);
	if (AmbienceComponent) { AmbienceComponent->Stop(); AmbienceComponent = nullptr; }
	Stage = nullptr;
	Owned.Reset();
	Super::Deinitialize();
}
