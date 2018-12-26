// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankBarrel.h"
#include "TankTurret.h"
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

	void SetTurretReference(UTankTurret*TurretToSet);
	

protected:
	// Called when the game starts
	//virtual void BeginPlay() override;

	
public:	
	// Called every frame
	//virtual void Tick(float DeltaTime) override;
	
	void AimAt(FVector OutHitLocation,float LaunchSpeed);

	
private:
	void MoveBarrelTowards(FVector AimDirection);
	UTankBarrel*Barrel = nullptr;
	UTankTurret*Turret = nullptr;
};
