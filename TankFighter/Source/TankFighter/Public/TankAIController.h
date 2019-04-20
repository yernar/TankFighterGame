// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "TankAIController.generated.h"

class UTankAimComponent;
class ATank;

/**
 * 
 */
UCLASS()
class TANKFIGHTER_API ATankAIController : public AAIController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	virtual void SetPawn(APawn*) override;

private:
	// Radius between AI and Player's Tank
	UPROPERTY(EditDefaultsOnly, Category = Movement)
		float AcceptanceRadius = 3000.f;
	UFUNCTION()
		void OnPossessedTankDeath();
};