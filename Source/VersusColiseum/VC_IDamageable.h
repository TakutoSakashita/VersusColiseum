#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "VC_IDamageable.generated.h"

UINTERFACE(MinimalAPI)
class UVC_IDamageable : public UInterface
{
	GENERATED_BODY()
};

class VERSUSCOLISEUM_API IVC_IDamageable
{
	GENERATED_BODY()

public:
	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
	virtual void GetDamage(int32 damage) = 0;
};
