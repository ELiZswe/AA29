// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalPatrol.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalPatrol : public AGoal
{
	GENERATED_BODY()
public:
	AGoalPatrol();

	void Init();
	int32 getGoal();
	void EnemyNotVisible();
	void ReachedDestination();
	void _constructWaypoints();

};
