// SUNDER: Ascension II — the player's settings.
#include "SunderSettingsSubsystem.h"

#include "Engine/Engine.h"
#include "Engine/GameInstance.h"
#include "Engine/World.h"
#include "GameFramework/GameUserSettings.h"
#include "Misc/ConfigCacheIni.h"

namespace
{
	const TCHAR* Section = TEXT("SunderSettings");

	UGameUserSettings* Engine() { return GEngine ? GEngine->GetGameUserSettings() : nullptr; }

	// Performance modes (DESIGN.md): Fidelity = the best look at 60 fps; Performance = high settings at 120 fps.
	bool IsPerformanceMode(const UGameUserSettings* S) { return S && S->GetFrameRateLimit() > 90.f; }
}

void USunderSettingsSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	ResetKeys();
	if (!GConfig) { return; }
	for (int32 i = 0; i < (int32)ESunderControl::Count; ++i)
	{
		FString Name;
		if (GConfig->GetString(Section, *FString::Printf(TEXT("Key_%s"), *ControlLabel((ESunderControl)i).Replace(TEXT(" "), TEXT(""))), Name, GGameUserSettingsIni))
		{
			const FKey Key(*Name);
			if (CanBind(Key)) { Keys[i] = Key; }
		}
		if (HasPadButton((ESunderControl)i) && GConfig->GetString(Section,
			*FString::Printf(TEXT("Pad_%s"), *ControlLabel((ESunderControl)i).Replace(TEXT(" "), TEXT(""))), Name, GGameUserSettingsIni))
		{
			const FKey Key(*Name);
			if (CanBindPad(Key)) { PadKeys[i] = Key; }
		}
	}
	GConfig->GetInt(Section, TEXT("MusicVolume"), MusicVolume, GGameUserSettingsIni);
	GConfig->GetInt(Section, TEXT("EffectsVolume"), EffectsVolume, GGameUserSettingsIni);
	GConfig->GetBool(Section, TEXT("ShowHitbox"), bShowHitbox, GGameUserSettingsIni);
	GConfig->GetInt(Section, TEXT("ScreenShake"), ScreenShake, GGameUserSettingsIni);
	ScreenShake = FMath::Clamp(ScreenShake, 0, 2);
	GConfig->GetInt(Section, TEXT("BulletColours"), BulletColours, GGameUserSettingsIni);
	BulletColours = FMath::Clamp(BulletColours, 0, 2);
	MusicVolume = FMath::Clamp(MusicVolume, 0, 10);
	EffectsVolume = FMath::Clamp(EffectsVolume, 0, 10);
}

void USunderSettingsSubsystem::Save() const
{
	if (!GConfig) { return; }
	GConfig->SetInt(Section, TEXT("MusicVolume"), MusicVolume, GGameUserSettingsIni);
	GConfig->SetInt(Section, TEXT("EffectsVolume"), EffectsVolume, GGameUserSettingsIni);
	GConfig->SetBool(Section, TEXT("ShowHitbox"), bShowHitbox, GGameUserSettingsIni);
	GConfig->SetInt(Section, TEXT("ScreenShake"), ScreenShake, GGameUserSettingsIni);
	GConfig->SetInt(Section, TEXT("BulletColours"), BulletColours, GGameUserSettingsIni);
	for (int32 i = 0; i < Keys.Num(); ++i)
	{
		GConfig->SetString(Section, *FString::Printf(TEXT("Key_%s"), *ControlLabel((ESunderControl)i).Replace(TEXT(" "), TEXT(""))),
			*Keys[i].GetFName().ToString(), GGameUserSettingsIni);
		if (HasPadButton((ESunderControl)i))
		{
			GConfig->SetString(Section, *FString::Printf(TEXT("Pad_%s"), *ControlLabel((ESunderControl)i).Replace(TEXT(" "), TEXT(""))),
				*PadKeys[i].GetFName().ToString(), GGameUserSettingsIni);
		}
	}
	GConfig->Flush(false, GGameUserSettingsIni);
}

void USunderSettingsSubsystem::Change(ESunderSetting Setting, int32 Direction)
{
	const int32 Step = Direction < 0 ? -1 : 1;
	UGameUserSettings* S = Engine();
	switch (Setting)
	{
	case ESunderSetting::MusicVolume:   MusicVolume = FMath::Clamp(MusicVolume + Step, 0, 10); break;
	case ESunderSetting::EffectsVolume: EffectsVolume = FMath::Clamp(EffectsVolume + Step, 0, 10); break;
	case ESunderSetting::ShowHitbox:    bShowHitbox = !bShowHitbox; break;
	case ESunderSetting::ScreenShake:   ScreenShake = (ScreenShake + Step + 3) % 3; break;
	case ESunderSetting::BulletColours: BulletColours = (BulletColours + Step + 3) % 3; break;
	case ESunderSetting::WindowMode:
		if (S)
		{
			static const EWindowMode::Type Modes[] = { EWindowMode::Fullscreen, EWindowMode::WindowedFullscreen, EWindowMode::Windowed };
			int32 Index = 0;
			for (int32 i = 0; i < 3; ++i) { if (Modes[i] == S->GetFullscreenMode()) { Index = i; } }
			S->SetFullscreenMode(Modes[(Index + Step + 3) % 3]);
		}
		break;
	case ESunderSetting::Performance:
		if (S)
		{
			const bool bPerformance = !IsPerformanceMode(S);
			S->SetOverallScalabilityLevel(bPerformance ? 2 : 3);   // High : Epic
			S->SetFrameRateLimit(bPerformance ? 120.f : 60.f);
		}
		break;
	case ESunderSetting::VSync:
		if (S) { S->SetVSyncEnabled(!S->IsVSyncEnabled()); }
		break;
	default:
		return;
	}
	if (Setting == ESunderSetting::WindowMode || Setting == ESunderSetting::Performance || Setting == ESunderSetting::VSync)
	{
		if (S) { S->ApplySettings(false); }                   // applies and saves the engine's own settings
	}
	else
	{
		Save();
	}
}

FString USunderSettingsSubsystem::Describe(ESunderSetting Setting) const
{
	const UGameUserSettings* S = Engine();
	auto Bar = [](int32 V) { return FString::ChrN(V, TEXT('|')) + FString::ChrN(10 - V, TEXT('.')) + FString::Printf(TEXT("  %d"), V); };
	switch (Setting)
	{
	case ESunderSetting::MusicVolume:   return Bar(MusicVolume);
	case ESunderSetting::EffectsVolume: return Bar(EffectsVolume);
	case ESunderSetting::ShowHitbox:    return bShowHitbox ? TEXT("ON") : TEXT("OFF");
	case ESunderSetting::ScreenShake:   return ScreenShake == 0 ? TEXT("OFF") : ScreenShake == 1 ? TEXT("LOW") : TEXT("FULL");
	case ESunderSetting::BulletColours: return BulletColours == 0 ? TEXT("STANDARD") : BulletColours == 1 ? TEXT("RED-GREEN SAFE") : TEXT("BLUE-YELLOW SAFE");
	case ESunderSetting::WindowMode:
		if (!S) { return TEXT("-"); }
		switch (S->GetFullscreenMode())
		{
		case EWindowMode::Fullscreen:         return TEXT("FULLSCREEN");
		case EWindowMode::WindowedFullscreen: return TEXT("BORDERLESS");
		default:                              return TEXT("WINDOWED");
		}
	case ESunderSetting::Performance: return IsPerformanceMode(S) ? TEXT("PERFORMANCE  (120 FPS)") : TEXT("FIDELITY  (60 FPS)");
	case ESunderSetting::VSync:       return S && S->IsVSyncEnabled() ? TEXT("ON") : TEXT("OFF");
	case ESunderSetting::Controls:    return TEXT("KEYBOARD");
	default:                          return FString();
	}
}

FString USunderSettingsSubsystem::Label(ESunderSetting Setting)
{
	switch (Setting)
	{
	case ESunderSetting::MusicVolume:   return TEXT("MUSIC");
	case ESunderSetting::EffectsVolume: return TEXT("EFFECTS");
	case ESunderSetting::WindowMode:    return TEXT("DISPLAY");
	case ESunderSetting::Performance:   return TEXT("MODE");
	case ESunderSetting::VSync:         return TEXT("VSYNC");
	case ESunderSetting::ScreenShake:   return TEXT("SCREEN SHAKE");
	case ESunderSetting::BulletColours: return TEXT("BULLET COLOURS");
	case ESunderSetting::Controls:      return TEXT("CONTROLS");
	case ESunderSetting::ShowHitbox:    return TEXT("SHOW HITBOX");
	default:                            return TEXT("BACK");
	}
}

float USunderSettingsSubsystem::MusicGain(const UObject* WorldContext)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	const USunderSettingsSubsystem* Self = GI ? GI->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	return Self ? Self->MusicVolume / 10.f : 1.f;
}

FKey USunderSettingsSubsystem::DefaultKey(ESunderControl Control)
{
	switch (Control)                                          // the arena's keys before remapping (as the web game's)
	{
	case ESunderControl::MoveUp:    return EKeys::W;
	case ESunderControl::MoveDown:  return EKeys::S;
	case ESunderControl::MoveLeft:  return EKeys::A;
	case ESunderControl::MoveRight: return EKeys::D;
	case ESunderControl::Beam:      return EKeys::SpaceBar;
	case ESunderControl::Shoot:     return EKeys::J;
	case ESunderControl::Bomb:      return EKeys::X;
	case ESunderControl::Pause:     return EKeys::P;
	default:                        return EKeys::Invalid;
	}
}

FString USunderSettingsSubsystem::ControlLabel(ESunderControl Control)
{
	switch (Control)
	{
	case ESunderControl::MoveUp:    return TEXT("MOVE UP");
	case ESunderControl::MoveDown:  return TEXT("MOVE DOWN");
	case ESunderControl::MoveLeft:  return TEXT("MOVE LEFT");
	case ESunderControl::MoveRight: return TEXT("MOVE RIGHT");
	case ESunderControl::Beam:      return TEXT("BEAM");
	case ESunderControl::Shoot:     return TEXT("SHOOT");
	case ESunderControl::Bomb:      return TEXT("BOMB");
	case ESunderControl::Pause:     return TEXT("PAUSE");
	default:                        return FString();
	}
}

bool USunderSettingsSubsystem::CanBind(const FKey& Key)
{
	return Key.IsValid() && !Key.IsGamepadKey() && !Key.IsMouseButton() && !Key.IsAxis1D() && !Key.IsAxis2D()
		&& Key != EKeys::Escape && Key != EKeys::AnyKey;
}

FString USunderSettingsSubsystem::KeyName(const FKey& Key)
{
	return Key.IsValid() ? Key.GetDisplayName().ToString().ToUpper() : TEXT("-");
}

FKey USunderSettingsSubsystem::GetKey(ESunderControl Control) const
{
	return Keys.IsValidIndex((int32)Control) ? Keys[(int32)Control] : DefaultKey(Control);
}

void USunderSettingsSubsystem::SetKey(ESunderControl Control, const FKey& Key)
{
	const int32 Index = (int32)Control;
	if (!Keys.IsValidIndex(Index) || !CanBind(Key)) { return; }
	const int32 Other = Keys.IndexOfByKey(Key);
	if (Other != INDEX_NONE && Other != Index) { Keys[Other] = Keys[Index]; }   // swap, so nothing is left unbound
	Keys[Index] = Key;
	Save();
}

void USunderSettingsSubsystem::ResetKeys()
{
	Keys.SetNum((int32)ESunderControl::Count);
	PadKeys.SetNum((int32)ESunderControl::Count);
	for (int32 i = 0; i < Keys.Num(); ++i)
	{
		Keys[i] = DefaultKey((ESunderControl)i);
		PadKeys[i] = DefaultPadKey((ESunderControl)i);
	}
}

bool USunderSettingsSubsystem::HasPadButton(ESunderControl Control)
{
	return Control == ESunderControl::Beam || Control == ESunderControl::Shoot || Control == ESunderControl::Bomb
		|| Control == ESunderControl::Pause;
}

FKey USunderSettingsSubsystem::DefaultPadKey(ESunderControl Control)
{
	switch (Control)                                          // the arena's pad layout before remapping
	{
	case ESunderControl::Beam:  return EKeys::Gamepad_RightTrigger;
	case ESunderControl::Shoot: return EKeys::Gamepad_FaceButton_Bottom;
	case ESunderControl::Bomb:  return EKeys::Gamepad_FaceButton_Top;
	case ESunderControl::Pause: return EKeys::Gamepad_Special_Right;
	default:                    return EKeys::Invalid;
	}
}

bool USunderSettingsSubsystem::CanBindPad(const FKey& Key)
{
	if (!Key.IsValid() || !Key.IsGamepadKey() || Key.IsAxis1D() || Key.IsAxis2D()) { return false; }
	if (Key == EKeys::Gamepad_Special_Left) { return false; }                   // Back / View cancels a rebind
	return !Key.GetFName().ToString().Contains(TEXT("Stick_"));                 // stick directions stay for moving
}

FKey USunderSettingsSubsystem::GetPadKey(ESunderControl Control) const
{
	return PadKeys.IsValidIndex((int32)Control) ? PadKeys[(int32)Control] : DefaultPadKey(Control);
}

void USunderSettingsSubsystem::SetPadKey(ESunderControl Control, const FKey& Key)
{
	const int32 Index = (int32)Control;
	if (!PadKeys.IsValidIndex(Index) || !HasPadButton(Control) || !CanBindPad(Key)) { return; }
	const int32 Other = PadKeys.IndexOfByKey(Key);
	if (Other != INDEX_NONE && Other != Index) { PadKeys[Other] = PadKeys[Index]; }   // swap
	PadKeys[Index] = Key;
	Save();
}

FString USunderSettingsSubsystem::PadName(const FKey& Key)
{
	static const TMap<FKey, FString> Names = {
		{ EKeys::Gamepad_FaceButton_Bottom, TEXT("A") }, { EKeys::Gamepad_FaceButton_Right, TEXT("B") },
		{ EKeys::Gamepad_FaceButton_Left, TEXT("X") }, { EKeys::Gamepad_FaceButton_Top, TEXT("Y") },
		{ EKeys::Gamepad_LeftShoulder, TEXT("LB") }, { EKeys::Gamepad_RightShoulder, TEXT("RB") },
		{ EKeys::Gamepad_LeftTrigger, TEXT("LT") }, { EKeys::Gamepad_RightTrigger, TEXT("RT") },
		{ EKeys::Gamepad_DPad_Up, TEXT("D-PAD UP") }, { EKeys::Gamepad_DPad_Down, TEXT("D-PAD DOWN") },
		{ EKeys::Gamepad_DPad_Left, TEXT("D-PAD LEFT") }, { EKeys::Gamepad_DPad_Right, TEXT("D-PAD RIGHT") },
		{ EKeys::Gamepad_LeftThumbstick, TEXT("L3") }, { EKeys::Gamepad_RightThumbstick, TEXT("R3") },
		{ EKeys::Gamepad_Special_Right, TEXT("START") }, { EKeys::Gamepad_Special_Left, TEXT("BACK") } };
	if (const FString* Name = Names.Find(Key)) { return *Name; }
	return Key.IsValid() ? Key.GetDisplayName().ToString().ToUpper() : TEXT("LEFT STICK");
}

const USunderSettingsSubsystem* USunderSettingsSubsystem::Get(const UObject* WorldContext)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	return GI ? GI->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
}

void USunderSettingsSubsystem::PaletteFor(int32 Mode, FLinearColor& OutEnemy, FLinearColor& OutPlayer)
{
	switch (Mode)
	{
	case 1:  // protanopia / deuteranopia: orange against sky blue (Okabe–Ito #E69F00 / #56B4E9)
		OutEnemy = FLinearColor(3.5f, 1.53f, 0.f);
		OutPlayer = FLinearColor(0.4f, 1.96f, 3.5f);
		break;
	case 2:  // tritanopia: vermillion against sky blue (Okabe–Ito #D55E00 / #56B4E9)
		OutEnemy = FLinearColor(3.5f, 0.59f, 0.f);
		OutPlayer = FLinearColor(0.4f, 1.96f, 3.5f);
		break;
	default: // the game's own: the enemy shot's violet, the Sunborn's gold
		OutEnemy = FLinearColor(1.3f, 0.12f, 2.7f);
		OutPlayer = FLinearColor(3.0f, 2.1f, 0.6f);
		break;
	}
}

bool USunderSettingsSubsystem::BulletPalette(const UObject* WorldContext, FLinearColor& OutEnemy, FLinearColor& OutPlayer)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	const USunderSettingsSubsystem* Self = GI ? GI->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	if (!Self || Self->BulletColours == 0) { return false; }
	PaletteFor(Self->BulletColours, OutEnemy, OutPlayer);
	return true;
}

float USunderSettingsSubsystem::ShakeScale(const UObject* WorldContext)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	const USunderSettingsSubsystem* Self = GI ? GI->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	return Self ? Self->ScreenShake * 0.5f : 1.f;
}

float USunderSettingsSubsystem::EffectsGain(const UObject* WorldContext)
{
	const UWorld* World = WorldContext ? WorldContext->GetWorld() : nullptr;
	const UGameInstance* GI = World ? World->GetGameInstance() : nullptr;
	const USunderSettingsSubsystem* Self = GI ? GI->GetSubsystem<USunderSettingsSubsystem>() : nullptr;
	return Self ? Self->EffectsVolume / 10.f : 1.f;
}
