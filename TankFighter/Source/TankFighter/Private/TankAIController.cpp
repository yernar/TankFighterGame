// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankAIController.h"
#include "Tank.h"
#include "TankAimComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*ATank* PlayersTank = GetPlayersTank();
	if (PlayersTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank found: %s"), *PlayersTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank is not found!"))*/
}

void ATankAIController::Tick(float DeltaTime) // TODO Refactor this method
{
	ATank* FirstPlayersTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	UTankAimComponent* ControlledTank = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (ensure(FirstPlayersTank))
	{
		MoveToActor(FirstPlayersTank, AcceptanceRadius);
		FVector* FirstPlayersTankLocation = new FVector(FirstPlayersTank->GetActorLocation());
		ControlledTank->AimAt(*FirstPlayersTankLocation);
		/// ControlledTank->Fire();
		delete FirstPlayersTankLocation;
	}	
}
