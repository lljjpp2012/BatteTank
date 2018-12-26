// Fill out your copyright notice in the Description page of Project Settings.



#include "MyPlayerController.h"
#include "DrawDebugHelpers.h"




#define OUT

void AMyPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	AimTowardsCrosshair();

}

void AMyPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//Get world location if linetrace through crosshair
	//if it hits the landscape
	//Tell controlled tank to aim at this point
	

	FVector OutHitLocation(0); //Out Parameter
	if (GetSightRayHitLocation(OutHitLocation))//Has "side-effect",is going to line trace
	{
		GetControlledTank()->AimAt(OutHitLocation);
	}
	
}
//Get world location of linetrace through crosshair,true if hits landscape
bool AMyPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	//Find the crosshair position
	int32 ViewporSizeX, ViewportSizeY;
	GetViewportSize(ViewporSizeX, ViewportSizeY);
	auto ScreenLocation = FVector2D(ViewporSizeX*CrossHairXLocation, ViewportSizeY*CrossHairYLocation);
	UE_LOG(LogTemp, Warning, TEXT("ScreenLocation:%s"), *ScreenLocation.ToString());
	//"De-project" the screen position of the crosshair to a world direction
	//Line-trace along that Lookdirection,and see what we hit(up to max range)
	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		GetLookVectorHitLocation(LookDirection, OutHitLocation);
		UE_LOG(LogTemp, Warning, TEXT("OutHitLocation:%s"), *OutHitLocation.ToString());
	}
	
	
	return true;
}

bool AMyPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector & LookDirection) const
{
	FVector Temp;
	if (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, Temp, LookDirection))
	{
		return true;
	}
	return false;
}

bool AMyPlayerController::GetLookVectorHitLocation(FVector LookDirection, FVector & HitLocation) const
{
	FHitResult HitResult;
	auto cameraStartLocation = PlayerCameraManager->GetCameraLocation();
	auto EndLocation = cameraStartLocation + (LookDirection * LineTraceRange);
	if (//LineTrace Succedds
		GetWorld()->LineTraceSingleByChannel(HitResult,
			cameraStartLocation,
			EndLocation,
			ECollisionChannel::ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		HitLocation = EndLocation;
	}
	return false;
}



ATank* AMyPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void AMyPlayerController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController not possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("PlayerController :%s Begin Play"),*(ControlledTank->GetName()))//don't forget toFstring "*"
	}
	

}
