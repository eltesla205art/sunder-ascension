// SUNDER: Ascension II — game mode for the arena.
#include "SunderGameMode.h"

#include "Engine/World.h"
#include "Kismet/GameplayStatics.h"
#include "SunderHUD.h"
#include "SunderKeeper.h"
#include "SunderShipPawn.h"
#include "Engine/GameInstance.h"
#include "SunderMusicSubsystem.h"
#include "SunderStorySubsystem.h"
#include "SunderLoadoutSubsystem.h"
#include "SunderPickup.h"
#include "Sound/SoundBase.h"
#include "TimerManager.h"

ASunderGameMode::ASunderGameMode()
{
	DefaultPawnClass = ASunderShipPawn::StaticClass();       // BP_SunderGameMode points this at BP_SunderShip
	HUDClass = ASunderHUD::StaticClass();
	PickupClass = ASunderPickup::StaticClass();

	// The web game's ships (web/game.html SHIPS) at power level 1, scaled to the Unreal ship's units: the Sunborn is the
	// baseline (950 speed, 5 hull, 0.09 s twin shots of 10 at 2200); the others keep the web game's ratios to it.
	auto Ship = [this](const TCHAR* Id, const TCHAR* Name, ESunderShotStyle Style, float Speed, float Hull, float Interval,
		float Damage, float ShotSpeed, float ShotScale, const FLinearColor& Color, const FLinearColor& Tint, float Body)
	{
		FSunderShipLoadout& L = Ships.AddDefaulted_GetRef();
		L.Id = Id; L.Name = Name; L.Style = Style; L.MoveSpeed = Speed; L.MaxHealth = Hull; L.FireInterval = Interval;
		L.ShotDamage = Damage; L.ShotSpeed = ShotSpeed; L.ShotScale = ShotScale; L.SpreadAngle = 6.f;
		L.Color = Color; L.Tint = Tint; L.BodyScale = Body;
		return &L;
	};
	//    id         name                  style                          speed   hull  every   dmg   shot   size
	FSunderShipLoadout* S = Ship(TEXT("sunborn"), TEXT("SUNBORN THUNDER"), ESunderShotStyle::TwinSpread, 950.f, 5.f, 0.09f, 10.f, 2200.f, 1.0f,
		FLinearColor(3.0f, 2.1f, 0.6f), FLinearColor(0.79f, 0.54f, 0.08f), 1.0f);    // 320 px/s, 3 hull, 0.14 s, ±6°
	S->Accent = FLinearColor(0.92f, 2.43f, 3.5f);   // #8CD9FF
	S->StartBombs = 3; S->FormNames = { TEXT("Falcon"), TEXT("Rising Falcon"), TEXT("Solar Horus") }; S->FormScales = { 1.f, 1.05f, 1.12f };
	S = Ship(TEXT("scarab"), TEXT("SCARAB WARBRINGER"), ESunderShotStyle::HeavyCannon, 742.f, 7.f, 0.129f, 30.f, 1925.f, 1.6f,
		FLinearColor(4.0f, 0.7f, 0.3f), FLinearColor(0.69f, 0.05f, 0.03f), 1.1f);    // 250, 4 hull, 0.20 s, 3-damage cannon
	S->Accent = FLinearColor(3.5f, 0.92f, 0.12f);   // #FF8C33
	S->StartBombs = 4; S->FormNames = { TEXT("Scarab"), TEXT("Armored Scarab"), TEXT("Khnum Ram") }; S->FormScales = { 1.f, 1.073f, 1.164f };
	S = Ship(TEXT("ibis"), TEXT("IBIS PHANTOM"), ESunderShotStyle::RapidStream, 1188.f, 3.f, 0.058f, 10.f, 2681.f, 0.8f,
		FLinearColor(0.6f, 3.6f, 1.4f), FLinearColor(0.07f, 0.69f, 0.22f), 0.92f);   // 400, 2 hull, 0.09 s, fast stream
	S->Accent = FLinearColor(1.82f, 3.5f, 2.43f);   // #BFFFD9
	S->StartBombs = 3; S->FormNames = { TEXT("Ibis"), TEXT("Twin Ibis"), TEXT("Thoth Ascendant") }; S->FormScales = { 1.f, 1.043f, 1.087f };
}

void ASunderGameMode::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options, ErrorMessage);
	UGameInstance* GI = GetGameInstance();
	USunderLoadoutSubsystem* Loadout = GI ? GI->GetSubsystem<USunderLoadoutSubsystem>() : nullptr;
	if (!Loadout) { return; }
	Loadout->ReadOptions(Options);                           // ?Ship= / ?Mode= on the URL win over the stored choice
	ShipId = Loadout->GetShipId();
	const USunderStorySubsystem* Story = GI->GetSubsystem<USunderStorySubsystem>();
	bSwarm = Loadout->GetMode() == ESunderPlayMode::Swarm && !(Story && Story->IsActive());
}

const FSunderShipLoadout* ASunderGameMode::GetShipLoadout() const
{
	for (const FSunderShipLoadout& L : Ships) { if (L.Id.Equals(ShipId, ESearchCase::IgnoreCase)) { return &L; } }
	return Ships.Num() > 0 ? &Ships[0] : nullptr;
}

APawn* ASunderGameMode::SpawnDefaultPawnAtTransform_Implementation(AController* NewPlayer, const FTransform& SpawnTransform)
{
	APawn* Pawn = Super::SpawnDefaultPawnAtTransform_Implementation(NewPlayer, SpawnTransform);
	if (ASunderShipPawn* ShipPawn = Cast<ASunderShipPawn>(Pawn))
	{
		if (const FSunderShipLoadout* L = GetShipLoadout()) { ShipPawn->ApplyLoadout(*L); }
		// Story mode: the ship arrives as it left the last Hour (its forms, weapon, bombs, shields and hull).
		const USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
		if (Story && Story->IsActive() && Story->HasCarriedShip()) { ShipPawn->ApplyState(Story->GetCarriedShip()); }
	}
	return Pawn;
}

void ASunderGameMode::PlayExplosion(bool bBig)
{
	USoundBase* Sound = bBig ? BigExplosionSound.Get() : ExplosionSound.Get();
	if (!Sound) { return; }
	const float Now = GetWorld()->GetTimeSeconds();
	if (!bBig && Now - LastExplosionAt < 0.03f) { return; }   // a bomb's sweep: one boom per frame or two, not one per kill
	if (!bBig) { LastExplosionAt = Now; }
	UGameplayStatics::PlaySound2D(this, Sound, ExplosionVolume);
}

void ASunderGameMode::TrySpawnPickup(const FVector& Location, float Chance)
{
	if (bGameOver || !PickupClass || FMath::FRand() >= Chance) { return; }
	float Total = 0.f;
	for (const float W : PickupWeights) { Total += FMath::Max(W, 0.f); }
	if (Total <= 0.f) { return; }
	float Roll = FMath::FRand() * Total;
	int32 Kind = 0;
	for (; Kind < PickupWeights.Num() - 1; ++Kind)
	{
		Roll -= FMath::Max(PickupWeights[Kind], 0.f);
		if (Roll < 0.f) { break; }
	}
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	if (ASunderPickup* Pickup = GetWorld()->SpawnActor<ASunderPickup>(PickupClass, Location, FRotator::ZeroRotator, Params))
	{
		Pickup->SetKind(static_cast<ESunderPickupKind>(FMath::Clamp(Kind, 0, 5)));
	}
}

float ASunderGameMode::GetSwarmTime() const
{
	if (!bSwarm) { return 0.f; }
	return (SwarmEndedAt >= 0.f ? SwarmEndedAt : GetWorld()->GetTimeSeconds()) - SwarmStartedAt;
}

void ASunderGameMode::BeginPlay()
{
	Super::BeginPlay();
	Lives = StartingLives;
	SwarmStartedAt = GetWorld()->GetTimeSeconds();
	Score = 0;
	bGameOver = false;
}

void ASunderGameMode::AddScore(int32 Points)
{
	if (!bGameOver) { Score += Points; }
}

void ASunderGameMode::AnnounceWave(int32 Number, const FString& Name)
{
	WaveNumber = Number;
	WaveName = Name;
	WaveAnnouncedAt = GetWorld()->GetTimeSeconds();
}

void ASunderGameMode::AnnounceKeeper(ASunderKeeper* Keeper, const FString& Title, const FString& InTaunt)
{
	ActiveKeeper = Keeper;
	KeeperTitle = Title;
	KeeperTaunt = InTaunt;
	KeeperAnnouncedAt = GetWorld()->GetTimeSeconds();
}

void ASunderGameMode::AnnounceKeeperFallen(const ASunderKeeper* Keeper)
{
	if (!Keeper) { return; }
	FallenAt = GetWorld()->GetTimeSeconds();
	FallenHour = Keeper->Hour;
	bFallenHourName = !Keeper->HourName.IsEmpty();
	FallenName = bFallenHourName ? Keeper->HourName : Keeper->KeeperName;
	FallenLine = Keeper->ClearLine;
	bFallenFinal = Keeper->bFinalKeeper;
	const FLinearColor& C = Keeper->KeeperColor;             // its Hour's colour, brought down from HDR for text
	const float Peak = FMath::Max3(C.R, C.G, C.B);
	if (Peak > 0.f) { FallenTint = FLinearColor(C.R / Peak, C.G / Peak, C.B / Peak); }
}

ASunderKeeper* ASunderGameMode::GetActiveKeeper() const
{
	return ActiveKeeper.Get();
}

void ASunderGameMode::ClearKeeper(ASunderKeeper* Keeper)
{
	if (ActiveKeeper.Get() == Keeper) { ActiveKeeper.Reset(); }
}

void ASunderGameMode::OnShipDestroyed(ASunderShipPawn* Ship)
{
	if (bGameOver || !Ship) { return; }
	PlayExplosion(true);                                     // the web game's "bigboom" as the ship goes
	Lives = FMath::Max(Lives - 1, 0);
	if (Lives > 0)
	{
		GetWorldTimerManager().SetTimer(RespawnTimer,
			FTimerDelegate::CreateWeakLambda(Ship, [Ship]() { Ship->Respawn(); }), RespawnDelay, false);
	}
	else
	{
		bGameOver = true;
		GameOverAt = GetWorld()->GetTimeSeconds();
		if (bSwarm) { SwarmEndedAt = GetWorld()->GetTimeSeconds(); }
		if (ASunderKeeper* Keeper = GetActiveKeeper()) { Keeper->Gloat(); }   // the Keeper has the last word
		GetWorldTimerManager().SetTimer(RestartTimer, this, &ASunderGameMode::RestartArena, RestartDelay, false);
	}
}

void ASunderGameMode::RestartArena()
{
	USunderStorySubsystem* Story = GetGameInstance() ? GetGameInstance()->GetSubsystem<USunderStorySubsystem>() : nullptr;
	if (Story && Story->IsActive())
	{
		// DAWN DENIED, in the story: its theme comes in at the weight the fight had reached.
		const USunderMusicSubsystem* Music = GetWorld()->GetSubsystem<USunderMusicSubsystem>();
		Story->ReportDefeat(this, Score, ActiveKeeper.IsValid() ? 3 : (Music ? Music->GetLayer() : 1));
		return;
	}
	UGameplayStatics::OpenLevel(this, MenuLevel.IsNone() ? FName(*UGameplayStatics::GetCurrentLevelName(this)) : MenuLevel);
}
