// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankBarrelStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);

private:
	//DPS = degrees per second
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxTankBarrelDPS = 10.f;
	//D = degrees
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxTankBarrelElevationsD = 25.5f; 
	//D = degrees
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MinTankBarrelElevationsD = 0.f;
};
