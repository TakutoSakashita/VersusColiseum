#include "VC_WeaponBase.h"

// Sets default values
AVC_WeaponBase::AVC_WeaponBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVC_WeaponBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVC_WeaponBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

