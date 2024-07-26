#pragma once

#include "CoreMinimal.h"
#include "Abilities/GameplayAbility.h"
#include "VC_BlogComboGameplayAbility.generated.h"

UCLASS()
class VERSUSCOLISEUM_API UVC_BlogComboGameplayAbility : public UGameplayAbility
{
	GENERATED_BODY()
	
	/** AbilitySystemComponentのGameplayTagCountContainerに新しいGameplayTagを追加する */
	UFUNCTION(BlueprintCallable, Category = "GamePlayAbility")
	virtual void AddGameplayTags(const FGameplayTagContainer GameplayTags);
 
	/** AbilitySystemComponentのGameplayTagCountContainerのGameplayTagを削除する */
	UFUNCTION(BlueprintCallable, Category = "GamePlayAbility")
	virtual void RemoveGameplayTags(const FGameplayTagContainer GameplayTags);
};
