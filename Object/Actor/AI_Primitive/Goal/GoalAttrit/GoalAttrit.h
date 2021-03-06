// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalAttrit.generated.h"

UCLASS()
class AGoalAttrit : public AGoal
{
	GENERATED_BODY()
public:
	AGoalAttrit();

	void Init();
	float reweightGoal();
	uint8 getGoal();
};
