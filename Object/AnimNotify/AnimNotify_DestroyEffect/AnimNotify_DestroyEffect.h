// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_DestroyEffect.generated.h"

UCLASS()
class UAnimNotify_DestroyEffect : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_DestroyEffect();

	UPROPERTY(EditAnywhere)				bool		bExpireParticles;			//var() bool bExpireParticles;
	UPROPERTY(EditAnywhere)				FName		DestroyTag;					//var() name DestroyTag;
};
