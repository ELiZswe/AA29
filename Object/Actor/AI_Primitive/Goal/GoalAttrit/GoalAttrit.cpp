// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/GoalAttrit/GoalAttrit.h"

AGoalAttrit::AGoalAttrit()
{

}

/*
State Enabled
{
Begin:
	DebugLog(DEBUG_AI,"GoalAttrit::Enabled{}::Begin");
	GoalDecider(Owner).SetEnemy(getMentalModel().getMostVulnerable(getPawn()));
	DebugLog(DEBUG_AI,"GoalAttrit::Enabled{}	GetAction");
	ActiveAction=_getBestAction();
	DebugLog(DEBUG_AI,"GoalAttrit::Enabled{}	ExecuteAction " $ string(ActiveAction));
	ActiveAction.executeAction();
	JL"Wait"
;
	DebugLog(DEBUG_AI,"GoalAttrit::Enabled{}	ActionComplete");
	DebugLog(DEBUG_Always,"Action Complete!!!- ---------------------");
	JL"GetAction"
;
}
*/

void AGoalAttrit::Init()
{
	/*
	_addAction('ActionAttack');
	_addAction('ActionFixJam');
	_addAction('ActionReload');
	_addAction('ActionSuppress');
	_addAction('ActionIdle');
	*/
}
float AGoalAttrit::reweightGoal()
{
	/*
	_score = FClamp(getMentalModel().attackAssessment(getPawn()), 0, 1);
	return FClamp(_score, 0, 1);
	*/
	return 0.1;	//FAKE    /ELiZ
}

uint8 AGoalAttrit::getGoal()
{
	return 1;
}
