// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalPatrol.generated.h"

UCLASS()
class AGoalPatrol : public AGoal
{
	GENERATED_BODY()
public:
	AGoalPatrol();

	void Init();
	uint8 getGoal();
	void EnemyNotVisible();
	void ReachedDestination();
	void _constructWaypoints();
};
