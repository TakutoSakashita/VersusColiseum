#include "VC_CharacterBase.h"
#include "VC_WeaponBase.h"

AVC_CharacterBase::AVC_CharacterBase()
	: CharacterState(EVC_CharacterState::None)
	, CharacterParam(FVC_CharacterInfo())
	, CurrentHP(0.f)
{
	PrimaryActorTick.bCanEverTick = true;
}

void AVC_CharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
	// 初期化
	CharacterState = EVC_CharacterState::Normal;
	CurrentHP = CharacterParam.MaxHP;
}

void AVC_CharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AVC_CharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

/// ToDo
/// @brief 武器を装備する
/// @param InWeapon	   キャラクターに装備させる武器
/// @param InSoketName メッシュにアタッチさせるソケットの名前
void AVC_CharacterBase::EquipWeapon(AVC_WeaponBase* const InWeapon, const FName& InSoketName)
{
	if (!IsValid(InWeapon)) return;

	WeaponActor = InWeapon;

	// アクターをプレイヤーメッシュのソケットにアタッチする
	FAttachmentTransformRules AttachTransform = { EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true };
	WeaponActor->AttachToComponent(GetMesh(), AttachTransform, InSoketName);
}

// /// ToDo
// /// @brief シールドを装備する
// /// @param InEquipment キャラクターに装備させるシールド
// /// @param InSoketName メッシュにアタッチさせるソケットの名前
// void AVC_CharacterBase::EquipShield(ASF_Shield* const InShield, const FName& InSoketName)
// {
// 	if (!IsValid(InShield)) return;
//
// 	ShieldActor = InShield;
//
// 	// アクターをプレイヤーメッシュのソケットにアタッチする
// 	FAttachmentTransformRules AttachTransform = { EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepWorld, true };
// 	ShieldActor->AttachToComponent(GetMesh(), AttachTransform, InSoketName);
// }