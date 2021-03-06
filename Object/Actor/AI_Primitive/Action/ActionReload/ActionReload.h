// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionReload.generated.h"

UCLASS()
class AActionReload : public AAction
{
	GENERATED_BODY()
public:
	AActionReload();

	float evaluateAction();
	void executeAction();
};
