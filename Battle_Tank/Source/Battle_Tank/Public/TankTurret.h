// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurret.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent), hidecategories = ("Collision"))
class BATTLE_TANK_API UTankTurret : public UStaticMeshComponent
{
	GENERATED_BODY()
public:
		void Elevate(float RelativeSpeed);
private:
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxDegreesParSecond = 40;//Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesParSecond = 0;
	
	
};
