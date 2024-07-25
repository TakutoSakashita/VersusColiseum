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

	////////////////////////////////////////// 入力バインド処理
	virtual void SetupInputComponent() override;
	
private:
	/********************MovementInput********************/
	// 視点Y軸回転処理
	void LookUp(const float InValue);
	// 視点X軸回転処理
	void Turn(const float InValue);

	// 前方向移動処理
	void MoveForward(const float InValue);
	// 横方向移動処理
	void MoveRight(const float InValue);

	// ダッシュ 回避処理
	void StartDashAvoid();
	void EndDashAvoid();

	// ジャンプ処理
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
