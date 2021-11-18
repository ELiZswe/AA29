// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/AGP_DamageType/AGP_DamageType.h"
#include "AGP_FellDamage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAGP_FellDamage : public UAGP_DamageType
{
	GENERATED_BODY()
public:
	UAGP_FellDamage();

	void GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor);

};
