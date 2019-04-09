// Copyright Magic Inc., Yernar Aldabergenov© 2019.


#include "TankTrackStaticMeshComponent.h"

UTankTrackStaticMeshComponent::UTankTrackStaticMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UTankTrackStaticMeshComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionAcceleration = (-FVector::DotProduct(GetRightVector(), GetComponentVelocity())) / DeltaTime * GetRightVector(); // Accelartion
	FVector CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Divide to 2, as we have 2 Tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrackStaticMeshComponent::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * MaxTrackDrivingF * Throttle;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

