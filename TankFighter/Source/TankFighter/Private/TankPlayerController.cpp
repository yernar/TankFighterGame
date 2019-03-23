// Fill out your copyright notice in the Description page of Project Settings.

#include "TankPlayerController.h"

void ATankPlayerController::BeginPlay() 
{
	Super::BeginPlay();
	auto ControlledTank = GetControlledTank();
	if (ControlledTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayerController posessing: %s"), *ControlledTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("Tank is not being posessed!"))
}

ATank* ATankPlayerController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}