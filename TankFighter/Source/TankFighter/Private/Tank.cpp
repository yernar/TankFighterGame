// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "Tank.h"
#include "Projectile.h"

// Sets default values
ATank::ATank()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
}

// Called when the game starts or when spawned
void ATank::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void ATank::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

float ATank::GetHealthPercent() const
{
	return float(CurrentHealth) / float(Health);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

float ATank::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	int32 DamageToApply = FMath::Clamp<int32>(DamageAmount, 0, CurrentHealth);
	CurrentHealth -= DamageToApply;
	if (CurrentHealth <= 0)
		UE_LOG(LogTemp, Warning, TEXT("Tank dead"))
	return DamageToApply;
}