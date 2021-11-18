// All the original content belonged to the US Army


#include "AA29/AI_Primitive/Goal/Goal.h"

AGoal::AGoal()
{

}

/*
State NotEnabled
{
	Function EnemyKilled ()
	{
	}
	Function SeePawn (Pawn Seen)
	{
	}
	Function EnemyVisible ()
	{
	}
	Function ReachedDestination ()
	{
	}
}
State Enabled
{
	Function NotifyComplete ()
	{
		DebugLog(DEBUG_AI,"dnback:: " $ Self.Name $ "::Enabled{}::notifyComplete()");
		if (sequenceNext == None)
		{
			DebugLog(DEBUG_AI,"dnback:: " $ Self.Name $ "; No following Goals, reweighting");
			Goal_Interface(Owner).reweightGoals();
		}
		else
		{
			DebugLog(DEBUG_AI,"dnback:: " $ Self.Name $ "; proceeding to next Goal, " $ sequenceNext.Name);
			sequenceNext.StartGoal();
		}
	}
}

*/

void AGoal::PreBeginPlay()
{
	bResumable = false;
	/*
	Controller = Goal_Interface(Owner).Controller;
	Init();
	decider = Goal_Interface(Owner);
	*/
}
void AGoal::Init()
{
}
void AGoal::_getBestAction()
{
	/*
	local Action test_action;
	local Action high_action;
	local float high_score;
	local float test_score;
	high_score = -1;
	DebugLog(DEBUG_AI, "Goal::_getBestAction()	Evaluating actions");
	test_action = _Top;
	if (test_action != None)
	{
		test_score = test_action.evaluateAction();
		DebugLog(DEBUG_AI, "Goal::_getBestAction()		" $ test_action $ " evaluated at " $ test_score);
		if (test_score == 1)
		{
			DebugLog(DEBUG_AI, "Goal::_getBestAction()	AutoReturning" $ test_action);
			Return test_action;
		}
		if (test_score > high_score)
		{
			high_score = test_score;
			high_action = test_action;
		}
		test_action = test_action.Next;
	}
	DebugLog(DEBUG_AI, "Goal::_getBestAction()	Returning " $ high_action);
	Return high_action;
	*/
}
void AGoal::_addAction(AAction*  add_class)
{
	/*
	local Action add_action;
	local Action last_action;
	add_action = Spawn(add_class, Self);
	if (add_action == None)
	{
		Log("WARNING:	Goal::_addAction()	Failed to add " $ add_class);
		Return;
	}
	if (_Top == None)
	{
		_Top = add_action;
	}
	else
	{
		last_action = _Top;
		if (last_action.Next != None)
		{
			last_action = last_action.Next;
		}
		last_action.Next = add_action;
	}
	add_action = None;
	*/
}
void AGoal::NotifyComplete()
{
}
int32 AGoal::getGoal()
{
	return 0;
}
void AGoal::SetScore(float set_score)
{
	//_score = FClamp(set_score, 0, 1);
}
float AGoal::GetScore()
{
	return _score;
}
void AGoal::getPawn()
{
	//Return AGP_Pawn(Controller.Pawn);
}
void AGoal::getMentalModel()
{
	//Return Controller.getMentalModel();
}
void AGoal::ReachedDestination()
{
}
void AGoal::EnemyNotVisible()
{
}
void AGoal::EnemyVisible()
{
}
void AGoal::SeePawn(APawn* Seen)
{
}
void AGoal::EnemyKilled()
{
}
void AGoal::ChangeScore(float new_score)
{
	/*
	DebugLog(DEBUG_AI, "Goal::ChangeScore()	Changing " $ getGoal() $ " scores: " $ _score @ new_score);
	if (_score == new_score)
	{
		Return False;
	}
	if (new_score < 0)
	{
		new_score = 0;
	}
	else
	{
		if (new_score > 1)
		{
			new_score = 1;
		}
	}
	_score = new_score;
	Return SelectGoal();
	*/
}
void AGoal::SelectGoal()
{
	/*
	local float real_score;
	real_score = _score;
	if (_score > 0.6)
	{
		_score += 0.1;
		if (_score > 1)
		{
			_score = 1;
		}
	}
	Goal_Interface(Owner).selectActiveGoal();
	_score = real_score;
	Return !Controller.ActiveGoal == Self;
	*/
}
void AGoal::StartGoal()
{
	/*
	if (bResumable == True)
	{
		GotoState(ResumeState, ResumeLabel);
	}
	else
	{
		GotoState('Enabled');
	}
	*/
}
void AGoal::LeaveGoal()
{
	/*
	ResumeState = GetStateName();
	ResumeLabel = 'Begin';
	bResumable = False;
	GotoState('NotEnabled');
	*/
}
void AGoal::reweightGoal()
{
}
void AGoal::IsEnemy(APawn* TestPawn)
{
	/*
	local Pawn.ETeam test_team;
	test_team = AGP_Pawn(TestPawn).idTeam;
	if (test_team == 4 || test_team == 0)
	{
		Return False;
	}
	else
	{
		Return AGP_Pawn(Controller.Pawn).idTeam != test_team;
	}
	*/
}
void AGoal::Range(float val1, float val2)
{
	/*
	if (val1 < val2)
	{
		Return val1 + val2 - val1 * FRand();
	}
	else
	{
		Return val2 + val1 - val2 * FRand();
	}
	*/
}
