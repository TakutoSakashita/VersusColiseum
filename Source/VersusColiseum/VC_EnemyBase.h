#pragma once

#include "CoreMinimal.h"
#include "VC_CharacterBase.h"
#include "VC_EnemyBase.generated.h"

UCLASS()
class VERSUSCOLISEUM_API AVC_EnemyBase : public AVC_CharacterBase
{
	GENERATED_BODY()

public:
	// EnemyManegerに書く予定
	// AVC_EnemyBase* GetNearestEnemy() {return nullptr;}
	
private:
	// ISF_DamageableInterface を介して継承されました
	virtual void GetDamage(int32 damage) override;
};
