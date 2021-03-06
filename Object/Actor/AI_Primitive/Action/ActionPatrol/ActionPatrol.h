// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionPatrol.generated.h"

UCLASS()
class AActionPatrol : public AAction
{
	GENERATED_BODY()
public:
	AActionPatrol();

	float evaluateAction();
	void executeAction();

};
