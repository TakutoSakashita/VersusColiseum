#include "VC_BlogComboGameplayAbility.h"
#include "AbilitySystemComponent.h"

void UVC_BlogComboGameplayAbility::AddGameplayTags(const FGameplayTagContainer GameplayTags)
{
	UAbilitySystemComponent* Comp = GetAbilitySystemComponentFromActorInfo();
 
	Comp->AddLooseGameplayTags(GameplayTags);
}

void UVC_BlogComboGameplayAbility::RemoveGameplayTags(const FGameplayTagContainer GameplayTags)
{
	UAbilitySystemComponent* Comp = GetAbilitySystemComponentFromActorInfo();
 
	Comp->RemoveLooseGameplayTags(GameplayTags);
}
