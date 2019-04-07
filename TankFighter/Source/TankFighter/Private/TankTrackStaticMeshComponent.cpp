// Copyright Magic Inc., Yernar Aldabergenov© 2019.


#include "TankTrackStaticMeshComponent.h"

void UTankTrackStaticMeshComponent::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * MaxTrackDrivingF * Throttle;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

