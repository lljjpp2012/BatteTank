// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrel.h"
#include "Components/ActorComponent.h"
#include "Engine/World.h"
#include "Components/SceneComponent.h"





void UTankBarrel::Elevate(float RelativeSpeed)
{
	auto ElevationChange = RelativeSpeed * MaxDegreesParSecond*GetWorld()->DeltaTimeSeconds;
	auto RawNewElevation = RelativeRotation.Roll + ElevationChange;
	auto Eleavation = FMath::Clamp< float > (RawNewElevation, MinElevationDegrees, MaxElevationDegress);
	UE_LOG(LogTemp, Warning, TEXT("ElevationChange: %f,RawNewElevation: %f,Eleavation:"),ElevationChange,RawNewElevation)
	
	//������ϣ�һ��Rotator ������������ptich yaw roll һһ��Ӧ����֪�� Ӳ����һ�ޣ����Ǿ��ˣ� 
	SetRelativeRotation(FRotator(0,0, Eleavation),true);
	
	
}