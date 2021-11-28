// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SupportEffect/SupportEffect.h"
#include "F18AirStrikeEffect.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AF18AirStrikeEffect : public ASupportEffect
{
	GENERATED_BODY()
public:
	AF18AirStrikeEffect();

	void SpawnEffects();
};
