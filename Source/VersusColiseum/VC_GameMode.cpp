#include "VC_GameMode.h"
#include "VC_Player.h"
#include "VC_PlayerController.h"
#include "Kismet/GameplayStatics.h"

AVC_GameMode::AVC_GameMode()
: PlayerCharacter(nullptr)
	, MainCamera(nullptr)
	, bIsInHitStop(false)
	, HitStopSpeed(0.5f)
	, HitStopTime(0.f)
	, Timer_HitStop(0.f)
{
	PrimaryActorTick.bCanEverTick = true;

	PlayerControllerClass = AVC_PlayerController::StaticClass();
}

void AVC_GameMode::BeginPlay()
{
	Super::BeginPlay();
}

void AVC_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsInHitStop)
	{
		// ヒットストップ時にも一定のDeltaTimeの値にする
		Timer_HitStop += DeltaTime * (1.f / HitStopSpeed);
		if (Timer_HitStop > HitStopTime)
		{
			UGameplayStatics::SetGlobalTimeDilation(GetWorld(), 1.f);
			bIsInHitStop = false;
			Timer_HitStop = 0.f;
			HitStopTime = 0.f;
		}
	}
}

void AVC_GameMode::StartHitStop(const float InHitStopSpeed, const float InHitStopTime)
{
	HitStopTime = 0.f;

	HitStopSpeed = InHitStopSpeed;
	HitStopTime = InHitStopTime;

	UGameplayStatics::SetGlobalTimeDilation(GetWorld(), HitStopSpeed);
	bIsInHitStop = true;
}
