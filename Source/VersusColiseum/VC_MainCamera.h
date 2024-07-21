// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VC_MainCamera.generated.h"

class UArrowComponent;
class USpringArmComponent;
class UCameraComponent;

UCLASS()
class VERSUSCOLISEUM_API AVC_MainCamera : public AActor
{
	GENERATED_BODY()
	
public:	
	AVC_MainCamera();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

public:
	void AddPitchRotation(float InValue);
	void AddYawRotation(float InValue);

private:
	void CalculateViewPoint(float height = 100.f/*, FRotator rotate = FRotator(-45, 0, 0)*/);/* pitch , yaw, roll */
	void UpdateOnNormal(const float InDeltaTime);

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UArrowComponent* arrow;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera | Visible", meta = (AllowPrivateAccess = "true"))
		USpringArmComponent* SpringArmComponent;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera | Visible", meta = (AllowPrivateAccess = "true"))
		UCameraComponent* CameraComponent;

	UPROPERTY(VisibleAnywhere, Category = "Camera | Visible")
		FVector ViewPoint;
	UPROPERTY(EditAnywhere, Category = "Camera | Edit")
		float MaxPitch;

public:
	// “ü—Í
	FVector2D inputValue;
	
	UPROPERTY(EditAnywhere)
		float pitch_sensitivity = 2.f;
	UPROPERTY(EditAnywhere)
		float yaw_sensitivity = 2.f;

	UPROPERTY(EditAnywhere)
		float current_pitch_min = -40.f;

	UPROPERTY(EditAnywhere)
		float current_pitch_max = 65.f;

	UPROPERTY(EditAnywhere)
		float boom_length_min = 180.f;

	UPROPERTY(EditAnywhere)
		float current_boom_length_max = 500.f;
	UPROPERTY(EditAnywhere)
		float boom_length_max = 500.f;

private:
	void UpdateRotation(const float DeltaTime);
};
