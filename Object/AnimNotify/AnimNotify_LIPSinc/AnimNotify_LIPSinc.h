// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_LIPSinc.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_LIPSinc : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_LIPSinc();


	UPROPERTY()													float Pitch;								//var() float Pitch;
	UPROPERTY()													int32 Radius;								//var() int Radius;
	UPROPERTY()													float Volume;								//var() float Volume;
	UPROPERTY()													FName LIPSincAnimName;						//var() name LIPSincAnimName;


};
