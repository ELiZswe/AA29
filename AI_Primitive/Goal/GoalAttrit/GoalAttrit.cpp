// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Goal/GoalAttrit/GoalAttrit.h"

AGoalAttrit::AGoalAttrit()
{

}

/*
State Enabled
{
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
	Return FClamp(_score, 0, 1);
	*/
	return 0.1;	//FAKE    /ELiZ
}
int32 AGoalAttrit::getGoal()
{
	return 1;
}