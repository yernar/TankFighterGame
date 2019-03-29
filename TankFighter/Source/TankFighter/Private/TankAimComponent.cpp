// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrelStaticMeshComponent.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTankAimComponent::AimAt(FVector& EndLocation, float ProjectileSpeed)
{
	if (!TankBarrel) return;
	//UE_LOG(LogTemp, Warning, TEXT("TEST UTANKAIMCOMPONENT AIMAT"))
	
	FVector FireVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("ProjectileSocket"));
	FVector AimDirection;
	FString TankName = GetOwner()->GetName();
	///FVector TankBarrelLocation = TankBarrel->GetComponentLocation();
	FString bTest;
	UGameplayStatics::SuggestProjectileVelocity(this, 
												FireVelocity, 
												StartLocation, 
												EndLocation, 
												ProjectileSpeed, 
												false, 
												0.f, 
												0.f, 
												ESuggestProjVelocityTraceOption::DoNotTrace) ? 
						AimDirection = FireVelocity.GetSafeNormal() :
						AimDirection = FVector(0);
	MoveBarrel(AimDirection);
	UE_LOG(LogTemp, Warning, TEXT("%s AimingDirection: %s"), *TankName, *AimDirection.ToCompactString())
	return;
}

void UTankAimComponent::SetTankBarrel(UTankBarrelStaticMeshComponent* TankBarrel)
{
	this->TankBarrel = TankBarrel;
}

void UTankAimComponent::MoveBarrel(FVector& AimDirection)
{
	FRotator BarrelRotation = TankBarrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;
	TankBarrel->Elevate(AimRotation.Pitch);
	return;
	//UE_LOG(LogTemp, Warning, TEXT("AimRotation: %s;\nBarrelRotation: %s;\nDeltaRotator: %s;"), *BarrelRotation.ToCompactString(), *AimRotation.ToCompactString(), *DeltaRotation.ToCompactString())
}

