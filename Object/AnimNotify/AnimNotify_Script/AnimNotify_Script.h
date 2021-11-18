// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_Script.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UAnimNotify_Script : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_Script();

	UPROPERTY()													FName NotifyName;								//var() name NotifyName;
};
