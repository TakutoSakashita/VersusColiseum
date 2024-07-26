#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VC_IDamageable.h"
#include "VC_CharacterBase.generated.h"

UENUM(BlueprintType)
enum class EVC_CharacterState : uint8
{
	None = 0 UMETA(DisplayName = "�Ȃ�"),
	Normal UMETA(DisplayName = "�ʏ펞"),
	BeginAttack UMETA(DisplayName = "�U���J�n��"),
	WeaponAttack UMETA(DisplayName = "�ߐڍU��"),
	ShieldAttack UMETA(DisplayName = "���U��"),
	EndAttack UMETA(DisplayName = "�U���I����"),
	Avoid UMETA(DisplayName = "���"),
	BeginDead UMETA(DisplayName = "���S�J�n��"),
	Dead UMETA(DisplayName = "���S��"),
	EndDead UMETA(DisplayName = "���S�I����"),
};

// �L�����N�^�[���ʂ̏����܂Ƃ߂��\����
USTRUCT(BlueprintType)
struct FVC_CharacterInfo
{
	GENERATED_BODY()

public:
	// �ő�HP
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MaxHP;
	// �ړ����x
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float MoveSpeed;

	// �ߐڍU���\����
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
	// �L�����N�^�[�̏��
	UPROPERTY(VisibleAnywhere, Category = "Visible | State")
	EVC_CharacterState CharacterState;
	// �L�����N�^�[�̃p�����[�^���
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

	// ���S���Ă��邩
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsDead() const
	{
		return CharacterState == EVC_CharacterState::BeginDead ||
		       CharacterState == EVC_CharacterState::Dead ||
		       CharacterState == EVC_CharacterState::EndDead
			       ? true
			       : false;
	}

	// �ߋ����U�������Ă��邩
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsAttack_Weapon() const { return CharacterState == EVC_CharacterState::WeaponAttack ? true : false; }

	// ���U�������Ă��邩
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	bool IsAttack_Shield() const { return CharacterState == EVC_CharacterState::ShieldAttack ? true : false; }

	// �U���\������ݒ�
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void SetAttackableDistance(const float InValue) { CharacterParam.AttackableDistance = InValue; }

	// �U���\�������擾
	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	float GetAttackableDistance() const { return CharacterParam.AttackableDistance; }

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	void SetCurretnHP(const float InHP) { CurrentHP = InHP; }

	UFUNCTION(BlueprintCallable, Category = "CharacterBase")
	float GetCurrentHP() const { return CurrentHP; }

private:
	// IVC_Damageableable ����Čp������܂���
	virtual void GetDamage(int32 damage) override {};
};
