#include "VC_Player.h"
#include "VC_GameMode.h"
#include "VC_MovementInput.h"
#include "VC_AttackInput.h"
#include "VC_PlayerController.h"
#include "Kismet/GameplayStatics.h"

AVC_Player::AVC_Player()
{
	// コンポーネント生成
	MoveInputComponent = CreateDefaultSubobject<UVC_MovementInput>(TEXT("MoveInputComponent"));
	AttackInputComponent = CreateDefaultSubobject<UVC_AttackInput>(TEXT("AttackInputComponent"));
}

void AVC_Player::BeginPlay()
{
	Super::BeginPlay();
	SetCharacterState(EVC_CharacterState::Normal);
	if (AVC_GameMode* VC_GameMode =
		Cast<AVC_GameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		VC_GameMode->SetPlayerCharacter(this);
	}

	if (AVC_PlayerController* CustomController =
		Cast<AVC_PlayerController>(UGameplayStatics::GetPlayerController(GetWorld(), 0))) {
		CustomController->SetPlayerCharacter(this);
		}
}

void AVC_Player::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVC_Player::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void AVC_Player::MoveForward(const float InValue)
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->MoveForward(InValue);
}

void AVC_Player::MoveRight(const float InValue)
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->MoveRight(InValue);
}

void AVC_Player::StartDashAvoid()
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->StartDashAvoid();
}

void AVC_Player::EndDashAvoid()
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->EndDashAvoid();
}

void AVC_Player::StartJump()
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->StartJump();
}

void AVC_Player::EndJump()
{
	if (!IsValid(MoveInputComponent)) return;
	MoveInputComponent->EndJump();
}

void AVC_Player::GetDamage(int32 damage)
{
}
