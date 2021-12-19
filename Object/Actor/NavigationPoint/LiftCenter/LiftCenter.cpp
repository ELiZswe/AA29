// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/LiftCenter/LiftCenter.h"

ALiftCenter::ALiftCenter()
{
	MaxDist2D = 400;
	bNeverUseStrafing = true;
	bForceNoStrafing = true;
	bSpecialMove = true;
	bNoAutoConnect = true;
	ExtraCost = 400;
	//bStatic = false;
	//RemoteRole = 0;
	//Texture = Texture'Engine.S_LiftCenter';
}

void ALiftCenter::PostBeginPlay()
{
	/*
	if (LiftTrigger != 'None')
	{
		ForEach DynamicActors('Trigger', RecommendedTrigger, LiftTrigger)
		{
		}
	}
	Super::PostBeginPlay();
	*/
}
void ALiftCenter::SpecialHandling(APawn* Other)
{
	/*
	if (MyLift == None)
	{
		return Self;
	}
	if (!MyLift.IsInState('StandOpenTimed'))
	{
		if (MyLift.bClosed && RecommendedTrigger != None)
		{
			return RecommendedTrigger;
		}
	}
	else
	{
		if (MyLift.BumpType == 0 && !Other.IsPlayerPawn())
		{
			return None;
		}
	}
	return this;
	*/
}
bool ALiftCenter::SuggestMovePreparation(APawn* Other)
{
	/*
	if (Other.Base == MyLift)
	{
		return false;
	}
	SetLocation(MyLift.Location + LiftOffset);
	SetBase(MyLift);
	if (MyLift.bInterpolating || !ProceedWithMove(Other))
	{
		Other.Controller.WaitForMover(MyLift);
		return true;
	}
	*/
	return false;
}
bool ALiftCenter::ProceedWithMove(APawn* Other)
{
	/*
	local LiftExit Start;
	local float Dist2D;
	local Object.Vector Dir;
	Start = LiftExit(Other.Anchor);
	if (Other.Controller == None)
	{
		return false;
	}
	else
	{
		if (Start != None && Start.KeyFrame != 255 && Other.ReachedDestination(Start))
		{
			if (MyLift.KeyNum == Start.KeyFrame)
			{
				return true;
			}
		}
		else
		{
			if (LiftExit(Other.Controller.MoveTarget) != None && Other.ReachedDestination(Self))
			{
				return LiftExit(Other.Controller.MoveTarget).CanBeReachedFromLiftBy(Other);
			}
			else
			{
				Dir = Location - Other.Location;
				Dir.Z = 0;
				Dist2D = VSize(Dir);
				if (Location.Z - CollisionHeight < Other.Location.Z - Other.CollisionHeight + 30 && Location.Z - CollisionHeight > Other.Location.Z - Other.CollisionHeight - 1200 && Dist2D < MaxDist2D)
				{
					return true;
				}
			}
		}
	}
	if (MyLift.bClosed)
	{
		Other.SetMoveTarget(SpecialHandling(Other));
		return true;
	}
	*/
	return false;
}
