// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/AI_Primitive/AI_Primitive.h"
#include "Goal.generated.h"

/**
 * 
 */
class AGoal_Interface;
class AAction;
class AAgentController;
//class AWaypoint;

UCLASS()
class AA29_API AGoal : public AAI_Primitive
{
	GENERATED_BODY()
public:
	AGoal();

	UPROPERTY()														AGoal_Interface* decider;					//var Goal_Interface decider;
	UPROPERTY()														APawn* Enemy;								//var Pawn Enemy;
	UPROPERTY()														FName ResumeLabel;							//var name ResumeLabel;
	UPROPERTY()														FName ResumeState;							//var name ResumeState;
	UPROPERTY()														bool bResumable;							//var bool bResumable;
	UPROPERTY()														AAction* ActiveAction;						//var Action ActiveAction;
	UPROPERTY()														AAction* _Top;								//var Action _Top;
	UPROPERTY()														AAgentController* Controller;				//var AgentController Controller;
	//UPROPERTY()														AWaypoint* current_waypoint;				//var Waypoint current_waypoint;
	UPROPERTY()														AGoal* sequenceNext;						//var Goal sequenceNext;
	UPROPERTY()														AGoal* Next;								//var Goal Next;
	UPROPERTY()														float _score;								//var float _score;


	void PreBeginPlay();
	void Init();
	void _getBestAction();
	void _addAction(AAction* add_class);
	void NotifyComplete();
	int32 getGoal();
	void SetScore(float set_score);
	float GetScore();
	void getPawn();
	void getMentalModel();
	void ReachedDestination();
	void EnemyNotVisible();
	void EnemyVisible();
	void SeePawn(APawn* Seen);
	void EnemyKilled();
	void ChangeScore(float new_score);
	void SelectGoal();
	void StartGoal();
	void LeaveGoal();
	void reweightGoal();
	void IsEnemy(APawn* TestPawn);
	void Range(float val1, float val2);

};
