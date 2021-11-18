// All the original content belonged to the US Army

#include "AA29/AI_Primitive/Goal/GoalDefend/GoalDefend.h"
#include "AA29/AI_Primitive/Action/ActionAttack/ActionAttack.h"
#include "AA29/AI_Primitive/Action/ActionFixJam/ActionFixJam.h"
#include "AA29/AI_Primitive/Action/ActionReload/ActionReload.h"
#include "AA29/AI_Primitive/Action/ActionMoveTo/ActionMoveTo.h"
#include "AA29/AI_Primitive/Action/ActionIdle/ActionIdle.h"



AGoalDefend::AGoalDefend()
{

}

/*
State Enabled
{
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
	if (DefendObject == None)
	{
		DefendObject = getPawn().Leader;
	}
	if (DefendObject == None)
	{
		GoalDecider(decider)._removeGoal(Self);
		Return 0;
	}
	_score = FClamp(getMentalModel().totalThreatAssessment(getPawn(), "notional", DefendObject.Location), 0, 1);
	Return FClamp(_score, 0, 1);
	*/

	return 0.1;     //FAKE   /ELiZ

}
int32 AGoalDefend::getGoal()
{
	return 5;
}