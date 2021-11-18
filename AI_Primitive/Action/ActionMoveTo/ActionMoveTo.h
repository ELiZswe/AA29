// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Action/Action.h"
#include "ActionMoveTo.generated.h"

/**
 * 
 */
class AContact;

UCLASS()
class AA29_API AActionMoveTo : public AAction
{
	GENERATED_BODY()
public:
	AActionMoveTo();

	UPROPERTY()																			AContact* Enemy;					//var AGP.Contact Enemy;

	float evaluateAction();
	void executeAction();

};
