// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Emitter/AA2_Emitter.h"
#include "VehicleWeaponAmbientEmitter.generated.h"

UCLASS()
class AVehicleWeaponAmbientEmitter : public AAA2_Emitter
{
	GENERATED_BODY()
public:
	AVehicleWeaponAmbientEmitter();

	void SetEmitterStatus(bool bEnabled);
};
