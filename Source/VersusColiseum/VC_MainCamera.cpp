// Fill out your copyright notice in the Description page of Project Settings.


#include "VC_MainCamera.h"

// Sets default values
AVC_MainCamera::AVC_MainCamera()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AVC_MainCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AVC_MainCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

