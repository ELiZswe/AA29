// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Mover/Mover.h"
#include "ClientMover.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AClientMover : public AMover
{
	GENERATED_BODY()
public:
	AClientMover();

	void PostBeginPlay();
};
