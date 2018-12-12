// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"
#include "MyPlayerController.h"
ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (!ControlledTank)
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController not possesing a tank"))
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("TankAIController :%s Begin Play"), *(ControlledTank->GetName()))//don't forget toFstring "*"
	}
	auto PlayerTank = GetPlayerTank();
		if (!PlayerTank)
		{
			UE_LOG(LogTemp, Warning, TEXT("where are you?"))
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("I find you!"))
		}

}

ATank * ATankAIController::GetPlayerTank() const
{
	auto PlayerPawn=
	 GetWorld()->GetFirstPlayerController()->GetPawn();
	if (!PlayerPawn) { return nullptr; }
	return Cast<ATank>(PlayerPawn);
}


