// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/HeadlightCorona/HeadlightCorona.h"
#include "BrakelightCorona.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ABrakelightCorona : public AHeadlightCorona
{
	GENERATED_BODY()
public:
	ABrakelightCorona();

	void UpdateBrakelightState(float Brake, int32 Gear);
};
