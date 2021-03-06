// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionIdle.generated.h"

UCLASS()
class AActionIdle : public AAction
{
	GENERATED_BODY()
public:
	AActionIdle();

	float evaluateAction();
	void executeAction();

};
