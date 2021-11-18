// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalAttrit.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalAttrit : public AGoal
{
	GENERATED_BODY()
public:
	AGoalAttrit();

	void Init();
	float reweightGoal();
	int32 getGoal();
};
