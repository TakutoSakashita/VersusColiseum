#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VC_GameMode.generated.h"

class AVC_Player;
class AVC_MainCamera;

UCLASS()
class VERSUSCOLISEUM_API AVC_GameMode : public AGameModeBase
{
	GENERATED_BODY()
public:
	AVC_GameMode();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	
public:
	// �q�b�g�X�g�b�v�J�n
	UFUNCTION(BlueprintCallable, Category = "GameMode")
	void StartHitStop(const float InHitStopSpeed, const float InHitStopTime);

private:
	UPROPERTY(VisibleAnywhere, Category = "GameMode")
	AVC_Player* PlayerCharacter;

	UPROPERTY(VisibleAnywhere, Category = "GameMode")
	AVC_MainCamera* MainCamera;

public:
	void SetPlayerCharacter(AVC_Player* const InPlayerCharacter) { PlayerCharacter = InPlayerCharacter; }
	void SetMainCamera(AVC_MainCamera* const InMainCamera) { MainCamera = InMainCamera; }

	UFUNCTION(BlueprintCallable, Category = "VC_GameMode")
	AVC_Player* GetPlayerCharacter() const { return PlayerCharacter; }
	UFUNCTION(BlueprintCallable, Category = "VC_GameMode")
	AVC_MainCamera* GetMainCamera() const { return MainCamera; }

private:
	// �q�b�g�X�g�b�v����
	UPROPERTY(VisibleInstanceOnly, Category = "HitStop | Visible")
	bool bIsInHitStop;
	// �q�b�g�X�g�b�v�̑��x
	UPROPERTY(EditAnywhere, Category = "HitStop | Edit")
	float HitStopSpeed;
	// �q�b�g�X�g�b�v�̎���
	UPROPERTY(VisibleInstanceOnly, Category = "HitStop | Visible")
	float HitStopTime;
	// �q�b�g�X�g�b�v�^�C�}�[�p
	UPROPERTY(VisibleInstanceOnly, Category = "HitStop | Visible")
	float Timer_HitStop;
};
