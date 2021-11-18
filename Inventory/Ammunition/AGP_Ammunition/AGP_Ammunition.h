// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Ammunition/Ammunition.h"
#include "AGP_Ammunition.generated.h"

/**
 * 
 */



//remaining:
//var class<Projectile> _cTracerClass;


UCLASS()
class AA29_API AAGP_Ammunition : public AAmmunition
{
	GENERATED_BODY()
public:
	AAGP_Ammunition();
	UPROPERTY()		int32 _iTracerCount;
	UPROPERTY()		float MomentumTransfer;
	UPROPERTY()		int32 Damage;
};
