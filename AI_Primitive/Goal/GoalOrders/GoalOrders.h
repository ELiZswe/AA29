// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalOrders.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalOrders : public AGoal
{
	GENERATED_BODY()
public:
	AGoalOrders();

	UPROPERTY()														AGoal* sequenceCurr;						//var AGP.Goal sequenceCurr;
	UPROPERTY()														AActor* Objective;							//var Actor Objective;

	void Init();
	int32 getGoal();
	void addSequencedGoal(AGoal* nextInSequence);
	float reweightGoal();

};
