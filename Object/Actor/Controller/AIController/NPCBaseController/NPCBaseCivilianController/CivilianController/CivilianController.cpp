// All the original content belonged to the US Army


#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseCivilianController/CivilianController/CivilianController.h"

ACivilianController::ACivilianController()
{

}

/*
State Dummy_Idle
{
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
Begin:
	StopMovement();
}
State Wander_Around
{
	Function PickWanderTarget()
	{
		local PathNode tempPath;
		int32 i = 0;
		int32 OldTarget = 0;
		OldTarget=nWanderTargetID;
		do
		{
			nWanderTargetID=int((FRand() * float(aWanderTargets.Length)));
		}
		until ((nWanderTargetID != OldTarget));
		nNumRoutePoints=-1;
		tempPath=PathNode(FindPathToward(aWanderTargets[nWanderTargetID]));
		if (tempPath == None)
		{
			GotoState('Dummy_Idle');
		}
		nRouteNum=0;
		for (i=0; i<62; i++)
		{
			if (RouteCache[i] != None)
			{
				nNumRoutePoints ++;
			}
		}
		if ((nNumRoutePoints > 0) && (tempPath != None))
		{
			GotoState('Wander_Around','WanderTo');
		}
	}
Begin:
	Sleep(2);
	JL'WanderTo'
;
	LookLeft();
	FinishRotation();
	LookRight();
	FinishRotation();
	LookRight();
	FinishRotation();
	LookLeft();
	FinishRotation();
	if (CheckDistance(RouteCache[nRouteNum].Location,500))
	{
		MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum],,,true);
	}
	else
	{
		MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum]);
	}
	if (RouteCache[nRouteNum].IsA('NPCDoorEntryPathNode'))
	{
		if ((FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])) != None) && FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])).bClosed)
		{
			StopMovement();
			if (OpenDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
				}
			}
		}
	}
	if (nRouteNum < nNumRoutePoints)
	{
		nRouteNum ++;
		if ((FRand() * float(100)) > float(50))
		{
			JL'Pause'
;
		}
		else
		{
			if ((FRand() * float(100)) > float(50))
			{
				JL'LookAround'
;
			}
			else
			{
				JL'WanderTo'
;
			}
		}
	}
	PickWanderTarget();
	PickWanderTarget();
}
State LiveGrenade
{
}
State Cowering
{
Begin:
	GotoState('Hide');
}
State Hidden
{
Begin:
	Crouch();
	Pawn.PlayWaiting();
	Pawn.LoopAnim('SurrenderKneesLoop',1,0,15);
}
State Hide
{
	Function NotifyHeardPlayerNoise(float fpLoudness, Pawn pawnHeard)
	{
	}
	Function NotifyPlayerPawnWatchingMe(Pawn pawnSeen)
	{
	}
	Function FindHidingSpot()
	{
		local NPCPathNode hidingSpot;
		local NPCPathNode tempPath;
		local Actor traceHit;
		FVector HitLocation = FVector(0,0,0);
		FVector HitNormal = FVector(0,0,0);
		FVector StartTrace = FVector(0,0,0);
		FVector EndTrace = FVector(0,0,0);
		int32 i = 0;
		local PathNode bestSpot;
		float hidingDist = 0;
		float newdist = 0;
		FVector diff = FVector(0,0,0);
		int32 coverChecked = 0;
		int32 searchRadius = 0;
		if (aDangerLocations.Length == 0)
		{
			return;
		}
		hidingDist=-1;
		Stand();
		if (aDangerLocations.Length == 0)
		{
			GotoState('Dummy_Idle');
		}
		coverChecked=0;
		searchRadius=500;
		if (searchRadius < 4000)
		{
			ForEach Pawn.RadiusActors(class'AGP.NPCPathNode',hidingSpot,float(searchRadius))
			{
				if (hidingSpot.npcbcUsingHallway != None)
				{
					continue;
				}
				if (((NPCDuckAndCoverPathNode(hidingSpot) == None) && (NPCCoverPositionPathNode(hidingSpot) == None)) || (NPCFirePositionPathNode(hidingSpot) != None))
				{
					continue;
				}
				coverChecked ++;
				StartTrace=hidingSpot.Location;
				EndTrace=aDangerLocations[0].Location;
				traceHit=Pawn.Trace(HitLocation,HitNormal,EndTrace,StartTrace,true);
				if ((traceHit != None) && (! traceHit.IsA('AGP_Character')))
				{
					diff=(Pawn.Location - hidingSpot.Location);
					diff.Z=0;
					newdist=VSize(diff);
					if ((hidingDist < 0) || (newdist < hidingDist))
					{
						hidingDist=newdist;
						bestSpot=hidingSpot;
					}
				}
			}
			if (bestSpot != None)
			{
			}
			searchRadius += 500;
		}
		if (bestSpot != None)
		{
			CoverNode=bestSpot;
			tempPath=NPCPathNode(FindPathToward(bestSpot));
			NPCPathNode(bestSpot).npcbcUsingHallway=Self;
			if (tempPath == None)
			{
				GotoState('Dummy_Idle');
			}
			nNumRoutePoints=-1;
			nRouteNum=0;
			for (i=0; i<62; i++)
			{
				if (RouteCache[i] != None)
				{
					nNumRoutePoints ++;
				}
			}
			if ((nNumRoutePoints > 0) && (tempPath != None))
			{
				GotoState('Hide','MoveToCover');
			}
		}
		else
		{
			GotoState('Dummy_Idle');
		}
	}
Begin:
	StopMovement();
	FindHidingSpot();
	MoveToward(RouteCache[nRouteNum],RouteCache[nRouteNum]);
	if (RouteCache[nRouteNum].IsA('NPCDoorEntryPathNode'))
	{
		if ((FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])) != None) && FindDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])).bClosed)
		{
			StopMovement();
			if (OpenDoor(NPCDoorEntryPathNode(RouteCache[nRouteNum])))
			{
				Sleep(0.1);
				if ((mLastDoorOpened != None) && mLastDoorOpened.bOpening)
				{
					Sleep(mLastDoorOpened.MoveTime);
				}
			}
		}
	}
	if (nRouteNum < nNumRoutePoints)
	{
		nRouteNum ++;
		if (! ValidateCover())
		{
			FindHidingSpot();
		}
		JL'MoveToCover'
;
	}
	GotoState('Hidden');
}
*/
