// SUNDER: Ascension II — impact effects that merge and throttle (see unreal/WEAPON_VFX.md §3.2).
#include "ImpactFXSubsystem.h"

#include "Engine/World.h"
#include "NiagaraComponent.h"
#include "NiagaraFunctionLibrary.h"
#include "NiagaraSystem.h"

void UImpactFXSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);
	const UImpactFXSettings* Settings = GetDefault<UImpactFXSettings>();
	ImpactFX = Settings->ImpactFX.LoadSynchronous();          // loaded once per world, never per hit
	ImpactFXLite = Settings->ImpactFXLite.LoadSynchronous();
	MergeRadius = Settings->MergeRadius;
	MaxMergedScale = Settings->MaxMergedScale;
	MaxFullImpactsPerFrame = Settings->MaxFullImpactsPerFrame;
	SortPriority = Settings->TranslucencySortPriority;
	Pending.Reserve(64);
}

bool UImpactFXSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

TStatId UImpactFXSubsystem::GetStatId() const
{
	RETURN_QUICK_DECLARE_CYCLE_STAT(UImpactFXSubsystem, STATGROUP_Tickables);
}

void UImpactFXSubsystem::QueueImpact(FVector Location, FVector Normal, FLinearColor Color)
{
	const float MergeSq = FMath::Square(MergeRadius);
	for (FPendingImpact& Existing : Pending)
	{
		if (FVector::DistSquared2D(Existing.Location, Location) < MergeSq)
		{
			Existing.Scale = FMath::Min(Existing.Scale + 0.25f, MaxMergedScale);   // a bigger burst, not more systems
			return;
		}
	}
	Pending.Add({ Location, Normal, Color, 1.f });
}

void UImpactFXSubsystem::Tick(float DeltaTime)
{
	if (Pending.Num() == 0) { return; }
	UWorld* World = GetWorld();
	int32 Spawned = 0;
	for (const FPendingImpact& Impact : Pending)
	{
		UNiagaraSystem* System = (Spawned < MaxFullImpactsPerFrame || !ImpactFXLite) ? ImpactFX.Get() : ImpactFXLite.Get();
		++Spawned;
		if (!System) { continue; }

		const FVector FlatNormal = FVector(Impact.Normal.X, Impact.Normal.Y, 0.f).GetSafeNormal(UE_SMALL_NUMBER, FVector::BackwardVector);
		// Pooled: the component returns to the pool by itself when every emitter completes.
		UNiagaraComponent* FX = UNiagaraFunctionLibrary::SpawnSystemAtLocation(
			World, System, Impact.Location, FlatNormal.Rotation(), FVector(1.f),
			/*bAutoDestroy*/ false, /*bAutoActivate*/ true, ENCPoolMethod::AutoRelease, /*bPreCullCheck*/ true);
		if (FX)
		{
			FX->SetVariableVec3(TEXT("ImpactNormal"), FlatNormal);
			FX->SetVariableLinearColor(TEXT("PlasmaColor"), Impact.Color);
			FX->SetVariableFloat(TEXT("Scale"), Impact.Scale);
			FX->SetTranslucentSortPriority(SortPriority);
		}
	}
	Pending.Reset();
}
