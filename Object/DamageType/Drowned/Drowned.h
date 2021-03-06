// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "Drowned.generated.h"

class AEffects;
UCLASS()
class UDrowned : public UaDamageType
{
	GENERATED_BODY()
public:
	UDrowned();

	AEffects* GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail);
};
