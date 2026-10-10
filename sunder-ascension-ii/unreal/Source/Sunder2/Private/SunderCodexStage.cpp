// SUNDER: Ascension II — the Codex's Keeper viewer.
#include "SunderCodexStage.h"

#include "Components/DirectionalLightComponent.h"
#include "Components/PointLightComponent.h"
#include "Components/SceneCaptureComponent2D.h"
#include "Components/StaticMeshComponent.h"
#include "Engine/StaticMesh.h"
#include "Engine/TextureRenderTarget2D.h"
#include "Engine/World.h"
#include "EngineUtils.h"
#include "Materials/MaterialInstanceDynamic.h"
#include "SunderEnemy.h"
#include "SunderKeeperAnim.h"

namespace
{
	// The web stage is in metres with the Keeper 5 across; here it is 300 units across, so 60 units to the metre.
	// Web (x, y, z) with y up and the Keeper facing +z becomes (-z, x, y) here, where it faces -X with Z up.
	constexpr float U = 60.f;
	FVector Web(float X, float Y, float Z) { return FVector(-Z, X, Y) * U; }
	FLinearColor Hex(uint32 C) { return FLinearColor(FColor((C >> 16) & 255, (C >> 8) & 255, C & 255)); }

	const TCHAR* ShapeMaterial = TEXT("/Engine/BasicShapes/BasicShapeMaterial.BasicShapeMaterial");

	UDirectionalLightComponent* MakeSun(AActor* Owner, USceneComponent* Parent, const TCHAR* Name, const FVector& From, uint32 Colour, float Lux)
	{
		UDirectionalLightComponent* L = Owner->CreateDefaultSubobject<UDirectionalLightComponent>(Name);
		L->SetupAttachment(Parent);
		L->SetRelativeRotation((-From).Rotation());            // shining from From toward the Keeper
		L->SetIntensity(Lux);
		L->SetLightColor(Hex(Colour));
		L->SetMobility(EComponentMobility::Movable);
		L->CastShadows = false;
		L->bAtmosphereSunLight = false;
		L->LightingChannels.bChannel0 = false;                  // only the Keeper (channel 1), never the level
		L->LightingChannels.bChannel1 = true;
		return L;
	}

	UStaticMeshComponent* MakeShape(AActor* Owner, USceneComponent* Parent, const TCHAR* Name)
	{
		UStaticMeshComponent* C = Owner->CreateDefaultSubobject<UStaticMeshComponent>(Name);
		C->SetupAttachment(Parent);
		C->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		C->SetCastShadow(false);
		C->SetVisibleInSceneCaptureOnly(true);                  // the level's cameras never see the stage
		C->LightingChannels.bChannel0 = false;
		C->LightingChannels.bChannel1 = true;
		return C;
	}
}

ASunderCodexStage::ASunderCodexStage()
{
	PrimaryActorTick.bCanEverTick = false;
	SetRootComponent(CreateDefaultSubobject<USceneComponent>(TEXT("Root")));
	Rig = CreateDefaultSubobject<USceneComponent>(TEXT("Rig"));
	Rig->SetupAttachment(GetRootComponent());
	Hover = CreateDefaultSubobject<USceneComponent>(TEXT("Hover"));
	Hover->SetupAttachment(Rig);
	Body = MakeShape(this, Hover, TEXT("Body"));

	// The web viewer's turntable plinth: an obsidian disc on a gold rim, under the Keeper.
	UStaticMeshComponent* Disc = MakeShape(this, Rig, TEXT("Plinth"));
	Disc->SetRelativeLocation(FVector(0.f, 0.f, -0.15f * U));
	Disc->SetRelativeScale3D(FVector(6.6f * U / 100.f, 6.6f * U / 100.f, 0.3f * U / 100.f));
	UStaticMeshComponent* Rim = MakeShape(this, Rig, TEXT("PlinthRim"));
	Rim->SetRelativeLocation(FVector(0.f, 0.f, -0.2f * U));
	Rim->SetRelativeScale3D(FVector(6.9f * U / 100.f, 6.9f * U / 100.f, 0.14f * U / 100.f));

	// keepers.html's lighting stack, turning with the Keeper as the web camera orbits it.
	Key = MakeSun(this, Rig, TEXT("Key"), Web(-5.f, 8.f, 6.f), 0xffe3c0, 3.4f);
	RimLight = MakeSun(this, Rig, TEXT("RimLight"), Web(4.f, 3.f, -7.f), 0x7d9cff, 2.8f);
	Fill = MakeSun(this, Rig, TEXT("Fill"), Web(3.f, 2.5f, 9.f), 0xc8d2ff, 1.1f);
	SkyLight = MakeSun(this, Rig, TEXT("HemisphereSky"), FVector(0.f, 0.f, 1.f), 0x5a6aa8, 0.55f);
	GroundLight = MakeSun(this, Rig, TEXT("HemisphereGround"), FVector(0.f, 0.f, -1.f), 0x1a0f08, 0.55f);
	Practical = CreateDefaultSubobject<UPointLightComponent>(TEXT("Practical"));
	Practical->SetupAttachment(Rig);
	Practical->SetRelativeLocation(Web(0.f, 2.2f, 2.2f));
	Practical->SetMobility(EComponentMobility::Movable);
	Practical->SetIntensityUnits(ELightUnits::Candelas);
	Practical->SetIntensity(9.f * (U / 100.f) * (U / 100.f));     // three.js's 9 cd at the stage's scale
	Practical->SetAttenuationRadius(8.f * U);
	Practical->CastShadows = false;
	Practical->LightingChannels.bChannel0 = false;
	Practical->LightingChannels.bChannel1 = true;

	// The camera: where the web viewer's starts, looking at its orbit target.
	const FVector Eye = Web(5.6f, 3.6f, 9.8f), Look = Web(0.f, 1.1f, 0.f);
	Distance = (Look - Eye).Size();
	Capture = CreateDefaultSubobject<USceneCaptureComponent2D>(TEXT("Capture"));
	Capture->SetupAttachment(GetRootComponent());
	Capture->SetRelativeLocation(Eye);
	Capture->SetRelativeRotation((Look - Eye).Rotation());
	Capture->FOVAngle = FieldOfView;
	Capture->bCaptureEveryFrame = false;                        // Render() captures, only while the Codex shows it
	Capture->bCaptureOnMovement = false;
	Capture->bAlwaysPersistRenderingState = true;               // keeps anti-aliasing history between captures
	Capture->CaptureSource = ESceneCaptureSource::SCS_FinalColorLDR;
	Capture->PrimitiveRenderMode = ESceneCapturePrimitiveRenderMode::PRM_UseShowOnlyList;
	Capture->ShowFlags.SetFog(false);
	Capture->ShowFlags.SetVolumetricFog(false);
	Capture->ShowFlags.SetAtmosphere(false);
	Capture->ShowFlags.SetSkyLighting(false);                   // a level's sky light would reach the Keeper
	Capture->ShowFlags.SetMotionBlur(false);
	Capture->ShowFlags.SetEyeAdaptation(false);
	FPostProcessSettings& PP = Capture->PostProcessSettings;
	PP.bOverride_AutoExposureMethod = true;              PP.AutoExposureMethod = EAutoExposureMethod::AEM_Manual;
	PP.bOverride_AutoExposureApplyPhysicalCameraExposure = true; PP.AutoExposureApplyPhysicalCameraExposure = false;
	PP.bOverride_AutoExposureBias = true;                PP.AutoExposureBias = 0.f;   // lux and candelas as three.js reads them
	PP.bOverride_BloomIntensity = true;                  PP.BloomIntensity = 0.5f;    // UnrealBloomPass 0.38, threshold 0.9
	PP.bOverride_BloomThreshold = true;                  PP.BloomThreshold = 0.9f;
	PP.bOverride_VignetteIntensity = true;               PP.VignetteIntensity = 0.f;
	PP.bOverride_DynamicGlobalIlluminationMethod = true; PP.DynamicGlobalIlluminationMethod = EDynamicGlobalIlluminationMethod::None;
	PP.bOverride_ReflectionMethod = true;                PP.ReflectionMethod = EReflectionMethod::ScreenSpace;

	// The sky behind: an indigo backdrop facing the camera, lit only by a violet glow from below the frame, so it
	// runs from the web sky's void at the top to its indigo and a faint violet horizon at the bottom.
	Backdrop = MakeShape(this, Capture, TEXT("Backdrop"));
	const float Back = Distance + 900.f, Half = Back * FMath::Tan(FMath::DegreesToRadians(FieldOfView * 0.5f));
	Backdrop->SetRelativeLocation(FVector(Back, 0.f, 0.f));
	Backdrop->SetRelativeRotation(FRotator(90.f, 0.f, 0.f));    // the plane's face toward the camera
	Backdrop->SetRelativeScale3D(FVector(Half * 2.6f / 100.f));
	Backdrop->LightingChannels.bChannel1 = false;
	Backdrop->LightingChannels.bChannel2 = true;
	Horizon = CreateDefaultSubobject<UPointLightComponent>(TEXT("Horizon"));
	Horizon->SetupAttachment(Capture);
	Horizon->SetRelativeLocation(FVector(Back - 600.f, 0.f, -Half - 380.f));
	Horizon->SetMobility(EComponentMobility::Movable);
	Horizon->SetIntensityUnits(ELightUnits::Candelas);
	Horizon->SetIntensity(36.f);
	Horizon->SetAttenuationRadius(Back * 2.f);
	Horizon->SetLightColor(FLinearColor(0.45f, 0.3f, 1.f));
	Horizon->CastShadows = false;
	Horizon->LightingChannels.bChannel0 = false;
	Horizon->LightingChannels.bChannel2 = true;
}

ASunderCodexStage* ASunderCodexStage::Get(UWorld* World)
{
	if (!World) { return nullptr; }
	for (TActorIterator<ASunderCodexStage> It(World); It; ++It) { return *It; }
	FActorSpawnParameters Params;
	Params.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;
	Params.ObjectFlags |= RF_Transient;
	ASunderCodexStage* Stage = World->SpawnActor<ASunderCodexStage>(FVector(0.f, 0.f, -100000.f), FRotator::ZeroRotator, Params);
	if (!Stage) { return nullptr; }

	// The engine's basic shapes in colour: obsidian, gold, and the sky's indigo (loaded here, not in the constructor).
	auto Paint = [Stage](const TCHAR* Part, const TCHAR* Shape, const FLinearColor& Colour)
	{
		TArray<UStaticMeshComponent*> Parts;
		Stage->GetComponents(Parts);
		for (UStaticMeshComponent* C : Parts)
		{
			if (C->GetFName() != Part) { continue; }
			C->SetStaticMesh(LoadObject<UStaticMesh>(nullptr, Shape));
			if (UMaterialInstanceDynamic* M = UMaterialInstanceDynamic::Create(LoadObject<UMaterialInterface>(nullptr, ShapeMaterial), Stage))
			{
				M->SetVectorParameterValue(TEXT("Color"), Colour);
				C->SetMaterial(0, M);
			}
		}
	};
	Paint(TEXT("Plinth"), TEXT("/Engine/BasicShapes/Cylinder.Cylinder"), FLinearColor(0.02f, 0.018f, 0.03f));
	Paint(TEXT("PlinthRim"), TEXT("/Engine/BasicShapes/Cylinder.Cylinder"), FLinearColor(0.8f, 0.55f, 0.15f));
	Paint(TEXT("Backdrop"), TEXT("/Engine/BasicShapes/Plane.Plane"), FLinearColor(0.6f, 0.6f, 0.6f));

	Stage->Target = NewObject<UTextureRenderTarget2D>(Stage);
	Stage->Target->RenderTargetFormat = RTF_RGBA8;
	Stage->Target->ClearColor = FLinearColor::Black;
	Stage->Target->InitAutoFormat(Stage->Resolution, Stage->Resolution);
	Stage->Target->UpdateResourceImmediate(true);
	Stage->Capture->TextureTarget = Stage->Target;
	TArray<UStaticMeshComponent*> Parts;
	Stage->GetComponents(Parts);
	for (UStaticMeshComponent* C : Parts) { Stage->Capture->ShowOnlyComponents.Add(C); }
	return Stage;
}

bool ASunderCodexStage::Show(const FString& Id, const FLinearColor& Accent, float Now)
{
	if (Id == ShownId) { return Body->GetStaticMesh() != nullptr; }
	ShownId = Id;
	ShownAt = Now;

	// The Keeper as its Blueprint wears it (create_keepers.py): its model and the turn that faces it down the screen,
	// which here faces it toward the camera. Without the Blueprint, the imported model as it is.
	UStaticMesh* Model = nullptr;
	FRotator Turn(0.f, 90.f, 0.f);
	const FString Name = TEXT("BP_Keeper_") + Id;
	if (UClass* Class = LoadClass<ASunderEnemy>(nullptr, *FString::Printf(TEXT("/Game/Sunder/Blueprints/Keepers/%s.%s_C"), *Name, *Name)))
	{
		const ASunderEnemy* Keeper = Class->GetDefaultObject<ASunderEnemy>();
		Model = Keeper->BodyMesh;
		Turn = Keeper->BodyRotation;
	}
	if (!Model) { Model = LoadObject<UStaticMesh>(nullptr, *FString::Printf(TEXT("/Game/Sunder/Keepers/Meshes/SM_Keeper_%s.SM_Keeper_%s"), *Id, *Id)); }

	// Its animation loop (create_keeper_anim.py), as the web viewer's mixer plays the GLB's: the fixed body in place of
	// the whole model, and each moving part on it, in the model's own space.
	Anim = LoadObject<USunderKeeperAnim>(nullptr, *FString::Printf(TEXT("/Game/Sunder/Keepers/Anim/DA_KeeperAnim_%s.DA_KeeperAnim_%s"), *Id, *Id));
	if (Anim && !Anim->Body) { Anim = nullptr; }
	if (!Model && Anim) { Model = Anim->Body; }
	Body->EmptyOverrideMaterials();
	Body->SetStaticMesh(Anim ? Anim->Body.Get() : Model);
	const int32 Moving = Anim ? Anim->Parts.Num() : 0;
	for (int32 i = 0; i < FMath::Max(Moving, Parts.Num()); ++i)
	{
		UStaticMeshComponent* Part = PartComponent(i);
		const bool bUsed = i < Moving && Anim->Parts[i].Mesh;
		Part->EmptyOverrideMaterials();
		Part->SetStaticMesh(bUsed ? Anim->Parts[i].Mesh.Get() : nullptr);
		Part->SetVisibility(bUsed);
		if (bUsed) { Part->SetRelativeTransform(Anim->Sample(i, 0.f)); }
	}
	Glows.Reset();
	FindGlows(Body);
	for (int32 i = 0; i < Moving; ++i) { FindGlows(Parts[i]); }
	if (!Model) { return false; }

	// keepers.html's prepare(): 5 across (here FitSize), standing on the plinth, centred over it. A tall Keeper is held
	// shorter so it stays in the square window.
	const FBox Box = Model->GetBoundingBox().TransformBy(FTransform(Turn));
	const FVector Size = Box.GetSize(), Centre = Box.GetCenter();
	const float Scale = FMath::Min(FitSize / FMath::Max3(Size.X, Size.Y, 1.f), 0.85f * FitSize / FMath::Max(Size.Z, 1.f));
	Body->SetRelativeRotation(Turn);
	Body->SetRelativeScale3D(FVector(Scale));
	Body->SetRelativeLocation(FVector(-Centre.X * Scale, -Centre.Y * Scale, -Box.Min.Z * Scale + 0.02f * U));
	Practical->SetLightColor(Accent);
	return true;
}

UTextureRenderTarget2D* ASunderCodexStage::Render(float Now)
{
	if (!Capture || !Target || !Body->GetStaticMesh()) { return nullptr; }
	// The web frame(): OrbitControls autoRotate 0.6 (a turn in 100 s; the Keeper and its lights turn, the camera and the
	// sky stay), the hover (0.25 up, ±0.08 at 1.4 rad/s) and the grow-in (0.6 → 1, ease-out cubic, 2.2 per second).
	Rig->SetRelativeRotation(FRotator(0.f, -Now * 3.6f, 0.f));
	const float Swap = FMath::Clamp((Now - ShownAt) * 2.2f, 0.f, 1.f), Ease = 1.f - FMath::Pow(1.f - Swap, 3.f);
	Hover->SetRelativeLocation(FVector(0.f, 0.f, (0.25f + FMath::Sin(Now * 1.4f) * 0.08f) * U));
	Hover->SetRelativeScale3D(FVector(0.6f + 0.4f * Ease));
	const float Pulse = 0.75f + 0.35f * FMath::Sin(Now * 3.1f);   // keepers.html: emissiveIntensity = base × this
	for (UMaterialInstanceDynamic* Glow : Glows) { if (Glow) { Glow->SetScalarParameterValue(TEXT("GlowPulse"), Pulse); } }
	if (Anim)                                                   // the loop, from when it came on, a loop a second
	{
		for (int32 i = 0; i < Anim->Parts.Num() && i < Parts.Num(); ++i) { Parts[i]->SetRelativeTransform(Anim->Sample(i, Now - ShownAt)); }
	}
	Capture->CaptureScene();
	return Target;
}

UStaticMeshComponent* ASunderCodexStage::PartComponent(int32 i)
{
	while (Parts.Num() <= i)
	{
		// Made at run time, like the parts of the Body they ride on: seen only by the capture, lit only by the stage.
		UStaticMeshComponent* Part = NewObject<UStaticMeshComponent>(this, *FString::Printf(TEXT("Part%d"), Parts.Num()));
		Part->SetupAttachment(Body);
		Part->SetCollisionEnabled(ECollisionEnabled::NoCollision);
		Part->SetCastShadow(false);
		Part->SetVisibleInSceneCaptureOnly(true);
		Part->LightingChannels.bChannel0 = false;
		Part->LightingChannels.bChannel1 = true;
		Part->RegisterComponent();
		Capture->ShowOnlyComponents.Add(Part);
		Parts.Add(Part);
	}
	return Parts[i];
}

void ASunderCodexStage::FindGlows(UStaticMeshComponent* Component)
{
	// The slots wearing create_keeper_glow.py's materials (they have a GlowPulse) get their own instance to breathe.
	if (!Component || !Component->GetStaticMesh()) { return; }
	for (int32 i = 0; i < Component->GetNumMaterials(); ++i)
	{
		UMaterialInterface* Material = Component->GetMaterial(i);
		float Pulse = 0.f;
		if (Material && Material->GetScalarParameterValue(FHashedMaterialParameterInfo(TEXT("GlowPulse")), Pulse))
		{
			Glows.Add(Component->CreateDynamicMaterialInstance(i, Material));
		}
	}
}
