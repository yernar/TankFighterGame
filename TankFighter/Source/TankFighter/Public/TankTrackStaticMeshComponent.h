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
	// Sets default values for this component's properties
	UTankTrackStaticMeshComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable, Category = Input)
		void SetThrottle(float Throttle);
private:
	float Throttle = 0.f;
	// F = Force, value in Newtons
	UPROPERTY(EditDefaultsOnly, Category = Force)
		float MaxTrackDrivingF = 50000000.f; // F = mass * acceleration. Tank mass = 50000kg * 10m/s^2
	UFUNCTION()
		void OnCompHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	void SidewaysForce();
	void DriveTracks();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;
};
