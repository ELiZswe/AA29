// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/Goal/Goal.h"
#include "AA29/Object/Actor/AI_Primitive/Action/Action.h"
#include "AA29/Object/Actor/Controller/AIController/AgentController/AgentController.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/AI_Primitive/Goal_Interface/Goal_Interface.h"
#include "AA29/Object/Actor/AI_Primitive/MentalModel/MentalModel.h"
#include "AA29/Object/Waypoint/Waypoint.h"

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
	Function SeePawn(APawn* Seen)
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
		DebugLog(DEBUG_AI,"dnback:: " + FString::FromInt(Self.Name) + "::Enabled{}::notifyComplete()");
		if (sequenceNext == nullptr)
		{
			DebugLog(DEBUG_AI,"dnback:: " + FString::FromInt(Self.Name) + "; No following Goals, reweighting");
			Cast<AGoal_Interface>(GetOwner())->reweightGoals();
		}
		else
		{
			DebugLog(DEBUG_AI,"dnback:: " + FString::FromInt(Self.Name) + "; proceeding to next Goal, " + FString::FromInt(sequenceNext.Name));
			sequenceNext.StartGoal();
		}
	}
}
*/

void AGoal::PreBeginPlay()
{
	bResumable = false;
	Controller = Cast<AGoal_Interface>(GetOwner())->Controller;
	Init();
	decider = Cast<AGoal_Interface>(GetOwner());
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
		DebugLog(DEBUG_AI,"Goal::_getBestAction()		" + FString::FromInt(test_action) + " evaluated at " + FString::FromInt(test_score));
		if (test_score == 1)
		{
			DebugLog(DEBUG_AI,"Goal::_getBestAction()	AutoReturning" + FString::FromInt(test_action));
			return test_action;
		}
		if (test_score > high_score)
		{
			high_score=test_score;
			high_action=test_action;
		}
	}
	DebugLog(DEBUG_AI,"Goal::_getBestAction()	Returning " + FString::FromInt(high_action));
	*/
	return high_action;
}

void AGoal::_addAction(AAction*  add_class)
{
	AAction* add_action = nullptr;
	AAction* last_action = nullptr;
	/*
	add_action = Spawn(add_class, this);
	if (add_action == nullptr)
	{
		Log("WARNING:	Goal::_addAction()	Failed to add " + add_class);
		return;
	}
	if (_Top == nullptr)
	{
		_Top = add_action;
	}
	else
	{
		last_action = _Top;
		if (last_action.Next != nullptr)
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
	//_score =FMath::Clamp(set_score, 0, 1);
}
float AGoal::GetScore()
{
	return _score;
}

AAGP_Pawn* AGoal::getPawn()
{
	//return Cast<AAGP_Pawn>(Controller.Pawn);
	return nullptr;    //FAKE  /ELiZ
}

AMentalModel* AGoal::getMentalModel()
{
	//return Controller.getMentalModel();
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
	DebugLog(DEBUG_AI, "Goal::ChangeScore()	Changing " + getGoal() + " scores: " + _score @ new_score);
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
	float real_score = 0;
	real_score = _score;
	/*
	if (_score > 0.6)
	{
		_score += 0.1;
		if (_score > 1)
		{
			_score = 1;
		}
	}
	Goal_Interface(GetOwner())->selectActiveGoal();
	_score = real_score;
	return !Controller.ActiveGoal == this;
	*/
	return false;    //FAKE   /ELiZ
}

void AGoal::StartGoal()
{
	if (bResumable == true)
	{
		//GotoState(ResumeState, ResumeLabel);
	}
	else
	{
		//GotoState('Enabled');
	}
}

void AGoal::LeaveGoal()
{
	//ResumeState = GetStateName();
	ResumeLabel = "Begin";
	bResumable = false;
	//GotoState("NotEnabled");
}

float AGoal::reweightGoal()
{
	return 0;    //FAKE   /EliZ
}

bool AGoal::IsEnemy(APawn* TestPawn)
{
	ETeam test_team = ETeam::TEAM_UnAssigned;
	/*
	test_team = Cast<AAGP_Pawn>(TestPawn).idTeam;
	if (test_team == 4 || test_team == 0)
	{
		return false;
	}
	else
	{
		return Cast<AAGP_Pawn>(Controller.Pawn).idTeam != test_team;
	}
	*/
	return false;   //FAKE  /EliZ
}

float AGoal::Range(float val1, float val2)
{
	/*
	if (val1 < val2)
	{
		return val1 + val2 - val1 * FMath::FRand();
	}
	else
	{
		return val2 + val1 - val2 * FMath::FRand();
	}
	*/
	return 0;   //FAKE  /EliZ
}
