
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()
	
public:	
	
	AMovingPlatform();

protected:

	virtual void BeginPlay() override;

public:	

	virtual void Tick(float DeltaTime) override;

private:

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	FVector PlatformVelocity = FVector(0,0,300);

	UPROPERTY(EditAnywhere, Category="Moving Platform")
	float MovedDistance = 3000;

	UPROPERTY(EditAnywhere, Category="Rotation")
	FRotator RotationVelocity;
	
	FVector StartLocation;

	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);

	bool ShouldPlatformReturn();
	float GetDistanceMoved();

};
