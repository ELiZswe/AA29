// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/DamageType/aDamageType.h"
#include "AA29/SideEffect/SideEffect.h"

#include "AGP_DamageType.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAGP_DamageType : public UaDamageType
{
	GENERATED_BODY()
public:
	UAGP_DamageType();

	
	UPROPERTY()		TArray<TSubclassOf<class ASideEffect>> SideEffects;				//var array<class<SideEffect> > SideEffects;

	void GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor);
};
