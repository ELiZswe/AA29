// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionFixJam.generated.h"

UCLASS()
class AActionFixJam : public AAction
{
	GENERATED_BODY()
public:
	AActionFixJam();


	float evaluateAction();
	void executeAction();
};
