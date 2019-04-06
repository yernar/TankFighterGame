// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankBarrelStaticMeshComponent.h"

void UTankBarrelStaticMeshComponent::Elevate(float ElevationSpeed)
{
	ElevationSpeed = /*FMath::Clamp(ElevationSpeed, 1.f, (-1.f));*/(ElevationSpeed >= 1.f ? 1.f : (ElevationSpeed <= -1.f ? -1.f : 0.f));
	ElevationSpeed *= MaxTankBarrelDPS * GetWorld()->DeltaTimeSeconds;
	float Elevation = RelativeRotation.Pitch + ElevationSpeed;
	SetRelativeRotation(FRotator(FMath::Clamp<float>(Elevation, 
		MinTankBarrelElevationsD, 
		MaxTankBarrelElevationsD), 
		0, 0));
}

