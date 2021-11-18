// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_Sound.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_Sound : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Sound();

	UPROPERTY()													int32 Radius;								//var() int Radius;
	UPROPERTY()													float Volume;								//var() float Volume;
	UPROPERTY()													USoundBase* Sound;							//var() Sound Sound;

};
