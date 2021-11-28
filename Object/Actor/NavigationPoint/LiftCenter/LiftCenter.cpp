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
		Return Self;
	}
	if (!MyLift.IsInState('StandOpenTimed'))
	{
		if (MyLift.bClosed && RecommendedTrigger != None)
		{
			Return RecommendedTrigger;
		}
	}
	else
	{
		if (MyLift.BumpType == 0 && !Other.IsPlayerPawn())
		{
			Return None;
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
		Return False;
	}
	SetLocation(MyLift.Location + LiftOffset);
	SetBase(MyLift);
	if (MyLift.bInterpolating || !ProceedWithMove(Other))
	{
		Other.Controller.WaitForMover(MyLift);
		Return True;
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
		Return False;
	}
	else
	{
		if (Start != None && Start.KeyFrame != 255 && Other.ReachedDestination(Start))
		{
			if (MyLift.KeyNum == Start.KeyFrame)
			{
				Return True;
			}
		}
		else
		{
			if (LiftExit(Other.Controller.MoveTarget) != None && Other.ReachedDestination(Self))
			{
				Return LiftExit(Other.Controller.MoveTarget).CanBeReachedFromLiftBy(Other);
			}
			else
			{
				Dir = Location - Other.Location;
				Dir.Z = 0;
				Dist2D = VSize(Dir);
				if (Location.Z - CollisionHeight < Other.Location.Z - Other.CollisionHeight + 30 && Location.Z - CollisionHeight > Other.Location.Z - Other.CollisionHeight - 1200 && Dist2D < MaxDist2D)
				{
					Return True;
				}
			}
		}
	}
	if (MyLift.bClosed)
	{
		Other.SetMoveTarget(SpecialHandling(Other));
		Return True;
	}
	*/
	return false;
}