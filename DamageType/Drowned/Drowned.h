// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/aDamageType.h"
#include "Drowned.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UDrowned : public UaDamageType
{
	GENERATED_BODY()
public:
	UDrowned();
	void GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
};
