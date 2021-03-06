// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Primitive.h"
#include "Action.generated.h"

class AAction;
class AAgentController;
class AGoal;
class AAGP_Pawn;
class AWeapon;
class AMentalModel;

UCLASS()
class AAction : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AAction();

	UPROPERTY()																			bool lastCallFailed;				//var bool lastCallFailed;
	UPROPERTY()																			AGoal* my_goal;						//var Goal my_goal;
	UPROPERTY()																			AAgentController* Controller;		//var AgentController Controller;
	UPROPERTY()																			AAction* sequenceNext;				//var Action sequenceNext;
	UPROPERTY()																			AAction* Next;						//var Action Next;

	void PreBeginPlay();
	AAGP_Pawn* getPawn();
	AWeapon* GetWeapon();
	AAGP_Pawn* getEnemy();
	bool SetEnemy(APawn* new_enemy);
	AMentalModel* getMentalModel();
	float evaluateAction();
	bool checkFailure();
	void registerAndExecute();
	void executeAction();
	void CompleteAction();
	void NotifyComplete(bool failed);
};
