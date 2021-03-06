// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/MyEnums.h"
#include "GoalDefend.generated.h"

UCLASS()
class AGoalDefend : public AGoal
{
	GENERATED_BODY()
public:
	AGoalDefend();

	UPROPERTY()														AActor* DefendObject;								//var Actor DefendObject;

	void Init();
	void addFocusObject(AActor* Focus);
	float reweightGoal();
	uint8 getGoal();
};
