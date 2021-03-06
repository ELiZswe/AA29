// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "DamagedEffect.generated.h"

UCLASS()
class ADamagedEffect : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	ADamagedEffect();

	void PostBeginPlay();
	void SetEffectScale(float Scaling);
	void UpdateDamagedEffect(bool bFlame, float VelMag);
};
