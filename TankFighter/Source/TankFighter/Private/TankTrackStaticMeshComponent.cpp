// Fill out your copyright notice in the Description page of Project Settings.


#include "TankTrackStaticMeshComponent.h"

void UTankTrackStaticMeshComponent::SetThrottle(float Throttle)
{
	///UE_LOG(LogTemp, Error, TEXT("%s Throttling: %f"), *GetName(), Throttle)
	FVector ForceApplied = GetForwardVector() * MaxTrackDrivingF * Throttle;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

