// Fill out your copyright notice in the Description page of Project Settings.

#include "Tank.h"
#include "TankAimComponent.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	TankAimComponent = CreateDefaultSubobject<UTankAimComponent>(FName("Aim Components"));
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();	
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void ATank::AimAt(FVector& HitLocation)
{
	///UE_LOG(LogTemp, Warning, TEXT("TEST ATANK AIMAT"))
	TankAimComponent->AimAt(HitLocation, ProjectileSpeed);
}

void ATank::SetTankBarrel(UTankBarrelStaticMeshComponent* TankBarrel)
{
	TankAimComponent->SetTankBarrel(TankBarrel);
}