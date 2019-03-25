// Fill out your copyright notice in the Description page of Project Settings.

#include "TankAIController.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*ATank* PlayersTank = GetPlayersTank();
	if (PlayersTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank found: %s"), *PlayersTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank is not found!"))*/
}

ATank* ATankAIController::GetControlledTank() const
{
	return Cast<ATank>(GetPawn());
}

ATank* ATankAIController::GetPlayersTank() const
{
	return Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
}
