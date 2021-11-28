// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "DieselSmoke.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ADieselSmoke : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ADieselSmoke();

	UPROPERTY(EditAnywhere)						int32 MaxPPS;								//var() int32 MaxPPS;

	void disableEffect();
	void SetEmitterColor(FColor DirtColor, int32 emitterNum);
	void UpdatePrecacheMaterials();
	void updatePuff(float puffCoeff);
};
