// Fill out your copyright notice in the Description page of Project Settings.


#include "VC_AnimInstance.h"

#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Character.h"

void UVC_AnimInstance::NativeInitializeAnimation()
{
	Super::NativeInitializeAnimation();

	if (OwnerCharacter  == nullptr)
	{
		OwnerCharacter  = Cast<ACharacter>(TryGetPawnOwner());
	}
}

void UVC_AnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwnerCharacter  == nullptr)
	{
		OwnerCharacter = Cast<ACharacter>(TryGetPawnOwner());
	}
	if (OwnerCharacter)
	{
		FVector Velocity = OwnerCharacter ->GetVelocity();
		Velocity.Z = 0;
		Speed = Velocity.Size();
		IsFall = OwnerCharacter ->GetMovementComponent()->IsFalling();
		
		if (OwnerCharacter ->GetCharacterMovement()->GetCurrentAcceleration().Size() > 0.f)
		{
			IsAccelerating = true;
		}
		else
		{
			IsAccelerating = false;
		}
	}
}



