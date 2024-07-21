
#include "VC_PlayerController.h"
#include "VC_Player.h"
#include "VC_MainCamera.h"

AVC_PlayerController::AVC_PlayerController()
	: PlayerCharacter(nullptr)
	, MainCamera(nullptr)
{
}

void AVC_PlayerController::BeginPlay()
{
	Super::BeginPlay();
}

void AVC_PlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	//movement process
	InputComponent->BindAxis("MoveForward", this, &AVC_PlayerController::MoveForward);
	InputComponent->BindAxis("MoveRight", this, &AVC_PlayerController::MoveRight);
	InputComponent->BindAxis("Turn", this, &AVC_PlayerController::Turn);
	InputComponent->BindAxis("LookUp", this, &AVC_PlayerController::LookUp);
	// InputComponent->BindAction("Avoid", IE_Pressed, this, &AVC_PlayerController::StartMoveDash);
	// InputComponent->BindAction("StartMoveJump", IE_Pressed, this, &AVC_PlayerController::StartMoveJump);
	// InputComponent->BindAction("EndMoveJump", IE_Pressed, this, &AVC_PlayerController::EndMoveJump);
	//
	// //attack process
	// InputComponent->BindAction("BeginWeaponAttack", IE_Pressed, this, &AVC_PlayerController::BeginShortRangeAttack);
	// InputComponent->BindAction("EndShortRangeAttack", IE_Released, this, &AVC_PlayerController::EndShortRangeAttack);
	// InputComponent->BindAction("BeginShieldAttack", IE_Pressed, this, &AVC_PlayerController::HomingAttack);
	// InputComponent->BindAction("EndShieldAttack", IE_Pressed, this, &AVC_PlayerController::LaserAttack);
	//
	// InputComponent->BindAction("LockOn", IE_Pressed, this, &AVC_PlayerController::LockOn);
}

void AVC_PlayerController::LookUp(const float InValue)
{
	if (!MainCamera) return;
	MainCamera->AddPitchRotation(InValue);
	//UE_LOG(LogTemp,Warning,TEXT("LookUp"));
}

void AVC_PlayerController::Turn(const float InValue)
{
	if (!MainCamera) return;
	MainCamera->AddYawRotation(InValue);
	//UE_LOG(LogTemp,Warning,TEXT("Turn"));
}

void AVC_PlayerController::MoveForward(const float InValue)
{
	if (!PlayerCharacter) return;
	PlayerCharacter->MoveForward(InValue);
	//UE_LOG(LogTemp,Warning,TEXT("MoveForward"));
}

void AVC_PlayerController::MoveRight(const float InValue)
{
	if (!PlayerCharacter) return;
	PlayerCharacter->MoveRight(InValue);
	//UE_LOG(LogTemp,Warning,TEXT("MoveRight"));

}
