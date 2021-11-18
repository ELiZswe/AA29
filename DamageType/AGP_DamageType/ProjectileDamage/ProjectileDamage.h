// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/AGP_DamageType/AGP_DamageType.h"
#include "ProjectileDamage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UProjectileDamage : public UAGP_DamageType
{
	GENERATED_BODY()
public:
	UProjectileDamage();

	//var float fCaliber;
	UPROPERTY()		float fCaliber;
};
