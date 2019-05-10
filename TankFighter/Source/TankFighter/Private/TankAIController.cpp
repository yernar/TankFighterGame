// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#include "TankAIController.h"
#include "TankAimComponent.h"
#include "Tank.h"

void ATankAIController::BeginPlay()
{
	Super::BeginPlay();
}

void ATankAIController::Tick(float DeltaTime)
{
	APawn* FirstPlayersTank = GetWorld()->GetFirstPlayerController()->GetPawn();
	UTankAimComponent* AimComponent = GetPawn()->FindComponentByClass<UTankAimComponent>();
	if (FirstPlayersTank && AimComponent && GetPawn())
	{
		MoveToActor(FirstPlayersTank, AcceptanceRadius);
		FVector* FirstPlayersTankLocation = new FVector(FirstPlayersTank->GetActorLocation());
		AimComponent->AimAt(*FirstPlayersTankLocation);
		AimComponent->Fire();
		delete FirstPlayersTankLocation;
	}
	else
		return;
}

void ATankAIController::SetPawn(APawn* InPawn)
{
	Super::SetPawn(InPawn);

	if (InPawn)
	{
		ATank* PossessedTank = Cast<ATank>(InPawn);
		if (!PossessedTank) return;

		PossessedTank->OnDeath.AddUniqueDynamic(this, &ATankAIController::OnPossessedTankDeath);
	}
}

void ATankAIController::OnPossessedTankDeath()
{
	if (!GetPawn()) return;

	GetPawn()->DetachFromControllerPendingDestroy();
}
