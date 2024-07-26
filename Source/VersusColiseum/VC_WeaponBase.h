#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "VC_WeaponBase.generated.h"

UCLASS()
class VERSUSCOLISEUM_API AVC_WeaponBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AVC_WeaponBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
