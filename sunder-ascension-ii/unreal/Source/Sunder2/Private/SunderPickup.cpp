// SUNDER: Ascension II — a falling power-up.
#include "SunderPickup.h"

#include "Components/SphereComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/TextRenderComponent.h"
#include "Engine/StaticMesh.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "UObject/ConstructorHelpers.h"

ASunderPickup::ASunderPickup()
{
	PrimaryActorTick.bCanEverTick = true;
	InitialLifeSpan = 8.f;                                     // long gone off the bottom of the screen by then

	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->InitSphereRadius(55.f);                       // generous, like the web game's (its radius + the ship's + 8)
	Collision->SetCollisionProfileName(TEXT("OverlapAllDynamic"));
	Collision->SetGenerateOverlapEvents(true);
	RootComponent = Collision;

	Gem = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Gem"));
	Gem->SetupAttachment(Collision);
	Gem->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	Gem->SetRelativeScale3D(FVector(0.55f, 0.55f, 0.12f));   // a flat square, turned 45° in Tick: a diamond from above
	static ConstructorHelpers::FObjectFinder<UStaticMesh> Cube(TEXT("/Engine/BasicShapes/Cube.Cube"));
	if (Cube.Succeeded()) { Gem->SetStaticMesh(Cube.Object); }

	Letter = CreateDefaultSubobject<UTextRenderComponent>(TEXT("Letter"));
	Letter->SetupAttachment(Collision);
	Letter->SetRelativeLocation(FVector(0.f, 0.f, 12.f));
	Letter->SetRelativeRotation(FRotator(90.f, 180.f, 0.f));  // lying flat, facing the camera above, upright on screen
	Letter->SetHorizontalAlignment(EHTA_Center);
	Letter->SetVerticalAlignment(EVRTA_TextCenter);
	Letter->SetWorldSize(46.f);
	Letter->SetTextRenderColor(FColor(255, 246, 201));
}

FLinearColor ASunderPickup::KindColor(ESunderPickupKind InKind)
{
	switch (InKind)                                            // the web game's pickup colours
	{
	case ESunderPickupKind::Spread: return FLinearColor(0.76f, 0.04f, 0.04f);   // #E23B3B
	case ESunderPickupKind::Laser:  return FLinearColor(0.03f, 0.21f, 0.69f);   // #2F7FD8
	case ESunderPickupKind::Power:  return FLinearColor(0.66f, 0.43f, 0.04f);   // #D4AF37
	case ESunderPickupKind::Bomb:   return FLinearColor(0.66f, 0.23f, 0.02f);   // #D4832B
	case ESunderPickupKind::Shield: return FLinearColor(0.04f, 0.39f, 0.76f);   // #3BA7E2
	case ESunderPickupKind::Life:   return FLinearColor(0.76f, 0.04f, 0.15f);   // #E23B6B
	}
	return FLinearColor::White;
}

FString ASunderPickup::KindLetter(ESunderPickupKind InKind)
{
	switch (InKind)
	{
	case ESunderPickupKind::Spread: return TEXT("S");
	case ESunderPickupKind::Laser:  return TEXT("L");
	case ESunderPickupKind::Power:  return TEXT("P");
	case ESunderPickupKind::Bomb:   return TEXT("B");
	case ESunderPickupKind::Shield: return TEXT("O");
	case ESunderPickupKind::Life:   return TEXT("+");
	}
	return FString();
}

void ASunderPickup::SetKind(ESunderPickupKind InKind)
{
	Kind = InKind;
	Letter->SetText(FText::FromString(KindLetter(Kind)));
	if (GemMaterial) { GemMaterial->SetVectorParameterValue(TEXT("Color"), KindColor(Kind)); }
}

void ASunderPickup::BeginPlay()
{
	Super::BeginPlay();
	StartY = GetActorLocation().Y;
	GemMaterial = Gem->CreateDynamicMaterialInstance(0);       // the engine shape material's "Color"
	SetKind(Kind);
	Collision->OnComponentBeginOverlap.AddDynamic(this, &ASunderPickup::OnOverlap);
}

void ASunderPickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Age += DeltaTime;
	FVector P = GetActorLocation();
	P.X -= FallSpeed * DeltaTime;                              // down the screen
	P.Y = StartY + 15.f * FMath::Sin(Age * 7.f);               // the web game's little wobble
	SetActorLocation(P);
	Gem->SetRelativeRotation(FRotator(0.f, 45.f + 25.f * FMath::Sin(Age * 3.f), 0.f));
	Gem->SetRelativeScale3D(FVector(0.55f, 0.55f, 0.12f) * (1.f + 0.08f * FMath::Sin(Age * 9.f)));   // a glint
}

void ASunderPickup::OnOverlap(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp,
	int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	ASunderShipPawn* Ship = Cast<ASunderShipPawn>(OtherActor);
	if (!Ship || !Ship->IsAlive()) { return; }
	Ship->CollectPickup(Kind);
	Destroy();
}
