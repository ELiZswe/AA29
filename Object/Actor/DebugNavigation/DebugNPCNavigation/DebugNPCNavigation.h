// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/DebugNavigation/DebugNavigation.h"
#include "DebugNPCNavigation.generated.h"

/**
 * 
 */
UCLASS()
class ADebugNPCNavigation : public ADebugNavigation
{
	GENERATED_BODY()
public:
	ADebugNPCNavigation();

	UPROPERTY()						float					YawRate;						//var float YawRate;

	void PostBeginPlay();
};
