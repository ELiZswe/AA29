// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Light/VolumeLight/VolumeLight.h"
#include "SpotHaze.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ASpotHaze : public AVolumeLight
{
	GENERATED_BODY()
public:
	ASpotHaze();

	void BeginPlay();
};
