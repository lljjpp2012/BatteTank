// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "Engine/World.h"


// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick =false;

	// No need to protect points as added at construction
	TankAimingCompononent = CreateDefaultSubobject<UTankaimingcomponent>(FName("Aiming Component"));

}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame


// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ATank::AimAt(FVector OutHitLocation)
{
	
	TankAimingCompononent->AimAt(OutHitLocation,LaunchSpeed);
}

void ATank::SetBarrelReference(UTankBarrel * BarrelToSet)
{
	TankAimingCompononent->SetBarrelReference(BarrelToSet);

	Barrel = BarrelToSet;

}
void ATank::SetTurretReference(UTankTurret * TurretToSet)
{
	TankAimingCompononent->SetTurretReference(TurretToSet);
}

void ATank::SetTrackReference(UTankTrack * LeftTrackToSet,UTankTrack*RightTrackToSet)
{
	TankAimingCompononent->SetTrackReference(LeftTrackToSet,RightTrackToSet);
	
}

void ATank::Fire()
{
	bool isReloaded = (FPlatformTime::Seconds() - LastFireTime) > ReloadTimeInSeconds;
	if (!TankFireBlueprint)
	{
		UE_LOG(LogTemp, Warning, TEXT("you don't have any kind of ball"))
			return;
	}
	if (Barrel && isReloaded) 
	{
		//Spawn aprojectile at the socket location on the barrel
		FVector FireballLocation = Barrel->GetSocketLocation(FName("projectile"));
		FRotator FireballRotation = Barrel->GetSocketRotation(FName("projectile"));
		auto Fireball = GetWorld()->SpawnActor<ATankFireBall>(TankFireBlueprint, FireballLocation, FireballRotation);
		FString name = GetName();
		
		Fireball->LaunchProjectile(LaunchSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	
	
}
