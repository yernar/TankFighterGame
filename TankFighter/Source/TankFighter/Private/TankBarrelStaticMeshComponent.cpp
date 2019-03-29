// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelStaticMeshComponent.h"

void UTankBarrelStaticMeshComponent::Elevate(float ElevationSpeed)
{
	ElevationSpeed = (ElevationSpeed >= 1.f ? 1.f : (ElevationSpeed <= -1.f ? -1.f : 0.f));
	float ElevationChange = ElevationSpeed * MaxTankBarrelDPS * GetWorld()->DeltaTimeSeconds;
	float RawNewElevation = RelativeRotation.Pitch + ElevationChange;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(RawNewElevation, MinTankBarrelElevationsD, MaxTankBarrelElevationsD), 0, 0));
}

