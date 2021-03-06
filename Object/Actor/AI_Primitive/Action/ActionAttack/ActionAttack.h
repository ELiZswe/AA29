// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionAttack.generated.h"

UCLASS()
class AActionAttack : public AAction
{
	GENERATED_BODY()
public:
	AActionAttack();

	float evaluateAction();
	void executeAction();

};
