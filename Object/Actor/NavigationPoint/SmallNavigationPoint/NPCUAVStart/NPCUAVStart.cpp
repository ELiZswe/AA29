// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCUAVStart/NPCUAVStart.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseRavenController/NPCBaseRavenController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"

ANPCUAVStart::ANPCUAVStart()
{
	bDebugInit = true;
	iNPCTeamID = 2;
	bAscendingNodeDirection = true;
	fpChanceOfSpawning = 100;
	bNoAutoConnect = true;
	bForcedOnly = true;
	//bProp = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/S_PSTagVehicle_Mat.S_PSTagVehicle_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
}

void ANPCUAVStart::Reset()
{
	Super::Reset();
	bEnabled = false;
}

void ANPCUAVStart::BeginPlay()
{
}

bool ANPCUAVStart::ShouldUseStartSpot()
{
	if (bMustSpawn)
	{
		return true;
	}
	/*
	if ((FMath::FRand() * 100) <= fpChanceOfSpawning)
	{
		return true;
	}
	*/
	return false;
}

void ANPCUAVStart::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
}

ANPCBaseRavenController* ANPCUAVStart::CreateNPC()
{
	ANPCBaseRavenController* npcbcNew = nullptr;
	int32 iInitialStartingPathNodeIndex = 0;
	/*
	if (!ShouldUseStartSpot())
	{
		return nullptr;
	}
	if (bDebugInit)
	{
		Log("");
		Log("");
		Log("");
		Log("*******************");
		Log("Creating new UAV controller for pawn at start spot: " + FString::FromInt(ControllerClass));
		Log("*******************");
	}
	npcbcNew = Spawn(ControllerClass);
	if (bDebugInit)
	{
		Log("Controller created: " + FString::FromInt(npcbcNew));
	}
	npcbcNew.bDebugPath = bDebugPath;
	if (Len(sNPCWaypointTag) > 0)
	{
		npcbcNew.sNPCWaypointTag = sNPCWaypointTag;
	}
	else
	{
		npcbcNew.sNPCWaypointTag = FString::FromInt(Tag);
	}
	if (bDebugInit)
	{
		Log("Pathnode waypoint tag is now: " + npcbcNew.sNPCWaypointTag);
	}
	npcbcNew.PreloadPathNodeList();
	if (bStartAndSpawnAtRandomNode && bDebugInit)
	{
		Log("Will find random pathnode from " + FString::FromInt(npcbcNew.apnFlyingPathNodesForPatrol.Num()) + " possible nodes");
	}
	iInitialStartingPathNodeIndex = iStartingPathNodeIndex;
	npcbcNew.iStartingPathNodeIndex = iStartingPathNodeIndex;
	npcbcNew.bAscendingNodeDirection = bAscendingNodeDirection;
	npcbcNew.bAutoReversePath = bAutoReversePath;
	npcbcNew.sNPCWaypointTag = sNPCWaypointTag;
	npcbcNew.ConvoyTag = ConvoyTag;
	npcbcNew.bConvoyLeader = ConvoyLeader;
	npcbcNew.bPatrol_NoPathfinding = Patrol_NoPathfinding;
	npcbcNew.bDebugMode = bDebugMode;
	npcbcNew.bDebugPath = bDebugPath;
	npcbcNew.bDebugSenses = bDebugSenses;
	npcbcNew.bTriggerStart = bTriggerStartVehicle;
	if (VehicleTag != "None")
	{
		npcbcNew.VehicleTag = VehicleTag;
	}
	else
	{
		npcbcNew.VehicleTag = Tag;
	}
	if (ControllerTag != "None")
	{
		npcbcNew.Tag = ControllerTag;
	}
	else
	{
		npcbcNew.Tag = Tag;
	}
	if (bDebugInit)
	{
		Log("Telling controller " + FString::FromInt(npcbcNew) + " to possess vehicle");
	}
	npcbcNew.iDamageLevelForEvent = iDamageLevelForEvent;
	npcbcNew.DamageEvent = DamageEvent;
	npcbcNew.ShotdownEvent = ShotdownEvent;
	npcbcNew.UsedEvent = UsedEvent;
	npcbcNew.fpRepairTime = fpRepairTime;
	npcbcNew.fpEngineFailureChance = fpEngineFailureChance;
	npcbcNew.fpRotorFailurePossible = fpRotorFailurePossible;
	npcbcNew.fpCockpitFailurePossible = fpCockpitFailurePossible;
	npcbcNew.VehicleClass = VehicleClass;
	npcbcNew.InitVehicle();
	npcbcNew.Possess(npcbcNew.agpvVehicle);
	Log("UAV Possess complete, pawn now: " + FString::FromInt(npcbcNew.Pawn) + " vs. vehicle: " + FString::FromInt(npcbcNew.agpvVehicle));
	npcbcNew.Start();
	*/
	return npcbcNew;
}

ANPCPlayerStart* ANPCUAVStart::FindNPCPlayerStartByTag(FString sTagToFind)
{
	ANavigationPoint* npIterator = nullptr;
	/*
	for (npIterator = Level.NavigationPointList; npIterator != nullptr; npIterator = npIterator.nextNavigationPoint)
	{
		if (npIterator->IsA(ANPCPlayerStart::StaticClass()) && (string(npIterator.Tag) ~= sTagToFind))
		{
			return NPCPlayerStart(npIterator);
		}
	}
	*/
	return nullptr;
}

void ANPCUAVStart::FindAICC()
{
	ANPCAICombatController* npcaiccIterator = nullptr;
	/*
	if (npcaiccCombatController != nullptr)
	{
		return;
	}
	ForEach AllActors(ANPCAICombatController::StaticClass(), npcaiccIterator)
	{
		if (npcaiccIterator.iTeamID == iNPCTeamID)
		{
			if (!npcaiccIterator.bDisableCombatController)
			{
				if (bDebugInit)
				{
					Log(string(this) + " Located combat controller!");
				}
				npcaiccCombatController = npcaiccIterator;
				return;
			}
		}
	}
	*/
}
