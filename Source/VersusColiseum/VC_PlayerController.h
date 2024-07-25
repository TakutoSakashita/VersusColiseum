#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "VC_PlayerController.generated.h"

class AVC_Player;
class AVC_MainCamera;

UCLASS()
class VERSUSCOLISEUM_API AVC_PlayerController : public APlayerController
{
	GENERATED_BODY()
public:
	AVC_PlayerController();
	
protected:
	virtual void BeginPlay() override;

	////////////////////////////////////////// ���̓o�C���h����
	virtual void SetupInputComponent() override;
	
private:
	/********************MovementInput********************/
	// ���_Y����]����
	void LookUp(const float InValue);
	// ���_X����]����
	void Turn(const float InValue);

	// �O�����ړ�����
	void MoveForward(const float InValue);
	// �������ړ�����
	void MoveRight(const float InValue);

	// �_�b�V�� �������
	void StartDashAvoid();
	void EndDashAvoid();

	// �W�����v����
	void StartJump();
	void EndJump();
	
protected:
	AVC_Player* PlayerCharacter;
	AVC_MainCamera* MainCamera;

public:
	UFUNCTION(BlueprintCallable, Category = "VC_GameMode")
	void SetPlayerCharacter(AVC_Player* const InPlayerCharacter) { PlayerCharacter = InPlayerCharacter; }

	UFUNCTION(BlueprintCallable, Category = "VC_GameMode")
	void SetMainCamera(AVC_MainCamera* const InMainCamera) { MainCamera = InMainCamera; }
};
