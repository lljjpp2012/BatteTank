// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta=(BlueprintSpawnableComponent),hidecategories = ("Collision"))//add this to Buleprint mode 后一项表示忽略的蓝图属性选项
class BATTLE_TANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	//-1 is max downward speed,and +1 is max up movement
	void Elevate(float RelativePersecond);
private:
	UPROPERTY(EditAnywhere,Category = Setup)//"Category"指在引擎中属性栏的名称，创建了一个名叫"TankBarrel"的属性栏包含了此成员变量
		float MaxDegreesParSecond = 20;//Sensible default
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinDegreesParSecond = 5;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MaxElevationDegress = 300;
	UPROPERTY(EditAnywhere, Category = Setup)
		float MinElevationDegrees = -30;
	
};
