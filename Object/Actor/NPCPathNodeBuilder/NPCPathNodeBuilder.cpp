// All the original content belonged to the US Army

#include "AA29/Object/Actor/NPCPathNodeBuilder/NPCPathNodeBuilder.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/StudentController/StudentController.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/NPCPathBuilderHUD/NPCPathBuilderHUD.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCWaypointPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCCoverPositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCCoverPositionPathNode/NPCFirePositionPathNode/NPCFirePositionPathNode.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/NPCPathNode/NPCWaypointPathNode/NPCLadderPathNode/NPCLadderPathNode.h"

// Sets default values
ANPCPathNodeBuilder::ANPCPathNodeBuilder()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	//bProp = true;
}


void ANPCPathNodeBuilder::BeginPlay()
{
	Super::BeginPlay();
}

//native final Function bool SavePathNodes(FString sFileName);
bool ANPCPathNodeBuilder::SavePathNodes(FString sFileName)
{
	return false;   //FAKE   /EliZ
}

//native final Function bool LoadPathNodes(FString sFileName);
bool ANPCPathNodeBuilder::LoadPathNodes(FString sFileName)
{
	return false;   //FAKE   /EliZ
}

//native final Function int32 GetMouseX();
int32 ANPCPathNodeBuilder::GetMouseX()
{
	return 0;   //FAKE   /EliZ
}

//native final Function int32 GetMouseY();
int32 ANPCPathNodeBuilder::GetMouseY()
{
	return 0;   //FAKE   /EliZ
}

//native final Function SetCurrentWaypointNodeTag(FString sNewTag);
void ANPCPathNodeBuilder::SetCurrentWaypointNodeTag(FString sNewTag)
{

}

//native final Function EnableTransientNaming(bool bUseTransient);
void ANPCPathNodeBuilder::EnableTransientNaming(bool bUseTransient)
{

}

//native final Function BuildAndTestPaths();
void ANPCPathNodeBuilder::BuildAndTestPaths()
{

}

//native final Function BuildFinalPaths(FString sMapNameToSave);
void ANPCPathNodeBuilder::BuildFinalPaths(FString sMapNameToSave)
{

}

//native final Function GetPathNodeFileList();
void ANPCPathNodeBuilder::GetPathNodeFileList()
{

}

void ANPCPathNodeBuilder::SetPathBuilderOwner(AStudentController* SC)
{
	ANPCPathBuilderHUD* npcpbhud = nullptr;
	scOwner = SC;
	/*
	npcpbhud = Spawn(ANPCPathBuilderHUD::StaticClass(), scOwner);
	Log("Pathbuilder HUD: " + FString::FromInt(npcpbhud));
	*/
	if (npcpbhud != nullptr)
	{
		scOwner->MyHUD = npcpbhud;
		npcpbhud->npcpnbActivePathBuilder = this;
	}
	else
	{
		ClientMessage("Could not create Path Builder HUD");
	}
}

void ANPCPathNodeBuilder::TestPathNodes()
{
	ClientMessage("Starting path building and testing process.");
	SavePathNodes(sCurrentPNBFileName);
	BuildAndTestPaths();
	//ConsoleCommand("quit");
}

void ANPCPathNodeBuilder::SaveFinalMapPaths(FString sFinalMapName)
{
	ClientMessage("Starting path building and testing process.");
	SavePathNodes(sCurrentPNBFileName);
	BuildFinalPaths(sFinalMapName);
	//ConsoleCommand("quit");
}

FString ANPCPathNodeBuilder::GetPNBFileName()
{
	return sCurrentPNBFileName;
}

void ANPCPathNodeBuilder::SavePathNodesToFile(FString sFileName)
{
	if (SavePathNodes(sFileName))
	{
		sCurrentPNBFileName = sFileName;
		ClientMessage("Path nodes saved to " + sFileName + ".pnb.xml");
	}
	else
	{
		ClientMessage("Unable to save path nodes to " + sFileName + ".pnb.xml");
	}
}

void ANPCPathNodeBuilder::LoadPathNodesFromFile(FString sFileName)
{
	bBusyLoading = true;
	ResetPathBuilding();
	if (LoadPathNodes(sFileName))
	{
		sCurrentPNBFileName = sFileName;
		ClientMessage("Path nodes loaded from " + sFileName + ".pnb.xml");
	}
	else
	{
		ClientMessage("Unable to load path nodes from " + sFileName + ".pnb.xml");
	}
	bBusyLoading = false;
}

void ANPCPathNodeBuilder::EnablePathBuilding(bool bEnable)
{
	ANPCPlayerStart* npcps = nullptr;
	bEnabledPathBuilding = bEnable;
	if ((!bEnable) && (scOwner != nullptr))
	{
		scOwner->SpawnDefaultHUD();
	}
	if (bEnable)
	{
		npcps = DropNPCPlayerStart("Grunt");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		npcps = DropNPCPlayerStart("NCO");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		npcps = DropNPCPlayerStart("Officer");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		npcps = DropNPCPlayerStart("Commando");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		npcps = DropNPCPlayerStart("Spotter");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		npcps = DropNPCPlayerStart("Civilian");
		if (npcps != nullptr)
		{
			npcps->Destroy();
		}
		ResetPathBuilding();
	}
}

void ANPCPathNodeBuilder::RequestResetPaths()
{
	if (fpTimeSinceResetPathsRequest == 0)
	{
		fpTimeSinceResetPathsRequest = GetWorld()->GetTimeSeconds();
		return;
	}
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceResetPathsRequest) > 5)
	{
		fpTimeSinceResetPathsRequest = 0;
		return;
	}
	ResetPathBuilding();
}

void ANPCPathNodeBuilder::ResetPathBuilding()
{
	int32 iNode = 0;
	int32 iPlayerStart = 0;
	for (iNode = 0; iNode < anpcpnPathNodes.Num(); iNode++)
	{
		anpcpnPathNodes[iNode]->Destroy(true);
	}
	for (iPlayerStart = 0; iPlayerStart < anpcpsPlayerStarts.Num(); iPlayerStart++)
	{
		anpcpsPlayerStarts[iPlayerStart]->Destroy(true);
	}
	if (npcpnNodeBeingEdited != nullptr)
	{
		npcpnNodeBeingEdited->DebugNavMarker(false, false);
	}
	if (npcpsBeingEdited != nullptr)
	{
		npcpsBeingEdited->DebugNavMarker(false, false);
	}
	anpcpnPathNodes.Empty();
	anpcpsPlayerStarts.Empty();
	npcpnLastDroppedPathNode = nullptr;
	npcpnNodeBeingEdited = nullptr;
	npcpnNodeLastEdited = nullptr;
	npcpsBeingEdited = nullptr;
	npcpsBeingDeleted = nullptr;
	vLastTestedAutoDropLocation = FVector(0, 0, 0);
}

void ANPCPathNodeBuilder::PausePathBuilding(bool bPause)
{
	bPathNodingPaused = bPause;
}

bool ANPCPathNodeBuilder::CanDropNode(bool bAutoDropTest)
{
	AActor* actIterator = nullptr;
	if (scOwner == nullptr)
	{
		return false;
	}
	if (scOwner->bNPCPBForceDrop == 1)
	{
		return true;
	}
	/*
	if (((bAutoDropTest && (scOwner.Pawn.Base != nullptr)) && scOwner.Pawn.Base->IsA(AStaticMeshActor::StaticClass())) && ((npcpnLastDroppedPathNode != nullptr) && (npcpnLastDroppedPathNode.Base != scOwner.Pawn.Base)))
	{
		return false;
	}
	*/
	if (bOnLadder)
	{
		return false;
	}
	/*
	ForEach RadiusActors(Class'Actor', actIterator, (scOwner.Pawn.CollisionRadius + float(10)), scOwner.Pawn.Location)
	{
		if ((!actIterator.bCollideActors) && (!actIterator->IsA(ANPCPathNode::StaticClass())))
		{
			continue;
		}
		if (actIterator == scOwner.Pawn.Base)
		{
			continue;
		}
		if ((actIterator->IsA(ANPCPathNode::StaticClass()) && (!actIterator.bHidden)) && (!actIterator.bDeleteMe))
		{
			Log("Too close to another path node: " + FString::FromInt(actIterator));
			return false;
		}
		if (((actIterator != scOwner.Pawn) && (actIterator.Owner != scOwner.Pawn)) && (actIterator.Location.Z > scOwner.Pawn.Location.Z))
		{
			Log("Found object too close to this node: " + FString::FromInt(actIterator) + " Distance: " + FString::FromInt(VSize((scOwner.Pawn.Location - actIterator.Location))));
			return false;
		}
	}
	*/
	return true;
}

ANPCPlayerStart* ANPCPathNodeBuilder::DropNPCPlayerStart(FString sType)
{
	ANPCPlayerStart* anpcpsClass = nullptr;
	ANPCPlayerStart* npcpsNew = nullptr;
	if (scOwner == nullptr)
	{
		return nullptr;
	}
	/*
	if (!CanDropNode())
	{
		scOwner.ClientMessage("Can't drop player start here (something would block it)");
		return nullptr;
	}
	switch (sType)
	{
	case "Grunt":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartGrunt", Class'Class'));
		break;
	case "NCO":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartNCO", Class'Class'));
		break;
	case "Officer":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartOfficer", Class'Class'));
		break;
	case "Commando":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartCommando", Class'Class'));
		break;
	case "Spotter":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartSpotter", Class'Class'));
		break;
	case "Civilian":
		anpcpsClass = class<NPCPlayerStart>(DynamicLoadObject("AGP.NPCPlayerStartCivilian", Class'Class'));
		break;
	default:
	}
	EnableTransientNaming(true);
	npcpsNew = Spawn(anpcpsClass, , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, false, true);
	EnableTransientNaming(false);
	Log("Spawning " + FString::FromInt(npcpsNew.Name));
	npcpsNew.bHidden = false;
	npcpsNew.SetRotation(scOwner.Pawn.Rotation);
	npcpsNew.bAscendingNodeDirection = true;
	anpcpsPlayerStarts.insert(anpcpsPlayerStarts.Num(), 1);
	anpcpsPlayerStarts[(anpcpsPlayerStarts.Num() - 1)] = npcpsNew;
	npcpsBeingEdited = npcpsNew;
	if (Len(sWaypointNavTag) > 0)
	{
		npcpsBeingEdited.sNPCWaypointTag = sWaypointNavTag;
	}
	*/
	return npcpsNew;
}

bool ANPCPathNodeBuilder::DropCustomNode(FString sType)
{
	ANPCPathNode* anpcpnClass = nullptr;
	ANPCPathNode* npcpnNew = nullptr;
	bool bSetWaypointTag = false;
	if (scOwner == nullptr)
	{
		return false;
	}
	/*
	if ((!CanDropNode()) && (!(sType ~= "Ladder")))
	{
		scOwner.ClientMessage("Can't drop node here (something would block it)");
		return false;
	}
	Log("Trying to drop node " + FString::FromInt(anpcpnClass));
	switch (sType)
	{
	case "Cover":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCCoverPositionPathNode", Class'Class'));
		break;
	case "Firing":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCFirePositionPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	case "Camper":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCCamperFirePositionPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	case "Alamo":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCAlamoFirePositionPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	case "Door":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCDoorEntryPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	case "Ladder":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCLadderPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	case "Rest":
		anpcpnClass = class<NPCPathNode>(DynamicLoadObject("AGP.NPCRestStopPathNode", Class'Class'));
		bSetWaypointTag = true;
		break;
	default:
		ClientMessage("Invalid type.  Use: Alamo, Camper, Cover, Door, Fire, Ladder");
		return false;
	}
	EnableTransientNaming(true);
	npcpnNew = Spawn(anpcpnClass, , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, false, true);
	EnableTransientNaming(false);
	if (npcpnNew == nullptr)
	{
		Log("Failed to create node of type " + FString::FromInt(npcpnNew) + " \"" + sType + "\"");
		ClientMessage("Failed to create pathnode");
		return false;
	}
	npcpnNew.bHidden = false;
	if (npcpnLastDroppedPathNode != nullptr)
	{
		npcpnLastDroppedPathNode.DebugNavMarker(false, false);
	}
	npcpnNew.bBlockZeroExtentTraces = true;
	npcpnNew.bBlockNonZeroExtentTraces = true;
	npcpnNew.DebugNavMarker(true, false);
	npcpnNew.SetRotation(scOwner.Pawn.Rotation);
	anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
	anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = npcpnNew;
	npcpnLastDroppedPathNode = npcpnNew;
	npcpnNodeLastEdited = npcpnNodeBeingEdited;
	npcpnNodeBeingEdited = npcpnLastDroppedPathNode;
	vLastTestedAutoDropLocation = npcpnLastDroppedPathNode.Location;
	if ((iWaypointIndex > 0) && bSetWaypointTag)
	{
		Log("Setting waypoint tag for " + FString::FromInt(npcpnNew) + ": " + sWaypointNavTag + "-" + FString::FromInt(iWaypointIndex));
		SetCurrentWaypointNodeTag(sWaypointNavTag + "-" + FString::FromInt(iWaypointIndex));
		iWaypointIndex++;
	}
	npcpsBeingEdited = nullptr;
	npcpsBeingDeleted = nullptr;
	if (npcpnNew->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		NPCFirePositionPathNode(npcpnNew).bCrouchHere = scOwner.Pawn.bIsCrouched;
		NPCFirePositionPathNode(npcpnNew).bProneHere = scOwner.Pawn.bIsProne;
	}
	else
	{
		if (npcpnNew->IsA(ANPCCoverPositionPathNode::StaticClass()))
	}
	{
	}
	Log("Created custom node " + FString::FromInt(npcpnNew) + " with tag: " + FString::FromInt(npcpnNew.Tag));
	if (bSetWaypointTag)
	{
		ClientMessage("Waypoint \"" + sType + "\" node added (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	}
	else
	{
		ClientMessage("Node added (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	}
	*/
	return true;
}

void ANPCPathNodeBuilder::ManNodePosition()
{
	if (npcpnNodeBeingEdited != nullptr)
	{
		/*
		scOwner.Pawn.SetLocation(npcpnNodeBeingEdited.Location);
		scOwner.Pawn.SetRotation(npcpnNodeBeingEdited.Rotation);
		scOwner.SetRotation(npcpnNodeBeingEdited.Rotation);
		if (npcpnNodeBeingEdited->IsA(ANPCFirePositionPathNode::StaticClass()))
		{
			if (Cast<ANPCFirePositionPathNode>(npcpnNodeBeingEdited).bCrouchHere)
			{
				scOwner.Pawn.ShouldCrouch(true);
			}
			else
			{
				if (Cast<ANPCFirePositionPathNode>(npcpnNodeBeingEdited).bProneHere)
				{
					scOwner.Pawn.ShouldProne(true);
				}
			}
		}
		*/
	}
}

void ANPCPathNodeBuilder::SetFireWeaponPosture()
{
	/*
	if (scOwner.Player.bShowWindowsMouse)
	{
		return;
	}
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuActivationButton) < 0.5)
	{
		return;
	}
	if ((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		if (scOwner.bLeanRight == 1)
		{
			NPCFirePositionPathNode(npcpnNodeBeingEdited).bShouldLeanRightToShoot = (!NPCFirePositionPathNode(npcpnNodeBeingEdited).bShouldLeanRightToShoot);
			return;
		}
		if (scOwner.bLeanLeft == 1)
		{
			NPCFirePositionPathNode(npcpnNodeBeingEdited).bShouldLeanLeftToShoot = (!NPCFirePositionPathNode(npcpnNodeBeingEdited).bShouldLeanLeftToShoot);
			return;
		}
		if (scOwner.Pawn.bIsCrouched)
		{
			NPCFirePositionPathNode(npcpnNodeBeingEdited).bShootWhileCrouched = (!NPCFirePositionPathNode(npcpnNodeBeingEdited).bShootWhileCrouched);
			return;
		}
		if (scOwner.Pawn.bIsProne)
		{
			NPCFirePositionPathNode(npcpnNodeBeingEdited).bShootWhileProne = (!NPCFirePositionPathNode(npcpnNodeBeingEdited).bShootWhileProne);
			return;
		}
		scOwner.NotifyAdminMessage("Firing options set");
	}
	else
	{
		scOwner.NotifyAdminMessage("Not a firing position or node derived from firing position node");
	}
	*/
}

void ANPCPathNodeBuilder::SetValidGrenadePosture()
{
	/*
	if ((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		NPCFirePositionPathNode(npcpnNodeBeingEdited).bCanUseGrenades = true;
	}
	*/
}

void ANPCPathNodeBuilder::DropNode(bool bIsAutoDrop)
{
	ANPCPathNode* npcpnNew = nullptr;
	/*
	if (scOwner == nullptr)
	{
		return;
	}
	if (scOwner.Player.bShowWindowsMouse || ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuIconClicked) < 0.5))
	{
		return;
	}
	if (!CanDropNode((bInAutoDropMode && bIsAutoDrop)))
	{
		ClientMessage("Can't drop node here (something would block it)");
		return;
	}
	if (bInAutoDropMode && bIsAutoDrop)
	{
		if ((scOwner.Pawn.Base != nullptr) && scOwner.Pawn.Base->IsA(AStaticMeshActor::StaticClass()))
		{
			scOwner.NotifyAdminMessage("Cannot auto-drop nodes on static meshes");
			ClientMessage("Cannot auto-drop on static meshes.  You must manually place the node.");
			return;
		}
	}
	EnableTransientNaming(true);
	if (scOwner.bNPCPBForceDrop == 1)
	{
		npcpnNew = Spawn(ANPCPathNode::StaticClass(), , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, true, true);
	}
	else
	{
		npcpnNew = Spawn(ANPCPathNode::StaticClass(), , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, false, true);
	}
	EnableTransientNaming(false);
	Log("Created node " + FString::FromInt(npcpnNew.Name));
	if (npcpnNew == nullptr)
	{
		scOwner.NotifyAdminMessage("Failure creating pathnode (probably collision)");
		ClientMessage("Failed to create pathnode");
		return;
	}
	if ((bIsAutoDrop && (npcpnNew.Base != nullptr)) && npcpnNew.Base->IsA(AStaticMeshActor::StaticClass()))
	{
		scOwner.NotifyAdminMessage("Pathnode would be created on an invalid base.");
		ClientMessage("Pathnode would be created on an invalid base.  You must manually drop the node.");
		npcpnNew.bHidden = true;
		npcpnNew.Destroy(true);
		return;
	}
	if (npcpnNew.Location.Z != scOwner.Pawn.Location.Z)
	{
		scOwner.NotifyAdminMessage("Node would be created at an invalid height.  Adjust location.");
		ClientMessage("Pathnode would be created at an invalid height.");
		npcpnNew.bHidden = true;
		npcpnNew.Destroy(true);
		return;
	}
	if (npcpnLastDroppedPathNode != nullptr)
	{
		npcpnLastDroppedPathNode.DebugNavMarker(false, false);
	}
	Log("Dropping node with pawn having base: " + FString::FromInt(scOwner.Pawn.Base));
	npcpnNew.bHidden = false;
	npcpnNew.DebugNavMarker(true, false);
	npcpnNew.bBlockZeroExtentTraces = true;
	npcpnNew.bBlockNonZeroExtentTraces = true;
	anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
	anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = npcpnNew;
	npcpnLastDroppedPathNode = npcpnNew;
	npcpnNodeLastEdited = npcpnNodeBeingEdited;
	npcpnNodeBeingEdited = npcpnLastDroppedPathNode;
	npcpnNodeBeingDeleted = nullptr;
	vLastTestedAutoDropLocation = npcpnLastDroppedPathNode.Location;
	npcpsBeingEdited = nullptr;
	npcpsBeingDeleted = nullptr;
	ClientMessage("Node added (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	*/
}

void ANPCPathNodeBuilder::DropRoadNode(bool bIsAutoDrop)
{
	ARoadPathNode* npcpnNew = nullptr;
	/*
	if (scOwner.Player.bShowWindowsMouse || ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuIconClicked) < 0.5))
	{
		return;
	}
	if (!CanDropNode((bInAutoDropMode && bIsAutoDrop)))
	{
		ClientMessage("Can't drop node here (something would block it)");
		return;
	}
	if (bInAutoDropMode && bIsAutoDrop)
	{
		if ((scOwner.Pawn.Base != nullptr) && scOwner.Pawn.Base->IsA(AStaticMeshActor::StaticClass()))
		{
			scOwner.NotifyAdminMessage("Cannot auto-drop nodes on static meshes");
			ClientMessage("Cannot auto-drop on static meshes.  You must manually place the node.");
			return;
		}
	}
	EnableTransientNaming(true);
	npcpnNew = Spawn(ARoadPathNode::StaticClass(), , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, false, true);
	if (npcpnNew == nullptr)
	{
		scOwner.NotifyAdminMessage("Failure creating pathnode (probably collision)");
		ClientMessage("Failed to create pathnode");
		return;
	}
	EnableTransientNaming(false);
	Log("Created road node " + FString::FromInt(npcpnNew.Name));
	if ((bIsAutoDrop && (npcpnNew.Base != nullptr)) && npcpnNew.Base->IsA(AStaticMeshActor::StaticClass()))
	{
		scOwner.NotifyAdminMessage("Pathnode would be created on an invalid base.");
		ClientMessage("Pathnode would be created on an invalid base.  You must manually drop the node.");
		npcpnNew.bHidden = true;
		npcpnNew.Destroy(true);
		return;
	}
	if (npcpnNew.Location.Z != scOwner.Pawn.Location.Z)
	{
		scOwner.NotifyAdminMessage("Node would be created at an invalid height.  Adjust location.");
		ClientMessage("Pathnode would be created at an invalid height.");
		npcpnNew.bHidden = true;
		npcpnNew.Destroy(true);
		return;
	}
	if (npcpnLastDroppedPathNode != nullptr)
	{
		npcpnLastDroppedPathNode.DebugNavMarker(false, false);
	}
	Log("Dropping node with pawn having base: " + FString::FromInt(scOwner.Pawn.Base));
	npcpnNew.bHidden = false;
	npcpnNew.DebugNavMarker(true, false);
	npcpnNew.bBlockZeroExtentTraces = true;
	npcpnNew.bBlockNonZeroExtentTraces = true;
	anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
	anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = npcpnNew;
	npcpnLastDroppedPathNode = npcpnNew;
	npcpnNodeLastEdited = npcpnNodeBeingEdited;
	npcpnNodeBeingEdited = npcpnLastDroppedPathNode;
	npcpnNodeBeingDeleted = nullptr;
	vLastTestedAutoDropLocation = npcpnLastDroppedPathNode.Location;
	npcpsBeingEdited = nullptr;
	npcpsBeingDeleted = nullptr;
	ClientMessage("Node added (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	*/
}

bool ANPCPathNodeBuilder::CanDropNodeAtLocation(FVector vDesiredLocation)
{
	AActor* actIterator = nullptr;
	/*
	ForEach RadiusActors(Class'Actor', actIterator, (scOwner.Pawn.CollisionRadius + float(10)), vDesiredLocation)
	{
		if ((!actIterator.bCollideActors) && (!actIterator->IsA(ANPCPathNode::StaticClass())))
		{
			continue;
		}
		if (actIterator->IsA(ANPCPathNode::StaticClass()))
		{
			return false;
		}
		if (((actIterator != scOwner.Pawn) && (actIterator.Owner != scOwner.Pawn)) && (actIterator.Location.Z > scOwner.Pawn.Location.Z))
		{
			Log("Found object too close to this node: " + FString::FromInt(actIterator) + " Distance: " + FString::FromInt(VSize((scOwner.Pawn.Location - actIterator.Location))));
			return false;
		}
	}
	*/
	return true;
}

void ANPCPathNodeBuilder::AutoDropNodeLastGoodLocation()
{
	ANPCPathNode* npcpnNew = nullptr;
	if (!CanDropNodeAtLocation(vLastTestedAutoDropLocation))
	{
		return;
	}
	EnableTransientNaming(true);
	/*
	npcpnNew = Spawn(ANPCPathNode::StaticClass(), , , vLastTestedAutoDropLocation, vLastTestedAutoDropRotation, false, true);
	EnableTransientNaming(false);
	if (npcpnNew == nullptr)
	{
		ClientMessage("Failed to create pathnode");
		return;
	}
	if (npcpnNew.Location.Z != vLastTestedAutoDropLocation.Z)
	{
		scOwner.NotifyAdminMessage("Auto-dropped node would be created at an invalid height.  Manually adjust node.");
		ClientMessage("Warning: auto-dropped node had an invalid height.  You must manually add this node.");
		npcpnNew.bHidden = true;
		npcpnNew.Destroy(true);
		return;
	}
	if (npcpnLastDroppedPathNode != nullptr)
	{
		npcpnLastDroppedPathNode.DebugNavMarker(false, false);
	}
	npcpnNew.bHidden = false;
	npcpnNew.DebugNavMarker(true, false);
	npcpnNew.bBlockZeroExtentTraces = true;
	npcpnNew.bBlockNonZeroExtentTraces = true;
	anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
	anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = npcpnNew;
	npcpnLastDroppedPathNode = npcpnNew;
	npcpnNodeLastEdited = npcpnNodeBeingEdited;
	npcpnNodeBeingEdited = npcpnLastDroppedPathNode;
	ClientMessage("Node automatically added due to obstruction (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	*/
}

void ANPCPathNodeBuilder::StartNewPatrolPathSetupPage()
{
	if (sWaypointNavTag.Len() > 0)
	{
		EndPatrolPath();
		return;
	}
	if (Cast<AAGP_HUD>(scOwner->MyHUD) != nullptr)
	{
		Cast<AAGP_HUD>(scOwner->MyHUD)->CloseAllMenus();
	}
	scOwner->ClientOpenMenu("AGP_Interface.AANPCPNB_StartPatrolPath",false,"","");
}

void ANPCPathNodeBuilder::StartNewPatrolPath(FString sWaypointTag)
{
	int32 iFoundIndex = 0;
	int32 iNode = 0;
	FString sTempIndex = "";
	bool fBadIndex = false;
	sWaypointNavTag = sWaypointTag;
	for (iFoundIndex = 1; iFoundIndex < 99; iFoundIndex++)
	{
		sTempIndex = sWaypointNavTag + "-" + FString::FromInt(iFoundIndex);
		fBadIndex = true;
		iNode = 0;
		if (iNode < anpcpnPathNodes.Num())
		{
			/*
			if (!anpcpnPathNodes[iNode]->IsA(ANPCWaypointPathNode::StaticClass()))
			{
			}
			if (string(anpcpnPathNodes[iNode].Tag) ~= sTempIndex)
			{
				fBadIndex = false;
			}
			else
			{
				iNode++;
			}
			*/
		}
		if (fBadIndex)
		{
		}
	}
	if (iFoundIndex > 1)
	{
		iWaypointIndex = iFoundIndex;
		ClientMessage("Continuing patrol path at tag \"" + sWaypointTag + "\"-" + FString::FromInt(iWaypointIndex));
	}
	else
	{
		iWaypointIndex = 1;
		ClientMessage("Starting new patrol path at tag \"" + sWaypointTag + "-" + FString::FromInt(iWaypointIndex) + "\"");
	}
}

void ANPCPathNodeBuilder::EndPatrolPath()
{
	sWaypointNavTag = "";
	iWaypointIndex = 0;
}

void ANPCPathNodeBuilder::DropWaypointNode()
{
	ANPCPathNode* npcpnNew = nullptr;
	/*
	if (scOwner == nullptr)
	{
		return;
	}
	if (!CanDropNode())
	{
		ClientMessage("Can't drop node here (something would block it");
		return;
	}
	if (iWaypointIndex == 0)
	{
		ClientMessage("You must define the waypoint nav tag before trying to drop a patrol pathnode");
		return;
	}
	npcpsBeingDeleted = nullptr;
	npcpsBeingEdited = nullptr;
	EnableTransientNaming(true);
	npcpnNew = Spawn(ANPCWaypointPathNode::StaticClass(), , , scOwner.Pawn->GetActorLocation(), scOwner.Pawn.Rotation, false, true);
	EnableTransientNaming(false);
	if (npcpnLastDroppedPathNode != nullptr)
	{
		npcpnLastDroppedPathNode.DebugNavMarker(false, false);
	}
	npcpnNew.bHidden = false;
	npcpnNew.DebugNavMarker(true, false);
	npcpnNew.bBlockZeroExtentTraces = true;
	npcpnNew.bBlockNonZeroExtentTraces = true;
	anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
	anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = npcpnNew;
	npcpnLastDroppedPathNode = npcpnNew;
	npcpnNodeLastEdited = npcpnNodeBeingEdited;
	npcpnNodeBeingEdited = npcpnLastDroppedPathNode;
	vLastTestedAutoDropLocation = npcpnLastDroppedPathNode.Location;
	SetCurrentWaypointNodeTag(sWaypointNavTag + "-" + FString::FromInt(iWaypointIndex));
	ClientMessage("Waypoint Node \"" + FString::FromInt(npcpnNew.Tag) + "\" added (you now have " + FString::FromInt(anpcpnPathNodes.Num()) + " nodes defined)");
	iWaypointIndex++;
	*/
}

void ANPCPathNodeBuilder::ClientMessage(FString sMsg)
{
	//scOwner.ClientMessage(sMsg);
}

void ANPCPathNodeBuilder::StartAutoDropMode()
{
	bInAutoDropMode = true;
	if (npcpnLastDroppedPathNode != nullptr)
	{
		vLastTestedAutoDropLocation = npcpnLastDroppedPathNode->GetActorLocation();
	}
	ClientMessage("Auto-drop mode enabled");
}

void ANPCPathNodeBuilder::EndAutoDropMode()
{
	bInAutoDropMode = false;
	ClientMessage("Auto-drop mode ended");
}

void ANPCPathNodeBuilder::EnteringLadderVolume()
{
	if (bInAutoDropMode)
	{
		bOnLadder = true;
		DropCustomNode("Ladder");
	}
}

void ANPCPathNodeBuilder::ExitingLadderVolume()
{
	bool bTopOfLadder = false;
	if (bInAutoDropMode)
	{
		/*
		if (((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCLadderPathNode::StaticClass())) && (npcpnNodeBeingEdited.Location.Z < scOwner.Pawn.Location.Z))
		{
			bTopOfLadder = true;
		}
		else
		{
			if (((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCLadderPathNode::StaticClass())) && (Cast<ANPCLadderPathNode>(npcpnNodeBeingEdited).Location.Z > scOwner.Pawn.Location.Z))
			{
				NPCLadderPathNode(npcpnNodeBeingEdited).bNearLadderTop = true;
			}
		}
		bOnLadder = false;
		DropCustomNode("Ladder");
		if (bTopOfLadder)
		{
			NPCLadderPathNode(npcpnNodeBeingEdited).bNearLadderTop = true;
		}
		*/
	}
}

void ANPCPathNodeBuilder::MoverUsed()
{
	DropCustomNode("Door");
}

void ANPCPathNodeBuilder::Action()
{
	ANavigationPoint* npIterator = nullptr;
	ANavigationPoint* npClosestToCenter = nullptr;
	/*
	ForEach RadiusActors(ANavigationPoint::StaticClass(), npIterator, 150, scOwner.Pawn.Location)
	{
		if ((!npIterator->IsA(ANPCPlayerStart::StaticClass())) && (!npIterator->IsA(ANPCPathNode::StaticClass())))
		{
			continue;
		}
		if (IsLocationInFrontOfOwner(npIterator.Location))
		{
			if (npClosestToCenter == nullptr)
			{
				npClosestToCenter = npIterator;
			}
			else
			{
				Log("Angle " + FString::FromInt(npIterator) + " is " + FString::FromInt(GetAngleFromOwner(npIterator.Location)));
				Log("Best Angle " + FString::FromInt(npClosestToCenter) + " is " + FString::FromInt(GetAngleFromOwner(npClosestToCenter.Location)));
				if (GetAngleFromOwner(npIterator.Location) > GetAngleFromOwner(npClosestToCenter.Location))
				{
					npClosestToCenter = npIterator;
				}
			}
		}
	}
	if ((npcpsBeingEdited != nullptr) && (npcpsBeingEdited == npClosestToCenter))
	{
		if (Cast<AAGP_HUD>(scOwner.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(scOwner.myHUD).CloseAllMenus();
		}
		scOwner.ClientOpenMenu("AGP_Interface.AANPCPNB_PlayerStartOptions");
		return;
	}
	if ((npcpnNodeBeingEdited != nullptr) && (npcpnNodeBeingEdited == npClosestToCenter))
	{
		ClientMessage("Node already selectd");
		if (Cast<AAGP_HUD>(scOwner.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(scOwner.myHUD).CloseAllMenus();
		}
		return;
	}
	if (npClosestToCenter != nullptr)
	{
		if (npcpnNodeBeingEdited != nullptr)
		{
			npcpnNodeBeingEdited.DebugNavMarker(false, false);
		}
		if (npcpsBeingEdited != nullptr)
		{
			npcpsBeingEdited.DebugNavMarker(false, false);
		}
		npcpnNodeLastEdited = npcpnNodeBeingEdited;
		npcpnNodeBeingDeleted = nullptr;
		npcpsBeingDeleted = nullptr;
		npcpsBeingEdited = nullptr;
		npcpnNodeBeingEdited = nullptr;
		if (npClosestToCenter->IsA(ANPCPathNode::StaticClass()))
		{
			npcpnNodeBeingEdited = NPCPathNode(npClosestToCenter);
			npcpnNodeBeingEdited.DebugNavMarker(true, false);
			ClientMessage("Now editing node \"" + FString::FromInt(npcpnNodeBeingEdited) + "\" tag: " + FString::FromInt(npcpnNodeBeingEdited.Tag));
		}
		else
		{
			npcpsBeingEdited = NPCPlayerStart(npClosestToCenter);
			if (npcpsBeingEdited != nullptr)
			{
				npcpsBeingEdited.DebugNavMarker(true, false);
			}
			ClientMessage("Now editing NPC Player Start \"" + FString::FromInt(npcpsBeingEdited) + "\" tag: " + FString::FromInt(npcpsBeingEdited.Tag));
		}
	}
	*/
}

void ANPCPathNodeBuilder::ForceConnection()
{
	bool bAlreadyForced = false;
	int32 iForcedNodes = 0;
	if ((npcpnNodeLastEdited != nullptr) && (npcpnNodeBeingEdited != nullptr))
	{
		/*
		for (iForcedNodes = 0; iForcedNodes < npcpnNodeBeingEdited.ForcedPaths.Num(); iForcedNodes++)
		{
			if (npcpnNodeBeingEdited.ForcedPaths[iForcedNodes] == npcpnNodeLastEdited.Name)
			{
				bAlreadyForced = true;
			}
		}
		if (!bAlreadyForced)
		{
			npcpnNodeBeingEdited.ForcedPaths.insert(0, 1);
			npcpnNodeBeingEdited.ForcedPaths[0] = npcpnNodeLastEdited.Name;
			ClientMessage("Forcing connection from " + FString::FromInt(npcpnNodeBeingEdited) + " to " + FString::FromInt(npcpnNodeLastEdited) + " ( " + FString::FromInt(npcpnNodeBeingEdited.ForcedPaths.Num()) + " forced now)");
		}
		else
		{
			ClientMessage("Forced connection already exists from " + FString::FromInt(npcpnNodeBeingEdited) + " to " + FString::FromInt(npcpnNodeLastEdited));
		}
		bAlreadyForced = false;
		for (iForcedNodes = 0; iForcedNodes < npcpnNodeLastEdited.ForcedPaths.Num(); iForcedNodes++)
		{
			if (npcpnNodeLastEdited.ForcedPaths[iForcedNodes] == npcpnNodeBeingEdited.Name)
			{
				bAlreadyForced = true;
			}
		}
		if (!bAlreadyForced)
		{
			npcpnNodeLastEdited.ForcedPaths.insert(0, 1);
			npcpnNodeLastEdited.ForcedPaths[0] = npcpnNodeBeingEdited.Name;
			ClientMessage("Forcing connection from " + FString::FromInt(npcpnNodeLastEdited) + " to " + FString::FromInt(npcpnNodeBeingEdited) + " ( " + FString::FromInt(npcpnNodeLastEdited.ForcedPaths.Num()) + " forced now)");
		}
		else
		{
			ClientMessage("Forced connection already exists from " + FString::FromInt(npcpnNodeLastEdited) + " to " + FString::FromInt(npcpnNodeBeingEdited));
		}
		*/
	}
	else
	{
		ClientMessage("You must select two nodes in sequence to force connect them");
	}
}

void ANPCPathNodeBuilder::RequestDeleteNode()
{
	int32 iNode = 0;
	if ((npcpnNodeBeingEdited == nullptr) && (npcpsBeingEdited == nullptr))
	{
		return;
	}
	/*
	if ((npcpnNodeBeingDeleted == nullptr) && (npcpsBeingDeleted == nullptr))
	{
		if (((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCWaypointPathNode::StaticClass())) && (iWaypointIndex < 1))
		{
			if (InStr(string(npcpnNodeBeingEdited.Tag), "-") != -1)
			{
				scOwner.NotifyAdminMessage("To delete waypoints you must enter Patrol Editing mode with \"StartPatrolPath\" for tag " + FString::FromInt(npcpnNodeBeingEdited.Tag));
				return;
			}
		}
		fpTimeSinceDeleteRequest = GetWorld()->GetTimeSeconds();
		npcpnNodeBeingDeleted = npcpnNodeBeingEdited;
		npcpsBeingDeleted = npcpsBeingEdited;
		if (npcpsBeingDeleted != nullptr)
		{
			scOwner.NotifyAdminMessage("Repeat command to delete this player start: " + FString::FromInt(npcpsBeingEdited));
		}
		else
		{
			scOwner.NotifyAdminMessage("Repeat command to delete this node: " + FString::FromInt(npcpnNodeBeingEdited));
		}
		return;
	}
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceDeleteRequest) < 5)
	{
		if (npcpsBeingDeleted != nullptr)
		{
			iNode = 0;
			if (iNode < anpcpsPlayerStarts.Num())
			{
				if (anpcpsPlayerStarts[iNode] == npcpsBeingDeleted)
				{
					anpcpsPlayerStarts.RemoveAt(iNode, 1);
				}
				else
				{
					iNode++;
				}
			}
			npcpsBeingDeleted.DebugNavMarker(false, false);
			npcpsBeingDeleted.bHidden = true;
			npcpsBeingDeleted.Destroy(true);
			scOwner.NotifyAdminMessage("NPC Player Start removed");
		}
		else
		{
			iNode = 0;
			if (iNode < anpcpnPathNodes.Num())
			{
				if (anpcpnPathNodes[iNode] == npcpnNodeBeingDeleted)
				{
					anpcpnPathNodes.RemoveAt(iNode, 1);
				}
				else
				{
					iNode++;
				}
			}
			npcpnNodeBeingDeleted.DebugNavMarker(false, false);
			npcpnNodeBeingDeleted.bHidden = true;
			npcpnNodeBeingDeleted.Destroy(true);
			scOwner.NotifyAdminMessage("Node removed");
		}
	}
	*/
	fpTimeSinceDeleteRequest = 0;
	npcpnNodeBeingEdited = nullptr;
	npcpnNodeBeingDeleted = nullptr;
	npcpsBeingDeleted = nullptr;
	npcpsBeingEdited = nullptr;
}

void ANPCPathNodeBuilder::EditRotationAndPosture()
{
	/*
	if ((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCFirePositionPathNode::StaticClass()))
	{
		NPCFirePositionPathNode(npcpnNodeBeingEdited).bCrouchHere = scOwner.Pawn.bIsCrouched;
		NPCFirePositionPathNode(npcpnNodeBeingEdited).bProneHere = scOwner.Pawn.bIsProne;
		npcpnNodeBeingEdited.SetRotation(scOwner.Pawn.Rotation);
		scOwner.NotifyAdminMessage("Rotation and Posture set for node");
	}
	*/
}

void ANPCPathNodeBuilder::SetCurrentNodeTag(FString sNewTag)
{
	/*
	if ((npcpnNodeBeingEdited != nullptr) && npcpnNodeBeingEdited->IsA(ANPCWaypointPathNode::StaticClass()))
	{
		SetCurrentWaypointNodeTag(sNewTag);
		scOwner.NotifyAdminMessage("Node " + FString::FromInt(npcpnNodeBeingEdited) + " tag set to " + FString::FromInt(npcpnNodeBeingEdited.Tag) + " from " + sNewTag);
	}
	else
	{
		if (npcpsBeingEdited != nullptr)
		{
			npcpsBeingEdited.sNPCWaypointTag = sNewTag;
			scOwner.NotifyAdminMessage("NPCPlayerStart waypoint tag set to " + npcpsBeingEdited.sNPCWaypointTag);
		}
	}
	*/
}

void ANPCPathNodeBuilder::SetNPCName(FString sNewName)
{
	if (npcpsBeingEdited != nullptr)
	{
		/*
		npcpsBeingEdited->HUDText = sNewName;
		scOwner->NotifyAdminMessage("NPC Name set to " + npcpsBeingEdited->HUDText);
		*/
	}
}

bool ANPCPathNodeBuilder::IsLocationInFrontOfOwner(FVector vLocation)
{
	FVector vLookDir = FVector(0, 0, 0);
	FVector vAimDir = FVector(0, 0, 0);
	/*
	vLookDir = Vector(scOwner.Pawn.Rotation);
	vAimDir = Normal((vLocation - scOwner.Pawn.Location));
	if ((vLookDir Dot vAimDir) < 0)
	{
		return false;
	}
	*/
	return true;
}

float ANPCPathNodeBuilder::GetAngleFromOwner(FVector vLocation)
{
	FVector vLookDir = FVector(0, 0, 0);
	FVector vAimDir = FVector(0, 0, 0);
	/*
	vLookDir = Vector(scOwner.Pawn.Rotation);
	vAimDir = Normal((vLocation - scOwner.Pawn.Location));
	return (vLookDir Dot vAimDir);
	*/
	return 0;    //FAKE   /EliZ
}

void ANPCPathNodeBuilder::ProcessMenuIconClick()
{
	/*
	if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuActivationButton) < 0.5)
	{
		return;
	}
	switch (Cast<ANPCPathBuilderHUD>(scOwner.myHUD).DetermineIconIndexClicked(GetMouseX(), GetMouseY()))
	{
	case NPCPathBuilderHUD(scOwner.myHUD).0:
		DropCustomNode("Cover");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).1:
		DropWaypointNode();
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).2:
		DropCustomNode("Alamo");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).3:
		DropCustomNode("Firing");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).5:
		DropCustomNode("Camper");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).4:
		DropCustomNode("Rest");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		break;
	case NPCPathBuilderHUD(scOwner.myHUD).6:
		if (bInAutoDropMode)
		{
			EndAutoDropMode();
		}
		else
		{
			StartAutoDropMode();
		}
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).7:
		DropNPCPlayerStart("Grunt");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).8:
		DropNPCPlayerStart("NCO");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).9:
		DropNPCPlayerStart("Officer");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).10:
		DropNPCPlayerStart("Commando");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).11:
		DropNPCPlayerStart("Spotter");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).12:
		DropNPCPlayerStart("Civilian");
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).13:
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		if (Cast<AAGP_HUD>(scOwner.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(scOwner.myHUD).CloseAllMenus();
		}
		scOwner.ClientOpenMenu("AGP_Interface.AANPCPNB_OpenPNBFile");
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).14:
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		if (Cast<AAGP_HUD>(scOwner.myHUD) != nullptr)
		{
			Cast<AAGP_HUD>(scOwner.myHUD).CloseAllMenus();
		}
		scOwner.ClientOpenMenu("AGP_Interface.AANPCPNB_SavePNBFile");
		GOTO JL067B;
	case NPCPathBuilderHUD(scOwner.myHUD).15:
		scOwner.Player.bShowWindowsMouse = false;
		scOwner.LockPlayer(false, false);
		StartNewPatrolPathSetupPage();
		GOTO JL067B;
	default:
	JL067B:
	}
	fpTimeSinceLastMenuIconClicked = GetWorld()->GetTimeSeconds();
	*/
}

void ANPCPathNodeBuilder::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	float fpDistanceToLastNode = 0;
	Super::Tick(DeltaTime);
	if (scOwner == nullptr)
	{
		return;
	}
	/*
	if (((fpTimeSinceDeleteRequest > 0) && (npcpnNodeBeingDeleted != nullptr)) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceDeleteRequest) > 5))
	{
		fpTimeSinceDeleteRequest = 0;
		npcpnNodeBeingDeleted = nullptr;
	}
	if ((fpTimeSinceResetPathsRequest > 0) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceResetPathsRequest) > 5))
	{
		fpTimeSinceResetPathsRequest = 0;
	}
	if (((scOwner.bFire == 1) && scOwner.Player.bShowWindowsMouse) && ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuIconClicked) > 0.5))
	{
		ProcessMenuIconClick();
	}
	if (scOwner.bNPCPBMenuToggle == 1)
	{
		if ((GetWorld()->GetTimeSeconds() - fpTimeSinceLastMenuActivationButton) > 0.5)
		{
			scOwner.Player.bShowWindowsMouse = (!scOwner.Player.bShowWindowsMouse);
			if (scOwner.Player.bShowWindowsMouse)
			{
				scOwner.LockPlayer(true, true);
			}
			else
			{
				scOwner.LockPlayer(false, false);
			}
			fpTimeSinceLastMenuActivationButton = GetWorld()->GetTimeSeconds();
		}
	}
	if (!bInAutoDropMode)
	{
		if (scOwner.bFire == 1)
		{
			if (CanDropNode())
			{
				scOwner.bFire = 0;
				DropNode();
			}
		}
		return;
	}
	if (npcpnLastDroppedPathNode == nullptr)
	{
		return;
	}
	if (scOwner.bAltFire == 1)
	{
		return;
	}
	fpDistanceToLastNode = VSize((npcpnLastDroppedPathNode.Location - scOwner.Pawn.Location));
	if (fpDistanceToLastNode < (scOwner.Pawn.CollisionRadius + float(10)))
	{
		return;
	}
	if (VSize((vLastLocationTestedForAutoDrop - scOwner.Pawn.Location)) < npcpnLastDroppedPathNode.CollisionRadius)
	{
		return;
	}
	if (CanSeeFullPathToLastNode())
	{
		if (CanDropNode())
		{
			vLastTestedAutoDropLocation = scOwner.Pawn.Location;
			vLastTestedAutoDropRotation = scOwner.Pawn.Rotation;
			if (fpDistanceToLastNode > float(200))
			{
				DropNode(true);
			}
		}
		vLastLocationTestedForAutoDrop = scOwner.Pawn.Location;
		return;
	}
	else
	{
		vLastLocationTestedForAutoDrop = scOwner.Pawn.Location;
		AutoDropNodeLastGoodLocation();
		if (CanDropNode())
		{
			vLastTestedAutoDropLocation = scOwner.Pawn.Location;
			vLastTestedAutoDropRotation = scOwner.Pawn.Rotation;
			DropNode(true);
		}
	}
	*/
}

bool ANPCPathNodeBuilder::CanSeeFullPathToLastNode()
{
	AActor* actHitActor = nullptr;
	FVector vHitLocation = FVector(0, 0, 0);
	FVector vHitNormal = FVector(0, 0, 0);
	FVector vTestLocation = FVector(0, 0, 0);
	FVector vStartLocation = FVector(0, 0, 0);
	FVector vOffsetRight = FVector(0, 0, 0);
	FVector vOffsetLeft = FVector(0, 0, 0);
	FVector VLength = FVector(0, 0, 0);
	bool bOldBlockZeroExtent = false;
	FRotator rotToLastNodeRight = FRotator(0, 0, 0);
	FRotator rotToLastNodeLeft = FRotator(0, 0, 0);
	int32 iOffset = 0;
	bool bCanSeeFullPath = false;
	FVector vCollisionHeightOffset = FVector(0, 0, 0);
	/*
	vCollisionHeightOffset = FVector(0, 0, 20);
	bOldBlockZeroExtent = scOwner.Pawn.bBlockZeroExtentTraces;
	scOwner.Pawn.bBlockZeroExtentTraces = false;
	VLength = (scOwner.Pawn.Location - npcpnLastDroppedPathNode.Location);
	bCanSeeFullPath = true;
	iOffset = 0;
	if (float(iOffset) < (scOwner.Pawn.CollisionRadius + float(10)))
	{
		rotToLastNodeRight = rotator((scOwner.Pawn.Location - npcpnLastDroppedPathNode.Location));
		(rotToLastNodeRight.Yaw += 16384);
		rotToLastNodeLeft = rotator((scOwner.Pawn.Location - npcpnLastDroppedPathNode.Location));
		(rotToLastNodeLeft.Yaw -= 16384);
		vOffsetRight = (Vector(Normalize(rotToLastNodeRight)) * float(iOffset));
		vOffsetLeft = (Vector(Normalize(rotToLastNodeLeft)) * float(iOffset));
		vTestLocation = (npcpnLastDroppedPathNode.Location + vOffsetRight);
		vStartLocation = (scOwner.Pawn.Location + vOffsetRight);
		(vTestLocation -= vCollisionHeightOffset);
		(vStartLocation -= vCollisionHeightOffset);
		actHitActor = scOwner.Pawn.Trace(vHitLocation, vHitNormal, vTestLocation, vStartLocation, true);
		if (((actHitActor != nullptr) && (actHitActor != npcpnLastDroppedPathNode)) || (VSizeSquared((vStartLocation - vHitLocation)) < VSizeSquared((vStartLocation - vTestLocation))))
		{
			scOwner.Pawn.bBlockZeroExtentTraces = bOldBlockZeroExtent;
			Log("Right Hitlocation: " + FString::FromInt(vTestLocation) + " Test Location: " + FString::FromInt(vTestLocation) + " distance: " + FString::FromInt(VSize((vHitLocation - vTestLocation))));
			NPCPathBuilderHUD(scOwner.myHUD).aiLineTestRightValid[(iOffset / 2)] = 0;
			bCanSeeFullPath = false;
		}
		else
		{
			NPCPathBuilderHUD(scOwner.myHUD).aiLineTestRightValid[(iOffset / 2)] = 1;
		}
		vTestLocation = (npcpnLastDroppedPathNode.Location + vOffsetLeft);
		vStartLocation = (scOwner.Pawn.Location + vOffsetLeft);
		(vTestLocation -= vCollisionHeightOffset);
		(vStartLocation -= vCollisionHeightOffset);
		actHitActor = scOwner.Pawn.Trace(vHitLocation, vHitNormal, vTestLocation, vStartLocation, true);
		if (((actHitActor != nullptr) && (actHitActor != npcpnLastDroppedPathNode)) || (VSizeSquared((vStartLocation - vHitLocation)) < VSizeSquared((vStartLocation - vTestLocation))))
		{
			scOwner.Pawn.bBlockZeroExtentTraces = bOldBlockZeroExtent;
			NPCPathBuilderHUD(scOwner.myHUD).aiLineTestLeftValid[(iOffset / 2)] = 0;
			bCanSeeFullPath = false;
		}
		else
		{
			NPCPathBuilderHUD(scOwner.myHUD).aiLineTestLeftValid[(iOffset / 2)] = 1;
		}
		(iOffset += 2);
	}
	*/
	return bCanSeeFullPath;
}

void ANPCPathNodeBuilder::ImportPaths()
{
	ANavigationPoint* npIterator = nullptr;
	/*
	anpcpnPathNodes.RemoveAt(0, anpcpnPathNodes.Num());
	for (npIterator = Level.NavigationPointList; npIterator != nullptr; npIterator = npIterator.nextNavigationPoint)
	{
		if (npIterator->IsA(ANPCPathNode::StaticClass()))
		{
			anpcpnPathNodes.insert(anpcpnPathNodes.Num(), 1);
			anpcpnPathNodes[(anpcpnPathNodes.Num() - 1)] = NPCPathNode(npIterator);
			npIterator.bHidden = false;
			NPCPathNode(npIterator).DebugNavMarker(true, false);
		}
	}
	ClientMessage("Nodes imported: " + FString::FromInt(anpcpnPathNodes.Num()));
	*/
}
