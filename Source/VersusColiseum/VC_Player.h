#pragma once

#include "CoreMinimal.h"
#include "VC_CharacterBase.h"
#include "Abilities/GameplayAbility.h"
#include "AbilitySystemInterface.h"
#include "VC_Player.generated.h"

class UVC_MovementInput;
class UVC_AttackInput;
class UAbilitySystemComponent;

UCLASS()
class VERSUSCOLISEUM_API AVC_Player : public AVC_CharacterBase
{
	GENERATED_BODY()

public:
	AVC_Player();
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	virtual void BeginPlay() override;

	// AbilitySystemを使用するうえで必須のコンポーネント
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystem;

	// このキャラクターが持つアビリティの配列
	UPROPERTY(EditDefaultsOnly, Category = "Abilities")
	TArray<TSubclassOf<UGameplayAbility>> AbilityList;
	
public:
	void MoveForward(const float InValue);
	void MoveRight(const float InValue);

	// ダッシュ 回避処理
	void StartDashAvoid();
	void EndDashAvoid();

	// ジャンプ処理
	void StartJump();
	void EndJump();

	// 新しいControllerが与えられたときにAbility Systemのアクタをリフレッシュする
	virtual void PossessedBy(AController* NewController) override;
	// Ability System Componentのゲッター
	UAbilitySystemComponent* GetAbilitySystemComponent() const { return AbilitySystem; }

	////////////////////// BlueprintImplementableEvent
	UFUNCTION(BlueprintImplementableEvent)
	void Init();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UVC_MovementInput* MoveInputComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UVC_AttackInput* AttackInputComponent;

	// ISF_DamageableInterface を介して継承されました
	virtual void GetDamage(int32 damage) override;
};
