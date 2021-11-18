// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalSurvive.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalSurvive : public AGoal
{
	GENERATED_BODY()
public:
	AGoalSurvive();

	UPROPERTY()														float cover;								//var float cover;

	void Init();
	float reweightGoal();
	int32 getGoal();

};
