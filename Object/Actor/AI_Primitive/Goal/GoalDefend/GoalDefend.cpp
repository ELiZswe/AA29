// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/GoalDefend/GoalDefend.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionAttack/ActionAttack.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionFixJam/ActionFixJam.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionReload/ActionReload.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionMoveTo/ActionMoveTo.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionIdle/ActionIdle.h"

AGoalDefend::AGoalDefend()
{

}

/*
State Enabled
{
Begin:
	DebugLog(DEBUG_AI,"dnback:: GoalDefend::Enabled{}::Begin");
	GoalDecider(decider).SetEnemy(getMentalModel().getBiggestThreat(getPawn(),"notional",DefendObject.Location));
	DebugLog(DEBUG_AI,"dnback:: GoalDefend::Enabled{}	GetAction");
	ActiveAction=_getBestAction();
	DebugLog(DEBUG_AI,"dnback:: GoalDefend::Enabled{}	ExecuteAction " + FString::FromInt(ActiveAction));
	ActiveAction.executeAction();
	JL"Wait"
;
	DebugLog(DEBUG_AI,"dnback:: GoalDefend::Enabled{}	ActionComplete");
	JL"GetAction"
;
}
*/

void AGoalDefend::Init()
{
	//_addAction(AActionAttack::StaticClass());
	//_addAction(AActionFixJam::StaticClass());
	//_addAction(AActionReload::StaticClass());
	//_addAction(AActionMoveTo::StaticClass());
	//_addAction(AActionIdle::StaticClass());
}

void AGoalDefend::addFocusObject(AActor* Focus)
{
	DefendObject = Focus;
}

float AGoalDefend::reweightGoal()
{
	/*
	if (DefendObject == nullptr)
	{
		DefendObject = getPawn().Leader;
	}
	if (DefendObject == nullptr)
	{
		GoalDecider(decider)._removeGoal(this);
		return 0;
	}
	_score =FMath::Clamp(getMentalModel().totalThreatAssessment(getPawn(), "notional", DefendObject.Location), 0, 1);
	returnFMath::Clamp(_score, 0, 1);
	*/

	return 0.1;     //FAKE   /ELiZ

}

uint8 AGoalDefend::getGoal()
{
	return 5;
}
