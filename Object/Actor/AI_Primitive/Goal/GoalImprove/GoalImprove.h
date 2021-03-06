// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalImprove.generated.h"

UCLASS()
class AGoalImprove : public AGoal
{
	GENERATED_BODY()
public:
	AGoalImprove();

	void Init();
	float reweightGoal();
	uint8 getGoal();
};
