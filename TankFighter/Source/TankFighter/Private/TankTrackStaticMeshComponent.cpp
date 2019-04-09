// Copyright Magic Inc., Yernar Aldabergenov© 2019.


#include "TankTrackStaticMeshComponent.h"

UTankTrackStaticMeshComponent::UTankTrackStaticMeshComponent()
{
	PrimaryComponentTick.bCanEverTick = false;
}

void UTankTrackStaticMeshComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}

void UTankTrackStaticMeshComponent::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrackStaticMeshComponent::OnCompHit);
}

void UTankTrackStaticMeshComponent::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	DriveTracks();
	SidewaysForce();
	Throttle = 0.f;
}

void UTankTrackStaticMeshComponent::SidewaysForce()
{
	UStaticMeshComponent* TankRoot = Cast<UStaticMeshComponent>(GetOwner()->GetRootComponent());
	FVector CorrectionAcceleration = (-FVector::DotProduct(GetRightVector(), GetComponentVelocity())) / (GetWorld()->GetDeltaSeconds()) * GetRightVector(); // Accelartion
	FVector CorrectionForce = (TankRoot->GetMass() * CorrectionAcceleration) / 2; // Divide to 2, as we have 2 Tracks
	TankRoot->AddForce(CorrectionForce);
}

void UTankTrackStaticMeshComponent::SetThrottle(float CurrentThrottle)
{
	Throttle = FMath::Clamp<float>(Throttle + CurrentThrottle, -1.f, 1.f);
	// DriveTracks(Throttle);
}

void UTankTrackStaticMeshComponent::DriveTracks()
{
	FVector ForceApplied = GetForwardVector() * MaxTrackDrivingF * Throttle;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

