// All the original content belonged to the US Army


#include "AA29/Object/Actor/AI_Primitive/Goal_Interface/GoalDecider/GoalDecider.h"

AGoalDecider::AGoalDecider()
{

}

void AGoalDecider::PreBeginPlay()
{
	/*
	local AGP.AGP_Objective obj;
	Controller = AgentController(Owner);
	mm = Controller.getMentalModel();
	_addGoal('GoalAttrit');
	if (AGP_Pawn(Controller.Pawn).TeamRole.getUnitLeader() != Controller.Pawn)
	{
		ForEach AllActors(Class'AGP_Objective', obj)
		{
			if (mm.findActorIdx(obj) != -1)
			{
				_addGoal('GoalDefend', obj);
			}
		}
	}
	selectActiveGoal();
	*/
}
void AGoalDecider::Timer()
{
	/*
	if (Controller.Pawn == None)
	{
		Disable('Timer');
		Return;
	}
	reweightGoals();
	SetTimer(1 / 0.1 + mm.getTension(), False);
	DebugLog(DEBUG_AI, "dnback:: GoalDecider.Timer(); triggered reweighting of goals, next reweight in " $ 1 / 0.1 + mm.getTension());
	*/
}
void AGoalDecider::SetEnemy(AContact* NewEnemy)
{
	if (NewEnemy != nullptr)
	{
		//Controller.Enemy = Pawn(NewEnemy.Target.Source);
		//Controller.enemyCont = NewEnemy;
	}
	//DebugLog(DEBUG_AI, "dnback:: GoalDecider.setEnemy(); enemy set to " $ NewEnemy.Target.Source.Name);
}
void AGoalDecider::reweightGoals()
{
	/*
	local AGP.Goal i_goal;
	i_goal = _Top;
	if (i_goal != None)
	{
		i_goal.reweightGoal();
		i_goal = i_goal.Next;
	}
	selectActiveGoal();
	*/
}
void AGoalDecider::selectActiveGoal()
{
	/*
	local AGP.Goal prev_goal;
	local AGP.Goal i_goal;
	local float high_score;
	local float Weight;
	prev_goal = ActiveGoal;
	high_score = -1;
	DebugLog(DEBUG_AI, "dnback:: GoalDecider.selectActiveGoal(); choosing next goal");
	i_goal = _Top;
	if (i_goal != None)
	{
		Weight = i_goal.GetScore();
		DebugLog(DEBUG_AI, "dnback:: GoalDecider.selectActiveGoal(); goal " $ i_goal.Name $ " has score " $ i_goal.GetScore());
		if (Weight >= 1)
		{
			ActiveGoal = i_goal;
		}
		else
		{
	else
	{
		if (Weight > high_score)
		{
			high_score = Weight;
			ActiveGoal = i_goal;
		}
	}
	i_goal = i_goal.Next;
		}
	}
	Controller.ActiveGoal = ActiveGoal;
	DebugLog(DEBUG_AI, "GoalDecider::selectActiveGoal()	Selected Goal " $ ActiveGoal $ " with score " $ ActiveGoal.GetScore());
	if (ActiveGoal != prev_goal)
	{
		if (prev_goal != None)
		{
			prev_goal.LeaveGoal();
		}
		DebugLog(DEBUG_AI, "GoalDecider::selectActiveGoal()	Starting new goal " $ ActiveGoal);
	}
	else
	{
		DebugLog(DEBUG_AI, "dnback:: GoalDecider.selectActiveGoal(); Resuming goal " $ ActiveGoal);
	}
	ActiveGoal.StartGoal();
	*/
}
void AGoalDecider::_addGoal(AGoal* add_class, AActor* Focus)
{
	/*
	local AGP.Goal last_goal;
	local AGP.Goal add_goal;
	add_goal = Spawn(add_class, Self);
	if (add_goal == None)
	{
		DebugLog(DEBUG_Warn, "GoalDecider::_addGoal()	Failed to add " $ add_class);
	}
	if (_Top == None)
	{
		_Top = add_goal;
	}
	else
	{
		last_goal = _Top;
		if (last_goal.Next != None)
		{
			last_goal = last_goal.Next;
		}
		last_goal.Next = add_goal;
	}
	add_goal = None;
	*/
}
bool AGoalDecider::_removeGoal(AGoal* rem_goal)
{
	/*
	local AGP.Goal prev_goal;
	if (_Top == None)
	{
		Return False;
	}
	else
	{
		if (_Top == rem_goal)
		{
			_Top = _Top.Next;
			Return True;
		}
		else
		{
			prev_goal = _Top;
			if (prev_goal.Next != rem_goal)
			{
				prev_goal = prev_goal.Next;
				if (prev_goal == None)
				{
					Return False;
				}
			}
			prev_goal.Next = rem_goal.Next;
			Return True;
		}
	}
	*/
	return true;     //FAKE /ELiZ
}
