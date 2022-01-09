// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/ScriptObject/Condition/Condition.h"
#include "Cond_WhenLSAnimEnds.generated.h"

UCLASS()
class UCond_WhenLSAnimEnds : public UCondition
{
	GENERATED_BODY()
public:
	UCond_WhenLSAnimEnds();

	UPROPERTY()										FName ActorTag;					//var name ActorTag;
	UPROPERTY()										AActor* TargetActor;			//var Actor TargetActor;

	void Destroyed();
	void ConditionStart();
	void ConditionFinish();
	bool ProcessParams();
};
