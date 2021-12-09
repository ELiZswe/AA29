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
int32 AGoalImprove::getGoal()
{
	return 7;
}
