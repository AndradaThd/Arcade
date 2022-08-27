

#include "MovingPlatform.h"

// Sets default values
AMovingPlatform::AMovingPlatform()
{
	PrimaryActorTick.bCanEverTick = true;

}

void AMovingPlatform::BeginPlay()
{
	Super::BeginPlay();
	StartLocation = GetActorLocation();
	

}

void AMovingPlatform::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	MovePlatform(DeltaTime);

	RotatePlatform(DeltaTime);
}

void AMovingPlatform::MovePlatform(float DeltaTime)
{
	
	if(ShouldPlatformReturn())											
	{		
		FVector MoveDirection = PlatformVelocity.GetSafeNormal();
		StartLocation = StartLocation + MoveDirection * MovedDistance;
		SetActorLocation(StartLocation);
		PlatformVelocity = -PlatformVelocity;
	}
	else
	{
		FVector CurrentLocation = GetActorLocation();							
		CurrentLocation=CurrentLocation + PlatformVelocity * DeltaTime;			
		SetActorLocation(CurrentLocation);	
	}
}

void AMovingPlatform::RotatePlatform(float DeltaTime)
{
	UE_LOG(LogTemp, Error, TEXT("%s rotating..."), *GetName());
	AddActorLocalRotation(RotationVelocity * DeltaTime);
}

bool AMovingPlatform::ShouldPlatformReturn()
{
	return GetDistanceMoved() > MovedDistance;
}

float AMovingPlatform::GetDistanceMoved()
{
	return FVector::Dist(StartLocation, GetActorLocation());
}
