// SUNDER: Ascension II — menu input.
#include "SunderMenuController.h"

#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "Engine/World.h"
#include "InputAction.h"
#include "InputMappingContext.h"
#include "SunderMenuGameMode.h"

void ASunderMenuController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* Input = Cast<UEnhancedInputComponent>(InputComponent);
	if (!Input)
	{
		UE_LOG(LogTemp, Warning, TEXT("SunderMenuController: set Project Settings → Input → Default Input Component Class to EnhancedInputComponent."));
		return;
	}
	Mapping = NewObject<UInputMappingContext>(this, TEXT("IMC_Menu"));

	auto Bind = [this, Input](const TCHAR* Name, std::initializer_list<FKey> Keys, void (ASunderMenuController::*Handler)())
	{
		UInputAction* Action = NewObject<UInputAction>(this, Name);
		Action->ValueType = EInputActionValueType::Boolean;
		Actions.Add(Action);
		for (const FKey& Key : Keys) { Mapping->MapKey(Action, Key); }
		Input->BindAction(Action, ETriggerEvent::Started, this, Handler);   // once per press
	};
	Bind(TEXT("IA_MenuUp"), { EKeys::W, EKeys::Up, EKeys::Gamepad_DPad_Up, EKeys::Gamepad_LeftStick_Up }, &ASunderMenuController::OnUp);
	Bind(TEXT("IA_MenuDown"), { EKeys::S, EKeys::Down, EKeys::Gamepad_DPad_Down, EKeys::Gamepad_LeftStick_Down }, &ASunderMenuController::OnDown);
	Bind(TEXT("IA_MenuLeft"), { EKeys::A, EKeys::Left, EKeys::Gamepad_DPad_Left, EKeys::Gamepad_LeftStick_Left }, &ASunderMenuController::OnLeft);
	Bind(TEXT("IA_MenuRight"), { EKeys::D, EKeys::Right, EKeys::Gamepad_DPad_Right, EKeys::Gamepad_LeftStick_Right }, &ASunderMenuController::OnRight);
	Bind(TEXT("IA_MenuConfirm"), { EKeys::SpaceBar, EKeys::Enter, EKeys::J, EKeys::Gamepad_FaceButton_Bottom, EKeys::Gamepad_Special_Right }, &ASunderMenuController::OnConfirm);
	Bind(TEXT("IA_MenuBack"), { EKeys::Escape, EKeys::BackSpace, EKeys::Gamepad_FaceButton_Right }, &ASunderMenuController::OnBack);
}

void ASunderMenuController::BeginPlay()
{
	Super::BeginPlay();
	if (Mapping && IsLocalController())
	{
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			Subsystem->AddMappingContext(Mapping, 0);
		}
	}
	SetInputMode(FInputModeGameOnly());
	SetShowMouseCursor(false);
}

ASunderMenuGameMode* ASunderMenuController::Menu() const
{
	return GetWorld() ? GetWorld()->GetAuthGameMode<ASunderMenuGameMode>() : nullptr;
}

void ASunderMenuController::OnUp() { if (ASunderMenuGameMode* M = Menu()) { M->ToggleMode(); } }
void ASunderMenuController::OnDown() { if (ASunderMenuGameMode* M = Menu()) { M->ToggleMode(); } }
void ASunderMenuController::OnLeft() { if (ASunderMenuGameMode* M = Menu()) { M->MoveShip(-1); } }
void ASunderMenuController::OnRight() { if (ASunderMenuGameMode* M = Menu()) { M->MoveShip(1); } }
void ASunderMenuController::OnConfirm() { if (ASunderMenuGameMode* M = Menu()) { M->Confirm(); } }
void ASunderMenuController::OnBack() { if (ASunderMenuGameMode* M = Menu()) { M->Back(); } }
