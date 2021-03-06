// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalAttackX.generated.h"

UCLASS()
class AGoalAttackX : public AGoal
{
	GENERATED_BODY()
public:
	AGoalAttackX();

	uint8 getGoal();
	void EnemyNotVisible();
};
