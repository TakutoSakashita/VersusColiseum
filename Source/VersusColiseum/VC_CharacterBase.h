#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "VC_IDamageable.h"
#include "VC_CharacterBase.generated.h"

//class ASF_EquipmentBase;
//class ASF_WeaponBase;
//class ASF_Shield;

UENUM(BlueprintType)
enum class EVC_CharacterState : uint8
{
	None = 0			UMETA(DisplayName = "�Ȃ�"),
	Normal				UMETA(DisplayName = "�ʏ펞"),
	BeginAttack			UMETA(DisplayName = "�U���J�n��"),
	ShortRangeAttack	UMETA(DisplayName = "�ߋ����U��"),
	LongRangeAttack		UMETA(DisplayName = "�������U��"),
	EndAttack			UMETA(DisplayName = "�U���I����"),
	Avoid				UMETA(DisplayName = "���"),
	BeginDead			UMETA(DisplayName = "���S�J�n��"),
	Dead				UMETA(DisplayName = "���S��"),
	EndDead				UMETA(DisplayName = "���S�I����"),
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
	float AttackableDistance_ShortRange;
	// �������U���\����
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	float AttackableDistance_LongRange;

public:
	FVC_CharacterInfo()
		: MaxHP(100.f)
		, MoveSpeed(600.f)
		, AttackableDistance_ShortRange(500.f)
		, AttackableDistance_LongRange(2000.f)
	{}
};

UCLASS()
class VERSUSCOLISEUM_API AVC_CharacterBase : public ACharacter /*public UVC_IDamageable*/
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVC_CharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
