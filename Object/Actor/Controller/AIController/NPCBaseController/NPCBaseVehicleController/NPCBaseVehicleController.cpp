// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseVehicleController/NPCBaseVehicleController.h"

ANPCBaseVehicleController::ANPCBaseVehicleController()
{

}

/*
State NoVehicle
{
	Function BeginState()
	{
		Log("NPC " $ string(Tag) $ " could not find a vehicle!");
	}
}
*/

/*
State WaitForVehicle
{
	Function BeginState()
	{
		SetTimer(1,true);
	}
	Function Timer()
	{
		DetermineVehicle();
	}
	Function DetermineVehicle()
	{
		local Vehicle agpvIterator;
		NPCLog("Looking for our ride (" $ string(Pawn.Tag) $ ")");
		ForEach AllActors(Class'Vehicle',agpvIterator,Pawn.Tag)
		{
			NPCLog("Testing vehicle: " $ string(agpvIterator) $ " tag: \"" $ string(agpvIterator.Tag) $ "\"");
			if (string(agpvIterator.Tag) ~= string(Pawn.Tag))
			{
				NPCLog("Found our ride: " $ string(agpvIterator));
				agpvVehicle=agpvIterator;
				GotoState("MoveToVehicle");
				return;
			}
		}
	}
}
*/

/*
State MoveToVehicle
{
	Event bool NotifyBump(Actor Other)
	{
		NPCLog("Bumped into something (vehicle?): " $ string(Other));
		if (Other == agpvVehicle)
		{
			NPCLog("Vehicle we're looking for we bumped into.");
			GotoState("EnteringVehicle");
			return true;
		}
		return false;
	}
Begin:
	NPCLog("MoveToVehicle.Begin entered");
	Sleep(2);
	Walk();
	WantsToWalk();
	if (true)
	{
		if (((Pawn == None) || (Pawn.Health < 0)) || (! bStart))
		{
			GotoState("None");
			JL"End"
;
		}
		ResumeTravelSpeed();
		actorNextPathLocation=FindPathToward(agpvVehicle,true);
		pnCurrentNodeLeadingToPathNode=PathNode(actorNextPathLocation);
		NPCLog("Path location: " $ string(actorNextPathLocation) $ " converted to pathnode: " $ string(pnCurrentNodeLeadingToPathNode));
		DebugDumpRoute();
		NPCLog("Moving to node " $ string(agpvVehicle) $ " via " $ string(pnCurrentNodeLeadingToPathNode));
		if (((! pointReachable(agpvVehicle.Location)) && (pnCurrentNodeLeadingToPathNode != None)) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
		{
			Focus=pnCurrentNodeLeadingToPathNode;
			TurnToActor(pnCurrentNodeLeadingToPathNode,512);
			FinishRotation();
			MoveToward(pnCurrentNodeLeadingToPathNode,pnCurrentNodeLeadingToPathNode,,false,(! ShouldRun()));
		}
		else
		{
			Focus=agpvVehicle;
			TurnToActor(agpvVehicle,512);
			FinishRotation();
			NPCLog("No more nodes found on the way - moving to last node which should be vehicle: " $ string(agpvVehicle.Tag));
			MoveTo(agpvVehicle.Location,agpvVehicle,(! ShouldRun()));
			GotoState("EnteringVehicle");
			JL"None"
;
		}
		iBumpsThisPathnode=0;
	}
	NPCLog("Got to vehicle, going to try to drive it");
	GotoState("EnteringVehicle");
}
*/

/*
State EnteringVehicle
{
	Event bool NotifyBump(Actor Other)
	{
		return true;
	}
Begin:
	StopMovement();
	if (! agpvVehicle.TryToDrive(Pawn))
	{
		NPCLog("Vehicle won't let me in");
		GotoState("None");
		JL"None"
;
	}
	NPCLog("In vehicle, should be sitting but without animation we aren't");
	GotoState("DrivingPatrol");
}
*/

/*
State DrivingPatrol
{
	Event bool NotifyBump(Actor Other)
	{
		NPCLog("Vehcile bumped into something (vehicle?): " $ string(Other));
		StopMovement();
		return false;
	}
	Function DetermineNextPathNode()
	{
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < (apnDrivingPathNodesForPatrol.Length - 1))
			{
				iCurrentDrivingPathNodeIndex ++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (apnDrivingPathNodesForPatrol.Length > 0)
					{
						NPCLog("Reversing direction back to descending");
						bAscendingNodeDirection=false;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=0;
				}
			}
			NPCLog("");
			NPCLog("");
			NPCLog("Ascending pathnodes - new index: " $ string(iCurrentPathNodeIndex) $ " node: " $ string(apnPathNodesForPatrol[iCurrentPathNodeIndex].Tag));
		}
		else
		{
			if (iCurrentDrivingPathNodeIndex > 0)
			{
				iCurrentDrivingPathNodeIndex --;
			}
			else
			{
				NPCLog("Descending path hit when on first node, see about reverse or wrap");
				if (bAutoReversePath)
				{
					if (apnDrivingPathNodesForPatrol.Length > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection=true;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=(apnDrivingPathNodesForPatrol.Length - 1);
				}
			}
			NPCLog("Descending pathnodes - new index: " $ string(iCurrentPathNodeIndex));
		}
		FindNextDrivingPatrolPathNode();
	}
Begin:
	NPCLog("DrivingPatrol.Begin entered");
	FindNextDrivingPatrolPathNode();
	if (pnCurrentRoadPathNode == None)
	{
		NPCLog("No path node to move to!");
		GotoState("None");
		JL"End"
;
	}
	NPCLog("Heading to next major patrol node");
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		bUseAlternatePath=(FRand() > 0.5);
		NPCLog("Alternate Driving path: " $ string(bUseAlternatePath));
	}
	NPCLog("At " $ string(Pawn.Location.X) $ "," $ string(Pawn.Location.Y) $ "," $ string(Pawn.Location.Z) $ " moving to driving node: " $ string(pnCurrentRoadPathNode.Tag) $ " at " $ string(pnCurrentRoadPathNode.Location.X) $ "," $ string(pnCurrentRoadPathNode.Location.Y) $ "," $ string(pnCurrentRoadPathNode.Location.Z) $ "  Distance: " $ string(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	Pawn.DesiredSpeed=pnCurrentRoadPathNode.fpDesiredSpeed;
	Pawn.MaxDesiredSpeed=pnCurrentRoadPathNode.fpMaxDesiredSpeed;
	Focus=pnCurrentRoadPathNode;
	FindPathToward(pnCurrentRoadPathNode,false);
	MoveTo(pnCurrentRoadPathNode.Location,pnCurrentRoadPathNode,true);
	NPCLog("Now at " $ string(Pawn.Location.X) $ "," $ string(Pawn.Location.Y) $ "," $ string(Pawn.Location.Z) $ " moving to driving node: " $ string(pnCurrentRoadPathNode.Tag) $ ", should be at " $ string(pnCurrentRoadPathNode.Location.X) $ "," $ string(pnCurrentRoadPathNode.Location.Y) $ "," $ string(pnCurrentRoadPathNode.Location.Z) $ "  Distance: " $ string(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	if (VSize((Pawn.Location - pnCurrentRoadPathNode.Location)) > float(512))
	{
		NPCLog("Still not really at location, trying again to move there");
		JL"MoveOn"
;
	}
	Sleep(0.1);
	DetermineNextPathNode();
	FindNextDrivingPatrolPathNode();
	JL"MoveOn"
;
}
*/

