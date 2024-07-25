#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "VC_MovementInput.generated.h"

class AVC_GameMode;
class AVC_MainCamera;
class AVC_Player;

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class VERSUSCOLISEUM_API UVC_MovementInput : public UActorComponent
{
	GENERATED_BODY()

public:	
	UVC_MovementInput();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void MoveForward(const float InValue);
	void MoveRight(const float InValue);

	// ダッシュ 回避処理
	void StartDashAvoid();
	void EndDashAvoid();

	// ジャンプ処理
	void StartJump();
	void EndJump();
	
protected:
	// 振り向き速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float rotationSpeed = 8.0f;
	// ダッシュ速度
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float dashSpeed = 1500.0f;

private:
	void CharacterRotate() const;

	////////////////////////////////////////// Get関数
	FORCEINLINE AVC_GameMode* GetGameMode() const;

	FORCEINLINE AVC_MainCamera* GetMainCamera() const;

	FORCEINLINE AVC_Player* GetPlayerCharacter() const;
		
};
