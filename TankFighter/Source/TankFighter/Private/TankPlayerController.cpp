// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	/*ATank* ControlledTank = GetControlledTank();
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
		///UE_LOG(LogTemp, Error, TEXT("SAD"))
		GetControlledTank()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 SizeX, SizeY; // Viewport sizes
	GetViewportSize(SizeX, SizeY);
	FVector2D ScreenLocation = FVector2D(SizeX * CrossHairXLocation, CrossHairYLocation * SizeY);
	///UE_LOG(LogTemp, Warning, TEXT("Location of Screen: %s"), *ScreenLocation.ToString())

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		///UE_LOG(LogTemp, Warning, TEXT("LookDirection: %s"), *HitLocation.ToString())
		GetLookVectorHitLocation(LookDirection, HitLocation);
		return true;
	}		
	else
	{
		UE_LOG(LogTemp, Error, TEXT("LookDirection Error"))
		return false;
	}	
}

bool ATankPlayerController::GetLookDirection(const FVector2D& ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; /// Camera's world location and look direction
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection));
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector Start = PlayerCameraManager->GetCameraLocation(); /// Starting Location
	FVector End = Start + LookDirection * LineTraceRange; /// Ending Location
	if (GetWorld()->LineTraceSingleByChannel(HitResult, 
											Start, 
											End, 
											ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		///UE_LOG(LogTemp, Warning, TEXT("TEST TRUE"))
		return true;
	}
	else
	{
		HitLocation = FVector(0);
		///UE_LOG(LogTemp, Warning, TEXT("TEST FALSE"))
		return false;
	}
			 
}

