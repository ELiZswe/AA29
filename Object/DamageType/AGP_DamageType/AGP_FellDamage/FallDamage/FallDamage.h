// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DamageType/AGP_DamageType/AGP_FellDamage/AGP_FellDamage.h"
#include "FallDamage.generated.h"

UCLASS()
class UFallDamage : public UAGP_FellDamage
{
	GENERATED_BODY()
public:
	UFallDamage();

	FString SuicideMessage(AAA2_PlayerState* Victim);
};
