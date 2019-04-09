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

void UTankTrackStaticMeshComponent::BeginPlay()
{
	OnComponentHit.AddDynamic(this, &UTankTrackStaticMeshComponent::OnCompHit);
}

void UTankTrackStaticMeshComponent::OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	UE_LOG(LogTemp, Warning, TEXT("HIITTTTING"))
}

void UTankTrackStaticMeshComponent::SetThrottle(float Throttle)
{
	FVector ForceApplied = GetForwardVector() * MaxTrackDrivingF * Throttle;
	FVector ForceLocation = GetComponentLocation();
	UPrimitiveComponent* TankRoot = Cast<UPrimitiveComponent>(GetOwner()->GetRootComponent());
	TankRoot->AddForceAtLocation(ForceApplied, ForceLocation);
}

