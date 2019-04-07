// Copyright Magic Inc., Yernar Aldabergenov© 2019.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Tank.generated.h"

UCLASS()
class TANKFIGHTER_API ATank : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ATank();

	// Called every frame
	virtual void Tick(float) override;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;	

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent*) override;
};
