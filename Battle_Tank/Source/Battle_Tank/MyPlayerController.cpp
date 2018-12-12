// Fill out your copyright notice in the Description page of Project Settings.


#include "MyPlayerController.h"



void AMyPlayerController::Tick(float Deltatime)
{
	Super::Tick(Deltatime);

	UE_LOG(LogTemp,Warning,TEXT("Player controller ticking"))

}

void AMyPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) { return; }
	//Get world location if linetrace through crosshair
	//if it hits the landscape
	//Tell controlled tank to aim at this point
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
