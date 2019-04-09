// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "TankAimComponent.generated.h"

class UTankBarrelStaticMeshComponent;
class UTankTurretStaticMeshComponent;
class AProjectile;

UENUM()
enum class EPointerStatus : uint8
{
	Reloading,
	Aiming,
	NoAmmo
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TANKFIGHTER_API UTankAimComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTankAimComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	// Player and AI's aimping point
	void AimAt(FVector&);

	UFUNCTION(BlueprintCallable, Category = Fire)
		int32 GetAmmo() const;
	UFUNCTION(BlueprintCallable, Category = Fire)
		void Fire();
	


private:
	void MoveTurretBarrel(FVector&);
	bool IsReloaded() const;

	UTankBarrelStaticMeshComponent* TankBarrel = nullptr;
	UTankTurretStaticMeshComponent* TankTurret = nullptr;
	double LastFireTime = 0;

	// Launch speed of a projectile. cm -> meter = 500 m/s;
	UPROPERTY(EditDefaultsOnly, Category = FiringSetup)
		float ProjectileSpeed = 5000.f;
	UPROPERTY(EditDefaultsOnly, Category = FiringSetup)
		float FireCooldown = 3.f;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		TSubclassOf<AProjectile> ProjectileType = nullptr;
	UPROPERTY(EditDefaultsOnly, Category = Setup)
		int32 Ammo = 5;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = Setup)
		EPointerStatus PointerStatus;
	UFUNCTION(BlueprintCallable, Category = Setup)
		void SetTankTurretBarrel(UTankTurretStaticMeshComponent* TankTurret, UTankBarrelStaticMeshComponent* TankBarrel);
};
