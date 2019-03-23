// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	/*auto ControlledTank = GetControlledTank();
	if (ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *ControlledTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("PlayerController is not being posessed!"))*/
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!GetControlledTank()) return;

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& OutHitLocation) const
{
	int32 SizeX, SizeY; // Viewport sizes
	GetViewportSize(SizeX, SizeY);
	auto ScreenLocation = FVector2D(SizeX * CrossHairXLocation, CrossHairYLocation * SizeY);
	///UE_LOG(LogTemp, Warning, TEXT("Location of Screen: %s"), *ScreenLocation.ToString())

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *LookDirection.ToString())
		return true;
	}		
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LookDirection Error"))
		return false;
	}	
}

bool ATankPlayerController::GetLookDirection(FVector2D ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; /// Camera's world location and look direction
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection));
}

