// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelStaticMeshComponent.h"

void UTankBarrelStaticMeshComponent::Elevate(float ElevationSpeed)
{
	ElevationSpeed = (ElevationSpeed >= 1.f ? 1.f : (ElevationSpeed <= -1.f ? -1.f : 0.f));
	ElevationSpeed *= MaxTankBarrelDPS * GetWorld()->DeltaTimeSeconds;
	float Elevation = RelativeRotation.Pitch + ElevationSpeed;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(Elevation, MinTankBarrelElevationsD, MaxTankBarrelElevationsD), 0, 0));
}

