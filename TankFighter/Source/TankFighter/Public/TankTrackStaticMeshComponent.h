// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankTrackStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

private:
	UFUNCTION(BlueprintCallable, Category = Input)
	void SetThrottle(float Throttle);
	
};
