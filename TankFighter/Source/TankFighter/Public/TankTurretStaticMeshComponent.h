// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTurretStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankTurretStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	void Rotate(float);

private:
	//DPS = degrees per second
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		float MaxTankTurretDPS = 25.f;
	
};
