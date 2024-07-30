#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VC_AttackInput.generated.h"

class UAbilitySystemComponent;
class AVC_Player;
class AVC_GameMode;
;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VERSUSCOLISEUM_API UVC_AttackInput : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UVC_AttackInput();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// 攻撃処理
	void BeginWeaponAttack() const;

private:
	AVC_GameMode* VC_GameMode;
	AVC_Player* VC_Player;
	
	// AbilitySystemを使用するうえで必須のコンポーネント
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, meta = (AllowPrivateAccess = "true"))
	UAbilitySystemComponent* AbilitySystem;
};
