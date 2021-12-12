// All the original content belonged to the US Army

#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"

// Sets default values
ANPCAICombatController::ANPCAICombatController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	asOrderNames = {
		"Patrol",
		"Guard",
		"Ambush",
		"Hunt",
		"Defend",
		"Harass",
		"Flee",
		"Surrender",
		"Rush"
	};

	asCombatActions = {
		"DoNothing",
		"ShiftPosition",
		"ScanForEnemy",
		"SwitchWeapons",
		"ReloadWeapon",
		"CrazyIvan",
		"TauntEnemy",
		"Collapse",
		"EngageEnemy",
		"ThrowFrag",
		"Advance",
		"PursueEnemy",
		"SuppressEnemy",
		"RushEnemy",
		"FireBlindly",
		"FlankEnemy",
		"FallBack",
		"SeekCover",
		"Breakout",
		"ThrowSmoke",
		"DuckAndCover",
		"Surrender",
		"Cower",
		"ReturnToPatrol",
		"RunFromGrenade",
	};
	asEvents = {
		"TimeElapsed",
		"HeardNoise",
		"LostEnemy",
		"KillEnemy",
		"FriendDied",
		"NewEnemy",
		"HeardGunfire",
		"SeeVehicle",
		"Buzzed",
		"Wounded",
		"Jam",
		"OutOfReloads",
		"SeeGrenade",
		"Anarchy",
		"ActionComplete"
	};
	iTeamID = 2;
	iMaxNPCsAtRespawn = 50;
	fpReinforcementDelayTime = 20;
	iVehicleRespawnMinVehicleLevel = 1;
	ActorHelp.SetNum(4);
	ActorHelp[0] = "Use this to control AA NPCs.";
	ActorHelp[2] = "See NPCTeamInfo to configure team to control";
	ActorHelp[3] = "See NPCArmory to configure mortars";
	//bHidden = true;
	//Texture = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/AGP/S_NCPAICombatController_Mat.S_NCPAICombatController_Mat'"), NULL, LOAD_None, NULL);
	//DrawScale = 10;
	bCollideWhenPlacing = true;
}

// Called every frame
void ANPCAICombatController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

static const int32 MAX_DEAD_NPCS_TO_TRACK = 128;
static const int32 MAXTIME_BETWEEN_ORDERS = 10;
static const int32 FIREMISSION_MORTAR_ROUNDS = 8;
static const int32 SUPPORTREQUEST_MORTAR = 1;
static const int32 SUPPORTREQUEST_NONE = 0;
static const int32 MAX_TEAMTHREAT_RADIUS = 1000;
static const int32 MAX_PLATOONS = 8;
static const int32 MAX_SQUADS_PER_PLATOON = 8;
static const int32 MAX_SPEECH_VOICES = 10;
static const int32 MAX_EVENTS = 15;
static const int32 EVENT_ACTIONCOMPLETE = 14;
static const int32 EVENT_ANARCHY = 13;
static const int32 EVENT_SEEGRENADE = 12;
static const int32 EVENT_OUTOFRELOADS = 11;
static const int32 EVENT_JAMRELOAD = 10;
static const int32 EVENT_WOUNDED = 9;
static const int32 EVENT_BUZZED = 8;
static const int32 EVENT_SEEVEHICLE = 7;
static const int32 EVENT_HEARDGUNFIRE = 6;
static const int32 EVENT_NEWENEMY = 5;
static const int32 EVENT_FRIENDDIED = 4;
static const int32 EVENT_KILLENEMY = 3;
static const int32 EVENT_LOSTENEMY = 2;
static const int32 EVENT_HEARDNOISE = 1;
static const int32 EVENT_TIMEELAPSED = 0;
static const int32 MAX_ORDERS = 9;
static const int32 AICCORDER_RUSH = 8;
static const int32 AICCORDER_SURRENDER = 7;
static const int32 AICCORDER_FLEE = 6;
static const int32 AICCORDER_HARASS = 5;
static const int32 AICCORDER_DEFEND = 4;
static const int32 AICCORDER_HUNT = 3;
static const int32 AICCORDER_AMBUSH = 2;
static const int32 AICCORDER_GUARD = 1;
static const int32 AICCORDER_PATROL = 0;
static const int32 THINKING_FREQUENCY_IN_SECONDS = 1.0;

//native final Function bool IsBodyNearLocation(AGP_Pawn agppwn);
bool ANPCAICombatController::IsBodyNearLocation(AAGP_Pawn* agppwn)
{
	return false;    //FAKE   /ELiZ
}

//native final Function AddDeadBodyLocation(AGP_Pawn agppwn);
void ANPCAICombatController::AddDeadBodyLocation(AAGP_Pawn* agppwn)
{

}

//native final Function FString DetermineCombatActionByState(int32 iOrderIndex, int32 iEventIndex, int32 iNodeIndex, int32 iMentalStateIndex, bool bEnableLogging);
FString ANPCAICombatController::DetermineCombatActionByState(int32 iOrderIndex, int32 iEventIndex, int32 iNodeIndex, int32 iMentalStateIndex, bool bEnableLogging)
{
	return "FAKE";    //FAKE   /ELiZ
}

//native final Function bool InitializeDecisionGrid(FString sFileName);
bool ANPCAICombatController::InitializeDecisionGrid(FString sFileName)
{
	return false;    //FAKE   /ELiZ
}

//native final Function bool InitializeSpeechGrid(FString sFileName);
bool ANPCAICombatController::InitializeSpeechGrid(FString sFileName)
{
	return false;    //FAKE   /ELiZ
}

//native final Function FString DetermineSpeechByState(int32 iOrderIndex, int32 iEventIndex, int32 iMentalStateIndex);
FString ANPCAICombatController::DetermineSpeechByState(int32 iOrderIndex, int32 iEventIndex, int32 iMentalStateIndex)
{
	return "FAKE";    //FAKE   /ELiZ
}

//native final Function NotifyDoorBreached(Vector vDoorLocation);
void ANPCAICombatController::NotifyDoorBreached(FVector vDoorLocation)
{

}

//native final Function NotifyObjectiveAccomplished(Actor actorObjective);
void ANPCAICombatController::NotifyObjectiveAccomplished(AActor* actorObjective)
{

}

//native final Function NotifyHelicopterLanding(Vector vPZLocation);
void ANPCAICombatController::NotifyHelicopterLanding(FVector vPZLocation)
{

}

//native final Function bool ReportUnderFireSquadAlert(ANPCBaseSoldierController* npcbcReporter, Actor aShooter);
bool ANPCAICombatController::ReportUnderFireSquadAlert(ANPCBaseSoldierController* npcbcReporter, AActor* aShooter)
{
	return false;    //FAKE   /ELiZ
}

//native final Function ActivateGarbageCollection();
void ANPCAICombatController::ActivateGarbageCollection()
{

}


void ANPCAICombatController::DisplayDebug(UCanvas* Canvas, const class FDebugDisplayInfo&, float& YL, float& YPos)
{
	/*
	int32 iOrder = 0;
	(YPos += YL);
	Canvas.SetPos(4, YPos);
	Canvas.DrawText("Company Alive: " $ string((fpPercentCompanyAlive * 100)) $ "%  (Total: " $ string(iTotalCompanyMembers) $ ", Alive: " $ string(iTotalLiveMembers) $ ")");
	for (iOrder = 0; iOrder < oqOrdersWaitingDeployment.Length; iOrder++)
	{
		YPos += YL;
		Canvas.SetPos(4, YPos);
		Canvas.DrawText("Order Queue:" $ GetVerboseOrders(iOrder) $ ": " $ string(oqOrdersWaitingDeployment[iOrder].npcbc) $ ", order: " $ string(oqOrdersWaitingDeployment[iOrder].iOrder) $ ", delivery time: " $ string(oqOrdersWaitingDeployment[iOrder].fpTimeToDeliver) $ " (in " $ string((Level.TimeSeconds - oqOrdersWaitingDeployment[iOrder].fpTimeToDeliver)) $ " seconds)");
	}
	*/
}

FString ANPCAICombatController::GetVerboseOrders(int32 CurrentOrders)
{
	/*
	switch (CurrentOrders)
	{
	case 0:
		return "ORDER_PATROL";
	case 1:
		return "ORDER_GUARD";
	case 2:
		return "ORDER_AMBUSH";
	case 3:
		return "ORDER_HUNT";
	case 4:
		return "ORDER_DEFEND";
	case 5:
		return "ORDER_HARASS";
	case 6:
		return "ORDER_FLEE";
	case 7:
		return "ORDER_SURRENDER";
	case 8:
		return "ORDER_RUSH";
	default:
		return string(CurrentOrders);
	}
	*/
	return "FAKE";    //FAKE   /ELiZ
}

void ANPCAICombatController::BeginPlay()
{
	/*
	amrtMortarData.insert(0, 17);
	amrtMortarData[0].fpMin = 615;
	amrtMortarData[0].fpMax = 732;
	amrtMortarData[0].fpFlightTime = 4.7;
	amrtMortarData[0].fpAngle = 10;
	amrtMortarData[1].fpMin = 732;
	amrtMortarData[1].fpMax = 846;
	amrtMortarData[1].fpFlightTime = 5.63;
	amrtMortarData[1].fpAngle = 12;
	amrtMortarData[2].fpMin = 845;
	amrtMortarData[2].fpMax = 953;
	amrtMortarData[2].fpFlightTime = 6.55;
	amrtMortarData[2].fpAngle = 14;
	amrtMortarData[3].fpMin = 953;
	amrtMortarData[3].fpMax = 1058;
	amrtMortarData[3].fpFlightTime = 7.47;
	amrtMortarData[3].fpAngle = 16;
	amrtMortarData[4].fpMin = 1058;
	amrtMortarData[4].fpMax = 1157;
	amrtMortarData[4].fpFlightTime = 8.37;
	amrtMortarData[4].fpAngle = 18;
	amrtMortarData[5].fpMin = 1157;
	amrtMortarData[5].fpMax = 1250;
	amrtMortarData[5].fpFlightTime = 9.27;
	amrtMortarData[5].fpAngle = 20;
	amrtMortarData[6].fpMin = 1250;
	amrtMortarData[6].fpMax = 1337;
	amrtMortarData[6].fpFlightTime = 10.15;
	amrtMortarData[6].fpAngle = 22;
	amrtMortarData[7].fpMin = 1337;
	amrtMortarData[7].fpMax = 1418;
	amrtMortarData[7].fpFlightTime = 11.02;
	amrtMortarData[7].fpAngle = 24;
	amrtMortarData[8].fpMin = 1418.400024;
	amrtMortarData[8].fpMax = 1492;
	amrtMortarData[8].fpFlightTime = 11.88;
	amrtMortarData[8].fpAngle = 26;
	amrtMortarData[9].fpMin = 1492;
	amrtMortarData[9].fpMax = 1558;
	amrtMortarData[9].fpFlightTime = 12.72;
	amrtMortarData[9].fpAngle = 28;
	amrtMortarData[10].fpMin = 1558;
	amrtMortarData[10].fpMax = 1617;
	amrtMortarData[10].fpFlightTime = 13.5;
	amrtMortarData[10].fpAngle = 30;
	amrtMortarData[11].fpMin = 1617;
	amrtMortarData[11].fpMax = 1668;
	amrtMortarData[11].fpFlightTime = 14.366;
	amrtMortarData[11].fpAngle = 32;
	amrtMortarData[12].fpMin = 1668;
	amrtMortarData[12].fpMax = 1711;
	amrtMortarData[12].fpFlightTime = 15.15;
	amrtMortarData[12].fpAngle = 34;
	amrtMortarData[13].fpMin = 1711;
	amrtMortarData[13].fpMax = 1746;
	amrtMortarData[13].fpFlightTime = 15.9;
	amrtMortarData[13].fpAngle = 36;
	amrtMortarData[14].fpMin = 1746;
	amrtMortarData[14].fpMax = 1711;
	amrtMortarData[14].fpFlightTime = 16.68;
	amrtMortarData[14].fpAngle = 38;
	amrtMortarData[15].fpMin = 1711;
	amrtMortarData[15].fpMax = 1790;
	amrtMortarData[15].fpFlightTime = 17.4;
	amrtMortarData[15].fpAngle = 40;
	amrtMortarData[16].fpMin = 1790;
	amrtMortarData[16].fpMax = 2500;
	amrtMortarData[16].fpFlightTime = 17.92;
	amrtMortarData[16].fpAngle = 42;
	InitializeDecisionGrid("NPCAICC.decision.xml");
	InitializeSpeechGrid("NPCAICC.speech.xml");
	bOfficerAvailable = IsOfficerAlive();
	iAvailableMortarAttacks = iMaxMortarAttacks;
	fpTimeUntilNextReinforcements = 0;
	fpTimeUntilNextVehicleReinforcements = 0;
	iReinforcementWave = 0;
	iVehicleReinforcementWave = 0;
	if (fpReinforcementDelayTime < float(20))
	{
		fpReinforcementDelayTime = 20;
	}
	InitializeRespawnInformation();
	*/

	Super::BeginPlay();
}

void ANPCAICombatController::EndGame()
{
	/*
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	bStarted = false;
	Log(string(Self) $ ".EndGame() entered, resetting officer available and available Mortar attacks to " $ string(iMaxMortarAttacks));
	npcsdCommandos.npcscMembers.remove(0, npcsdCommandos.npcscMembers.Length);
	npcsdCommandos.npcncoLeader = None;
	npcsdCommandos.bSquadDead = false;
	anpcbcVehicles.remove(0, anpcbcVehicles.Length);
	afmifActiveRounds.remove(0, afmifActiveRounds.Length);
	aecEnemyContacts.remove(0, aecEnemyContacts.Length);
	oqOrdersWaitingDeployment.remove(0, oqOrdersWaitingDeployment.Length);
	asfrqFireMissions.remove(0, asfrqFireMissions.Length);
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.remove(0, anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length);
			anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader = None;
			anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].bSquadDead = false;
			anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].iAmbushSet = 0;
		}
	}
	bOfficerAvailable = IsOfficerAlive();
	iAvailableMortarAttacks = iMaxMortarAttacks;
	InitializeRespawnInformation();
	iDeadNPCs = 0;
	ActivateGarbageCollection();
	SetTimer(0, false);
	*/
}

void ANPCAICombatController::StartAICC()
{
	/*
	bStarted = true;
	DebugLog(DEBUG_AI, string(Self) $ ".MatchStarting");
	fpTimeUntilNextReinforcements = (Level.TimeSeconds + float(15));
	fpTimeUntilNextVehicleReinforcements = (Level.TimeSeconds + float(30));
	iReinforcementWave = 0;
	iVehicleReinforcementWave = 0;
	SetTimer(1, true);
	*/
}

void ANPCAICombatController::InitializeRespawnInformation()
{
	/*
	local NavigationPoint N;
	if (arrRespawnInformation.Length > 0)
	{
		arrRespawnInformation.remove(0, arrRespawnInformation.Length);
	}
	N = Level.NavigationPointList;
	if (N != None)
	{
		if (N.IsA("NPCPlayerStart"))
		{
			DebugLog(DEBUG_AI, "Found possible player start for respawns " $ string(N));
			DebugLog(DEBUG_AI, "Respawns allowed: " $ string(NPCPlayerStart(N).iRespawnsAllowed) $ " Reserve: " $ string(NPCPlayerStart(N).bSpawnAsReserve) $ " Platoon: " $ string(NPCPlayerStart(N).iPlatoonID) $ ", Squad: " $ string(NPCPlayerStart(N).iSquadID) $ ", Fireteam: " $ string(NPCPlayerStart(N).iFireteamID) $ " VehiclePassenger: " $ string(NPCPlayerStart(N).bVehiclePassenger));
			if (((NPCPlayerStart(N).iRespawnsAllowed > 0) || NPCPlayerStart(N).bSpawnAsReserve) && (!NPCPlayerStart(N).bVehiclePassenger))
			{
				DebugLog(DEBUG_AI, "Found non-vehicle passenger respawn player start: " $ string(N));
				arrRespawnInformation.insert(0, 1);
				arrRespawnInformation[0].snpStart = SmallNavigationPoint(N);
				arrRespawnInformation[0].iRespawnsLeft = NPCPlayerStart(N).iRespawnsAllowed;
				DebugLog(DEBUG_AI, "Now have " $ string(arrRespawnInformation.Length) $ " NPC reserves defined");
			}
		}
		else
		{
			if (N.IsA("NPCVehicleStart"))
			{
				if ((NPCVehicleStart(N).iRespawnsAllowed > 0) || NPCVehicleStart(N).bSpawnAsReserve)
				{
					arrRespawnInformation.insert(0, 1);
					arrRespawnInformation[0].snpStart = SmallNavigationPoint(N);
					arrRespawnInformation[0].iRespawnsLeft = NPCVehicleStart(N).iRespawnsAllowed;
				}
			}
		}
		N = N.nextNavigationPoint;
	}
	*/
}

void ANPCAICombatController::PostBeginPlay()
{
	/*
	local NPCSpeechManager npcsmgrIterator;
	local NPCSpeechManager npcsmgrDefault;
	bool bSpeechManagerVoicesFound = false;
	ForEach AllActors(class'AGP.NPCSpeechManager', npcsmgrIterator)
	{
		DebugLog(DEBUG_AI, "Found speech set for voice " $ string(npcsmgrIterator.iVoiceIndex) $ " (" $ npcsmgrIterator.sDescription $ ")");
		if (npcsmgrIterator.bCivilianVoice)
		{
			continue;
		}
		if (npcsmgrIterator.iVoiceIndex > 10)
		{
			Log("WARNING - Speech manager voice " $ string(npcsmgrIterator) $ " has an invalid speech index of " $ string(npcsmgrIterator.iVoiceIndex));
			continue;
		}
		if (anpcsmgrSpeechManager[npcsmgrIterator.iVoiceIndex] != None)
		{
			Log("WARNING - Speech manager voice " $ string(npcsmgrIterator.iVoiceIndex) $ " defined more than once in " $ string(anpcsmgrSpeechManager[npcsmgrIterator.iVoiceIndex]) $ " and " $ string(npcsmgrIterator));
		}
		bSpeechManagerVoicesFound = true;
		if (npcsmgrDefault == None)
		{
			npcsmgrDefault = npcsmgrIterator;
		}
		anpcsmgrSpeechManager[npcsmgrIterator.iVoiceIndex] = npcsmgrIterator;
	}
	if (anpcsmgrSpeechManager[0] == None)
	{
		anpcsmgrSpeechManager[0] = npcsmgrDefault;
	}
	if (!bSpeechManagerVoicesFound)
	{
		Log("WARNING - No speech managers found for AI speech");
	}
	bInAnarchy = false;
	*/
}

void ANPCAICombatController::RegisterVehicle(ANPCBaseController* npcbc)
{
	/*
	anpcbcVehicles.insert(0, 1);
	anpcbcVehicles[0] = npcbc;
	DebugLog(DEBUG_AI, "Vehicle " $ string(npcbc) $ " registered with APawn* " $ string(npcbc.Pawn));
	*/
}

void ANPCAICombatController::RegisterWithCombatController(ANPCBaseSoldierController* npcbc)
{
	/*
	if (npcbc.IsA("NPCCommandoController"))
	{
		npcsdCommandos.npcscMembers.insert(npcsdCommandos.npcscMembers.Length, 1);
		npcsdCommandos.npcscMembers[(npcsdCommandos.npcscMembers.Length - 1)] = npcbc;
		npcbc.npcaiccCombatController = Self;
		return;
	}
	else
	{
		anpcpPlatoons[npcbc.iPlatoonID].anpcsdSquads[npcbc.iSquadID].npcscMembers.insert(anpcpPlatoons[npcbc.iPlatoonID].anpcsdSquads[npcbc.iSquadID].npcscMembers.Length, 1);
		anpcpPlatoons[npcbc.iPlatoonID].anpcsdSquads[npcbc.iSquadID].npcscMembers[(anpcpPlatoons[npcbc.iPlatoonID].anpcsdSquads[npcbc.iSquadID].npcscMembers.Length - 1)] = npcbc;
		npcbc.npcaiccCombatController = Self;
	}
	if (npcbc.IsA("NPCNCOController"))
	{
		bOfficerAvailable = true;
	}
	*/
}

void ANPCAICombatController::AdjustNPCOrders(ANPCBaseSoldierController* npcbc, bool bImmediateOrder)
{
	//npcbc.DetermineBalanceOfPower();
}

bool ANPCAICombatController::ShouldActivateCombatAction(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	switch (npcbcReporter.sNextAICCAction)
	{
	case "":
	case "DoNothing":
	case "Ignore":
		return false;
	default:
		return true;
	}
	*/
	return false;    //FAKE  /ELiZ
}

void ANPCAICombatController::ProcessCombatAction(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	if (npcbcReporter.bDebugMode)
	{
		Log("ProcessCombatAction() entered for " $ string(npcbcReporter.Tag) $ " with requested action: " $ npcbcReporter.sNextAICCAction);
	}
	npcbcReporter.sLastCombatAction = npcbcReporter.sNextAICCAction;
	npcbcReporter.sNextAICCAction = "";
	if ((AGP_Pawn(npcbcReporter.Pawn) != None) && (AGP_Pawn(npcbcReporter.Pawn).MyDebug_ActionIcon != None))
	{
		AGP_Pawn(npcbcReporter.Pawn).MyDebug_ActionIcon.UpdateAction(npcbcReporter.sNextAICCAction);
	}
	switch (npcbcReporter.sLastCombatAction)
	{
	case "":
	case "DoNothing":
		return;
	case "Ignore":
		return;
	case "ScanForEnemy":
		npcbcReporter.AICCMessageScanForEnemy();
		break;
	case "EngageEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageEngageEnemy();
		break;
	case "SuppressEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageSuppressEnemy();
		break;
	case "ThrowFrag":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageThrowFrag();
		break;
	case "ThrowSmoke":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageThrowSmoke();
		break;
	case "Advance":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageAdvance();
		break;
	case "CrazyIvan":
		npcbcReporter.AICCMessageCrazyIvan();
		break;
	case "SwitchWeapons":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageSwitchWeapons();
		break;
	case "PursueEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessagePursueEnemy();
		break;
	case "FallBack":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageFallBack();
		break;
	case "FlankEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageFlankEnemy();
		break;
	case "RushEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageRushEnemy();
		break;
	case "TauntEnemy":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageTauntEnemy();
		break;
	case "SeekCover":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageSeekCover();
		break;
	case "RequestMortar":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageRequestMortar();
		break;
	case "DuckAndCover":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageDuckAndCover();
		break;
	case "Collapse":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageCollapse();
		break;
	case "Cower":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageCower();
		break;
	case "FireBlindly":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageFireBlindly();
		break;
	case "BreakOut":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageBreakOut();
		break;
	case "ReloadWeapon":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageReload();
		break;
	case "ShiftPosition":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCMessageShiftPosition();
		break;
	case "RunFromGrenade":
		TransitionToCombatOrders(npcbcReporter);
		npcbcReporter.AICCLiveGrenade();
		break;
	case "ReturnToPatrol":
		npcbcReporter.AICCReturnToPatrol();
		break;
	default:
	}
	*/
}

void ANPCAICombatController::TransitionToCombatOrders(ANPCBaseSoldierController* npcbsc)
{
	/*
	if (npcbsc.iNPCCurrentOrders == 0)
	{
		npcbsc.NPCLog("Transitioning to HUNT orders");
		npcbsc.ChangeOrders(3);
		return;
	}
	if (npcbsc.iNPCCurrentOrders == 1)
	{
		npcbsc.NPCLog("Transitioning to DEFEND orders");
		npcbsc.ChangeOrders(4);
		return;
	}
	if (npcbsc.iNPCCurrentOrders == 2)
	{
		npcbsc.NPCLog("Transitioning to HARASS orders");
		npcbsc.ChangeOrders(5);
		return;
	}
	*/
}

void ANPCAICombatController::DetermineDecisionOrderPercentEntryAction(ANPCBaseSoldierController* npcbcReporter, int32 iEventIndex)
{
	/*
	int32 iNodeIndex = 0;
	int32 iMentalStateIndex = 0;
	FString sCombatAction = "";
	if (npcbcReporter.IsInPain())
	{
		iMentalStateIndex = 0;
	}
	else
	{
		if (npcbcReporter.IsInPanic())
		{
			iMentalStateIndex = 1;
		}
		else
		{
			if (npcbcReporter.IsSuppressed())
			{
				iMentalStateIndex = 2;
			}
			else
			{
				if (npcbcReporter.IsConcerned())
				{
					iMentalStateIndex = 3;
				}
				else
				{
					if (npcbcReporter.IsNormal())
					{
						iMentalStateIndex = 4;
					}
					else
					{
						if (npcbcReporter.IsBrave())
						{
							iMentalStateIndex = 5;
						}
						else
						{
							if (npcbcReporter.IsReckless())
							{
								iMentalStateIndex = 6;
							}
						}
					}
				}
			}
		}
	}
	if (!npcbcReporter.IsInCover())
	{
		iNodeIndex = 2;
	}
	else
	{
		if ((npcbcReporter.IsInFiringNode() && (!npcbcReporter.IsInAlamoNode())) && npcbcReporter.bFindAlamoFirePosition)
		{
			iNodeIndex = 0;
		}
		else
		{
			if (npcbcReporter.IsInCover() || npcbcReporter.IsInAlamoNode())
			{
				iNodeIndex = 1;
			}
			else
			{
				npcbcReporter.sNextAICCAction = "DoNothing";
			}
		}
	}
	npcbcReporter.sNextAICCAction = DetermineCombatActionByState(npcbcReporter.iNPCCurrentOrders, iEventIndex, iNodeIndex, iMentalStateIndex, npcbcReporter.bDebugMode);
	if (npcbcReporter.bDebugMode)
	{
		Log("Combat action for event " $ string(iEventIndex) $ " is " $ sCombatAction);
	}
	*/
}

void ANPCAICombatController::ReportMentalStateChange(ANPCBaseSoldierController* npcbcReporter)
{
	//AdjustNPCOrders(npcbcReporter, false);
}

bool ANPCAICombatController::IsOfficerAlive()
{
	/*
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			if (((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader != None) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.Pawn != None)) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.Pawn.Health > 0))
			{
				return true;
			}
		}
	}
	*/
	return false;
}

bool ANPCAICombatController::IsNewContact(ANPCBaseController* npcbcReporter, APawn* pawnContact, bool bDebug)
{
	/*
	int32 iContact = 0;
	if (bDebug)
	{
		Log(string(Self) $ " Current contacts length: " $ string(aecEnemyContacts.Length));
	}
	for (iContact = 0; iContact < aecEnemyContacts.Length; iContact++)
	{
		if ((aecEnemyContacts[iContact].npcbcReporting == npcbcReporter) && (aecEnemyContacts[iContact].pawnEnemyContact == pawnContact))
		{
			if (bDebug)
			{
				Log(string(Self) $ " found existing contact entry for " $ string(npcbcReporter) $ " and " $ string(pawnContact));
			}
			return false;
		}
	}
	if (bDebug)
	{
		Log(string(Self) $ " contact NOT found for " $ string(npcbcReporter) $ " and " $ string(pawnContact));
	}
	*/
	return true;
}

bool ANPCAICombatController::IsLostContact(ANPCBaseController* npcbcReporter, APawn* pawnContact)
{
	/*
	int32 iContact = 0;
	for (iContact = 0; iContact < aecEnemyContacts.Length; iContact++)
	{
		if ((aecEnemyContacts[iContact].npcbcReporting == npcbcReporter) && (aecEnemyContacts[iContact].pawnEnemyContact == pawnContact))
		{
			return aecEnemyContacts[iContact].bContactLost;
		}
	}
	*/
	return false;
}

bool ANPCAICombatController::UpdateContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel)
{
	/*
	int32 iContact = 0;
	float fpRangeAccuracy = 0;
	for (iContact = 0; iContact < aecEnemyContacts.Length; iContact++)
	{
		if ((aecEnemyContacts[iContact].npcbcReporting == npcbcReporter) && (aecEnemyContacts[iContact].pawnEnemyContact == pawnContact))
		{
			aecEnemyContacts[iContact].fpTimeOfReport = Level.TimeSeconds;
			aecEnemyContacts[iContact].vLocation = npcbcReporter.Pawn.Location;
			aecEnemyContacts[iContact].rotRotation = npcbcReporter.Pawn.Rotation;
			aecEnemyContacts[iContact].bContactLost = false;
			fpRangeAccuracy = (npcbcReporter.fNPCExperience / 100);
			fpRangeAccuracy += 0.5;
			if (fpRangeAccuracy > 1)
			{
				fpRangeAccuracy = 1;
			}
			aecEnemyContacts[iContact].fpEstimatedRange = (VSize((aecEnemyContacts[iContact].pawnEnemyContact.Location - npcbcReporter.Pawn.Location)) * fpRangeAccuracy);
			return true;
		}
	}
	*/
	return false;
}

void ANPCAICombatController::DetermineLostContactAction(int32 iContactIndex)
{
}

void ANPCAICombatController::Timer()
{
	int32 iContact = 0;
	int32 iVehicle = 0;
	int32 iLiveVehicles = 0;
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	int32 iMember = 0;
	/*
	if (!bStarted)
	{
		return;
	}
	for (iContact = 0; iContact < aecEnemyContacts.Length; iContact++)
	{
		if ((aecEnemyContacts[iContact].pawnEnemyContact != None) && aecEnemyContacts[iContact].pawnEnemyContact.isDead())
		{
			aecEnemyContacts.remove(iContact, 1);
			iContact--;
		}
		else
		{
			if (aecEnemyContacts[iContact].bContactLost && ((Level.TimeSeconds - aecEnemyContacts[iContact].fpTimeOfReport) > float(20)))
			{
				aecEnemyContacts.remove(iContact, 1);
				iContact--;
			}
		}
	}
	iTotalCompanyMembers = 0;
	iTotalLiveMembers = 0;
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			iTotalCompanyMembers += anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length;
			iTotalLiveMembers += EvaluatePlatoonSquadMembers(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad]);
			if (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader != None)
			{
				ProcessIdleTimer(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader);
			}
			for (iMember = 0; iMember < anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length; iMember++)
			{
				ProcessIdleTimer(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember]);
			}
		}
	}
	for (iMember = 0; iMember < npcsdCommandos.npcscMembers.Length; iMember++)
	{
		ProcessIdleTimer(npcsdCommandos.npcscMembers[iMember]);
	}
	iTotalCompanyMembers += npcsdCommandos.npcscMembers.Length;
	iTotalLiveMembers += EvaluatePlatoonSquadMembers(npcsdCommandos);
	iCurrentTotalLiveMembers = iTotalLiveMembers;
	ProcessOrderQueue();
	ProcessFireMissions();
	ProcessInFlightFireMissions();
	if (bAllowAnarchy && (!IsOfficerAlive()))
	{
		EnterAnarchyState();
	}
	fpPercentCompanyAlive = (float(iTotalLiveMembers) / float(iTotalCompanyMembers));
	if ((bForceReinforcementsNow || ((((iTotalCompanyMembers > 0) && (fpPercentCompanyAlive <= 0.5)) && (iTotalLiveMembers < iMaxNPCsAtRespawn)) && (Level.TimeSeconds > fpTimeUntilNextReinforcements))) && (Level.TimeSeconds > 15))
	{
		DebugLog(DEBUG_AI, "NPC prepositioned Reinforcements wave " $ string(iReinforcementWave) $ " being activated, NPC strength currently: " $ string(fpPercentCompanyAlive) $ " next reinforcements at: " $ string(fpTimeUntilNextReinforcements));
		SpawnLevelReinforcements((++iReinforcementWave), iTotalLiveMembers);
		fpTimeUntilNextReinforcements = (Level.TimeSeconds + fpReinforcementDelayTime);
		for (iVehicle = 0; iVehicle < anpcbcVehicles.Length; iVehicle++)
		{
			if (((((NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).anpcbscVehicleSoldiers.Length == 0) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).anpcpsSquadPlayerStarts.Length > 0)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).Pawn != None)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).Pawn.Health > 0)) && (!NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).IsInState("UnloadSquad")))
			{
				NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).UnloadPassengers();
			}
		}
		bForceReinforcementsNow = false;
		return;
	}
	iLiveVehicles = 0;
	for (iVehicle = 0; iVehicle < anpcbcVehicles.Length; iVehicle++)
	{
		if (((NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]) != None) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).agpvVehicle != None)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).agpvVehicle.Health >= 0))
		{
			iLiveVehicles++;
		}
	}
	if ((iLiveVehicles <= iVehicleRespawnMinVehicleLevel) && (Level.TimeSeconds > fpTimeUntilNextVehicleReinforcements))
	{
		DebugLog(DEBUG_AI, "Spawning vehicle reinforcements, currently live: " $ string(iLiveVehicles) $ " at time: " $ string(Level.TimeSeconds));
		SpawnVehicleLevelReinforcements((++iVehicleReinforcementWave));
		fpTimeUntilNextVehicleReinforcements = (Level.TimeSeconds + fpReinforcementDelayTime);
	}
	if (((iTotalCompanyMembers > 0) && (fpPercentCompanyAlive > 0.1)) && (fpPercentCompanyAlive <= 0.15))
	{
		AddOrderToQueue(None, 6, 0);
	}
	else
	{
		if ((iTotalCompanyMembers > 0) && (fpPercentCompanyAlive < 0.05))
		{
			DebugLog(DEBUG_AI, "MIGHT SURRENDER - Total company members: " $ string(iTotalCompanyMembers) $ " alive: " $ string(iTotalLiveMembers) $ " percent: " $ string(fpPercentCompanyAlive));
			if (FRand() > 0.75)
			{
				DebugLog(DEBUG_AI, "WOULD SURRENDER - Total company members: " $ string(iTotalCompanyMembers) $ " alive: " $ string(iTotalLiveMembers) $ " percent: " $ string(fpPercentCompanyAlive));
				AddOrderToQueue(None, 7, 0);
			}
		}
	}
	*/
}

void ANPCAICombatController::SpawnLevelReinforcements(int32 iLevel, int32 iCurrentlyAlive)
{
	int32 iReserveIndex = 0;
	int32 iCoverOption = 0;
	int32 iObjectOption = 0;
	/*
	local NPCPlayerStart npcpsIterator;
	local NPCBaseSoldierController npcbscSpawned;
	local Actor aLocation;
	for (iReserveIndex = 0; iReserveIndex < arrRespawnInformation.Length; iReserveIndex++)
	{
		if (iCurrentlyAlive > iMaxNPCsAtRespawn)
		{
		}
		if (arrRespawnInformation[iReserveIndex].snpStart.IsA("NPCPlayerStartSoldier") && (arrRespawnInformation[iReserveIndex].iRespawnsLeft > 0))
		{
			npcpsIterator = NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart);
			if (npcpsIterator.bVehiclePassenger)
			{
			}
			if (NPCPlayerStartSoldier(npcpsIterator).iReinforcementWave != iLevel)
			{
			}
			npcbscSpawned = NPCBaseSoldierController(npcpsIterator.CreateNPC());
			if (npcbscSpawned != None)
			{
				iCurrentlyAlive++;
				arrRespawnInformation[iReserveIndex].iRespawnsLeft--;
				if (npcbscSpawned.IsA("NPCBaseSoldierController"))
				{
					if (NPCPlayerStartSoldier(npcpsIterator).epcReinforcementCommand == NPCPlayerStartSoldier(npcpsIterator).2)
					{
						aLocation = GetActorByTag(NPCPlayerStartSoldier(npcpsIterator).nameReinforcementHeadToObjectTag);
						if (aLocation != None)
						{
							npcbscSpawned.npcpnTravelLocation = npcbscSpawned.LocateClosestNodeToLocation(aLocation.Location);
							npcbscSpawned.Start();
							if (iObjectOption < 5)
							{
								npcbscSpawned.iHeadToLocationCoverOption = (5 - iObjectOption++);
							}
							else
							{
								npcbscSpawned.iHeadToLocationCoverOption = 0;
							}
							npcbscSpawned.AICCHeadToLocation(npcbscSpawned.npcpnTravelLocation.Location, npcbscSpawned.npcpnTravelLocation);
							return;
						}
						else
						{
							npcbscSpawned.Start();
							npcbscSpawned.AICCMessageSeekCover();
						}
					}
					else
					{
						if (NPCPlayerStartSoldier(npcpsIterator).epcReinforcementCommand == NPCPlayerStartSoldier(npcpsIterator).0)
						{
							npcbscSpawned.Start();
						}
						else
						{
							npcbscSpawned.Start();
							if (iObjectOption < 5)
							{
								npcbscSpawned.iHeadToLocationCoverOption = (5 - iCoverOption++);
							}
							else
							{
								npcbscSpawned.iHeadToLocationCoverOption = 0;
							}
							npcbscSpawned.npcpnTravelLocation = None;
							npcbscSpawned.HeadToObjective(0, true);
						}
					}
				}
			}
		}
	}
	*/
}

void ANPCAICombatController::SpawnTriggeredReinforcements(int32 iPlatoonID, int32 iSquadID, int32 iFireteamID, FString sCommand, FVector vLocation)
{
	int32 iReserveIndex = 0;
	int32 iVehicle = 0;
	int32 iSpawned = 0;
	/*
	local NPCPlayerStart npcpsIterator;
	local NPCBaseSoldierController npcbscSpawned;
	DebugLog(DEBUG_AI, string(Self) $ "SpawnTriggeredReinforcements entered for platoon " $ string(iPlatoonID) $ ", Squad: " $ string(iSquadID) $ ", Fireteam: " $ string(iFireteamID) $ ", command: " $ sCommand);
	for (iReserveIndex = 0; iReserveIndex < arrRespawnInformation.Length; iReserveIndex++)
	{
		if ((iSpawned + iCurrentTotalLiveMembers) > iMaxNPCsAtRespawn)
		{
			return;
		}
		if (arrRespawnInformation[iReserveIndex].snpStart.IsA("NPCPlayerStart"))
		{
			DebugLog(DEBUG_AI, "Examining NPC reserve for platoon " $ string(NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iPlatoonID) $ " Squad: " $ string(NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iSquadID) $ " Fireteam: " $ string(NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iFireteamID) $ " Respawns left: " $ string(arrRespawnInformation[iReserveIndex].iRespawnsLeft) $ " VehiclePassenger: " $ string(NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).bVehiclePassenger));
		}
		if (((((arrRespawnInformation[iReserveIndex].snpStart.IsA("NPCPlayerStart") && (arrRespawnInformation[iReserveIndex].iRespawnsLeft > 0)) && (NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iPlatoonID == iPlatoonID)) && (NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iSquadID == iSquadID)) && (NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).iFireteamID == iFireteamID)) && (!NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart).bVehiclePassenger))
		{
			npcpsIterator = NPCPlayerStart(arrRespawnInformation[iReserveIndex].snpStart);
			npcbscSpawned = NPCBaseSoldierController(npcpsIterator.CreateNPC());
			DebugLog(DEBUG_AI, "Spawned reserve NPC controller: " $ string(npcbscSpawned));
			if (npcbscSpawned != None)
			{
				iSpawned++;
				arrRespawnInformation[iReserveIndex].iRespawnsLeft--;
				switch (sCommand)
				{
				case "GotoObjective":
					npcbscSpawned.iHeadToLocationCoverOption = Rand(5);
					npcbscSpawned.HeadToObjective();
					break;
				case "FollowOrders":
					break;
				case "GotoTrigger":
					npcbscSpawned.iHeadToLocationCoverOption = Rand(5);
					npcbscSpawned.AICCHeadToLocation(vLocation, npcbscSpawned.LocateClosestNodeToLocation(vLocation));
					break;
				default:
				}
			}
		}
		if ((((arrRespawnInformation[iReserveIndex].snpStart.IsA("NPCVehicleStart") && (arrRespawnInformation[iReserveIndex].iRespawnsLeft > 0)) && (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).iPlatoonID == iPlatoonID)) && (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).iSquadID == iSquadID)) && (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).iFireteamID == iFireteamID))
		{
			if (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).CreateNPC() != None)
			{
				arrRespawnInformation[iReserveIndex].iRespawnsLeft--;
			}
		}
	}
	for (iVehicle = 0; iVehicle < anpcbcVehicles.Length; iVehicle++)
	{
		if (((((((((anpcbcVehicles[iVehicle] != None) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).anpcbscVehicleSoldiers.Length == 0)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).anpcpsSquadPlayerStarts.Length > 0)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).Pawn != None)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).Pawn.Health > 0)) && (!NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).IsInState("UnloadSquad"))) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).iPlatoonID == iPlatoonID)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).iSquadID == iSquadID)) && (NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).iFireteamID == iFireteamID))
		{
			NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).UnloadPassengers();
		}
	}
	*/
}

void ANPCAICombatController::SpawnVehicleLevelReinforcements(int32 iWaveLevel)
{
	/*
	int32 iReserveIndex = 0;
	DebugLog(DEBUG_AI, "Reinforcement wave: " $ string(iWaveLevel));
	for (iReserveIndex = 0; iReserveIndex < arrRespawnInformation.Length; iReserveIndex++)
	{
		if (arrRespawnInformation[iReserveIndex].snpStart.IsA("NPCVehicleStart"))
		{
			if (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).iReinforcementWave == iWaveLevel)
			{
				if (NPCVehicleStart(arrRespawnInformation[iReserveIndex].snpStart).CreateNPC() != None)
				{
					arrRespawnInformation[iReserveIndex].iRespawnsLeft--;
				}
			}
		}
	}
	*/
}

void ANPCAICombatController::EnterAnarchyState()
{
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	int32 iMember = 0;
	/*
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			for (iMember = 0; iMember < anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length; iMember++)
			{
				ReportNeedToEnterAnarchyState(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember]);
			}
		}
	}
	bInAnarchy = true;
	*/
}

void ANPCAICombatController::ProcessIdleTimer(ANPCBaseSoldierController* npcsc)
{
	/*
	if (npcsc == None)
	{
		return;
	}
	if (npcsc.fpTimeToEndLastInterrupt == 0)
	{
		npcsc.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
		return;
	}
	if (Level.TimeSeconds > npcsc.fpTimeToEndLastInterrupt)
	{
		ReportTimeElapsed(npcsc);
	}
	*/
}

void ANPCAICombatController::ProcessOrderQueue()
{
	int32 iOrder = 0;
	/*
	for (iOrder = 0; iOrder < oqOrdersWaitingDeployment.Length; iOrder++)
	{
		if (((oqOrdersWaitingDeployment[iOrder].bOrderForAll || (oqOrdersWaitingDeployment[iOrder].npcbc != None)) || (oqOrdersWaitingDeployment[iOrder].iSupportRequest != 0)) && (Level.TimeSeconds >= oqOrdersWaitingDeployment[iOrder].fpTimeToDeliver))
		{
			if ((oqOrdersWaitingDeployment[iOrder].iOrder == -1) && (oqOrdersWaitingDeployment[iOrder].iTacticalOrder == -1))
			{
				switch (oqOrdersWaitingDeployment[iOrder].sAICCCombatAction)
				{
				case "Advance":
					NPCBaseSoldierController(oqOrdersWaitingDeployment[iOrder].npcbc).Enemy = oqOrdersWaitingDeployment[iOrder].pawnTarget;
					NPCBaseSoldierController(oqOrdersWaitingDeployment[iOrder].npcbc).AICCMessageAdvance();
					break;
				case "EngageEnemy":
					NPCBaseSoldierController(oqOrdersWaitingDeployment[iOrder].npcbc).Enemy = oqOrdersWaitingDeployment[iOrder].pawnTarget;
					NPCBaseSoldierController(oqOrdersWaitingDeployment[iOrder].npcbc).AICCMessageEngageEnemy();
					break;
				case "SuppressiveFire":
					DebugLog(DEBUG_AI, "Suppressive fire being requested of soldier: " $ string(oqOrdersWaitingDeployment[iOrder].npcbc));
					NPCBaseSoldierController(oqOrdersWaitingDeployment[iOrder].npcbc).SuppressiveFireRequested(None, oqOrdersWaitingDeployment[iOrder].pawnTarget.Location);
					break;
				default:
				}
			}
			else
			{
				if (oqOrdersWaitingDeployment[iOrder].iSupportRequest > 0)
				{
					ProcessSupportRequest(oqOrdersWaitingDeployment[iOrder]);
				}
				else
				{
					if (oqOrdersWaitingDeployment[iOrder].bOrderForAll)
					{
						ProcessTeamOrder(oqOrdersWaitingDeployment[iOrder]);
					}
					else
					{
						ProcessSoldierOrder(oqOrdersWaitingDeployment[iOrder].npcbc, oqOrdersWaitingDeployment[iOrder]);
					}
				}
			}
			oqOrdersWaitingDeployment.remove(iOrder, 1);
			iOrder--;
		}
	}
	*/
}

void ANPCAICombatController::ProcessSupportRequest(FOrderQueue oqEntry)
{
	/*
	float fpSkill = 0;
	if (oqEntry.npcbc != None)
	{
		fpSkill = oqEntry.npcbc.fpMortarRequestSkill;
	}
	else
	{
		fpSkill = 0.75;
	}
	AddFireMissionRequestToQueue(NPCBaseSoldierController(oqEntry.npcbc), oqEntry.iSupportRequest, fpSkill, oqEntry.vSupportArea, oqEntry.bSmokeMission);
	*/
}

void ANPCAICombatController::ProcessTeamOrder(FOrderQueue oqEntry)
{
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	int32 iMember = 0;
	/*
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			for (iMember = 0; iMember < anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length; iMember++)
			{
				if ((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember] != None) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].Pawn != None))
				{
					if (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].Pawn.Health > 0)
					{
						ProcessSoldierOrder(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember], oqEntry);
					}
				}
			}
		}
	}
	for (iMember = 0; iMember < npcsdCommandos.npcscMembers.Length; iMember++)
	{
		ProcessSoldierOrder(npcsdCommandos.npcscMembers[iMember], oqEntry);
	}
	*/
}

void ANPCAICombatController::ProcessSoldierOrder(ANPCBaseController* npbc, FOrderQueue oqEntry)
{
	//IssueOrder(npbc, oqEntry.iOrder);
}

void ANPCAICombatController::AddOrderToQueue(ANPCBaseController* npcbc, int32 iOrderCommand, int32 iTacticalOrder, FString sCombatAction, APawn* pawnTarget)
{
	/*
	int32 iOrder = 0;
	float fpLastOrderTime = 0;
	if ((iOrderCommand != -1) && (iTacticalOrder != -1))
	{
		oqOrdersWaitingDeployment.insert(oqOrdersWaitingDeployment.Length, 1);
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].npcbc = npcbc;
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].iOrder = iOrderCommand;
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].iTacticalOrder = iTacticalOrder;
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].sAICCCombatAction = sCombatAction;
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].pawnTarget = pawnTarget;
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver = (Level.TimeSeconds + (FRand() * 2));
		return;
	}
	for (iOrder = 0; iOrder < oqOrdersWaitingDeployment.Length; iOrder++)
	{
		if (((oqOrdersWaitingDeployment[iOrder].npcbc == npcbc) && (oqOrdersWaitingDeployment[iOrder].iOrder == iOrderCommand)) && (oqOrdersWaitingDeployment[iOrder].iTacticalOrder == iTacticalOrder))
		{
			return;
		}
	}
	if (oqOrdersWaitingDeployment.Length >= 1)
	{
		fpLastOrderTime = oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver;
	}
	else
	{
		fpLastOrderTime = Level.TimeSeconds;
	}
	oqOrdersWaitingDeployment.insert(oqOrdersWaitingDeployment.Length, 1);
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].npcbc = npcbc;
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].iOrder = iOrderCommand;
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].iTacticalOrder = iTacticalOrder;
	if (npcbc == None)
	{
		oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].bOrderForAll = true;
	}
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver = (fpLastOrderTime + (FRand() * float(10)));
	*/
}

bool ANPCAICombatController::AddSupportRequestToQueue(ANPCBaseSoldierController* npcbscReporter, int32 iSupportRequest, FVector vSupportLocation, APawn* pawnTarget, bool bSmokeMission)
{
	int32 iOrder = 0;
	/*
	float fpLastOrderTime = 0;
	if (iSupportRequest == 0)
	{
		return false;
	}
	if ((iSupportRequest == 1) && (iAvailableMortarAttacks == 0))
	{
		DebugLog(DEBUG_Warn, string(Self) $ "AddSupportRequestToQueue() - WARNING - mortar request but out of mortars");
		return false;
	}
	for (iOrder = 0; iOrder < oqOrdersWaitingDeployment.Length; iOrder++)
	{
		if ((Abs(VSize((oqOrdersWaitingDeployment[iOrder].vSupportArea - vSupportLocation))) < float(512)) && (oqOrdersWaitingDeployment[iOrder].iSupportRequest == iSupportRequest))
		{
			return false;
		}
	}
	if (oqOrdersWaitingDeployment.Length >= 1)
	{
		fpLastOrderTime = oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver;
	}
	else
	{
		fpLastOrderTime = Level.TimeSeconds;
	}
	oqOrdersWaitingDeployment.insert(oqOrdersWaitingDeployment.Length, 1);
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].iSupportRequest = iSupportRequest;
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].vSupportArea = vSupportLocation;
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].npcbc = npcbscReporter;
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].bSmokeMission = bSmokeMission;
	if (iSupportRequest == 1)
	{
		if (npcbscReporter.IsA("NPCMortarSpotterController"))
		{
			NPCMortarSpotterController(npcbscReporter).AddFireMissionRequest(vSupportLocation, pawnTarget);
		}
	}
	oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver = (Level.TimeSeconds + (FRand() * float(10)));
	DebugLog(DEBUG_AIMortar, string(Self) $ "AddSuportRequestToQueue() - order queue now has " $ string(oqOrdersWaitingDeployment.Length) $ " orders in it, order delivery at: " $ string(oqOrdersWaitingDeployment[(oqOrdersWaitingDeployment.Length - 1)].fpTimeToDeliver));
	*/
	return true;
}

float ANPCAICombatController::LookupMortarFlightTime(float fpDistanceToTargetMeters)
{
	/*
	int32 iMortarLookup = 0;
	if (fpDistanceToTargetMeters < amrtMortarData[0].fpMin)
	{
		DebugLog(DEBUG_AIMortar, "Mortar Using minimum range/time for too close a target");
		fpDistanceToTargetMeters = amrtMortarData[0].fpMin;
	}
	for (iMortarLookup = 0; iMortarLookup < amrtMortarData.Length; iMortarLookup++)
	{
		if ((fpDistanceToTargetMeters >= amrtMortarData[iMortarLookup].fpMin) && (fpDistanceToTargetMeters <= amrtMortarData[iMortarLookup].fpMax))
		{
			DebugLog(DEBUG_AIMortar, "Mortar found using entry with flight time: " $ string(amrtMortarData[iMortarLookup].fpMin) $ " and max: " $ string(amrtMortarData[iMortarLookup].fpMax) $ " flight time: " $ string(amrtMortarData[iMortarLookup].fpFlightTime));
			return amrtMortarData[iMortarLookup].fpFlightTime;
		}
	}
	return amrtMortarData[0].fpFlightTime;
	*/
	return 0;   //FAKE   /ELiZ
}

void ANPCAICombatController::ProcessFireMissions()
{
	/*
	int32 iFireMission = 0;
	local Actor actMortarLaunchSound;
	local Sound sndMortar;
	float fpDistanceToTargetMeters = 0;
	for (iFireMission = 0; iFireMission < asfrqFireMissions.Length; iFireMission++)
	{
		if (((Level.TimeSeconds >= asfrqFireMissions[iFireMission].fpTimeToFire) && (asfrqFireMissions[iFireMission].fpTimeToFire != 0)) || ((Level.TimeSeconds >= asfrqFireMissions[iFireMission].fpTimeToSpawn) && (asfrqFireMissions[iFireMission].fpTimeToSpawn != 0)))
		{
			switch (asfrqFireMissions[iFireMission].iSupportType)
			{
			case 1:
				if (iAvailableMortarAttacks > 0)
				{
					if (asfrqFireMissions[iFireMission].fpTimeToFire > 0)
					{
						DebugLog(DEBUG_AIMortar, string(Self) $ " Mortar Request rounds: " $ string(iAvailableMortarAttacks) $ ", playing launch sound for mission: " $ string(iFireMission));
						sndMortar = Sound'S_AAO_Armory.60mm_Mortar.s_arm_mortar_tube_firing';
						actMortarLaunchSound = Spawn(Class'EffectLocation', , , Location);
						actMortarLaunchSound.LifeSpan = GetSoundDuration(sndMortar);
						actMortarLaunchSound.PlaySound(sndMortar, 0, 1, false, 5000, , true);
						fpDistanceToTargetMeters = (VSize((Location - asfrqFireMissions[iFireMission].vTargetArea)) / float(50));
						afmifActiveRounds.insert(0, 1);
						afmifActiveRounds[0].vTargetArea = asfrqFireMissions[iFireMission].vTargetArea;
						afmifActiveRounds[0].fpSkill = asfrqFireMissions[iFireMission].fpSkillLevel;
						if (asfrqFireMissions[iFireMission].npcbscSpotter != None)
						{
							afmifActiveRounds[0].pawnSpotter = asfrqFireMissions[iFireMission].npcbscSpotter.Pawn;
						}
						afmifActiveRounds[0].bSmokeMission = asfrqFireMissions[iFireMission].bSmokeMission;
						DebugLog(DEBUG_AIMortar, "Mortar distance to target in meter: " $ string(fpDistanceToTargetMeters));
						afmifActiveRounds[0].fpSpawnTime = (Level.TimeSeconds + LookupMortarFlightTime(fpDistanceToTargetMeters));
						iAvailableMortarAttacks--;
						asfrqFireMissions[iFireMission].iRoundsToFire--;
						if ((asfrqFireMissions[iFireMission].npcbscSpotter != None) && asfrqFireMissions[iFireMission].npcbscSpotter.IsA("NPCMortarSpotterController"))
						{
							NPCMortarSpotterController(asfrqFireMissions[iFireMission].npcbscSpotter).FireMissionInProgress(asfrqFireMissions[iFireMission].vTargetArea);
						}
						DebugLog(DEBUG_AIMortar, string(Self) $ " Mortar Request rounds: " $ string(iAvailableMortarAttacks) $ ", generating mortar round in flight for mission: " $ string(iFireMission));
						asfrqFireMissions[iFireMission].fpTimeToFire = (((Level.TimeSeconds + (1.5 * (1 - (fpMortarCrewSkill / 100)))) + (FRand() * 1)) + 1.5);
						if ((asfrqFireMissions[iFireMission].iRoundsToFire <= 0) || (iAvailableMortarAttacks <= 0))
						{
							DebugLog(DEBUG_AIMortar, string(Self) $ " Mortar Fire mission complete, removing: " $ string(iFireMission));
							if ((asfrqFireMissions[iFireMission].npcbscSpotter != None) && asfrqFireMissions[iFireMission].npcbscSpotter.IsA("NPCMortarSpotterController"))
							{
								NPCMortarSpotterController(asfrqFireMissions[iFireMission].npcbscSpotter).FireMissionComplete(asfrqFireMissions[iFireMission].vTargetArea);
							}
							asfrqFireMissions.remove(iFireMission, 1);
							iFireMission--;
						}
					}
					break;
				}
				asfrqFireMissions.remove(iFireMission, 1);
				iFireMission--;
			}
	default:
		}
	}
	*/
}

void ANPCAICombatController::ProcessInFlightFireMissions()
{
	/*
	int32 iRound = 0;
	FVector vTarget = FVector(0, 0, 0);
	local BaseProjectile bpMortarRound;
	if (bpMortarRoundClass == None)
	{
		bpMortarRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_60mmMortar", Class'Class'));
	}
	if (bpMortarSmokeRoundClass == None)
	{
		bpMortarSmokeRoundClass = class<BaseProjectile>(DynamicLoadObject("AGP_Inventory.Proj_60mmSmokeMortar", Class'Class'));
	}
	for (iRound = 0; iRound < afmifActiveRounds.Length; iRound++)
	{
		if (Level.TimeSeconds < afmifActiveRounds[iRound].fpSpawnTime)
		{
		}
		vTarget = afmifActiveRounds[iRound].vTargetArea;
		if (FRand() >= 0.5)
		{
			vTarget.X += ((1 - (afmifActiveRounds[iRound].fpSkill / 100)) * (float(50) + (FRand() * float(3750))));
		}
		else
		{
			vTarget.X -= ((1 - (afmifActiveRounds[iRound].fpSkill / 100)) * (float(50) + (FRand() * float(3750))));
		}
		if (FRand() >= 0.5)
		{
			vTarget.Y += ((1 - (afmifActiveRounds[iRound].fpSkill / 100)) * (float(50) + (FRand() * float(3750))));
		}
		else
		{
			vTarget.Y -= ((1 - (afmifActiveRounds[iRound].fpSkill / 100)) * (float(50) + (FRand() * float(3750))));
		}
		vTarget.Z += float(1500);
		DebugLog(DEBUG_AIMortar, "Spawning mortar round at " $ string(vTarget));
		if (afmifActiveRounds[iRound].bSmokeMission)
		{
			bpMortarRound = Spawn(bpMortarSmokeRoundClass, afmifActiveRounds[iRound].pawnSpotter, , vTarget, , true);
		}
		else
		{
			bpMortarRound = Spawn(bpMortarRoundClass, afmifActiveRounds[iRound].pawnSpotter, , vTarget, , true);
		}
		DebugLog(DEBUG_AIMortar, "Spawned mortar: " $ string(bpMortarRound) $ " instigated by " $ string(afmifActiveRounds[iRound].pawnSpotter));
		afmifActiveRounds.remove(iRound, 1);
		return;
	}
	*/
}

void ANPCAICombatController::AddFireMissionRequestToQueue(ANPCBaseSoldierController* npcbscSpotter, int32 iSupportType, float fpSkillLevel, FVector vTargetArea, bool bSmokeMission)
{
	/*
	if ((iSupportType == 1) && (iAvailableMortarAttacks <= 0))
	{
		return;
	}
	asfrqFireMissions.insert(asfrqFireMissions.Length, 1);
	asfrqFireMissions[(asfrqFireMissions.Length - 1)].npcbscSpotter = npcbscSpotter;
	asfrqFireMissions[(asfrqFireMissions.Length - 1)].iSupportType = iSupportType;
	asfrqFireMissions[(asfrqFireMissions.Length - 1)].vTargetArea = vTargetArea;
	asfrqFireMissions[(asfrqFireMissions.Length - 1)].fpSkillLevel = fpSkillLevel;
	asfrqFireMissions[(asfrqFireMissions.Length - 1)].bSmokeMission = bSmokeMission;
	switch (iSupportType)
	{
	case 1:
		asfrqFireMissions[(asfrqFireMissions.Length - 1)].iRoundsToFire = 8;
		asfrqFireMissions[(asfrqFireMissions.Length - 1)].fpTimeToFire = ((Level.TimeSeconds + ((1 - (fpMortarCrewSkill / 100)) * (FRand() * float(20)))) + 10);
		asfrqFireMissions[(asfrqFireMissions.Length - 1)].fpTimeToSpawn = 0;
		DebugLog(DEBUG_AIMortar, string(Self) $ "AddFireMissionRequesttoQueue() firing time set to: " $ string(asfrqFireMissions[(asfrqFireMissions.Length - 1)].fpTimeToFire) $ " instigator: " $ string(asfrqFireMissions[(asfrqFireMissions.Length - 1)].npcbscSpotter));
		break;
	default:
	}
	*/
}

int32 ANPCAICombatController::EvaluatePlatoonSquadMembers(FNPCSquadDetails npcsd)
{
	int32 iMember = 0;
	int32 iLiveMembers = 0;
	/*
	if (npcsd.bSquadDead)
	{
		return 0;
	}
	for (iMember = 0; iMember < npcsd.npcscMembers.Length; iMember++)
	{
		if ((npcsd.npcscMembers[iMember] != None) && (npcsd.npcscMembers[iMember].Pawn != None))
		{
			if (npcsd.npcscMembers[iMember].Pawn.Health > 0)
			{
				iLiveMembers++;
				if (npcsd.npcscMembers[iMember].Pawn.Health < 25)
				{
					IssueOrder(npcsd.npcscMembers[iMember], 6);
				}
			}
		}
	}
	if (iLiveMembers == 0)
	{
		npcsd.bSquadDead = true;
	}
	*/
	return iLiveMembers;
}

void ANPCAICombatController::IssueOrder(ANPCBaseController* npcbc, int32 iNewOrder)
{
	/*
	if (npcbc == None)
	{
		return;
	}
	switch (iNewOrder)
	{
	case 3:
		npcbc.ChangeOrders(npcbc.3);
		break;
	case 4:
		npcbc.ChangeOrders(npcbc.4);
		break;
	case 5:
		npcbc.ChangeOrders(npcbc.5);
		break;
	case 6:
		NPCBaseSoldierController(npcbc).AICCMessageFallBack();
		break;
	case 7:
		DebugLog(DEBUG_AI, "NPC " $ string(npcbc) $ " changing orders to surrender");
		npcbc.ChangeOrders(npcbc.7);
		NPCBaseSoldierController(npcbc).AICCMessageSurrender();
		break;
	case 8:
		break;
	default:
	}
	*/
}

float ANPCAICombatController::GetLeadershipBonus(ANPCBaseSoldierController* npcbsc)
{
	int32 iPlatoon = 0;
	int32 iSquad = 0;
	int32 iMember = 0;
	float fpGruntBonus = 0;
	float fpOfficerBonus = 0;
	/*
	for (iPlatoon = 0; iPlatoon < 8; iPlatoon++)
	{
		for (iSquad = 0; iSquad < 8; iSquad++)
		{
			if ((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader != None) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.Pawn != None))
			{
				if (Abs(VSize((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.Pawn.Location - npcbsc.Pawn.Location))) < float(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.iNPCLeadershipMentalStateRange))
				{
					if (float(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.iNPCLeadershipMentalStateBonus) > fpOfficerBonus)
					{
						fpOfficerBonus = float(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcncoLeader.iNPCLeadershipMentalStateBonus);
					}
				}
			}
			if (fpGruntBonus == 0)
			{
				for (iMember = 0; iMember < anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers.Length; iMember++)
				{
					if (((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember] != npcbsc) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember] != None)) && (anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].Pawn != None))
					{
						if (Abs(VSize((anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].Pawn.Location - npcbsc.Pawn.Location))) < float(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].iNPCLeadershipMentalStateRange))
						{
							fpGruntBonus = float(anpcpPlatoons[iPlatoon].anpcsdSquads[iSquad].npcscMembers[iMember].iNPCLeadershipMentalStateBonus);
						}
					}
				}
			}
		}
	}
	*/
	return (fpOfficerBonus + fpGruntBonus);
}

float ANPCAICombatController::GetThreatAnalysisForTeam(ANPCBaseSoldierController* npcbsc)
{
	int32 iThreatLevel = 0;
	int32 iMember = 0;
	/*
	if (npcbsc.IsA("NPCCommandoController"))
	{
		for (iMember = 0; iMember < npcsdCommandos.npcscMembers.Length; iMember++)
		{
			if ((npcsdCommandos.npcscMembers[iMember] != None) && (npcsdCommandos.npcscMembers[iMember].Pawn != None))
			{
				if (npcsdCommandos.npcscMembers[iMember] == npcbsc)
				{
					iThreatLevel += int(npcbsc.EvaluateEnemyThreat(npcbsc.Pawn));
				}
				else
				{
					if (Abs(VSize((npcsdCommandos.npcscMembers[iMember].Pawn.Location - npcbsc.Pawn.Location))) < float(1000))
					{
						iThreatLevel += int(npcbsc.EvaluateEnemyThreat(npcsdCommandos.npcscMembers[iMember].Pawn));
					}
				}
			}
		}
	}
	else
	{
		if ((anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcncoLeader != None) && (anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcncoLeader.Pawn != None))
		{
			iThreatLevel += int(npcbsc.EvaluateEnemyThreat(anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcncoLeader.Pawn));
		}
		for (iMember = 0; iMember < anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers.Length; iMember++)
		{
			if ((anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers[iMember] != None) && (anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers[iMember].Pawn != None))
			{
				if (npcbsc == anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers[iMember])
				{
					iThreatLevel += int(npcbsc.EvaluateEnemyThreat(npcbsc.Pawn));
				}
				else
				{
					if (Abs(VSize((npcbsc.Pawn.Location - anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers[iMember].Pawn.Location))) < float(1000))
					{
						iThreatLevel += int(npcbsc.EvaluateEnemyThreat(anpcpPlatoons[npcbsc.iPlatoonID].anpcsdSquads[npcbsc.iSquadID].npcscMembers[iMember].Pawn));
					}
				}
			}
		}
	}
	return float(iThreatLevel);
	*/

	return 0;      //FAKE   /ELiZ
}

int32 ANPCAICombatController::GetOrderForNPC(ANPCBaseController* npcbc)
{
	return 0;
}

void ANPCAICombatController::ForceOrderPercent(AHumanController* hcRequesting, FString sOrderName)
{
}

bool ANPCAICombatController::ReportActionFailed(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, npcbcReporter.iLastInterruptEventPriority);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportActionComplete(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	if (npcbcReporter.bDebugMode)
	{
		Log("Action " $ npcbcReporter.sLastCombatAction $ " complete");
	}
	npcbcReporter.iLastInterrupt = 0;
	npcbcReporter.iLastInterruptEventPriority = 0;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 14);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportTimeElapsed(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	if (npcbcReporter.IsInState("Targeting") && (npcbcReporter.Enemy != None))
	{
		npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
		return false;
	}
	npcbcReporter.iLastInterrupt = 0;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	npcbcReporter.iLastInterruptEventPriority = 0;
	if (((npcbcReporter.iNPCCurrentOrders == 0) || (npcbcReporter.iNPCCurrentOrders == 1)) || (npcbcReporter.iNPCCurrentOrders == 2))
	{
		PlayEventAudio(npcbcReporter);
	}
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 0);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportLostContact(ANPCBaseController* npcbcReporter, APawn* pawnContact)
{
	int32 iContact = 0;
	/*
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 2;
	iContact = 0;
	if (iContact < aecEnemyContacts.Length)
	{
		if ((aecEnemyContacts[iContact].npcbcReporting == npcbcReporter) && (aecEnemyContacts[iContact].pawnEnemyContact == pawnContact))
		{
			aecEnemyContacts[iContact].bContactLost = true;
		}
		else
		{
			iContact++;
		}
	}
	if ((((NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 2) && (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority != 5)) && (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority != 6)) && (NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt > Level.TimeSeconds))
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ "ReportLostContact() - event is lower than last interrupt" $ asEvents[NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority]);
		}
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 2;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 2);
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportWounded(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel)
{
	/*
	if (npcbcReporter.Pawn.Health <= 0)
	{
		bOfficerAvailable = IsOfficerAlive();
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 9;
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 9;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	AdjustNPCOrders(NPCBaseSoldierController(npcbcReporter), true);
	ReportUnderFireSquadAlert(NPCBaseSoldierController(npcbcReporter), pawnContact);
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 9);
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportKilledEnemy(ANPCBaseSoldierController* npcbcReporter, APawn* pawnContact)
{
	int32 iContact = 0;
	/*
	npcbcReporter.iLastInterrupt = 3;
	for (iContact = 0; iContact < aecEnemyContacts.Length; iContact++)
	{
		if (aecEnemyContacts[iContact].pawnEnemyContact == pawnContact)
		{
			aecEnemyContacts.remove(iContact, 1);
			iContact--;
		}
	}
	if (npcbcReporter.iLastInterruptEventPriority > 3)
	{
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 3;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 3);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportFriendDied(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	npcbcReporter.iLastInterrupt = 4;
	if (npcbcReporter.iLastInterruptEventPriority > 4)
	{
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 4;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 4);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel)
{
	int32 iNewIndex = 0;
	float fpRangeInaccuracy = 0;
	/*
	local Controller ctrlrIterator;
	if (((pawnContact == None) || (npcbcReporter == None)) || (npcbcReporter.Pawn == None))
	{
		return false;
	}
	if (pawnContact.IsA("Vehicle"))
	{
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 5;
	if (npcbcReporter.bDebugMode)
	{
		Log(string(Self) $ ".ReportContact() Contact report by " $ string(npcbcReporter.Tag) $ " of APawn* " $ string(pawnContact));
	}
	if (!IsNewContact(npcbcReporter, pawnContact))
	{
		if (IsLostContact(npcbcReporter, pawnContact))
		{
			UpdateContact(npcbcReporter, iContactType, pawnContact, iThreatLevel);
			if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 5)
			{
				if (npcbcReporter.bDebugMode)
				{
					Log(string(Self) $ ".ReportContact() contact is lower interrupt than last event: " $ asEvents[NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority]);
				}
				return false;
			}
			NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 5;
			NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
			if (npcbcReporter.bDebugMode)
			{
				Log(string(Self) $ ".ReportContact() contact is generating combat action request ");
			}
			DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 5);
			if ((((NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Surrender") && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Cower")) && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Collapse")) && (VSize((pawnContact.Location - npcbcReporter.Pawn.Location)) < float(500)))
			{
				if (npcbcReporter.bDebugMode)
				{
					Log(string(Self) $ "ReportContact() - overriding combat action of \"" $ NPCBaseSoldierController(npcbcReporter).sNextAICCAction $ "\" with EngageEnemy due to range");
				}
				NPCBaseSoldierController(npcbcReporter).sNextAICCAction = "EngageEnemy";
			}
			return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
		}
		UpdateContact(npcbcReporter, iContactType, pawnContact, iThreatLevel);
		if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority != 5)
		{
			NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
			if (NPCBaseSoldierController(npcbcReporter).Enemy != pawnContact)
			{
				DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 5);
			}
			return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
		}
		return false;
	}
	iNewIndex = aecEnemyContacts.Length;
	aecEnemyContacts.insert(aecEnemyContacts.Length, 1);
	aecEnemyContacts[iNewIndex].npcbcReporting = npcbcReporter;
	aecEnemyContacts[iNewIndex].pawnEnemyContact = pawnContact;
	aecEnemyContacts[iNewIndex].iContactType = iContactType;
	aecEnemyContacts[iNewIndex].vLocation = npcbcReporter.Pawn.Location;
	aecEnemyContacts[iNewIndex].rotRotation = npcbcReporter.Pawn.Rotation;
	fpRangeInaccuracy = (20 - ((npcbcReporter.fNPCExperience / 100) * 20));
	if (FRand() > 0.5)
	{
		(fpRangeInaccuracy *= float(-1));
	}
	if (npcbcReporter.bDebugMode)
	{
		Log("Target report's inaccuracy based on experience of " $ string(npcbcReporter.fNPCExperience) $ " is " $ string(fpRangeInaccuracy));
		Log("Target actual distance: " $ string(VSize((pawnContact.Location - npcbcReporter.Pawn.Location))));
	}
	aecEnemyContacts[iNewIndex].fpEstimatedRange = (VSize((pawnContact.Location - npcbcReporter.Pawn.Location)) + fpRangeInaccuracy);
	if (npcbcReporter.bDebugMode)
	{
		Log("Target reported from " $ string(npcbcReporter.Pawn.Location) $ " bearing " $ string(((float(npcbcReporter.Pawn.Rotation.Yaw) / 65535) * 360)) $ ", range " $ string((aecEnemyContacts[iNewIndex].fpEstimatedRange / 50)) $ " meters");
	}
	AdjustNPCOrders(NPCBaseSoldierController(npcbcReporter), false);
	if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 5)
	{
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 5;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 5);
	if ((((NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Surrender") && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Cower")) && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Collapse")) && (VSize((pawnContact.Location - npcbcReporter.Pawn.Location)) < float(500)))
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ "ReportContact() - overriding combat action of \"" $ NPCBaseSoldierController(npcbcReporter).sNextAICCAction $ "\" with EngageEnemy due to range");
		}
		NPCBaseSoldierController(npcbcReporter).sNextAICCAction = "EngageEnemy";
	}
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	ctrlrIterator = Level.ControllerList;
	if (ctrlrIterator != None)
	{
		if (ctrlrIterator == npcbcReporter)
		{
		}
		if (((ctrlrIterator.IsA("NPCBaseSoldierController") && (!ctrlrIterator.IsInState("Targeting"))) && (NPCBaseSoldierController(ctrlrIterator).iNPCCurrentOrders != 2)) && (NPCBaseSoldierController(ctrlrIterator).Pawn != None))
		{
			if (NPCBaseSoldierController(ctrlrIterator).LineOfSightTo(pawnContact))
			{
				AddOrderToQueue(NPCBaseSoldierController(ctrlrIterator), -1, -1, "EngageEnemy", pawnContact);
			}
			else
			{
				if (VSize((NPCBaseSoldierController(ctrlrIterator).Pawn.Location - npcbcReporter.Location)) < float(1500))
				{
					AddOrderToQueue(NPCBaseSoldierController(ctrlrIterator), -1, -1, "Advance", pawnContact);
				}
			}
		}
		ctrlrIterator = ctrlrIterator.nextController;
	}
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportHeardNoise(ANPCBaseController* npcbcReporter, FVector vLocation)
{
	/*
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 1;
	AdjustNPCOrders(NPCBaseSoldierController(npcbcReporter), false);
	if (npcbcReporter.bDebugMode)
	{
		Log("ReportHeardNoise entered, last interrupt: " $ string(NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority));
	}
	if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 1)
	{
		if (npcbcReporter.bDebugMode)
		{
			Log("ReportHeardNoise entered but is lower interrupt than current event: " $ asEvents[NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority]);
		}
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 1;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 1);
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportHeardGunfire(ANPCBaseController* npcbcReporter, FVector vLocation)
{
	/*
	local AGP_Pawn agppIterator;
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 6;
	AdjustNPCOrders(NPCBaseSoldierController(npcbcReporter), false);
	if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 6)
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ "ReportHeardGunfire() - event is lower than last interrupt" $ asEvents[NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority]);
		}
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 6;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	ForEach RadiusActors(class'AGP.AGP_Pawn', agppIterator, 550, vLocation)
	{
		if (HumanController(agppIterator.Controller) != None)
		{
			ReportUnderFireSquadAlert(NPCBaseSoldierController(npcbcReporter), agppIterator);
		}
		else
		{
		}
	}
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 6);
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportVehicleContact(ANPCBaseController* npcbcReporter, int32 iContactType, APawn* pawnContact, int32 iThreatLevel)
{
	int32 iNewIndex = 0;
	int32 iVehicle = 0;
	float fpRangeInaccuracy = 0;
	/*
	if (((pawnContact == None) || (npcbcReporter == None)) || (npcbcReporter.Pawn == None))
	{
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterrupt = 7;
	if (npcbcReporter.bDebugMode)
	{
		Log(string(Self) $ ".ReportVehicleContact() Contact report by " $ string(npcbcReporter.Tag) $ " of APawn* " $ string(pawnContact));
	}
	if (!IsNewContact(npcbcReporter, pawnContact))
	{
		if (IsLostContact(npcbcReporter, pawnContact))
		{
			if (npcbcReporter.bDebugMode)
			{
				Log(string(Self) $ ".ReportVehicleContact() Lost contact reacquiring report by " $ string(npcbcReporter.Tag) $ " of APawn* " $ string(pawnContact));
			}
			UpdateContact(npcbcReporter, iContactType, pawnContact, iThreatLevel);
			for (iVehicle = 0; iVehicle < anpcbcVehicles.Length; iVehicle++)
			{
				NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).NotifyEnemyVehicleSpotted(pawnContact.Location);
			}
			if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 7)
			{
				if (npcbcReporter.bDebugMode)
				{
					Log(string(Self) $ ".ReportVehicleContact() contact is lower interrupt than last event: " $ asEvents[NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority]);
				}
				return false;
			}
			NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 7;
			NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
			if (npcbcReporter.bDebugMode)
			{
				Log(string(Self) $ ".ReportVehicleContact() contact is generating combat action request ");
			}
			DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 7);
			return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
		}
		UpdateContact(npcbcReporter, iContactType, pawnContact, iThreatLevel);
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ ".ReportVehicleContact() updating existing active contact.");
		}
		if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority != 7)
		{
			NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
			if (NPCBaseSoldierController(npcbcReporter).Enemy != pawnContact)
			{
				DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 7);
			}
			return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
		}
		return false;
	}
	if (npcbcReporter.bDebugMode)
	{
		Log(string(Self) $ ".ReportVehicleContact() New contact report by " $ string(npcbcReporter.Tag) $ " of APawn* " $ string(pawnContact));
	}
	for (iVehicle = 0; iVehicle < anpcbcVehicles.Length; iVehicle++)
	{
		if (anpcbcVehicles[iVehicle] != None)
		{
			NPCBasePreCrewedVehicleController(anpcbcVehicles[iVehicle]).NotifyEnemyVehicleSpotted(pawnContact.Location);
		}
	}
	iNewIndex = aecEnemyContacts.Length;
	aecEnemyContacts.insert(aecEnemyContacts.Length, 1);
	aecEnemyContacts[iNewIndex].npcbcReporting = npcbcReporter;
	aecEnemyContacts[iNewIndex].pawnEnemyContact = pawnContact;
	aecEnemyContacts[iNewIndex].iContactType = iContactType;
	aecEnemyContacts[iNewIndex].vLocation = npcbcReporter.Pawn.Location;
	aecEnemyContacts[iNewIndex].rotRotation = npcbcReporter.Pawn.Rotation;
	fpRangeInaccuracy = (20 - ((npcbcReporter.fNPCExperience / 100) * 20));
	if (FRand() > 0.5)
	{
		fpRangeInaccuracy *= float(-1);
	}
	if (npcbcReporter.bDebugMode)
	{
		Log("Target report's inaccuracy based on experience of " $ string(npcbcReporter.fNPCExperience) $ " is " $ string(fpRangeInaccuracy));
		Log("Target actual distance: " $ string(VSize((pawnContact.Location - npcbcReporter.Pawn.Location))));
	}
	aecEnemyContacts[iNewIndex].fpEstimatedRange = (VSize((pawnContact.Location - npcbcReporter.Pawn.Location)) + fpRangeInaccuracy);
	if (npcbcReporter.bDebugMode)
	{
		Log("Target reported from " $ string(npcbcReporter.Pawn.Location) $ " bearing " $ string(((float(npcbcReporter.Pawn.Rotation.Yaw) / 65535) * 360)) $ ", range " $ string((aecEnemyContacts[iNewIndex].fpEstimatedRange / 50)) $ " meters");
	}
	AdjustNPCOrders(NPCBaseSoldierController(npcbcReporter), false);
	if (NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority > 7)
	{
		return false;
	}
	NPCBaseSoldierController(npcbcReporter).iLastInterruptEventPriority = 5;
	NPCBaseSoldierController(npcbcReporter).fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	DetermineDecisionOrderPercentEntryAction(NPCBaseSoldierController(npcbcReporter), 7);
	if ((((NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Surrender") && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Cower")) && (NPCBaseSoldierController(npcbcReporter).sNextAICCAction != "Collapse")) && (VSize((pawnContact.Location - npcbcReporter.Pawn.Location)) < float(500)))
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ ".ReportVehicleContact() - overriding combat action of \"" $ NPCBaseSoldierController(npcbcReporter).sNextAICCAction $ "\" with EngageEnemy due to range");
		}
		NPCBaseSoldierController(npcbcReporter).sNextAICCAction = "EngageEnemy";
	}
	PlayEventAudio(NPCBaseSoldierController(npcbcReporter));
	return ShouldActivateCombatAction(NPCBaseSoldierController(npcbcReporter));
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportOutOfAmmo(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	npcbcReporter.iLastInterrupt = 11;
	if (npcbcReporter.iLastInterruptEventPriority > 11)
	{
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 11;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 11);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportUnderFire(ANPCBaseSoldierController* npcbcReporter, AActor* aShooter)
{
	/*
	npcbcReporter.iLastInterrupt = 8;
	AdjustNPCOrders(npcbcReporter, true);
	if (npcbcReporter.iLastInterruptEventPriority > 8)
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ "ReportUnderFire() - event is lower than last interrupt" $ asEvents[npcbcReporter.iLastInterruptEventPriority]);
		}
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 8;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	ReportUnderFireSquadAlert(npcbcReporter, aShooter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 8);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportGrenadeContact(ANPCBaseSoldierController* npcbcReporter, FVector vLocGrenade)
{
	/*
	npcbcReporter.iLastInterrupt = 12;
	AdjustNPCOrders(npcbcReporter, true);
	npcbcReporter.iLastInterruptEventPriority = 12;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 12);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportWeaponJamReload(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	AdjustNPCOrders(npcbcReporter, true);
	if ((npcbcReporter.iLastInterruptEventPriority > 10) && (Level.TimeSeconds < npcbcReporter.fpTimeToEndLastInterrupt))
	{
		if (npcbcReporter.bDebugMode)
		{
			Log(string(Self) $ "ReportWeaponJamReload() - event is lower than last interrupt" $ asEvents[npcbcReporter.iLastInterruptEventPriority]);
		}
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 10;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	PlayEventAudio(npcbcReporter);
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 10);
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

bool ANPCAICombatController::ReportNeedToEnterAnarchyState(ANPCBaseSoldierController* npcbcReporter)
{
	/*
	FString sCombatAction = "";
	if (npcbcReporter == None)
	{
		return false;
	}
	npcbcReporter.iLastInterruptEventPriority = 13;
	npcbcReporter.fpTimeToEndLastInterrupt = ((Level.TimeSeconds + 5) + (FRand() * 3));
	if (npcbcReporter.bDebugMode)
	{
		Log(string(Self) $ "ReportNeedToEnterAnarchyState() for " $ string(npcbcReporter) $ " entered");
	}
	DetermineDecisionOrderPercentEntryAction(npcbcReporter, 13);
	if (npcbcReporter.bDebugMode)
	{
		Log(string(Self) $ "ReportNeedToEnterAnarchyState() for " $ string(npcbcReporter) $ " combat action determined: " $ sCombatAction);
	}
	PlayEventAudio(npcbcReporter);
	if ((npcbcReporter.sNextAICCAction == "DoNothing") || (Len(npcbcReporter.sNextAICCAction) == 0))
	{
		npcbcReporter.sNextAICCAction = "FallBack";
	}
	return ShouldActivateCombatAction(npcbcReporter);
	*/
	return false;    //FAKE   /EliZ
}

FString ANPCAICombatController::DetermineInterruptSpeech(ANPCBaseSoldierController* npcbcReporter)
{
	int32 iMentalStateIndex = 0;
	FString sSpeech = "";
	/*
	if (npcbcReporter.IsInPain())
	{
		iMentalStateIndex = 0;
	}
	else
	{
		if (npcbcReporter.IsInPanic())
		{
			iMentalStateIndex = 1;
		}
		else
		{
			if (npcbcReporter.IsSuppressed())
			{
				iMentalStateIndex = 2;
			}
			else
			{
				if (npcbcReporter.IsConcerned())
				{
					iMentalStateIndex = 3;
				}
				else
				{
					if (npcbcReporter.IsNormal())
					{
						iMentalStateIndex = 4;
					}
					else
					{
						if (npcbcReporter.IsBrave())
						{
							iMentalStateIndex = 5;
						}
						else
						{
							if (npcbcReporter.IsReckless())
							{
								iMentalStateIndex = 6;
							}
						}
					}
				}
			}
		}
	}
	sSpeech = DetermineSpeechByState(npcbcReporter.iNPCCurrentOrders, npcbcReporter.iLastInterruptEventPriority, iMentalStateIndex);
	*/
	return sSpeech;
}

float ANPCAICombatController::PlayEventAudio(ANPCBaseSoldierController* npcbscReporter, FString sOverrideSpeechType)
{
	FString sType = "";
	float fpVolume = 0;
	float fpRadius = 0;
	int32 iSoundTry = 0;
	bool bMustPlay = false;
	float fpPitch = 0;
	int32 iVoiceIndex = 0;
	/*
	local Sound sndToPlay;
	local AActor* actSound;
	if (npcbscReporter == None)
	{
		return 0;
	}
	if (npcbscReporter.Pawn == None)
	{
		return 0;
	}
	if (!npcbscReporter.bStart)
	{
		return 0;
	}
	if (anpcsmgrSpeechManager[0] == None)
	{
		Log(string(Self) $ "WARNING - NPC PlayAudio() request with no audio defined");
		return 0;
	}
	if (npcbscReporter.Pawn.Health <= 0)
	{
		return 0;
	}
	if (Len(sOverrideSpeechType) == 0)
	{
		sType = DetermineInterruptSpeech(npcbscReporter);
	}
	else
	{
		sType = sOverrideSpeechType;
	}
	if (sType != "Wounded")
	{
		if (Level.TimeSeconds < npcbscReporter.fpTimeUntilNextSpeech)
		{
			return 0;
		}
	}
	if (npcbscReporter.bDebugMode)
	{
		Log(string(Self) $ "PlayEventAudio() trying to play audio for " $ string(npcbscReporter.Tag) $ " in state " $ string(npcbscReporter.GetStateName()) $ " Type: \"" $ sType $ "\"");
	}
	if (anpcsmgrSpeechManager[npcbscReporter.iVoiceIndex] == None)
	{
		iVoiceIndex = 0;
	}
	else
	{
		iVoiceIndex = npcbscReporter.iVoiceIndex;
	}
	fpRadius = 250;
	for (iSoundTry = 0; iSoundTry < 20; iSoundTry++)
	{
		switch (sType)
		{
		case "":
		case "No Speech":
			return 0;
		case "Idle":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomIdleSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.75;
			fpRadius = 250;
			break;
		case "Attacking":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomAttackingSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.95;
			fpRadius = 1000;
			break;
		case "Concerned":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomConcernedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.8;
			fpRadius = 500;
			break;
		case "Angry":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomAngrySounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.95;
			fpRadius = 1000;
			break;
		case "Terrified":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomTerrifiedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.8;
			fpRadius = 750;
			break;
		case "Injured":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomInjuredSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.6;
			fpRadius = 750;
			bMustPlay = true;
			break;
		case "Taunt":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomTauntSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.95;
			fpRadius = 1000;
			break;
		case "Wounded":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomWoundedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.85;
			fpRadius = 750;
			bMustPlay = true;
			break;
		case "FriendWounded":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomFriendWoundedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.75;
			fpRadius = 750;
			bMustPlay = true;
			break;
		case "Grenade":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomGrenadeSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.99;
			fpRadius = 1250;
			bMustPlay = true;
			break;
		case "FriendDown":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomFriendDownSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.75;
			fpRadius = 750;
			bMustPlay = true;
			break;
		case "Surrender":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomSurrenderSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.95;
			fpRadius = 10009;
			break;
		case "VehicleSpotted":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomVehicleSpottedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.8;
			fpRadius = 1000;
			bMustPlay = true;
			break;
		case "EnemySpotted":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomEnemySpottedSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.8;
			fpRadius = 750;
			bMustPlay = true;
			break;
		case "Warning":
			sndToPlay = anpcsmgrSpeechManager[iVoiceIndex].GetRandomWarningSounds(npcbscReporter.bMaleVoice);
			fpVolume = 0.85;
			fpRadius = 750;
			break;
		default:
		}
		if (bMustPlay)
		{
		}
		if (anpcsmgrSpeechManager[iVoiceIndex].AddSoundToSoundHistory(sndToPlay))
		{
		}
	}
	if (sndToPlay == None)
	{
		return 0;
	}
	if (npcbscReporter.bDebugMode)
	{
		Log(string(Self) $ "PlayEventAudio() found sound \"" $ string(sndToPlay) $ "\" for type \"" $ sType $ "\" at volume " $ string(fpVolume) $ " radius: " $ string(fpRadius));
	}
	actSound = Spawn(Class'EffectLocation', , , npcbscReporter.Pawn.Location);
	actSound.LifeSpan = GetSoundDuration(sndToPlay);
	if (anpcsmgrSpeechManager[npcbscReporter.iVoiceIndex] == None)
	{
		if (npcbscReporter.fpVoicePitch != 0)
		{
			actSound.PlaySound(sndToPlay, 0, fpVolume, false, fpRadius, npcbscReporter.fpVoicePitch, true);
		}
		else
		{
			fpPitch = (0.7 + (float(npcbscReporter.iVoiceIndex) * 0.05));
			actSound.PlaySound(sndToPlay, 0, fpVolume, false, fpRadius, fpPitch, true);
		}
	}
	else
	{
		if (anpcsmgrSpeechManager[npcbscReporter.iVoiceIndex].fpOveridePitch > 0)
		{
			actSound.PlaySound(sndToPlay, 0, fpVolume, false, fpRadius, anpcsmgrSpeechManager[npcbscReporter.iVoiceIndex].fpOveridePitch, true);
		}
		else
		{
			if (npcbscReporter.fpVoicePitch != 0)
			{
				actSound.PlaySound(sndToPlay, 0, fpVolume, false, fpRadius, npcbscReporter.fpVoicePitch, true);
			}
			else
			{
				actSound.PlaySound(sndToPlay, 0, fpVolume, false, fpRadius, , true);
			}
		}
	}
	npcbscReporter.sndLastSoundPlayed = sndToPlay;
	npcbscReporter.actLastSoundPlayedEffect = actSound;
	npcbscReporter.fpTimeUntilNextSpeech = ((Level.TimeSeconds + GetSoundDuration(sndToPlay)) + (FRand() * float(15)));
	return GetSoundDuration(sndToPlay);
	*/

	return 0;   //FAKE   /ELiZ
}

void ANPCAICombatController::SetSquadRandomAmbushSet(int32 iPlatoonID, int32 iSquadID, int32 iAmbushSet)
{
	//anpcpPlatoons[iPlatoonID].anpcsdSquads[iSquadID].iAmbushSet = iAmbushSet;
}

int32 ANPCAICombatController::GetSquadRandomAmbushSet(int32 iPlatoonID, int32 iSquadID)
{
	//return anpcpPlatoons[iPlatoonID].anpcsdSquads[iSquadID].iAmbushSet;
	return 0;   //FAKE   /ELiZ
}

void ANPCAICombatController::ForceReinforcementsNow()
{
	bForceReinforcementsNow = true;
}
