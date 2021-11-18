// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalAttackX.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalAttackX : public AGoal
{
	GENERATED_BODY()
public:
	AGoalAttackX();

	int32 getGoal();
	void EnemyNotVisible();
};
