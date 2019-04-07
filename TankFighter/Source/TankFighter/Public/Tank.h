// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

class UTankAimComponent;
class AProjectile;
class UTankBarrelStaticMeshComponent;
class UTankTrackStaticMeshComponent;

UCLASS()
class TANKFIGHTER_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float) override;

	// Called to bind functionality to input
	/// virtual void SetupPlayerInputComponent(class UInputComponent*) override;

	// Player and AI's aimping point
	// void AimAt(FVector&);

	UFUNCTION(BlueprintCallable)
		void Fire();

private:
	UPROPERTY(EditDefaultsOnly, Category = FiringSetup)
		float FireCooldown = 3.f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileType = nullptr;
	double LastFireTime = 0;
	UTankBarrelStaticMeshComponent* TankBarrel = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = FiringSetup)
		float ProjectileSpeed = 5000.f; /// Launch speed of a projectile. cm -> meter = 500 m/s;s
};
