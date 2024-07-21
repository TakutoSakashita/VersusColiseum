#include "VC_CharacterBase.h"

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