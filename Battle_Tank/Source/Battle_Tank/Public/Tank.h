// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tankaimingcomponent.h"
#include "TankFireBall.h"
#include "Tank.generated.h"

class UTankBarrel;
class UTankTurret;
class UTankTrack;


UCLASS()
class BATTLE_TANK_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UTankaimingcomponent*TankAimingCompononent = nullptr;

public:	
	// Called every frame
	/*virtual void Tick(float DeltaTime) override;*/

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	void AimAt(FVector OutHitLocation);
	


	UFUNCTION(BlueprintCallable,Category=Setup)
	void SetBarrelReference(UTankBarrel*BarrelToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
	void SetTurretReference(UTankTurret*TurretToSet);

	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTrackReference(UTankTrack*LeftTrackToSet,UTankTrack*RightTrackToSet);





	UPROPERTY(EditAnywhere, Category = Firing)
		float LaunchSpeed = 4000;//Sensible starting value of 1000m/s

	UFUNCTION(BlueprintCallable,Category = Fire)
		void Fire();

	UPROPERTY(EditAnywhere, Category = Setup)
		TSubclassOf<ATankFireBall>TankFireBlueprint;
	//Local barrel reference for spawning projectile(tankfire-ball)
	UTankBarrel*Barrel = nullptr;

	UPROPERTY(EditDefaultsOnly, Category =Firing)
	float ReloadTimeInSeconds = 3.f;
	
	double LastFireTime = 0;
};
