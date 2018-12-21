// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Tank.h"
#include "TankAIController.generated.h"

/**
 * 
 */
UCLASS()
class BATTLE_TANK_API ATankAIController : public AAIController
{
	GENERATED_BODY()

private:
	    ATank* GetControlledTank() const;

		virtual void BeginPlay() override;
	
		virtual void Tick(float DeltaTime) override;

		ATank*GetPlayerTank()const;
};
