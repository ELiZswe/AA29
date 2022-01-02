// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseVehicleController/NPCBaseVehicleController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"

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
		AVehicle* agpvIterator = nullptr;
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
	Event bool NotifyBump(AActor* Other)
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
		if (((Pawn == nullptr) || (Pawn.Health < 0)) || (! bStart))
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
		if (((! pointReachable(agpvVehicle.Location)) && (pnCurrentNodeLeadingToPathNode != nullptr)) && (pnCurrentNodeLeadingToPathNode != pnCurrentPathNode))
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
	Event bool NotifyBump(AActor* Other)
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
	Event bool NotifyBump(AActor* Other)
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
	if (pnCurrentRoadPathNode == nullptr)
	{
		NPCLog("No path node to move to!");
		GotoState("None");
		JL"End"
;
	}
	NPCLog("Heading to next major patrol node");
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		bUseAlternatePath=(FMath::FRand() > 0.5);
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

void ANPCBaseVehicleController::Start()
{
	bStart = true;
	//Pawn.PlayWaiting();
	WantsToWalk();
	NPCLog("Starting to wait for vehicle");
	//GotoState("WaitForVehicle");
}

/*
void ANPCBaseVehicleController::Possess(APawn* aPawn)
{
	if ((aPawn != nullptr) && aPawn.IsA("AGP_Pawn"))
	{
		NPCLog("Possess() entered for AGP_Pawn");
		Super::Possess(aPawn);
		aPawn.Controller = Self;
		priFromNPCPawn = aPawn.PlayerReplicationInfo;
	}
	else
	{
		NPCLog("Possess() entered for non-AGP_Pawn with PRI of: " $ string(priFromNPCPawn));
		Possess(aPawn);
		aPawn.PossessedBy(Self);
		aPawn.Controller = Self;
		aPawn.PlayerReplicationInfo = priFromNPCPawn;
		Pawn = aPawn;
	}
}
*/

void ANPCBaseVehicleController::PreloadPathNodeList()
{
	int32 iNode = 0;
	APathNode* pnFound = nullptr;
	/*
	Super::PreloadPathNodeList();
	for (iNode = 0; iNode < 99; iNode++)
	{
		pnFound = GetPathnodeByTag(string(sNPCWaypointTag $ "-" $ string((iNode + 1))));
		if (pnFound == nullptr)
		{
		}
		apnDrivingPathNodesForPatrol[iNode] = NPCRoadPathNode(pnFound);
		if (bDebugPath)
		{
			pnFound.bHidden = false;
		}
		NPCPathLog("Found path node for " $ sNPCWaypointTag $ "-" $ string((iNode + 1)));
	}
	*/
}

ANPCRoadPathNode* ANPCBaseVehicleController::FindNextDrivingPatrolPathNode()
{
	/*
	NPCPathLog("Searching for next navpoint to move to: " + string((iCurrentDrivingPathNodeIndex + 1)));
	if (iCurrentDrivingPathNodeIndex < apnDrivingPathNodesForPatrol.Length)
	{
		NPCPathLog("Found pathnode: " + string(apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex]));
		pnCurrentRoadPathNode = apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
		return pnCurrentRoadPathNode;
	}
	NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
	*/
	return nullptr;
}

/*
void ANPCBaseVehicleController::UnPossess()
{
	if (Pawn.IsA("AGP_Pawn"))
	{
		NPCLog("Current pawn is AGP_Pawn, we're doing nothing there");
	}
}
*/

float ANPCBaseVehicleController::PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate)
{
	APawn* pwnCurrent = nullptr;
	/*
	if (((Pawn == nullptr) || ((Pawn != nullptr) && (Pawn.Health <= 0))) && (agpvVehicle.Driver == nullptr))
	{
		return 0;
	}
	if ((Pawn != nullptr) && Pawn.IsA("AGP_Pawn"))
	{
		pwnCurrent = Pawn;
	}
	else
	{
		pwnCurrent = agpvVehicle.Driver;
	}
	NPCLog("Pawn: " $ string(pwnCurrent) $ " trying to play animation " $ string(nameAnimation) $ " of duration " $ string(pwnCurrent.GetAnimDuration(nameAnimation)) $ " seconds.");
	NPCLog("Pawn Mesh: " $ string(pwnCurrent.Mesh));
	if (pwnCurrent.GetAnimDuration(nameAnimation) > 0)
	{
		if (Level.NetMode == NM_Standalone)
		{
			pwnCurrent.EnableChannelNotify(15, 1);
			pwnCurrent.AnimBlendParams(15, 1, pwnCurrent.BlendChangeTime, pwnCurrent.BlendChangeTime, "Spine02");
			pwnCurrent.PlayAnim(nameAnimation, 1, 0.05, 15);
		}
		else
		{
			pwnCurrent.AnimAction = nameAnimation;
		}
	}
	else
	{
		Log("*** WARNING *** INVALID Animation " $ string(nameAnimation) $ " for pawn " $ string(pwnCurrent) $ " Tag: " $ string(pwnCurrent.Tag));
	}
	return pwnCurrent->GetAnimDuration(nameAnimation);
	*/
	return 0;    //FAKE   /ELiZ
}

void ANPCBaseVehicleController::NPCLog(FString sLogText)
{
	/*
	if ((agpvVehicle != nullptr) && (agpvVehicle.Driver != nullptr))
	{
		if (bDebugMode)
		{
			Log(string(Level.TimeSeconds) $ " - " $ string(Self) $ "." $ string(GetStateName()) $ " - " $ string(agpvVehicle.Driver) $ " " $ sLogText);
		}
	}
	else
	{
		if (Pawn != nullptr)
		{
			if (bDebugMode)
			{
				Log(string(Level.TimeSeconds) $ " - " $ string(Self) $ "." $ string(GetStateName()) $ " - " $ string(Pawn.Name) $ " " $ sLogText);
			}
		}
		else
		{
			Log(string(Level.TimeSeconds) $ " - " $ string(Self) $ "." $ string(GetStateName()) $ " - " $ sLogText);
		}
	}
	*/
}

