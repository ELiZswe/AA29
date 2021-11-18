// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_DestroyableObjective/AGP_DestroyableObjective.h"
#include "AGP_MortarRangeDestroyableObj.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_MortarRangeDestroyableObj : public AAGP_DestroyableObjective
{
	GENERATED_BODY()
public:
	AAGP_MortarRangeDestroyableObj(const FObjectInitializer& objectInitializer);

	UPROPERTY()								bool bDestuctionReported;				//var bool bDestuctionReported;
	
	//void TakeDamage(int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, UaDamageType*  DamageType, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor, UTexture2D* HitMaterial);
};
