// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankTurretStaticMeshComponent.h"

void UTankTurretStaticMeshComponent::Rotate(float RotationSpeed)
{
	RotationSpeed = /*FMath::Clamp(RotationSpeed, 1.f, (-1.f));*/(RotationSpeed >= 1.f ? 1.f : (RotationSpeed <= -1.f ? -1.f : 0.f));
	RotationSpeed *= MaxTankTurretDPS * GetWorld()->DeltaTimeSeconds;
	float Rotation = RelativeRotation.Yaw + RotationSpeed;
	SetRelativeRotation(FRotator(0.f, Rotation, 0.f));
}
