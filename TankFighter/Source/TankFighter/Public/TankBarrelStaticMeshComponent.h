// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrelStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS()
class TANKFIGHTER_API UTankBarrelStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float);
};
