// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalOrders.generated.h"

class AGoal;
UCLASS()
class AGoalOrders : public AGoal
{
	GENERATED_BODY()
public:
	AGoalOrders();

	UPROPERTY()														AGoal* sequenceCurr;						//var AGP.Goal sequenceCurr;
	UPROPERTY()														AActor* Objective;							//var Actor Objective;

	void Init();
	uint8 getGoal();
	void addSequencedGoal(AGoal* nextInSequence);
	float reweightGoal();

};
