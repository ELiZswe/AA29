// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionFlee.generated.h"

class APathNode;


UCLASS()
class AActionFlee : public AAction
{
	GENERATED_BODY()
public:
	AActionFlee();


	UPROPERTY()																			APathNode* goalNode;					//var PathNode goalNode;

	float evaluateAction();
	void executeAction();

};
