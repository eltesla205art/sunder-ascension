// SUNDER: Ascension II — weapon test target.
#include "SunderTargetDummy.h"

#include "Components/StaticMeshComponent.h"
#include "Engine/DamageEvents.h"
#include "Engine/StaticMesh.h"
#include "Engine/World.h"
#include "ImpactFXSubsystem.h"
#include "TimerManager.h"
#include "UObject/ConstructorHelpers.h"

ASunderTargetDummy::ASunderTargetDummy()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	Mesh->SetCollisionProfileName(TEXT("BlockAll"));         // blocks the beam's trace; overlaps plasma shots
	Mesh->SetGenerateOverlapEvents(true);
	RootComponent = Mesh;
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (Cube.Succeeded()) { Mesh->SetStaticMesh(Cube.Object); }
}

void ASunderTargetDummy::BeginPlay()
{
	Super::BeginPlay();
	Home = GetActorLocation();
	BaseScale = GetActorScale3D();
	Health = MaxHealth;
	DriftTime = FMath::FRandRange(0.f, 6.f);                  // dummies placed together don't move in step
}

float ASunderTargetDummy::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
	AActor* DamageCauser)
{
	const float Applied = Super::TakeDamage(DamageAmount, DamageEvent, EventInstigator, DamageCauser);
	if (!bAlive || DamageAmount <= 0.f) { return Applied; }
	Health -= DamageAmount;
	HitPulse = 1.f;
	if (Health <= 0.f)
	{
		bAlive = false;
		if (UImpactFXSubsystem* Impacts = GetWorld()->GetSubsystem<UImpactFXSubsystem>())
		{
			for (int32 i = 0; i < 3; ++i)                        // three bursts merge into one big one
			{
				Impacts->QueueImpact(GetActorLocation(), FVector::BackwardVector, DeathColor);
			}
		}
		SetActorHiddenInGame(true);
		SetActorEnableCollision(false);
		GetWorldTimerManager().SetTimer(RespawnTimer, this, &ASunderTargetDummy::Respawn, RespawnDelay, false);
	}
	return DamageAmount;
}

void ASunderTargetDummy::Respawn()
{
	Health = MaxHealth;
	bAlive = true;
	SetActorHiddenInGame(false);
	SetActorEnableCollision(true);
}

void ASunderTargetDummy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	DriftTime += DeltaTime;
	SetActorLocation(Home + FVector(0.f, FMath::Sin(DriftTime * DriftSpeed) * DriftAmplitude, 0.f));
	HitPulse = FMath::Max(HitPulse - DeltaTime * 8.f, 0.f);   // a quick swell when hit
	SetActorScale3D(BaseScale * (1.f + 0.12f * HitPulse));
}
