// Fill out your copyright notice in the Description page of Project Settings.

#include "Tankaimingcomponent.h"

#include "Kismet/GameplayStatics.h"
#include "Components/ActorComponent.h"


// Sets default values for this component's properties
UTankaimingcomponent::UTankaimingcomponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	//bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = false;

	
}


void UTankaimingcomponent::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	Barrel=BarrelToSet;


}






void UTankaimingcomponent::AimAt(FVector OutHitLocation,float LaunchSpeed)
{
	
	if (!Barrel) { return; }

	FVector OutLaunchVelocity(0);
	FVector StartLocation= Barrel->GetSocketLocation(FName("projectile"));
	UE_LOG(LogTemp, Warning, TEXT(" StartLocation is %s"), *StartLocation.ToString())
	bool bHaveAimSolution =
		(UGameplayStatics::SuggestProjectileVelocity(this,
			OutLaunchVelocity,
			StartLocation,
			OutHitLocation,
			LaunchSpeed,
			false,
			0,
			0,
			ESuggestProjVelocityTraceOption::DoNotTrace));//Calulat the OutLaunchVelocity有默认值的参数可以省略
	if(bHaveAimSolution)
	{
	auto AimDirection = OutLaunchVelocity.GetSafeNormal();
	auto TankName = GetOwner()->GetName();

	MoveBarrelTowards(AimDirection);

	
	UE_LOG(LogTemp, Warning, TEXT(" aim solution found to %s" ),*AimDirection.Rotation().ToString())
	}
	else
	{
		
		UE_LOG(LogTemp,Warning,TEXT("No aim solve found"))

	}

	
}

void UTankaimingcomponent::MoveBarrelTowards(FVector AimDirection)
{
	//work-out difference between current barrel roation,and AimDirection
	auto BarrelRotator = Barrel->GetForwardVector().Rotation();
	auto AimAsRotator = AimDirection.Rotation();
	auto DeltaRotator = AimAsRotator - BarrelRotator;
	

		//Work-out difference between current barrel roation,and aimDirection
		//Move the barrel the right amount this frame
		//Given a max elevation speed,and the frame time
		Barrel->Elevate(1);
}
