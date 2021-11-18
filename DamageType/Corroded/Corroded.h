// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/aDamageType.h"
#include "Corroded.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UCorroded : public UaDamageType
{
	GENERATED_BODY()
public:
	UCorroded();
	void GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
};
