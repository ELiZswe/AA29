// All the original content belonged to the US Army

#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseVehicleController/NPCBaseVehicleController.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/NPCRoadPathNode/NPCRoadPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/PathNode.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

ANPCBaseVehicleController::ANPCBaseVehicleController()
{

}

/*
State NoVehicle
{
	Function BeginState()
	{
		Log("NPC " + FString::FromInt(Tag) + " could not find a vehicle!");
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
		NPCLog("Looking for our ride (" + FString::FromInt(Pawn.Tag) + ")");
		ForEach AllActors(AVehicle::StaticClass(),agpvIterator,Pawn.Tag)
		{
			NPCLog("Testing vehicle: " + FString::FromInt(agpvIterator) + " tag: \"" + FString::FromInt(agpvIterator.Tag) + "\"");
			if (string(agpvIterator.Tag) ~= FString::FromInt(Pawn.Tag))
			{
				NPCLog("Found our ride: " + FString::FromInt(agpvIterator));
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
		NPCLog("Bumped into something (vehicle?): " + FString::FromInt(Other));
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
			JL"End";
		}
		ResumeTravelSpeed();
		actorNextPathLocation=FindPathToward(agpvVehicle,true);
		pnCurrentNodeLeadingToPathNode=PathNode(actorNextPathLocation);
		NPCLog("Path location: " + FString::FromInt(actorNextPathLocation) + " converted to pathnode: " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
		DebugDumpRoute();
		NPCLog("Moving to node " + FString::FromInt(agpvVehicle) + " via " + FString::FromInt(pnCurrentNodeLeadingToPathNode));
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
			NPCLog("No more nodes found on the way - moving to last node which should be vehicle: " + FString::FromInt(agpvVehicle.Tag));
			MoveTo(agpvVehicle->GetActorLocation(),agpvVehicle,(! ShouldRun()));
			GotoState("EnteringVehicle");
			JL"None";
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
		NPCLog("Vehcile bumped into something (vehicle?): " + FString::FromInt(Other));
		StopMovement();
		return false;
	}
	Function DetermineNextPathNode()
	{
		if (bAscendingNodeDirection)
		{
			if (iCurrentDrivingPathNodeIndex < (apnDrivingPathNodesForPatrol.Num() - 1))
			{
				iCurrentDrivingPathNodeIndex ++;
			}
			else
			{
				if (bAutoReversePath)
				{
					if (apnDrivingPathNodesForPatrol.Num() > 0)
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
			NPCLog("Ascending pathnodes - new index: " + FString::FromInt(iCurrentPathNodeIndex) + " node: " + FString::FromInt(apnPathNodesForPatrol[iCurrentPathNodeIndex].Tag));
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
					if (apnDrivingPathNodesForPatrol.Num() > 0)
					{
						NPCLog("Reversing direction back to ascending");
						bAscendingNodeDirection=true;
						DetermineNextPathNode();
						return;
					}
				}
				else
				{
					iCurrentDrivingPathNodeIndex=(apnDrivingPathNodesForPatrol.Num() - 1);
				}
			}
			NPCLog("Descending pathnodes - new index: " + FString::FromInt(iCurrentPathNodeIndex));
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
		JL"End";
	}
	NPCLog("Heading to next major patrol node");
	if (iCurrentDrivingPathNodeIndex == 0)
	{
		bUseAlternatePath=(FMath::FRand() > 0.5);
		NPCLog("Alternate Driving path: " + FString::FromInt(bUseAlternatePath));
	}
	NPCLog("At " + FString::FromInt(Pawn.Location.X) + "," + FString::FromInt(Pawn.Location.Y) + "," + FString::FromInt(Pawn.Location.Z) + " moving to driving node: " + FString::FromInt(pnCurrentRoadPathNode.Tag) + " at " + FString::FromInt(pnCurrentRoadPathNode.Location.X) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Y) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Z) + "  Distance: " + FString::FromInt(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	Pawn.DesiredSpeed=pnCurrentRoadPathNode.fpDesiredSpeed;
	Pawn.MaxDesiredSpeed=pnCurrentRoadPathNode.fpMaxDesiredSpeed;
	Focus=pnCurrentRoadPathNode;
	FindPathToward(pnCurrentRoadPathNode,false);
	MoveTo(pnCurrentRoadPathNode->GetActorLocation(),pnCurrentRoadPathNode,true);
	NPCLog("Now at " + FString::FromInt(Pawn.Location.X) + "," + FString::FromInt(Pawn.Location.Y) + "," + FString::FromInt(Pawn.Location.Z) + " moving to driving node: " + FString::FromInt(pnCurrentRoadPathNode.Tag) + ", should be at " + FString::FromInt(pnCurrentRoadPathNode.Location.X) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Y) + "," + FString::FromInt(pnCurrentRoadPathNode.Location.Z) + "  Distance: " + FString::FromInt(VSize((Pawn.Location - pnCurrentRoadPathNode.Location))));
	if (VSize((Pawn.Location - pnCurrentRoadPathNode.Location)) > float(512))
	{
		NPCLog("Still not really at location, trying again to move there");
		JL"MoveOn";
	}
	Sleep(0.1);
	DetermineNextPathNode();
	FindNextDrivingPatrolPathNode();
	JL"MoveOn";
}
*/

void ANPCBaseVehicleController::Start()
{
	bStart = true;
	//Pawn.PlayWaiting();
	WantsToWalk();
	NPCLog("Starting to wait for vehicle");
	ChangeState("WaitForVehicle");
}

/*
void ANPCBaseVehicleController::Possess(APawn* aPawn)
{
	if ((aPawn != nullptr) && aPawn->IsA("AAGP_Pawn::StaticClass()"))
	{
		NPCLog("Possess() entered for AGP_Pawn");
		Super::Possess(aPawn);
		aPawn.Controller = this;
		priFromNPCPawn = aPawn.PlayerReplicationInfo;
	}
	else
	{
		NPCLog("Possess() entered for non-AGP_Pawn with PRI of: " + FString::FromInt(priFromNPCPawn));
		Possess(aPawn);
		aPawn.PossessedBy(this);
		aPawn.Controller = this;
		aPawn.PlayerReplicationInfo = priFromNPCPawn;
		Pawn = aPawn;
	}
}
*/

void ANPCBaseVehicleController::PreloadPathNodeList()
{
	int32 iNode = 0;
	APathNode* pnFound = nullptr;
	Super::PreloadPathNodeList();
	for (iNode = 0; iNode < 99; iNode++)
	{
		//pnFound = GetPathnodeByTag(string(sNPCWaypointTag + "-" + FString::FromInt((iNode + 1))));
		if (pnFound == nullptr)
		{
		}
		//apnDrivingPathNodesForPatrol[iNode] = Cast<ANPCRoadPathNode>(pnFound);
		if (bDebugPath)
		{
			//pnFound->bHidden = false;
		}
		NPCPathLog("Found path node for " + sNPCWaypointTag + "-" + FString::FromInt((iNode + 1)));
	}
}

ANPCRoadPathNode* ANPCBaseVehicleController::FindNextDrivingPatrolPathNode()
{
	NPCPathLog("Searching for next navpoint to move to: " + FString::FromInt((iCurrentDrivingPathNodeIndex + 1)));
	if (iCurrentDrivingPathNodeIndex < apnDrivingPathNodesForPatrol.Num())
	{
		//NPCPathLog("Found pathnode: " + apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex]);
		pnCurrentRoadPathNode = apnDrivingPathNodesForPatrol[iCurrentDrivingPathNodeIndex];
		return pnCurrentRoadPathNode;
	}
	NPCPathLog("FindNextDrivingPatrolPathNode() - Couldn't find pathnode");
	return nullptr;
}

/*
void ANPCBaseVehicleController::UnPossess()
{
	if (Pawn->IsA("AAGP_Pawn::StaticClass()"))
	{
		NPCLog("Current pawn is AGP_Pawn, we're doing nothing there");
	}
}
*/

float ANPCBaseVehicleController::PlayCustomAnimation(FName nameAnimation, bool bLoop, float fpRate)
{
	APawn* pwnCurrent = nullptr;
	/*
	if (((GetPawn() == nullptr) || ((GetPawn() != nullptr) && (GetPawn()->Health <= 0))) && (agpvVehicle->Driver == nullptr))
	{
		return 0;
	}
	*/
	if ((GetPawn() != nullptr) && GetPawn()->IsA(AAGP_Pawn::StaticClass()))
	{
		pwnCurrent = GetPawn();
	}
	else
	{
		pwnCurrent = agpvVehicle->Driver;
	}
	//NPCLog("Pawn: " + pwnCurrent + " trying to play animation " + nameAnimation + " of duration " + pwnCurrent->GetAnimDuration(nameAnimation) + " seconds.");
	//NPCLog("Pawn Mesh: " + FString::FromInt(pwnCurrent->Mesh));
	/*
	if (pwnCurrent->GetAnimDuration(nameAnimation) > 0)
	{
		if (GetWorld()->GetNetMode() == NM_Standalone)
		{
			pwnCurrent->EnableChannelNotify(15, 1);
			pwnCurrent->AnimBlendParams(15, 1, pwnCurrent->BlendChangeTime, pwnCurrent->BlendChangeTime, "Spine02");
			pwnCurrent->PlayAnim(nameAnimation, 1, 0.05, 15);
		}
		else
		{
			pwnCurrent->AnimAction = nameAnimation;
		}
	}
	else
	{
		Log("*** WARNING *** INVALID Animation " + FString::FromInt(nameAnimation) + " for pawn " + FString::FromInt(pwnCurrent) + " Tag: " + FString::FromInt(pwnCurrent->Tag));
	}
	return pwnCurrent->GetAnimDuration(nameAnimation);
	*/
	return 0;    //FAKE   /ELiZ
}

void ANPCBaseVehicleController::NPCLog(FString sLogText)
{
	if ((agpvVehicle != nullptr) && (agpvVehicle->Driver != nullptr))
	{
		if (bDebugMode)
		{
			//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + FString::FromInt(agpvVehicle->Driver) + " " + sLogText);
		}
	}
	else
	{
		if (GetPawn() != nullptr)
		{
			if (bDebugMode)
			{
				//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + FString::FromInt(Pawn.Name) + " " + sLogText);
			}
		}
		else
		{
			//Log(string(GetWorld()->GetTimeSeconds()) + " - " + FString::FromInt(this) + "." + FString::FromInt(GetStateName()) + " - " + sLogText);
		}
	}
}

