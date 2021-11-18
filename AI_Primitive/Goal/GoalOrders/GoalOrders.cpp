// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Goal/GoalOrders/GoalOrders.h"

AGoalOrders::AGoalOrders()
{
	_score = 0.5;
}

/*
State Enabled
{
}
*/

void AGoalOrders::Init()
{
	sequenceNext = nullptr;
	sequenceCurr = nullptr;
}

int32 AGoalOrders::getGoal()
{
	return 3;
}

void AGoalOrders::addSequencedGoal(AGoal* nextInSequence)
{
	if (sequenceNext == nullptr)
	{
		sequenceNext = nextInSequence;
		sequenceCurr = sequenceNext;
	}
	else
	{
		sequenceCurr->sequenceNext = nextInSequence;
		sequenceCurr = sequenceCurr->sequenceNext;
	}
}

float AGoalOrders::reweightGoal()
{
	if (sequenceNext == nullptr)
	{
		_score = 0;
	}
	else
	{
		//_score = Controller.Pawn.fObedience;
	}
	return _score;
}