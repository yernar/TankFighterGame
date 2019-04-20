// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankPlayerController.h"
#include "TankAimComponent.h"
#include "Tank.h"

void ATankPlayerController::BeginPlay()
{
	Super::BeginPlay();
	if (!ensure(GetAimComponent())) return;
	FoundAimingComponent(GetAimComponent());
}

void ATankPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	AimTowardsCrosshair();
}

void ATankPlayerController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!ensure(PossessedTank)) return;

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankPlayerController::OnPossessedTankDeath);
	}
}

void ATankPlayerController::OnPossessedTankDeath()
{
	if (!GetPawn()) return;
	StartSpectatingOnly();
}

UTankAimComponent* ATankPlayerController::GetAimComponent() const
{
	return GetPawn()->FindComponentByClass<UTankAimComponent>();
}

void ATankPlayerController::AimTowardsCrosshair()
{
	if (!ensure(GetPawn())) return;
	if (!ensure(GetAimComponent())) return;
	if (!ensure(this)) return;

	FVector HitLocation;
	if (GetSightRayHitLocation(HitLocation))
	{
		GetAimComponent()->AimAt(HitLocation);
	}
}

bool ATankPlayerController::GetSightRayHitLocation(FVector& HitLocation) const
{
	int32 SizeX, SizeY; // Viewport sizes
	GetViewportSize(SizeX, SizeY);
	FVector2D ScreenLocation = FVector2D(SizeX * CrossHairXLocation, CrossHairYLocation * SizeY);

	FVector LookDirection;
	if (GetLookDirection(ScreenLocation, LookDirection))
	{
		return GetLookVectorHitLocation(LookDirection, HitLocation);		
	}		
	else return false;
}

bool ATankPlayerController::GetLookDirection(const FVector2D& ScreenLocation, FVector& LookDirection) const
{
	FVector WorldLocation; // Camera's world location and look direction
	return (DeprojectScreenPositionToWorld(ScreenLocation.X, ScreenLocation.Y, WorldLocation, LookDirection));
}

bool ATankPlayerController::GetLookVectorHitLocation(const FVector& LookDirection, FVector& HitLocation) const
{
	FHitResult HitResult;
	FVector Start = PlayerCameraManager->GetCameraLocation(); // Starting Location
	FVector End = Start + LookDirection * LineTraceRange; // Ending Location
	if (GetWorld()->LineTraceSingleByChannel(HitResult, 
			Start, 
			End, 
			ECC_Visibility))
	{
		HitLocation = HitResult.Location;
		return true;
	}
	else
	{
		HitLocation = FVector(0);
		return false;
	}			 
}