// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/GoalImprove/GoalImprove.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionFixJam/ActionFixJam.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionReload/ActionReload.h"
#include "AA29/Object/Actor/AI_Primitive/Action/ActionIdle/ActionIdle.h"

AGoalImprove::AGoalImprove()
{

}

/*
State Enabled
{
Begin:
	DebugLog(DEBUG_AI,"GoalImprove::Enabled{}::Begin");
	DebugLog(DEBUG_AI,"GoalImprove::Enabled{}	GetAction");
	ActiveAction=_getBestAction();
	DebugLog(DEBUG_AI,"GoalImprove::Enabled{}	ExecuteAction " + FString::FromInt(ActiveAction));
	ActiveAction.executeAction();
	JL"Wait"
;
	DebugLog(DEBUG_AI,"GoalImprove::Enabled{}	ActionComplete");
	JL"GetAction"
;
}
*/

void AGoalImprove::Init()
{
	//_addAction(AActionFixJam::StaticClass());
	//_addAction(AActionReload::StaticClass());
	//_addAction(AActionIdle::StaticClass());
}

float AGoalImprove::reweightGoal()
{
	_score = 0.01;
	return _score;
}

uint8 AGoalImprove::getGoal()
{
	return 7;
}
