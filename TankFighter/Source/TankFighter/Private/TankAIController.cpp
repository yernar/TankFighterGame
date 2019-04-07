// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankAIController.h"
#include "TankAimComponent.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	APawn* FirstPlayersTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	UTankAimComponent* AimComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (ensure(FirstPlayersTank && AimComponent))
	{
		MoveToActor(FirstPlayersTank, AcceptanceRadius);
		FVector* FirstPlayersTankLocation = new FVector(FirstPlayersTank->GetActorLocation());
		AimComponent->AimAt(*FirstPlayersTankLocation);
		AimComponent->Fire();
		delete FirstPlayersTankLocation;
	}	
}