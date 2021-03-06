// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/AnimNotify/AA2_AnimNotify.h"
#include "AnimNotify_MatSubAction.generated.h"

class UMatSubAction;

UCLASS()
class UAnimNotify_MatSubAction : public UAA2_AnimNotify
{
	GENERATED_BODY()
public:
	UAnimNotify_MatSubAction();


	UPROPERTY(EditAnywhere)			UMatSubAction*	SubAction;			//var() MatSubAction SubAction;
};
