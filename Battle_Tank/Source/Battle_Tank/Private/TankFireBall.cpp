// Fill out your copyright notice in the Description page of Project Settings.

#include "TankFireBall.h"

#include "GameFramework/ProjectileMovementComponent.h"


// Sets default values
ATankFireBall::ATankFireBall()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	ProjectileMovement= CreateDefaultSubobject<UProjectileMovementComponent>(FName("ProjectileMovementComponent"));
	ProjectileMovement->bAutoActivate = false;
}

// Called when the game starts or when spawned
void ATankFireBall::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ATankFireBall::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATankFireBall::LaunchProjectile(float Speed)
{
	auto Time = GetWorld()->GetTimeSeconds();
	
		ProjectileMovement->SetVelocityInLocalSpace(FVector::ForwardVector * Speed);
	ProjectileMovement->Activate();
}