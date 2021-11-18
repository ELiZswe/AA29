// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/Goal/Goal.h"
#include "GoalDefend.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AGoalDefend : public AGoal
{
	GENERATED_BODY()
public:
	AGoalDefend();

	UPROPERTY()														AActor* DefendObject;								//var Actor DefendObject;

	void Init();
	void addFocusObject(AActor* Focus);
	float reweightGoal();
	int32 getGoal();
	
};
