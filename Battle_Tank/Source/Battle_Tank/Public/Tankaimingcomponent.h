// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "Tankaimingcomponent.generated.h"

//class UTankBarrel;//Forward Declaration

//Holds barrel's properties and Elevate method 此注释会在蓝图展示
UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class BATTLE_TANK_API UTankaimingcomponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankaimingcomponent();

	void SetBarrelReference(UTankBarrel*BarrelToSet);

	

protected:
	// Called when the game starts
	

	
public:	
	// Called every frame
	

	void AimAt(FVector HitLocation,float LaunchSpeed);

	
private:
	void MoveBarrelTowards(FVector AimDirection);
	UTankBarrel*Barrel = nullptr;
};
