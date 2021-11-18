// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionTakeCover.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AActionTakeCover : public AAction
{
	GENERATED_BODY()
public:
	AActionTakeCover();

	UPROPERTY()																			float localCover;					//var float localCover;

	float evaluateAction();
	void executeAction();
};
