// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class UTankAimComponent;
class ATank;

/**
 * 
 */
UCLASS()
class TANKFIGHTER_API ATankPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	virtual void BeginPlay() override;
	virtual void Tick(float) override;
	virtual void SetPawn(APawn*) override;

	UFUNCTION()
		void OnPossessedTankDeath();

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
		UTankAimComponent* GetAimComponent() const;
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FoundAimingComponent(UTankAimComponent* TankAimCompRef);

private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(const FVector2D&, FVector&) const;
	bool GetLookVectorHitLocation(const FVector&, FVector&) const;

	// X size
	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;
	// Y size
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333f;
	// cm->meter->kilometer
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f; 
};
