// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankAimComponent.h"
#include "Runtime/Engine/Classes/Kismet/GameplayStatics.h"
#include "TankBarrelStaticMeshComponent.h"
#include "TankTurretStaticMeshComponent.h"
#include "Projectile.h"

// Sets default values for this component's properties
UTankAimComponent::UTankAimComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTankAimComponent::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void UTankAimComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
	if (IsReloaded())
	{
		PointerStatus = EPointerStatus::Aiming;
	}
	else
		PointerStatus = EPointerStatus::Reloading;
}

void UTankAimComponent::AimAt(FVector& EndLocation)
{
	if (!ensure(TankBarrel)) return;	
	FVector FireVelocity;
	FVector StartLocation = TankBarrel->GetSocketLocation(FName("ProjectileSocket"));
	FVector AimDirection;
	FString TankName = GetOwner()->GetName();
	FString bTest;
	UGameplayStatics::SuggestProjectileVelocity(this, 
						FireVelocity, 
						StartLocation, 
						EndLocation, 
						ProjectileSpeed, 
						false, 0.f, 0.f, 
						ESuggestProjVelocityTraceOption::DoNotTrace) ? 
				AimDirection = FireVelocity.GetSafeNormal() :
				AimDirection = FVector(0);
	MoveBarrel(AimDirection);
	RotateTurret(AimDirection);
	return;
}

void UTankAimComponent::SetTankTurretBarrel(UTankTurretStaticMeshComponent* TankTurret, UTankBarrelStaticMeshComponent* TankBarrel)
{
	this->TankTurret = TankTurret;
	this->TankBarrel = TankBarrel;
}

void UTankAimComponent::MoveBarrel(FVector& AimDirection)
{
	FRotator BarrelRotation = TankBarrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - BarrelRotation;
	TankBarrel->Elevate(DeltaRotation.Pitch);
	return;
}

void UTankAimComponent::RotateTurret(FVector& AimDirection)
{
	FRotator TurretRotation = TankBarrel->GetForwardVector().Rotation();
	FRotator AimRotation = AimDirection.Rotation();
	FRotator DeltaRotation = AimRotation - TurretRotation;
	( (FMath::Abs(DeltaRotation.Yaw) < 180) ? 
		(TankTurret->Rotate(DeltaRotation.Yaw)) : 
		(TankTurret->Rotate(-DeltaRotation.Yaw)) );
	return;
}

bool UTankAimComponent::IsReloaded() const
{	
	return ((FPlatformTime::Seconds() - LastFireTime) > FireCooldown);
}

void UTankAimComponent::Fire()
{
	if (ensure(TankBarrel && ProjectileType) && IsReloaded())
	{
		AProjectile *Projectile = GetWorld()->SpawnActor<AProjectile>(ProjectileType,
			(TankBarrel->GetSocketLocation(FName("ProjectileSocket"))),
			(TankBarrel->GetSocketRotation(FName("ProjectileSocket"))));
		Projectile->LaunchProjectile(ProjectileSpeed);
		LastFireTime = FPlatformTime::Seconds();
	}
	else if (!ensure(TankBarrel && ProjectileType)) return;
}