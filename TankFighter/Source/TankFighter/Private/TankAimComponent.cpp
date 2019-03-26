// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAimComponent.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

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

void UTankAimComponent::AimAt(FVector& HitLocation)
{
	FString TankName = GetOwner()->GetName();
	FVector TankBarrelLocation = TankBarrel->GetComponentLocation();
	UE_LOG(LogTemp, Warning, TEXT("%s is aiming at: %s; from: %s"), *TankName, *HitLocation.ToString(), *TankBarrelLocation.ToString())
}

void UTankAimComponent::SetTankBarrel(UStaticMeshComponent* TankBarrel)
{
	this->TankBarrel = TankBarrel;
}

