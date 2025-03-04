#include "VC_MovementInput.h"
#include "VC_Player.h"
#include "VC_MainCamera.h"
#include "VC_GameMode.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"

UVC_MovementInput::UVC_MovementInput()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UVC_MovementInput::BeginPlay()
{
	Super::BeginPlay();
}

void UVC_MovementInput::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UVC_MovementInput::MoveForward(const float InValue)
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;

	// 入力方向に移動
	GetPlayerCharacter()->AddMovementInput(GetMainCamera()->GetActorForwardVector(), InValue);

	// 回転
	CharacterRotate();
}

void UVC_MovementInput::MoveRight(const float InValue)
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;

	// 入力方向に移動
	GetPlayerCharacter()->AddMovementInput(GetMainCamera()->GetActorRightVector(), InValue);

	// 回転
	CharacterRotate();
}

void UVC_MovementInput::StartDashAvoid()
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;

	GetPlayerCharacter()->GetCharacterMovement()->MaxWalkSpeed = 1200.f;
	// GetPlayerCharacter()->GetCharacterMovement()->MaxAcceleration = 4096.f;
}

void UVC_MovementInput::EndDashAvoid()
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;

	GetPlayerCharacter()->GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetPlayerCharacter()->GetCharacterMovement()->MaxAcceleration = 2048.f;
}

void UVC_MovementInput::StartJump()
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;
}

void UVC_MovementInput::EndJump()
{
	if (!IsValid(GetMainCamera())) return;
	if (!IsValid(GetPlayerCharacter())) return;
}

void UVC_MovementInput::CharacterRotate() const
{
	if (!IsValid(GetPlayerCharacter())) return;

	const FVector movement = GetPlayerCharacter()->GetLastMovementInputVector();

	// 入力がある時だけ回転
	if (movement.X != 0 || movement.Y != 0)
	{
		//UE_LOG(LogTemp, Warning, TEXT(" : %s"), "rotation");
		const FRotator currentRot = { 0.f, GetPlayerCharacter()->GetActorRotation().Yaw, 0.f };
		const FRotator targetRot = { 0.f, movement.Rotation().Yaw, 0.f };
		GetPlayerCharacter()->SetActorRotation(FMath::RInterpTo(currentRot, targetRot, GetWorld()->GetDeltaSeconds(), rotationSpeed));
	}
}

AVC_GameMode* UVC_MovementInput::GetGameMode() const
{
	return Cast<AVC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
}

AVC_MainCamera* UVC_MovementInput::GetMainCamera() const
{
	if (!GetGameMode()) return nullptr;
	return GetGameMode()->GetMainCamera();
}

AVC_Player* UVC_MovementInput::GetPlayerCharacter() const
{
	if (!GetGameMode()) return nullptr;
	return GetGameMode()->GetPlayerCharacter();
}

