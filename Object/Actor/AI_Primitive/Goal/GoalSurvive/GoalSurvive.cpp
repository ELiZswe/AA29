// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/GoalSurvive/GoalSurvive.h"

AGoalSurvive::AGoalSurvive()
{

}

/*
State Enabled
{
Begin:
	DebugLog(DEBUG_AI,"GoalSurvive::Enabled{}::Begin");
	GoalDecider(Owner).SetEnemy(getMentalModel().getBiggestThreat(getPawn()));
	DebugLog(DEBUG_AI,"GoalSurvive::Enabled{}	GetAction");
	ActiveAction=_getBestAction();
	DebugLog(DEBUG_AI,"GoalSurvive::Enabled{}	ExecuteAction " $ string(ActiveAction));
	ActiveAction.executeAction();
}
*/

void AGoalSurvive::Init()
{
	/*
	_addAction('ActionTakeCover');
	_addAction('ActionFlee');
	_addAction('ActionFixJam');
	_addAction('ActionReload');
	_addAction('ActionIdle');
	*/
	cover = 0;
}
float AGoalSurvive::reweightGoal()
{
	/*
	_score = getMentalModel().totalThreatAssessment(getPawn(), , , cover);
	_score *= FClamp(50 / Controller.Pawn.Health, 0, 1);
	*/
	return _score;
}
int32 AGoalSurvive::getGoal()
{
	return 2;
}
