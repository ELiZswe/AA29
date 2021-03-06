// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "ActionSuppress.generated.h"

UCLASS()
class AActionSuppress : public AAction
{
	GENERATED_BODY()
public:
	AActionSuppress();

	UPROPERTY()																			AActor* SuppressionTarget;					//var Actor SuppressionTarget;

	float evaluateAction();
	void executeAction();

};
