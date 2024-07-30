#include "VC_AttackInput.h"
#include "VC_Player.h"
#include "VC_GameMode.h"
#include "AbilitySystemComponent.h"
#include "Kismet/GameplayStatics.h"

UVC_AttackInput::UVC_AttackInput()
: VC_GameMode(nullptr)
	, VC_Player(nullptr)
	, AbilitySystem(nullptr)
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UVC_AttackInput::BeginPlay()
{
	Super::BeginPlay();
}

void UVC_AttackInput::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// null check
	if(!IsValid(VC_GameMode)){
		VC_GameMode = Cast<AVC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	}

	if(!IsValid(VC_Player)){
		VC_Player = VC_GameMode->GetPlayerCharacter();
	}

	if(!IsValid(AbilitySystem)){
		AbilitySystem = Cast<UAbilitySystemComponent>(VC_Player->GetAbilitySystemComponent());
	}
}

void UVC_AttackInput::BeginWeaponAttack() const
{
	//UE_LOG(LogTemp,Warning,TEXT("BeginWeaponAttack"));
	
	AbilitySystem->TryActivateAbilitiesByTag(FGameplayTagContainer(FGameplayTag::RequestGameplayTag(FName("Ability.Action.Attack"))),true);
}

