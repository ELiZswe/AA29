// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/Goal_Interface/Goal_Interface.h"
#include "GoalDecider.generated.h"

class AMentalModel;
class AGoal;
class AContact;

UCLASS()
class AGoalDecider : public AGoal_Interface
{
	GENERATED_BODY()
public:
	AGoalDecider();

	UPROPERTY()														AMentalModel* mm;								//var AGP.MentalModel mm;
	UPROPERTY()														AGoal* _Top;								//var AGP.Goal _Top;
	UPROPERTY()														AGoal* ActiveGoal;								//var AGP.Goal ActiveGoal;

	void PreBeginPlay();
	void Timer();
	void SetEnemy(AContact* NewEnemy);
	void reweightGoals();
	void selectActiveGoal();
	void _addGoal(AGoal* add_class, AActor* Focus);
	bool _removeGoal(AGoal* rem_goal);
};
