// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "CoreMinimal.h"

#include "GameFramework/PlayerController.h"
#include "Tank.h"
#include "MyPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API AMyPlayerController : public APlayerController
{
	GENERATED_BODY()
	
public:
	ATank* GetControlledTank() const;

	virtual void BeginPlay() override;
	
	virtual void Tick(float DeltaTime) override;

	//Start the tank moving the barrel so that a shot would it where
	//the crosshair intersects the world
	void AimTowardsCrosshair();
	//Return an OUT parameter,true if hit landscape
	bool GetSightRayHitLocation(FVector& OutHitLocation) const;
private:
	UPROPERTY(EditAnywhere)
	float CrossHairXLocation = 0.5;
	UPROPERTY(EditAnywhere)
	float CrossHairYLocation=0.3333;
	UPROPERTY(EditAnywhere)
	float LineTraceRange = 1000000;
	FVector PlayerViewPointLocation;
	FRotator PlayerViewPointRocation;
	
	bool GetLookDirection(FVector2D ScreenLocation,FVector& LookDirection) const;
	bool GetLookVectorHitLocation(FVector LookDirection, FVector& HitLocation) const;
};
