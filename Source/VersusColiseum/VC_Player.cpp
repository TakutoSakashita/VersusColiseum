#include "VC_Player.h"
#include "VC_GameMode.h"
#include "VC_MovementInput.h"
#include "VC_AttackInput.h"
#include "VC_PlayerController.h"
#include "AbilitySystemComponent.h"
#include "VC_Weapon.h"
#include "Kismet/GameplayStatics.h"

AVC_Player::AVC_Player()
{
	// コンポーネント生成
	MoveInputComponent = CreateDefaultSubobject<UVC_MovementInput>(TEXT("MoveInputComponent"));
	AttackInputComponent = CreateDefaultSubobject<UVC_AttackInput>(TEXT("AttackInputComponent"));

	// GAS
	AbilitySystem = CreateDefaultSubobject<UAbilitySystemComponent>(TEXT("AbilitySystem"));
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

	// GAS
	if (IsValid(AbilitySystem))
	{
		int32 InputID(0);
		if (HasAuthority() && AbilityList.Num() > 0)
		{
			for (auto Ability : AbilityList)
			{
				AbilitySystem->GiveAbility(FGameplayAbilitySpec(Ability.GetDefaultObject(), 1, InputID++));
			}
		}
		AbilitySystem->InitAbilityActorInfo(this, this);
	}

	AVC_Weapon* Weapon = Cast<AVC_Weapon>(UGameplayStatics::GetActorOfClass(GetWorld(),AVC_Weapon::StaticClass()));
	EquipWeapon(Weapon,"hand_rSocket");
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

void AVC_Player::BeginWeaponAttack()
{
	if (!IsValid(AttackInputComponent)) return;
	AttackInputComponent->BeginWeaponAttack();
}

void AVC_Player::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	AbilitySystem->RefreshAbilityActorInfo();
}

void AVC_Player::GetDamage(int32 damage)
{
	
}
