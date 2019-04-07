// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "TankPlayerController.generated.h"

class ATank;
class UTankAimComponent;

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

protected:
	UFUNCTION(BlueprintCallable, Category = Setup)
		ATank* GetControlledTank() const;
	UFUNCTION(BlueprintImplementableEvent, Category = Setup)
		void FoundAimingComponent(UTankAimComponent* TankAimCompRef);

private:
	void AimTowardsCrosshair();
	bool GetSightRayHitLocation(FVector&) const;
	bool GetLookDirection(const FVector2D&, FVector&) const;
	bool GetLookVectorHitLocation(const FVector&, FVector&) const;

	UPROPERTY(EditDefaultsOnly)
		float CrossHairXLocation = 0.5f;
	UPROPERTY(EditDefaultsOnly)
		float CrossHairYLocation = 0.3333f;
	UPROPERTY(EditDefaultsOnly)
		float LineTraceRange = 1000000.f; /// cm->meter->kilometer = 10km

};
