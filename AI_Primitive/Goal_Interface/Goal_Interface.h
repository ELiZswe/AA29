// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/AI_Primitive.h"
#include "Goal_Interface.generated.h"

class AAgentController;

UCLASS()
class AA29_API AGoal_Interface : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AGoal_Interface();

	UPROPERTY()														AAgentController* Controller;								//var AgentController Controller;

	void selectActiveGoal();
	void increaseTension(float Add);
	void reweightGoals();

};
