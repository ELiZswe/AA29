// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/DamageType/aDamageType.h"
#include "AA29/Object/Actor/SideEffect/SideEffect.h"

#include "AGP_DamageType.generated.h"

UCLASS()
class UAGP_DamageType : public UaDamageType
{
	GENERATED_BODY()
public:
	UAGP_DamageType();

	
	UPROPERTY()		TArray<TSubclassOf<ASideEffect>> SideEffects;				//var array<class<SideEffect> > SideEffects;

	TArray<ASideEffect*> GetSideEffects(AController* Affected, int32 Damage, APawn* instigatedBy, FVector HitLocation, FVector Momentum, FBoneInfo Bone, AController* KillerController, AActor* ResponsibleActor);
};
