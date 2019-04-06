// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankTrackStaticMeshComponent.generated.h"

/**
 * 
 */
UCLASS( meta = (BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankTrackStaticMeshComponent : public UStaticMeshComponent
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
private:
	// F = Force, value in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Force)
		float MaxTrackDrivingF = 50000000.f; // F = mass * acceleration. Tank mass = 50000kg * 10m/s^2
};
