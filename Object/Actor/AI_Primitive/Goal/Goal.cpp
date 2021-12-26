// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"

AGoal::AGoal()
{

}

/*
auto State NotEnabled
{
	Function ReachedDestination()
	{
	}
	Function EnemyVisible()
	{
	}
	Function SeePawn(Pawn Seen)
	{
	}
	Function EnemyKilled()
	{
	}
}
*/

/*
State Enabled
{
	Function NotifyComplete()
	{
		DebugLog(DEBUG_AI,"dnback:: " $ string(Self.Name) $ "::Enabled{}::notifyComplete()");
		if (sequenceNext == nullptr)
		{
			DebugLog(DEBUG_AI,"dnback:: " $ string(Self.Name) $ "; No following Goals, reweighting");
			Goal_Interface(Owner).reweightGoals();
		}
		else
		{
			DebugLog(DEBUG_AI,"dnback:: " $ string(Self.Name) $ "; proceeding to next Goal, " $ string(sequenceNext.Name));
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

AAction* AGoal::_getBestAction()
{
	AAction* test_action = nullptr;
	AAction* high_action = nullptr;
	float high_score = 0;
	float test_score = 0;
	high_score=-1;
	/*
	DebugLog(DEBUG_AI,"Goal::_getBestAction()	Evaluating actions");
	for (test_action=_Top; test_action!=nullptr; test_action=test_action.Next)
	{
		test_score=test_action.evaluateAction();
		DebugLog(DEBUG_AI,"Goal::_getBestAction()		" $ string(test_action) $ " evaluated at " $ string(test_score));
		if (test_score == 1)
		{
			DebugLog(DEBUG_AI,"Goal::_getBestAction()	AutoReturning" $ string(test_action));
			return test_action;
		}
		if (test_score > high_score)
		{
			high_score=test_score;
			high_action=test_action;
		}
	}
	DebugLog(DEBUG_AI,"Goal::_getBestAction()	Returning " $ string(high_action));
	*/
	return high_action;
}

void AGoal::_addAction(AAction*  add_class)
{
	/*
	local Action add_action;
	local Action last_action;
	add_action = Spawn(add_class, Self);
	if (add_action == nullptr)
	{
		Log("WARNING:	Goal::_addAction()	Failed to add " $ add_class);
		Return;
	}
	if (_Top == nullptr)
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
	add_action = nullptr;
	*/
}

void AGoal::NotifyComplete()
{
}

uint8 AGoal::getGoal()
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

AAGP_Pawn* AGoal::getPawn()
{
	//Return AGP_Pawn(Controller.Pawn);
	return nullptr;    //FAKE  /ELiZ
}

AMentalModel* AGoal::getMentalModel()
{
	//Return Controller.getMentalModel();
	return nullptr;    //FAKE  /ELiZ
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

bool AGoal::ChangeScore(float new_score)
{
	/*
	DebugLog(DEBUG_AI, "Goal::ChangeScore()	Changing " $ getGoal() $ " scores: " $ _score @ new_score);
	if (_score == new_score)
	{
		return false;
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
	*/
	return SelectGoal();
}

bool AGoal::SelectGoal()
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
	return !Controller.ActiveGoal == Self;
	*/
	return false;    //FAKE   /ELiZ
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

float AGoal::reweightGoal()
{
	return 0;    //FAKE   /EliZ
}

bool AGoal::IsEnemy(APawn* TestPawn)
{
	/*
	local Pawn.ETeam test_team;
	test_team = AGP_Pawn(TestPawn).idTeam;
	if (test_team == 4 || test_team == 0)
	{
		return false;
	}
	else
	{
		return AGP_Pawn(Controller.Pawn).idTeam != test_team;
	}
	*/
	return false;   //FAKE  /EliZ
}

float AGoal::Range(float val1, float val2)
{
	/*
	if (val1 < val2)
	{
		return val1 + val2 - val1 * FRand();
	}
	else
	{
		return val2 + val1 - val2 * FRand();
	}
	*/
	return 0;   //FAKE  /EliZ
}
