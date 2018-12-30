// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "MyPlayerController.h"
#include "Engine/World.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	
	

}

void ATankAIController::Tick(float DeltaTime)
{
	
	//Get world location if linetrace through crosshair
	//if it hits the landscape
	//Tell controlled tank to aim at this point
	auto PlayerTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	auto ControlledTank = Cast<ATank>(GetPawn());
	if (PlayerTank)
	{
		FVector OutHitLocation = PlayerTank->GetActorLocation();


		ControlledTank->AimAt(OutHitLocation);

		ControlledTank->Fire();
	}

	
	
}



