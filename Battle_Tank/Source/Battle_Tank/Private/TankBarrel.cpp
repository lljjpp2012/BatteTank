// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"





void UTankBarrel::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesParSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Roll + ElevationChange;
	auto Eleavation = FMath::Clamp< float > (RawNewElevation, MinElevationDegrees, MaxElevationDegress);
	//UE_LOG(LogTemp, Warning, TEXT("ElevationChange: %f,RawNewElevation: %f,Eleavation:"),ElevationChange,RawNewElevation)
	
	//һ��Rotator ������������ptich yaw roll һһ��Ӧ(15-20)
	SetRelativeRotation(FRotator(0,0, Eleavation),true);
	
	
}