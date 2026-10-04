// SUNDER: Ascension II — projectile actor pool (see unreal/WEAPON_VFX.md §3.4).
#include "ProjectilePoolSubsystem.h"

#include "Engine/World.h"
#include "SunderProjectile.h"

bool UProjectilePoolSubsystem::DoesSupportWorldType(const EWorldType::Type WorldType) const
{
	return WorldType == EWorldType::Game || WorldType == EWorldType::PIE;
}

ASunderProjectile* UProjectilePoolSubsystem::SpawnParked(TSubclassOf<ASunderProjectile> ProjectileClass)
{
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	ASunderProjectile* Projectile = GetWorld()->SpawnActor<ASunderProjectile>(ProjectileClass, FTransform::Identity, Params);
	if (Projectile)
	{
		++TotalCreated;
		Projectile->Park();
	}
	return Projectile;
}

ASunderProjectile* UProjectilePoolSubsystem::Acquire(TSubclassOf<ASunderProjectile> ProjectileClass, FVector Location,
	FVector Direction, AActor* Owner, APawn* Instigator)
{
	if (!ProjectileClass) { return nullptr; }
	ASunderProjectile* Projectile = nullptr;
	if (FSunderProjectileFreeList* List = Free.Find(ProjectileClass.Get()))
	{
		while (List->Items.Num() > 0 && !Projectile)
		{
			ASunderProjectile* Candidate = List->Items.Pop();
			if (IsValid(Candidate)) { Projectile = Candidate; }       // skip anything destroyed behind our back
		}
	}
	if (!Projectile) { Projectile = SpawnParked(ProjectileClass); }  // pool ran dry: grow (Prewarm to avoid this)
	if (Projectile) { Projectile->Fire(Location, Direction, Owner, Instigator); }
	return Projectile;
}

void UProjectilePoolSubsystem::Release(ASunderProjectile* Projectile)
{
	if (!IsValid(Projectile) || Projectile->IsParked()) { return; }
	Projectile->Park();
	Free.FindOrAdd(Projectile->GetClass()).Items.Add(Projectile);
}

void UProjectilePoolSubsystem::Prewarm(TSubclassOf<ASunderProjectile> ProjectileClass, int32 Count)
{
	if (!ProjectileClass) { return; }
	FSunderProjectileFreeList& List = Free.FindOrAdd(ProjectileClass.Get());
	List.Items.Reserve(List.Items.Num() + Count);
	for (int32 i = 0; i < Count; ++i)
	{
		if (ASunderProjectile* Projectile = SpawnParked(ProjectileClass)) { List.Items.Add(Projectile); }
	}
}

int32 UProjectilePoolSubsystem::GetParkedCount(TSubclassOf<ASunderProjectile> ProjectileClass) const
{
	const FSunderProjectileFreeList* List = ProjectileClass ? Free.Find(ProjectileClass.Get()) : nullptr;
	return List ? List->Items.Num() : 0;
}
