// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DamageType/AGP_DamageType/AGP_DamageType.h"
#include "DamTypeVehicleExplosion.generated.h"

UCLASS()
class UDamTypeVehicleExplosion : public UAGP_DamageType
{
	GENERATED_BODY()
public:
	UDamTypeVehicleExplosion();
	
	void GetHitEffects(AxEmitter*& HitEffects, int32 VictimHealth);
};
