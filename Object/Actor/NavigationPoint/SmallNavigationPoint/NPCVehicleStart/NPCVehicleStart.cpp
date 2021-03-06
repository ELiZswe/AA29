// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCVehicleStart/NPCVehicleStart.h"
#include "AA29/Object/Actor/NavigationPoint/PathNode/RoadPathNode/RoadPathNode.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
ANPCVehicleStart::ANPCVehicleStart()
{
	//ControllerClass = class'AGP.NPCBasePreCrewedVehicleController';
	DrawDriverInTP = true;
	iNPCInitialMentalState = 10;
	iNPCLeadershipMentalStateRange = 2500;
	iNPCTeamID = 2;
	fpNPCHearingRadius = 500;
	fpNPCVisionConeAngle = 32678;
	fpNPCMaxVisualRange = 5000;
	bMaleVoice = true;
	namePostUnloadState = "Guarding";
	bFireWhileUnloading = true;
	fpMinDelayBeforeMovingOut = 8;
	bAscendingNodeDirection = true;
	bLikesToCloseDoorBehindSelf = true;
	fpChanceOfSpawning = 100;
	fpNPCWeaponEffectiveRange = 100000;
	bHasCoAxMachineGun = true;
	iCoAxRounds = 1000;
	RagdollOverride = "SoldierM";
	RagInvInertia = 4;
	RagShootStrength = 10000;
	RagSpinScale = 13;
	RagProneProjectileScale = 0.35;
	bNoAutoConnect = true;
	bForcedOnly = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/S_PSTagVehicle_Mat.S_PSTagVehicle_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 0.5;
}

void ANPCVehicleStart::Reset()
{
	Super::Reset();
	bEnabled = false;
}

void ANPCVehicleStart::BeginPlay()
{
}

bool ANPCVehicleStart::ShouldUseStartSpot()
{
	if (bMustSpawn)
	{
		return true;
	}
	if ((FMath::FRand() * 100) <= fpChanceOfSpawning)
	{
		return true;
	}
	return false;
}

void ANPCVehicleStart::CustomCreation(ANPCBaseController* npbcController, AAGP_Pawn* agpPawn)
{
}

ANPCBaseController* ANPCVehicleStart::CreateNPC()
{
	ANPCBasePreCrewedVehicleControlle* npcbcNew = nullptr;
	AAGP_Pawn* agpPawnNew = nullptr;
	int32 iAttach = 0;
	int32 Iterations = 0;
	int32 iSpawnAttempts = 0;
	int32 iSquadMember = 0;
	int32 iInitialStartingPathNodeIndex = 0;
	TArray<int32> AlreadyCheckedIndex;
	bool bFailed = false;
	int32 i = 0;
	if (!ShouldUseStartSpot())
	{
		return nullptr;
	}
	if (bDebugInit)
	{
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT(""));
		UE_LOG(LogTemp, Log, TEXT("*******************"));
		//UE_LOG(LogTemp, Log, TEXT("Creating new controller for pawn at start spot: %s"),ControllerClass.GetName());
		UE_LOG(LogTemp, Log, TEXT("*******************"));
	}
	//npcbcNew = Spawn(ControllerClass);
	if (bDebugInit)
	{
		UE_LOG(LogTemp, Log, TEXT("Controller created: %s"),npcbcNew);
	}
	npcbcNew->bDebugPath = bDebugPath;
	if (sNPCWaypointTag.Len() > 0)
	{
		npcbcNew->sNPCWaypointTag = sNPCWaypointTag;
	}
	else
	{
		//npcbcNew->sNPCWaypointTag = Tag;
	}
	if (bDebugInit)
	{
		//Log("Pathnode waypoint tag is now: " + npcbcNew->sNPCWaypointTag);
	}
	npcbcNew->PreloadPathNodeList();
	npcbcNew->fpNPCWeaponEffectiveRange = fpNPCWeaponEffectiveRange;
	//npcbcNew->iActivePatrolPath = Rand(npcbcNew->avppDrivingPathsForPatrols.Num());
	if (bStartAndSpawnAtRandomNode && bDebugInit)
	{
		//Log("Will find random pathnode from " + FString::FromInt(npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol.Num()) + " possible nodes");
	}
	iInitialStartingPathNodeIndex = iStartingPathNodeIndex;

	//PawnSpawnClass = class<AGP_Pawn>(DynamicLoadObject("AGP_Characters.NPC_ISoldierGrunt_NoAux", Class'Class'));
	if (agpPawnNew == nullptr)
	{
		Iterations++;
		if (bStartAndSpawnAtRandomNode)
		{
			if (iSpawnAttempts++ > npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol.Num())
			{
				if (bDebugInit)
				{
					UE_LOG(LogTemp, Log, TEXT("unable to spawn at random node location, using player start location as fall-back"));
				}
				//agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation);
			}
			else
			{
				//iStartingPathNodeIndex = Rand((npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol.Num() + 1));
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
					if (Iterations < 500)
					{
						//AlreadyCheckedIndex.insert(AlreadyCheckedIndex.Num(), 1);
						AlreadyCheckedIndex[(AlreadyCheckedIndex.Num() - 1)] = iStartingPathNodeIndex;
					}
				}
				if (bDebugInit)
				{
					//Log(string(Tag) + " trying random node " + FString::FromInt(iStartingPathNodeIndex));
				}
				if ((iStartingPathNodeIndex == npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol.Num()) || (Iterations > 500))
				{
					if (bDebugInit)
					{
						if (Iterations > 500)
						{
							UE_LOG(LogTemp, Log, TEXT("Only valid location was already occupied. Giving up and using actual player start location."));
						}
						else
						{
							UE_LOG(LogTemp, Log, TEXT("Randomly using actual player start location"));
						}
					}
					//agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation);
				}
				else
				{
					if (npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex]->bNeverRandomSpawnHere || npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex]->taken)
					{
						if (bDebugInit)
						{
							UE_LOG(LogTemp, Log, TEXT("Blocked pathnode being skipped for random spawn"));
						}
					}
					else
					{
						npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex]->taken = true;
						//agpPawnNew = Spawn(PawnSpawnClass, , , npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex]->GetActorLocation(), npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex].Rotation);
						if (agpPawnNew != nullptr)
						{
							if (bDebugInit)
							{
								//Log(string(Tag) + " got a good spawn at random location ( " + FString::FromInt(iStartingPathNodeIndex) + ") of node " + FString::FromInt(npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex].Tag));
							}
							//npcbcNew->SetLocation(agpPawnNew->Location);
							//npcbcNew->SetRotation(agpPawnNew->Rotation);
							iStartingPathNodeIndex++;
							npcbcNew->avppDrivingPathsForPatrols[npcbcNew->iActivePatrolPath].apnDrivingPathNodesForPatrol[iStartingPathNodeIndex]->taken = false;
						}
						else
						{
						}
						//agpPawnNew = Spawn(PawnSpawnClass, , , Location, Rotation);
					}
				}
			}
		}
	}
	//agpPawnNew->bHidden = true;
	if (bUseRandomStartingNode && (!bStartAndSpawnAtRandomNode))
	{
		//iStartingPathNodeIndex = (Rand((npcbcNew->apnPathNodesForPatrol.Num() - 1)) + 1);
	}
	if (bDebugInit)
	{
		//Log("Vehicle created: " + FString::FromInt(agpPawnNew));
	}
	if (bDebugInit)
	{
		//Log("Pawn being created, bStartAsDummyPawn: " + FString::FromInt(bStartAsDummyPawn));
	}
	npcbcNew->bStartAsDummyPawn = bStartAsDummyPawn;
	npcbcNew->AnimSequence = AnimSequence;
	npcbcNew->AnimRate = AnimRate;
	npcbcNew->AnimTime = AnimTime;
	npcbcNew->AnimChannel = AnimChannel;
	npcbcNew->iNPCInitialMentalState = iNPCInitialMentalState;
	npcbcNew->iNPCLeadershipMentalStateBonus = iNPCLeadershipMentalStateBonus;
	npcbcNew->iNPCLeadershipMentalStateRange = iNPCLeadershipMentalStateRange;
	npcbcNew->iNPCTeamID = iNPCTeamID;
	npcbcNew->fpNPCHearingRadius = fpNPCHearingRadius;
	npcbcNew->fpNPCVisionConeAngle = fpNPCVisionConeAngle;
	npcbcNew->fpNPCMaxVisualRange = fpNPCMaxVisualRange;
	npcbcNew->bIgnoreFogDistance = bIgnoreFogDistance;
	npcbcNew->bNPCSpeaksEnglish = bNPCSpeaksEnglish;
	npcbcNew->bNPCCanBeHealed = bNPCCanBeHealed;
	npcbcNew->fpNPCWeaponAccuracy = fpNPCWeaponAccuracy;
	npcbcNew->fNPCExperience = fNPCExperience;
	npcbcNew->fNPCLikesToCrouch = fNPCLikesToCrouch;
	npcbcNew->iMinThreatLevel = iMinThreatLevel;
	npcbcNew->bMaleVoice = bMaleVoice;
	npcbcNew->sMovieToPlayOnUse = sMovieToPlayOnUse;
	npcbcNew->sndAudioToPlayOnUse = sndAudioToPlayOnUse;
	npcbcNew->iMovieToPlayOnUseFramerate = iMovieToPlayOnUseFramerate;
	npcbcNew->iStartingPathNodeIndex = iStartingPathNodeIndex;
	npcbcNew->bScanWhenStopped = bScanWhenStopped;
	npcbcNew->fChanceOfStoppingAtNode = fChanceOfStoppingAtNode;
	npcbcNew->bAscendingNodeDirection = bAscendingNodeDirection;
	npcbcNew->bAutoReversePath = bAutoReversePath;
	npcbcNew->sNPCWaypointTag = sNPCWaypointTag;
	npcbcNew->ConvoyTag = ConvoyTag;
	npcbcNew->bConvoyLeader = ConvoyLeader;
	npcbcNew->bPatrol_NoPathfinding = Patrol_NoPathfinding;
	npcbcNew->bDebugMode = bDebugMode;
	npcbcNew->bDebugPath = bDebugPath;
	npcbcNew->bDebugSenses = bDebugSenses;
	npcbcNew->bLikesToCloseDoorBehindSelf = bLikesToCloseDoorBehindSelf;
	npcbcNew->iFragGrenadeCount = iFragGrenadeCount;
	npcbcNew->iSmokeGrenadeCount = iSmokeGrenadeCount;
	npcbcNew->iFlashGrenadeCount = iFlashGrenadeCount;
	npcbcNew->iRPGCount = iRPGCount;
	npcbcNew->i203Rounds = i203Rounds;
	npcbcNew->bHasBinoculars = bHasBinoculars;
	npcbcNew->fpMortarRequestSkill = fpMortarRequestSkill;
	/*
	if (string(VehicleClass) != "AGP_Vehicles.T62A")
	{
		bHasCoAxMachineGun = false;
	}
	*/
	npcbcNew->bHasCoAxMachineGun = bHasCoAxMachineGun;
	npcbcNew->iCoAxRounds = iCoAxRounds;
	npcbcNew->bTriggerStart = bTriggerStartVehicle;
	if (VehicleTag != "None")
	{
		npcbcNew->VehicleTag = VehicleTag;
	}
	else
	{
		//npcbcNew->VehicleTag = Tag;
	}
	if (((namePrimaryWeapon == nullptr) && (!bNoDefaultWeapons)) && (sPrimaryWeaponDefaultClass.Len() > 0))
	{
		//npcbcNew->namePrimaryWeapon = class<AGP_Weapon>(DynamicLoadObject(sPrimaryWeaponDefaultClass, Class'Class'));
	}
	else
	{
		npcbcNew->namePrimaryWeapon = namePrimaryWeapon;
	}
	if (((nameSecondaryWeapon == nullptr) && (!bNoDefaultWeapons)) && (sSecondaryWeaponDefaultClass.Len() > 0))
	{
		//npcbcNew->nameSecondaryWeapon = class<AGP_Weapon>(DynamicLoadObject(sSecondaryWeaponDefaultClass, Class'Class'));
	}
	else
	{
		npcbcNew->nameSecondaryWeapon = namePrimaryWeapon;
	}
	npcbcNew->iSquadID = iSquadID;
	npcbcNew->iFireteamID = iFireteamID;
	npcbcNew->iPlatoonID = iPlatoonID;
	if (aoAttachments.Num() > 0)
	{
		//npcbcNew->aoAttachments.insert(0, aoAttachments.Num());
		for (iAttach = 0; iAttach < aoAttachments.Num(); iAttach++)
		{
			npcbcNew->aoAttachments[iAttach].Attachment = aoAttachments[iAttach].Attachment;
			npcbcNew->aoAttachments[iAttach].Bone = aoAttachments[iAttach].Bone;
			npcbcNew->aoAttachments[iAttach].LocationOffset = aoAttachments[iAttach].LocationOffset;
			npcbcNew->aoAttachments[iAttach].RotationOffset = aoAttachments[iAttach].RotationOffset;
			npcbcNew->aoAttachments[iAttach].bUseParentScale = aoAttachments[iAttach].bUseParentScale;
			npcbcNew->aoAttachments[iAttach].Scale = aoAttachments[iAttach].Scale;
		}
	}
	switch (enpcoPrimaryOrders)
	{
	case ENPCOrders2::NPCOrder_Guard:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->1;
		break;
	case ENPCOrders2::NPCOrder_Ambush:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->2;
		break;
	case ENPCOrders2::NPCOrder_UnloadPassengers:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->100;
		break;
	case ENPCOrders2::NPCOrder_PatrolAndUnload:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->101;
		break;
	case ENPCOrders2::NPCOrder_AssaultLocation:
		UE_LOG(LogTemp, Log, TEXT("Setting vehicle to assaultlocation orders"));
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->9;
		npcbcNew->nameAssaultLocationTag = nameAssaultLocationTag;
		break;
	case ENPCOrders2::NPCOrder_Patrol:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->0;
	default:
		//npcbcNew->iNPCPrimaryOrders = npcbcNew->0;
		break;
	}
	npcbcNew->fpDelayedInitialOrderExecutionTime = fpDelayedInitialOrderExecutionTime;
	npcbcNew->nameAssaultLocationTag = nameAssaultLocationTag;
	npcbcNew->bSmokeOnAssault = bSmokeOnAssault;
	/*
	switch (enptoTacticalOrders)
	{
	case 0:
		npcbcNew->iNPCTacticalOrders = npcbcNew->100;
		break;
	case 1:
		npcbcNew->iNPCTacticalOrders = npcbcNew->200;
		break;
	case 2:
		npcbcNew->iNPCTacticalOrders = npcbcNew->300;
		break;
	case 3:
		npcbcNew->iNPCTacticalOrders = npcbcNew->400;
		break;
	default:
		npcbcNew->iNPCTacticalOrders = npcbcNew->100;
		break;
	}
	*/
	if (anameSquadPlayerStartsTag.Num() > 0)
	{
		//npcbcNew->anpcpsSquadPlayerStarts.insert(0, anameSquadPlayerStartsTag.Num());
		for (iSquadMember = 0; iSquadMember < anameSquadPlayerStartsTag.Num(); iSquadMember++)
		{
			//npcbcNew->anpcpsSquadPlayerStarts[iSquadMember] = FindNPCPlayerStartByTag(string(anameSquadPlayerStartsTag[iSquadMember]));
			if (npcbcNew->anpcpsSquadPlayerStarts[iSquadMember] == nullptr)
			{
				//Log("*** WARNING *** Vehicle " + FString::FromInt(Tag) + " has an invalid passenger[" + FString::FromInt(iSquadMember) + "] configured: " + FString::FromInt(anameSquadPlayerStartsTag[iSquadMember]));
			}
			else
			{
				//DebugLog(DEBUG_AIVehicle, "Found vehicle passenger player start: " + FString::FromInt(npcbcNew->anpcpsSquadPlayerStarts[iSquadMember]));
				//DebugLog(DEBUG_AIVehicle, "Vehicle passenger player start has tag: " + FString::FromInt(npcbcNew->anpcpsSquadPlayerStarts[iSquadMember].Tag));
			}
		}
	}
	npcbcNew->namePostUnloadState = namePostUnloadState;
	npcbcNew->fpDelayedInitialOrderExecutionTime = fpDelayedInitialOrderExecutionTime;
	npcbcNew->bFireWhileUnloading = bFireWhileUnloading;
	npcbcNew->bUnloadIfDamaged = bUnloadIfDamaged;
	npcbcNew->nameUnloadLocation = nameUnloadLocation;
	if (PawnTag != "None")
	{
		//agpPawnNew->Tag = PawnTag;
	}
	else
	{
		//agpPawnNew->Tag = Tag;
	}
	if (ControllerTag != "None")
	{
		//npcbcNew->Tag = ControllerTag;
	}
	else
	{
		//npcbcNew->Tag = Tag;
	}
	if (bUserSetSkin)
	{
		if (setPants != nullptr)
		{
			agpPawnNew->Skins[0] = setPants;
			agpPawnNew->Skins[1] = setShirt;
			agpPawnNew->Skins[2] = setHands;
			agpPawnNew->Skins[3] = setFace;
		}
		if (meshPawn != nullptr)
		{
			//agpPawnNew->LinkMesh(meshPawn, true);
		}
		if (bDebugInit)
		{
			//Log("Setting NPC " + FString::FromInt(Tag) + " to mesh: " + FString::FromInt(meshPawn));
		}
	}
	agpPawnNew->RagdollOverride = RagdollOverride;
	agpPawnNew->RagdollLifeSpan = RagdollLifeSpan;
	agpPawnNew->RagInvInertia = RagInvInertia;
	agpPawnNew->RagDeathVel = RagDeathVel;
	agpPawnNew->RagShootStrength = RagShootStrength;
	agpPawnNew->RagSpinScale = RagSpinScale;
	agpPawnNew->RagDeathUpKick = RagDeathUpKick;
	agpPawnNew->RagProneProjectileScale = RagProneProjectileScale;
	agpPawnNew->bNPCDisableSkinSwapping = true;
	CustomCreation(npcbcNew, agpPawnNew);
	if (bDebugInit)
	{
		//Log("Telling controller " + FString::FromInt(npcbcNew) + " to possess pawn: " + FString::FromInt(agpPawnNew) + " vehicle class: " + FString::FromInt(VehicleClass));
	}
	npcbcNew->VehicleClass = VehicleClass;
	npcbcNew->DrawDriverInTP = DrawDriverInTP;
	npcbcNew->Possess(agpPawnNew);
	FindAICC();
	if (npcaiccCombatController != nullptr)
	{
		npcaiccCombatController->RegisterVehicle(npcbcNew);
	}
	return Cast<ANPCBaseController>(npcbcNew);
}

ANPCPlayerStart* ANPCVehicleStart::FindNPCPlayerStartByTag(FString sTagToFind)
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

void ANPCVehicleStart::FindAICC()
{
	ANPCAICombatController* npcaiccIterator = nullptr;
	if (npcaiccCombatController != nullptr)
	{
		return;
	}
	/*
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
