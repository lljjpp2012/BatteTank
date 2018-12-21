// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent),hidecategories = ("Collision"))//add this to Buleprint mode ��һ���ʾ���Ե���ͼ����ѡ��
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward speed,and +1 is max up movement
	void Elevate(float RelativePersecond);
private:
	UPROPERTY(EditAnywhere,Category = Setup)//"Category"ָ�������������������ƣ�������һ������"TankBarrel"�������������˴˳�Ա����
		float MaxDegreesParSecond = 20;//Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesParSecond = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegress = 300;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = -30;
	
};
