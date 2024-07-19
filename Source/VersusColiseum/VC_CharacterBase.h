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
	None = 0			UMETA(DisplayName = "なし"),
	Normal				UMETA(DisplayName = "通常時"),
	BeginAttack			UMETA(DisplayName = "攻撃開始時"),
	ShortRangeAttack	UMETA(DisplayName = "近距離攻撃"),
	LongRangeAttack		UMETA(DisplayName = "遠距離攻撃"),
	EndAttack			UMETA(DisplayName = "攻撃終了時"),
	Avoid				UMETA(DisplayName = "回避中"),
	BeginDead			UMETA(DisplayName = "死亡開始時"),
	Dead				UMETA(DisplayName = "死亡中"),
	EndDead				UMETA(DisplayName = "死亡終了時"),
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
	float AttackableDistance_ShortRange;
	// 遠距離攻撃可能距離
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
