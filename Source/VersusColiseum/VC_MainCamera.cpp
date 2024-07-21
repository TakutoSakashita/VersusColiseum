#include "VC_MainCamera.h"
#include "VC_Player.h"
#include "VC_PlayerController.h"
#include "VC_GameMode.h"
#include "Components/ArrowComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/GameplayStatics.h"

AVC_MainCamera::AVC_MainCamera()
	: ViewPoint(FVector(0.f))
	, MaxPitch(60.f)
{
	PrimaryActorTick.bCanEverTick = true;

	arrow = CreateDefaultSubobject<UArrowComponent>(TEXT("Arrow"));
	if (arrow)
		RootComponent = arrow;

	if (IsValid(SpringArmComponent = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArmComponent"))))
	{
		SpringArmComponent->SetupAttachment(RootComponent);
		SpringArmComponent->TargetArmLength = 500.f;
		SpringArmComponent->bDoCollisionTest = false;
		SpringArmComponent->bEnableCameraLag = true;
	}

	if (IsValid(CameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComponent"))))
	{
		CameraComponent->SetupAttachment(SpringArmComponent, USpringArmComponent::SocketName);
		CameraComponent->AspectRatio = 1.95f;
	}
}

void AVC_MainCamera::BeginPlay()
{
	Super::BeginPlay();
	// èâä˙âª
	if (AVC_GameMode* const VC_GameMode = Cast<AVC_GameMode>(UGameplayStatics::GetGameMode(GetWorld())))
	{
		VC_GameMode->SetMainCamera(this);

		if (AVC_Player* const VC_Player = VC_GameMode->GetPlayerCharacter())
			ViewPoint = VC_Player->GetActorLocation();
	}


	APlayerController* const PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (PlayerController)
		PlayerController->SetViewTargetWithBlend(this);

	AVC_PlayerController* CustomController = Cast<AVC_PlayerController>(PlayerController);
	if (CustomController)
		CustomController->SetMainCamera(this);
}

void AVC_MainCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	// null check
	AVC_GameMode* const VC_GameMode = Cast<AVC_GameMode>(UGameplayStatics::GetGameMode(GetWorld()));
	if (!IsValid(VC_GameMode)) return;
	
	AVC_Player* const VC_Player = VC_GameMode->GetPlayerCharacter();
	if (!IsValid(VC_Player)) return;
	
	UpdateOnNormal(DeltaTime);
	UpdateRotation(DeltaTime);

}
void AVC_MainCamera::UpdateRotation(const float DeltaTime)
{
	// èàóùóéÇøëŒçÙ
	float rotateCorrection = 60.f / (1.0f / DeltaTime);

	// äpìxåvéZ
	FRotator rotation = arrow->GetRelativeRotation();
	// pitchêßå¿
	rotation.Pitch = FMath::Clamp(rotation.Pitch + (inputValue.Y * pitch_sensitivity * rotateCorrection), current_pitch_min, current_pitch_max);
	rotation.Yaw += inputValue.X * yaw_sensitivity * rotateCorrection;
	// ãóó£ï‚ê≥
	float newLength = (-rotation.Pitch - current_pitch_min) / (current_pitch_max - current_pitch_min) * (current_boom_length_max - boom_length_min) + boom_length_min;
	SpringArmComponent->TargetArmLength = newLength;
	// âÒì]
	arrow->SetRelativeRotation(rotation);
}

void AVC_MainCamera::AddPitchRotation(float InValue)
{
	if (InValue == 0.f) return;

	// åªç›ÇÃÉJÉÅÉâÇÃâÒì]ó Ç…â¡éZ
	FRotator NewRotation = GetActorRotation();
	NewRotation.Pitch += InValue;

	// ï‚ê≥
	if (NewRotation.Pitch >= MaxPitch)
		NewRotation.Pitch = MaxPitch;
	else if (NewRotation.Pitch <= -MaxPitch)
		NewRotation.Pitch = -MaxPitch;

	// ìKóp
	SetActorRotation(NewRotation);
}

void AVC_MainCamera::AddYawRotation(float InValue)
{
	if (InValue == 0.f) return;

	// åªç›ÇÃÉJÉÅÉâÇÃâÒì]ó Ç…â¡éZ
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += InValue;

	// ìKóp
	SetActorRotation(NewRotation);
}

void AVC_MainCamera::CalculateViewPoint(float height)
{
	if (APawn* const Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		//UE_LOG(LogTemp,Warning,TEXT("CalculateViewPoint"));
		ViewPoint = Player->GetActorLocation() + FVector(0, 0, height);
	}
}

void AVC_MainCamera::UpdateOnNormal(const float InDeltaTime)
{
	//UE_LOG(LogTemp,Warning,TEXT("UpdateOnNormal"));

	if (APawn* const Player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0))
	{
		CalculateViewPoint();
		ViewPoint = Player->GetActorLocation();
		SetActorLocation(ViewPoint);
	}
}