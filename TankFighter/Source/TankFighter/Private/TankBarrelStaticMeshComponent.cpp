// Fill out your copyright notice in the Description page of Project Settings.

#include "TankBarrelStaticMeshComponent.h"

void UTankBarrelStaticMeshComponent::Elevate(float DPS) /// DPS = DegreesPerSecond
{
	UE_LOG(LogTemp, Warning, TEXT("SPEED: %f"), DPS)
}

