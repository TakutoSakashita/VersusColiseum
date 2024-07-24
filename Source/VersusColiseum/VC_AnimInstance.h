#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "VC_AnimInstance.generated.h"


UCLASS()
class VERSUSCOLISEUM_API UVC_AnimInstance : public UAnimInstance
{
	GENERATED_BODY()

public:
	virtual void NativeInitializeAnimation() override;

	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	
protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Movement)
	float Speed;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	bool IsAccelerating;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	bool IsFall;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement)
	class ACharacter* OwnerCharacter;
};
