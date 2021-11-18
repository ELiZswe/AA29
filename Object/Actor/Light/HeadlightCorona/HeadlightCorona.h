// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/AA2_Light.h"
#include "HeadlightCorona.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AHeadlightCorona : public AAA2_Light
{
	GENERATED_BODY()
public:
	AHeadlightCorona();

	void ChangeTeamTint(uint8 t);
};
