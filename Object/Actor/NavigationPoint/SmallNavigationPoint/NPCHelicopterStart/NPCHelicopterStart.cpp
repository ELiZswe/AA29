// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCHelicopterStart/NPCHelicopterStart.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"

ANPCHelicopterStart::ANPCHelicopterStart()
{
	DrawDriverInTP = true;
	iNPCTeamID = 2;
	bIncludeCoPilot = true;
	bIncludeCrewchief = true;
	bIncludeLoadMaster = true;
	bRequirePZVolume = true;
	fpMaxDistanceSmokeFromPZ = 2500;
	bAscendingNodeDirection = true;
	fpChanceOfSpawning = 100;
	bNoAutoConnect = true;
	bForcedOnly = true;
	//bProp = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/S_PSTagVehicle_Mat.S_PSTagVehicle_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
}

void ANPCHelicopterStart::Reset()
{
	Super::Reset();
	bEnabled = false;
}

void ANPCHelicopterStart::BeginPlay()
{
}

bool ANPCHelicopterStart::ShouldUseStartSpot()
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

void ANPCHelicopterStart::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
}

ANPCBaseHelicopterController* ANPCHelicopterStart::CreateNPC()
{
	ANPCBaseHelicopterController* npcbcNew = nullptr;
	AAGP_Pawn* agpPawnNew = nullptr;
	int32 Iterations = 0;
	int32 iSpawnAttempts = 0;
	int32 iSquadMember = 0;
	int32 iInitialStartingPathNodeIndex = 0;
	TArray<int32> AlreadyCheckedIndex = {};
	bool bFailed = false;
	int32 i = 0;
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
		Log("Creating new helicopter controller for APawn* at start spot: " + FString::FromInt(ControllerClass));
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
	PawnSpawnClass = class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_BHPilot", Class'Class'));
	if (agpPawnNew == nullptr)
	{
		Iterations++;
		if (bStartAndSpawnAtRandomNode)
		{
			if (iSpawnAttempts++ > npcbcNew.apnFlyingPathNodesForPatrol.Num())
			{
				if (bDebugInit)
				{
					Log("unable to spawn at random node location, using player start location as fall-back");
				}
				agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation, true, true);
			}
			else
			{
				iStartingPathNodeIndex = Rand((npcbcNew.apnFlyingPathNodesForPatrol.Num() + 1));
				if (AlreadyCheckedIndex.Num() > 0)
				{
					for (i = 0; i < AlreadyCheckedIndex.Num(); i++)
					{
						if (AlreadyCheckedIndex[i] == iStartingPathNodeIndex)
						{
							iSpawnAttempts--;
							bFailed = true;
						}
					}
				}
				if (bFailed && (Iterations < 500))
				{
					bFailed = false;
				}
				else
				{
				else
				{
					if (Iterations < 500)
					{
						AlreadyCheckedIndex.insert(AlreadyCheckedIndex.Num(), 1);
						AlreadyCheckedIndex[(AlreadyCheckedIndex.Num() - 1)] = iStartingPathNodeIndex;
					}
				}
				if (bDebugInit)
				{
					Log(string(Tag) + " trying random node " + FString::FromInt(iStartingPathNodeIndex));
				}
				if ((iStartingPathNodeIndex == npcbcNew.apnFlyingPathNodesForPatrol.Num()) || (Iterations > 500))
				{
					if (bDebugInit)
					{
						if (Iterations > 500)
						{
							Log("Only valid location was already occupied. Giving up and using actual player start location.");
						}
						else
						{
							Log("Randomly using actual player start location");
						}
					}
					agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation, true, true);
				}
				else
				{
					npcbcNew.apnFlyingPathNodesForPatrol[iStartingPathNodeIndex].taken = true;
					agpPawnNew = Spawn(PawnSpawnClass, , , npcbcNew.apnFlyingPathNodesForPatrol[iStartingPathNodeIndex]->GetActorLocation(), npcbcNew.apnFlyingPathNodesForPatrol[iStartingPathNodeIndex].Rotation, true, true);
					if (agpPawnNew != nullptr)
					{
						if (bDebugInit)
						{
							Log(string(Tag) + " got a good spawn at random location ( " + FString::FromInt(iStartingPathNodeIndex) + ") of node " + FString::FromInt(npcbcNew.apnFlyingPathNodesForPatrol[iStartingPathNodeIndex].Tag));
						}
						npcbcNew.SetLocation(agpPawnNew.Location);
						npcbcNew.SetRotation(agpPawnNew.Rotation);
						iStartingPathNodeIndex++;
						npcbcNew.apnFlyingPathNodesForPatrol[iStartingPathNodeIndex].taken = false;
					}
					else
					{
					}
					agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation, true, true);
				}
				}
			}
		}
	}
	if (bDebugInit)
	{
		Log("driver APawn* spawned: " + FString::FromInt(agpPawnNew));
	}
	agpPawnNew.bHidden = true;
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
	switch (enpcoPrimaryOrders)
	{
	case 1:
		npcbcNew.iNPCPrimaryOrders = npcbcNew.1;
		break;
	case 2:
		npcbcNew.iNPCPrimaryOrders = npcbcNew.2;
		break;
	case 0:
	default:
		npcbcNew.iNPCPrimaryOrders = npcbcNew.0;
		break;
	}
	if (anameSquadPlayerStartsTag.Num() > 0)
	{
		npcbcNew.anpcpsSquadPlayerStarts.insert(0, anameSquadPlayerStartsTag.Num());
		for (iSquadMember = 0; iSquadMember < anameSquadPlayerStartsTag.Num(); iSquadMember++)
		{
			npcbcNew.anpcpsSquadPlayerStarts[iSquadMember] = FindNPCPlayerStartByTag(string(anameSquadPlayerStartsTag[iSquadMember]));
			if (npcbcNew.anpcpsSquadPlayerStarts[iSquadMember] == nullptr)
			{
				Log("*** WARNING *** Vehicle " + FString::FromInt(Tag) + " has an invalid passenger[" + FString::FromInt(iSquadMember) + "] configured: " + FString::FromInt(anameSquadPlayerStartsTag[iSquadMember]));
			}
			else
			{
				DebugLog(DEBUG_AIVehicle, "Found vehicle passenger player start: " + FString::FromInt(npcbcNew.anpcpsSquadPlayerStarts[iSquadMember]));
				DebugLog(DEBUG_AIVehicle, "Vehicle passenger player start has tag: " + FString::FromInt(npcbcNew.anpcpsSquadPlayerStarts[iSquadMember].Tag));
			}
		}
	}
	if (PawnTag != "None")
	{
		agpPawnNew.Tag = PawnTag;
	}
	else
	{
		agpPawnNew.Tag = Tag;
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
		Log("Telling controller " + FString::FromInt(npcbcNew) + " to possess pawn: " + FString::FromInt(agpPawnNew));
	}
	npcbcNew.iDamageLevelForEvent = iDamageLevelForEvent;
	npcbcNew.DamageEvent = DamageEvent;
	npcbcNew.ShotdownEvent = ShotdownEvent;
	npcbcNew.UsedEvent = UsedEvent;
	npcbcNew.PlayersboardedEvent = PlayersboardedEvent;
	npcbcNew.bRequirePZVolume = bRequirePZVolume;
	npcbcNew.fpMaxDistanceSmokeFromPZ = fpMaxDistanceSmokeFromPZ;
	npcbcNew.bIncludeCoPilot = bIncludeCoPilot;
	npcbcNew.bIncludeLoadMaster = bIncludeLoadMaster;
	npcbcNew.bIncludeCrewchief = bIncludeCrewchief;
	npcbcNew.bIncludeRearwardWounded = bIncludeRearwardWounded;
	npcbcNew.bIncludeForwardWounded = bIncludeForwardWounded;
	npcbcNew.fpRepairTime = fpRepairTime;
	npcbcNew.fpEngineFailureChance = fpEngineFailureChance;
	npcbcNew.fpRotorFailurePossible = fpRotorFailurePossible;
	npcbcNew.fpCockpitFailurePossible = fpCockpitFailurePossible;
	npcbcNew.bDummyHelicopter = bDummyHelicopter;
	npcbcNew.VehicleClass = VehicleClass;
	npcbcNew.DrawDriverInTP = DrawDriverInTP;
	npcbcNew.rotDummyRotation = Rotation;
	npcbcNew.Possess(agpPawnNew);
	npcbcNew.InitVehicle();
	npcbcNew.Start();
	FindEnemyAICC();
	npcbcNew.npcaiccEnemyCombatController = npcaiccEnemyCombatController;
	*/
	return npcbcNew;
}

ANPCPlayerStart* ANPCHelicopterStart::FindNPCPlayerStartByTag(FString sTagToFind)
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

void ANPCHelicopterStart::FindEnemyAICC()
{
	ANPCAICombatController* npcaiccIterator = nullptr;
	/*
	if (npcaiccEnemyCombatController != nullptr)
	{
		return;
	}
	ForEach AllActors(ANPCAICombatController::StaticClass(), npcaiccIterator)
	{
		if (npcaiccIterator.iTeamID != iNPCTeamID)
		{
			if (!npcaiccIterator.bDisableCombatController)
			{
				Log(string(this) + " Located enemy combat controller!");
				npcaiccEnemyCombatController = npcaiccIterator;
				return;
			}
		}
	}
	*/
}
