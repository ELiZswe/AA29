// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/AGP_DamageType/AGP_FellDamage/AGP_FellDamage.h"
#include "FallDamage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UFallDamage : public UAGP_FellDamage
{
	GENERATED_BODY()
public:
	UFallDamage();

	//void SuicideMessage(PlayerReplicationInfo Victim);
};
