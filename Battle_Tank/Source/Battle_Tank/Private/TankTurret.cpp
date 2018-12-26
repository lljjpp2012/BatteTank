// Fill out your copyright notice in the Description page of Project Settings.

#include "TankTurret.h"
#include "Engine/World.h"

void UTankTurret::Elevate(float RelativeSpeed)
{
	RelativeSpeed = FMath::Clamp<float>(RelativeSpeed, -1, +1);
	auto ElevationChange = RelativeSpeed * MaxDegreesParSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Yaw + ElevationChange;
	
	//UE_LOG(LogTemp, Warning, TEXT("ElevationChange: %f,RawNewElevation: %f,Eleavation:"),ElevationChange,RawNewElevation)
	/*if (RawNewElevation >= 180)
	{
		RawNewElevation -= 360;
	}
	if (RawNewElevation <= -180)
	{
		RawNewElevation += 360;
	}*/
	//一个Rotator 的三个变量，ptich yaw roll 一一对应(15-20)
	SetRelativeRotation(FRotator(0, RawNewElevation,0 ), true);



}
