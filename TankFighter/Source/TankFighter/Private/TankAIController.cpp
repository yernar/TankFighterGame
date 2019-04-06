// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankAIController.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
	/*ATank* PlayersTank = GetPlayersTank();
	if (PlayersTank)
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank found: %s"), *PlayersTank->GetName())
	else
		UE_LOG(LogTemp, Warning, TEXT("PlayersTank is not found!"))*/
}

void ATankAIController::Tick(float DeltaTime)
{
	ATank* FirstPlayersTank = Cast<ATank>(GetWorld()->GetFirstPlayerController()->GetPawn());
	ATank* ControlledTank = Cast<ATank>(GetPawn());
	if (FirstPlayersTank)
	{
		MoveToActor(FirstPlayersTank, AcceptanceRadius);
		FVector* FirstPlayersTankLocation = new FVector(FirstPlayersTank->GetActorLocation());
		ControlledTank->AimAt(*FirstPlayersTankLocation);
		ControlledTank->Fire();
		delete FirstPlayersTankLocation;
	}	
}
