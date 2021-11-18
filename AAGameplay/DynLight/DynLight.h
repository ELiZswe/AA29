// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AAGameplay/AAGameplay.h"
#include "DynLight.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADynLight : public AAAGameplay
{
	GENERATED_BODY()
public:
	ADynLight();

	void BeginPlay();
};
