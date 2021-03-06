// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalSurvive.generated.h"

UCLASS()
class AGoalSurvive : public AGoal
{
	GENERATED_BODY()
public:
	AGoalSurvive();

	UPROPERTY()														float cover;								//var float cover;

	void Init();
	float reweightGoal();
	uint8 getGoal();
};
