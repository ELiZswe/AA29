// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "aux_light_signal.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API Aaux_light_signal : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	Aaux_light_signal();


	void SetSignalColor(FColor Color);
	void SetSignalSize(float Units);

};
