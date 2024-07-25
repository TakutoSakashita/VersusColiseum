#pragma once

#include "CoreMinimal.h"
#include "VC_CharacterBase.h"
#include "VC_Player.generated.h"

class UVC_MovementInput;
class UVC_AttackInput;

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
	
public:
	void MoveForward(const float InValue);
	void MoveRight(const float InValue);

	// �_�b�V�� �������
	void StartDashAvoid();
	void EndDashAvoid();

	// �W�����v����
	void StartJump();
	void EndJump();

	////////////////////// BlueprintImplementableEvent
	UFUNCTION(BlueprintImplementableEvent)
	void Init();

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UVC_MovementInput* MoveInputComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component", meta = (AllowPrivateAccess = "true"))
	UVC_AttackInput* AttackInputComponent;

	// ISF_DamageableInterface ����Čp������܂���
	virtual void GetDamage(int32 damage) override;
};
