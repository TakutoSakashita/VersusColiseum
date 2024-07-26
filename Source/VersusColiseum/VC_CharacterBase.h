#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VC_IDamageable.h"
#include "VC_CharacterBase.generated.h"

UENUM(BlueprintType)
enum class EVC_CharacterState : uint8
{
	None = 0 UMETA(DisplayName = "なし"),
	Normal UMETA(DisplayName = "通常時"),
	BeginAttack UMETA(DisplayName = "攻撃開始時"),
	WeaponAttack UMETA(DisplayName = "近接攻撃"),
	ShieldAttack UMETA(DisplayName = "盾攻撃"),
	EndAttack UMETA(DisplayName = "攻撃終了時"),
	Avoid UMETA(DisplayName = "回避"),
	BeginDead UMETA(DisplayName = "死亡開始時"),
	Dead UMETA(DisplayName = "死亡中"),
	EndDead UMETA(DisplayName = "死亡終了時"),
};

// キャラクター共通の情報をまとめた構造体
USTRUCT(BlueprintType)
struct FVC_CharacterInfo
{
	GENERATED_BODY()

public:
	// 最大HP
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHP;
	// 移動速度
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveSpeed;

	// 近接攻撃可能距離
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackableDistance;

public:
	FVC_CharacterInfo()
		: MaxHP(100.f)
		  , MoveSpeed(600.f)
		  , AttackableDistance(500.f)
	{
	}
};

UCLASS()
class VERSUSCOLISEUM_API AVC_CharacterBase : public ACharacter, public IVC_IDamageable
{
	GENERATED_BODY()

public:
	AVC_CharacterBase();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	// キャラクターの状態
	UPROPERTY(VisibleAnywhere, Category = "Visible | State")
	EVC_CharacterState CharacterState;
	// キャラクターのパラメータ情報
	UPROPERTY(EditAnywhere, Category = "Edit | Param")
	FVC_CharacterInfo CharacterParam;

	// HP
	UPROPERTY()
	float CurrentHP;

public:
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void SetCharacterState(const EVC_CharacterState InCharacterState) { CharacterState = InCharacterState; }

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	EVC_CharacterState GetCharacterState() { return CharacterState; }

	// 死亡しているか
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsDead() const
	{
		return CharacterState == EVC_CharacterState::BeginDead ||
		       CharacterState == EVC_CharacterState::Dead ||
		       CharacterState == EVC_CharacterState::EndDead
			       ? true
			       : false;
	}

	// 近距離攻撃をしているか
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsAttack_Weapon() const { return CharacterState == EVC_CharacterState::WeaponAttack ? true : false; }

	// 盾攻撃をしているか
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsAttack_Shield() const { return CharacterState == EVC_CharacterState::ShieldAttack ? true : false; }

	// 攻撃可能距離を設定
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void SetAttackableDistance(const float InValue) { CharacterParam.AttackableDistance = InValue; }

	// 攻撃可能距離を取得
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	float GetAttackableDistance() const { return CharacterParam.AttackableDistance; }

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void SetCurretnHP(const float InHP) { CurrentHP = InHP; }

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	float GetCurrentHP() const { return CurrentHP; }

private:
	// IVC_Damageableable を介して継承されました
	virtual void GetDamage(int32 damage) override {};
};
