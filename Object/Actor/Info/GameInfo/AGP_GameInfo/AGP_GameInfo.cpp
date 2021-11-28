// All the original content belonged to the US Army


#include "AGP_GameInfo.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "GameFramework/WorldSettings.h"
#include "AA29/Object/Actor/Info/StatsInfo/STS2_DBAuthStatsInfo/STS2_DBAuthStatsInfo.h"
#include "AA29/AA2_WorldSettings.h"

AAGP_GameInfo::AAGP_GameInfo()
{
	MaxAuthConnections = 1;
	ServerAuthFailures = -1;
	bEnableMapTesting = true;
	bEnableCodeTesting = true;
	iMaxAINPCsToSpawn = -1;
	iMaxAICivilianNPCsToSpawn = -1;
	iMaxAISpotterNPCsToSpawn = -1;
	iMaxAIVehiclesToSpawn = -1;
	iMaxT62sToSpawn = -1;
	iMaxBMPsToSpawn = -1;
	iMaxBTRsToSpawn = -1;
	fpNPCSpawnDelay = 0.1;
	fpNPCInitialSpawnDelay = 1.5;
	ServerToursDownloadServer = "dms1.americasarmy.com";
	sndESSS2Introduction = LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_ESSAudio/S2RadioMessages/S2Introduction.S2Introduction"), NULL, LOAD_None, NULL);;
	iDelayedRoundStartTimeSeconds = 10;
	bWaitingToStartMatch = true;
	bLoggingGame = true;
	bAllowVehicles = true;
	DefaultPlayerClassName = "AGP_Characters.AGP_Character";
	ScoreBoardType = "Engine.AGP_ScoreBoard";
	HUDType = "AGP.AGP_HUD";
	DefaultPlayerName = FText::FromString("Recruit");
	BroadcastHandlerClass = "AGP.CommoHandler";
	PlayerControllerClassName = "AGP.HumanController";
	GameName = "America's Army";
//	StatsClass = class'AGP.STS2_DBAuthStatsInfo';


}

void AAGP_GameInfo::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AAGP_GameInfo::EvaluatePlayerStatus(APlayerController* PC)
{
}
void AAGP_GameInfo::GetSystemTimeSeconds()
{
}
/*
void AAGP_GameInfo::PrecacheGameTextures(ALevelInfo* myLevel)
{
	myLevel.AddPrecacheMaterial(Texture'BlobTexture');
	myLevel.AddPrecacheMaterial(Texture'GRADIENT_Fade');
	myLevel.AddPrecacheMaterial(Texture'fx_decal_dirt');
	myLevel.AddPrecacheMaterial(Texture'fx_part_con');
	myLevel.AddPrecacheMaterial(Texture'fx_smk_ball01');
	myLevel.AddPrecacheMaterial(Texture'fx_part_smokeanim01');
	myLevel.AddPrecacheMaterial(Texture'fx2_part_dirtbits');
	myLevel.AddPrecacheMaterial(Texture'FX_dust_hitA');
	myLevel.AddPrecacheMaterial(Texture'fx_smk_ball03');
	myLevel.AddPrecacheMaterial(Texture'fx2_part_dirtclumps');
	myLevel.AddPrecacheMaterial(Texture'fx_smk_ball02');
	myLevel.AddPrecacheMaterial(Texture'fx_smk_ball04');
	myLevel.AddPrecacheMaterial(Texture'fx2_part_spark01');
	myLevel.AddPrecacheMaterial(Texture'fx_flash_tracer_new1a');
	myLevel.AddPrecacheMaterial(Texture'fx2_cor_05');
	myLevel.AddPrecacheMaterial(Texture'fx_particle_startblast01');
	myLevel.AddPrecacheMaterial(Texture'Fade');
	myLevel.AddPrecacheMaterial(Texture'skn_env_cubmap');
	myLevel.AddPrecacheMaterial(Texture'skn_weap_hands_Cauc');
	myLevel.AddPrecacheMaterial(Texture'skn_weap_camosleeve_Frst');
	myLevel.AddPrecacheMaterial(Texture'skn_weap_camosleeve_new_frst');
	if (myCast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_pants_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_b');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_pants_b');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_camo_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_pants_camo_b');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_camo_b');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_pants_camo_a');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_a');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_b');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_c');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_d');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_e');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_f');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_commando_face_g');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_face_h');
		myLevel.AddPrecacheMaterial(Texture't_char_commando_hands_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_hands_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_face_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_pants_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_shirt_a');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_pants_b');
		myLevel.AddPrecacheMaterial(Texture't_char_enemy_infantry_shirt_b');
		myLevel.AddPrecacheMaterial(Texture'Civ_HAND_MaleA');
		myLevel.AddPrecacheMaterial(Texture'Civ_HAND_MaleB');
		myLevel.AddPrecacheMaterial(Texture'Civ_HAND_MaleC');
		myLevel.AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleA');
		myLevel.AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleB');
		myLevel.AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleC');
		myLevel.AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleD');
		myLevel.AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_black');
		myLevel.AddPrecacheMaterial(Texture'Civ_PANTS_Jeans_Blue');
		myLevel.AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_Brown');
		myLevel.AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_Green');
		myLevel.AddPrecacheMaterial(Texture'Civ_SHIRT_blue');
		myLevel.AddPrecacheMaterial(Texture'Civ_SHIRT_Vest_WhiteA');
		myLevel.AddPrecacheMaterial(Texture'Civ_SHIRT_WhiteA');
		myLevel.AddPrecacheMaterial(Texture'Civ_SHIRT_yellow');
	}
	PrecacheGameTextures(myLevel);
}
*/
/*
void AAGP_GameInfo::PrecacheGameStaticMeshes(ALevelInfo* myLevel)
{
	myLevel.AddPrecacheStaticMesh(StaticMesh'ammo_556');
	myLevel.AddPrecacheStaticMesh(StaticMesh'ammo_545x39_bullet_1p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'ammo_556_linked');
	myLevel.AddPrecacheStaticMesh(StaticMesh'9mm_ammo_1p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'ammo_9x39_bullet_1p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo1p_m203_40mmround');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo1p_m203_40mmshell');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo3p_rpg7round_unfired');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo3p_pg7vr_unfired');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo1p_bs1_nade');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo1p_m203_40mmround');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_ammo1p_m203_40mmshell');
	myLevel.AddPrecacheStaticMesh(StaticMesh'rpg7_pg7vr');
	myLevel.AddPrecacheStaticMesh(StaticMesh'fx_part_con_chunk1');
	myLevel.AddPrecacheStaticMesh(StaticMesh'fx_part_con_chunk2');
	myLevel.AddPrecacheStaticMesh(StaticMesh'fx_part_grass');
	myLevel.AddPrecacheStaticMesh(StaticMesh'fx_part_tile01');
	myLevel.AddPrecacheStaticMesh(StaticMesh'fx_part_wood_chunk1');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_door_breacher');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn_m14th3_incen_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-m83_smoke_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-flashbang_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'wpn2_pipebomb_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-m67_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-miles_m67_thrown_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-miles_m67_3p');
	myLevel.AddPrecacheStaticMesh(StaticMesh'm-miles_weapon_3p');
	if (myLevel.bCoOpGame)
	{
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_beret');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_ballcap');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_ballcap_b');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_scarf');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_helmet');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_AAO_bowie');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_helmet');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_civilian_sunglasses');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_junglehat');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_junglehat_b');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_watchcap');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm_atta_enemynpc_watchcap_b');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-ak47_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-rgd-5_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-ak74_gp30_40mm_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-mosin_nagant_sniper_rifle_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-rpk_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-rpk_sup_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-dragonov_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm2-wpn_rpg7_projectile_003_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-rgd-5_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-rgd-5_thrown_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm2-wpn_rpg7_up_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm2-wpn_rpg7_pg7vr_up_rocket_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm2-wpn_rpg7_up_rocket_3p');
		myLevel.AddPrecacheStaticMesh(StaticMesh'm-dragonov_3p');
	}
	PrecacheGameStaticMeshes(myLevel);
}
*/
/*
void AAGP_GameInfo::PreBeginPlay ()
{
	
	Super::PreBeginPlay();
	
	//if (GetNetMode() == ENetMode::NM_DedicatedServer)
	//{
	//	if (! LogFileOpen())
	//	{
	//		Log("Error creating log file!");
	//	}
	//	else
	//	{
	//		LogFileWrite("DevNet","LogStart");
	//		LogFileWrite("DevNet",GameReplicationInfo.ServerName $ ":" $ Left(Level,InStr(Level,".")));
	//	}
	//}
}
*/
/*
void AAGP_GameInfo::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameInfo::BeginPlay()"));
	Super::BeginPlay();

	local Screenplay S;
		BeginPlay();
		Switch(ForceGameplay)
		{
			case 1:
			if (Level.GamePlayMode != 0)
			{
				Level.GamePlayMode=0;
				DisableQualification();
			}
			break;
			case 2:
			if (Level.GamePlayMode != 1)
			{
				Level.GamePlayMode=1;
				DisableQualification();
			}
			break;
			default:
		}
		_Screenplay=None;
		ForEach AllActors(Class'Screenplay',S)
		{
			_Screenplay=S;
			GOTO JL00A6;
	JL00A6:
		}
		if (_Screenplay == None)
		{
			Return;
		}
}
*/
void AAGP_GameInfo::DisableQualification()
{
}
/*
void AAGP_GameInfo::PostBeginPlay()
{
	Super::PostBeginPlay();
}
*/
void AAGP_GameInfo::InitLogging()
{
	bool bTraining;
	bTraining = IsTrainingMission();

	if (! bEnableStatLogging || ! bLoggingGame || ! bTraining && GetNetMode() == ENetMode::NM_Standalone || GetNetMode() == ENetMode::NM_ListenServer || GetNetMode() == ENetMode::NM_Client)
	{
		UE_LOG(LogTemp, Warning, TEXT("Not initing Stats Object"));
		return;
	}
	if (StatsClass != nullptr)
	{
		if (Stats == nullptr)
		{

			UWorld* const World = GetWorld();
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = GetInstigator();
				Stats = GetWorld()->SpawnActor<ASTS2_DBAuthStatsInfo>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			}
			
		}
		if (Stats == nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("Could not create StatsInfo"));
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("StatsInfo class not specified for this GameType"));
	}
	//Log("Created Stats object" @ Stats);
}

void AAGP_GameInfo::EndLogging(FString Reason)
{
}

void AAGP_GameInfo::AddAllPlayersToStatsInfo()
{
	/*
		local HumanController HC;
		local int i;
		local int t;
		if (Stats != None)
		{
			t=0;
			if (t < 2)
			{
				if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
				{
					if (t > 0)
					{
					}
				}
				else
				{
					for (i=0; i<GameReplicationInfo.Teams[t].NumRequestSlots; i++)
					{
						if (GameReplicationInfo.Teams[t].ActualList_Player[i] != None)
						{
							HC=HumanController(GameReplicationInfo.Teams[t].ActualList_Player[i].Owner);
							if (Stats != None && HC != None)
							{
								HC.PlayerStatsIndex=Level.Game.Stats.AddPlayerByName(HC.GetAuthUserName(),HC.EncryptedPassword);
							}
						}
					}
					t ++;
				}
			}
		}
	*/
}
void AAGP_GameInfo::GetStatForPlayer(AHumanController* HC, FString sStatName)
{
	/*
		if (HC->PlayerStatsIndex >= 0)
		{
			switch(sStatName)
			{
				case "CapturedObjectives":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryCapturedObjectives();
				case "CapturedObjectiveDeaths":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryCapturedObjectiveDeaths();
				case "Healed":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryHealed();
				case "UsedMedic":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryUsedMedic();
				case "MedPacksUsed":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryMedPacksUsed();
				case "TimePlayedSeconds":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryTimePlayedSeconds();
				case "TimeAliveSeconds":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryTimeAliveSeconds();
				case "RoundsStarted":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundStarted();
				case "RoundsSurvivedWon":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundsSurvivedWon();
				case "RoundsSurvivedLost":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundsSurvivedLost();
				case "ShotsFiredMachineGun":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredMachineGun();
				case "ShotsFiredAssaultRifle":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredAssaultRifle();
				case "ShotsFiredPistol":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredPistol();
				case "ShotsFiredGrenade":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredGrenade();
				case "ShotsFiredSniper":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredSniper();
				case "ShotsFiredRocket":
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredRocket();
				case "ShotsHitMachineGun":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitMachineGun();
				case "ShotsHitAssaultRifle":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitAssaultRifle();
				case "ShotsHitPistol":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitPistol();
				case "ShotsHitGrenade":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitGrenade();
				case "ShotsHitSniper":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitSniper();
				case "ShotsHitRocket":
				if (! Level.Game.bDeathMessages)
				{
					Return -1;
				}
				Return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitRocket();
				default:
			}
			Return 0;
	*/
}
bool AAGP_GameInfo::ShouldIgnoreStats()
{
	if (Stats != NULL)
	{
		return false;
	}
	return false;
}
bool AAGP_GameInfo::IsTrainingMission()
{
	/*
	AActor* A;
	ForEach DynamicActors(Class'Actor',A)
	{
		if (A.IsA('EventLab'))
		{
			return true;
		}
	}
	*/
	return false;   //FAKE   /ELiZ
}
void AAGP_GameInfo::UpdateClientsOfCheatAndForceclassStatus()
{
}
/*
void AAGP_GameInfo::StartMatch()
{
	Super::StartMatch();
	
		local PlayerController PC;
		local Controller p;
		local Actor A;
		local Pawn DeleteMe;
		local NPCPlayerStart npcpsIterator;
		local NPCVehicleStart npcvsIterator;
		local NPCHelicopterStart npchsIterator;
		local NPCUAVStart npcuavsIterator;
		local NPCConversationPack npccpIterator;
		local int iPlayerVehiclesSpawned;
		local NavigationPoint npIterator;
		local NPCAICombatController npcaicc;
		local Gameplay.ScriptedTrigger triggerIter;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::StartMatch() - Entered"));
		GameReplicationInfo.bTempDisableRoundScoring=False;
		GameReplicationInfo.iSpotterBaseGridY=Rand(5) * 10;
		GameReplicationInfo.iSpotterBaseGridY=Rand(5) * 10;
		CalculateAIDifficultyValues();
		StopCustomTimer('NPCSpawnTimer');
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::StartMatch() - Entered"));
		if (GameStats != None)
		{
			GameStats.StartGame();
		}
		InitLogging();
		CleanupLevel();
		ForEach AllActors(Class'Actor',A)
		{
			A.MatchStarting();
		}
		GameReplicationInfo.bForceClassUsedInRound=GameReplicationInfo.bAllowForceclassing;
		UpdateClientsOfCheatAndForceclassStatus();
		AssignStartPoints();
		AssignClassAndRole();
		iPlayersSpawned=0;
		p=Level.ControllerList;
		if (p != None)
		{
			if (p.IsA('AIController'))
			{
			}
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::StartMatch() - Trying to start " $ p));
			PC=PlayerController(p);
			if (PC != None)
			{
				if (bGameEnded)
				{
					Return;
				}
				DeleteMe=PC.Pawn;
				PC.Pawn=None;
				if (PC.IsInState('ValidatePB') || PC.IsInState('ServerAuthorizePlayer') || PC.IsInState('FailedAuthorization') || PC.IsInState('UnauthorizedJoinComplete') || PC.IsInState('PlayerAuthorizationComplete'))
				{
					UE_LOG(LogTemp, Warning, TEXT("Player validating or authorizing and not ready to play"));
				}
				else
				{
					PreparePlayerForStartMatch(PC);
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::StartMatch() - about to call RestartPlayer()"));
					HumanController(PC).CleanupLevel();
					if (! PC.PlayerReplicationInfo.bOnlySpectator)
					{
						RestartPlayer(PC);
						if (PC.Pawn != None)
						{
							LogPlayerStart(PC);
							iPlayersSpawned ++;
						}
						else
						{
							EnterSpectatorMode(PC);
							HumanController(PC).ClientResetSpectator();
						}
					}
					else
					{
						EnterSpectatorMode(PC);
						HumanController(PC).ClientResetSpectator();
					}
					if (DeleteMe != None)
					{
						DeleteMe.Controller=None;
						DeleteMe.Destroy();
					}
				}
			}
			p=p.nextController;
		}
		AddAllPlayersToStatsInfo();
		ConfigureESSObjectives();
		ForEach AllActors(Class'ScriptedTrigger',triggerIter)
		{
			triggerIter.Reset();
		}
		if (ShouldIgnoreStats())
		{
			Stats.IgnoreStatsThisRound();
		}
		RecordStartMatch();
		if (! bDEBUGDisablePlayerVehicles)
		{
			iPlayerVehiclesSpawned=0;
			npIterator=Level.NavigationPointList;
			if (npIterator != None)
			{
				if (iPlayerVehiclesSpawned == iMaxPlayerVehiclesToSpawn && iMaxPlayerVehiclesToSpawn > 0)
				{
				}
				if (! npIterator.IsA('AGPVehicleStart'))
				{
				}
				AGPVehicleStart(npIterator).CreateVehicle();
				iPlayerVehiclesSpawned ++;
				npIterator=npIterator.nextNavigationPoint;
			}
		}
		else
		{
			Log("WARNING - INI DEBUG AGP_GameInfo.bDEBUGDisablePlayerVehicles OPTION DISABLED PLAYER VEHICLES");
		}
		iNPCsSpawned=0;
		if (fpMaxNPCToPlayerRatio > 2.5)
		{
			Log("Using configuration set NPC to player ratio");
			iMaxAINPCsToSpawn=fpMaxNPCToPlayerRatio * iPlayersSpawned + 1;
			Log("NPC to Player Ratio set to " $ fpMaxNPCToPlayerRatio);
		}
		else
		{
			if (Level.fpMaxNPCToPlayerRatio > 0)
			{
				iMaxAINPCsToSpawn=Level.fpMaxNPCToPlayerRatio * iPlayersSpawned + 1;
			}
		}
		if (iMaxAINPCsToSpawn < 25 && iMaxAINPCsToSpawn != -1)
		{
			Log("AI limited to 25 by balance/ratio rules");
			iMaxAINPCsToSpawn=25;
		}
		anpcpsPSToSpawn.remove (0,anpcpsPSToSpawn.Length);
		iNPCsSpawned=0;
		iNPCPSSpawnIndex=0;
		iNPCSpottersSpawned=0;
		iCivilianNPCsSpawned=0;
		iMustSpawnNPCsSpawned=0;
		npIterator=Level.NavigationPointList;
		if (npIterator != None)
		{
			if (! npIterator.IsA('NPCPlayerStart'))
			{
			}
			npcpsIterator=NPCPlayerStart(npIterator);
			if (npcpsIterator.bSpawnAsReserve)
			{
			}
			if (! npcpsIterator.bSpawnable)
			{
			}
			if (npcpsIterator.bCanDelaySpawn && GetNetMode() != ENetMode::NM_Standalone)
			{
				anpcpsPSToSpawn.insert (0,1);
				anpcpsPSToSpawn[0]=npcpsIterator;
			}
			else
			{
				if (npcpsIterator.IsA('NPCPlayerStartCivilian'))
				{
					if (iMaxAICivilianNPCsToSpawn == -1 || iCivilianNPCsSpawned < iMaxAICivilianNPCsToSpawn)
					{
						if (npcpsIterator.CreateNPC() != None)
						{
							UE_LOG(LogTemp, Warning, TEXT("Spawned civilian: " $ npcpsIterator.Tag $ " object: " $ npcpsIterator));
							iCivilianNPCsSpawned ++;
						}
					}
				}
				else
				{
					if (npcpsIterator.IsA('NPCMortarSpotterController'))
					{
						if (iMaxAISpotterNPCsToSpawn == -1 || npcpsIterator.bMustSpawn || iNPCSpottersSpawned < iMaxAISpotterNPCsToSpawn)
						{
							if (npcpsIterator.CreateNPC() != None)
							{
								UE_LOG(LogTemp, Warning, TEXT("Spawned mortar: " $ npcpsIterator.Tag $ " object: " $ npcpsIterator));
								if (npcpsIterator.bMustSpawn)
								{
									iMustSpawnNPCsSpawned ++;
								}
								iNPCSpottersSpawned ++;
							}
						}
					}
					else
					{
						if (iMaxAINPCsToSpawn > 0)
						{
							if (iNPCsSpawned >= iMaxAINPCsToSpawn && ! npcpsIterator.bMustSpawn)
							{
							}
						}
						else
						{
							if (npcpsIterator.CreateNPC() != None)
							{
								UE_LOG(LogTemp, Warning, TEXT("Spawning soldier : " $ npcpsIterator.Tag $ " object: " $ npcpsIterator));
								if (npcpsIterator.bMustSpawn)
								{
									iMustSpawnNPCsSpawned ++;
								}
								iNPCsSpawned ++;
							}
						}
					}
				}
			}
			npIterator=npIterator.nextNavigationPoint;
		}
		iAIVehiclesSpawned=0;
		iT62sSpawned=0;
		iBMPsSpawned=0;
		iBTRsSpawned=0;
		if (! bDEBUGDisableAIVehicles)
		{
			npIterator=Level.NavigationPointList;
			if (npIterator != None)
			{
				if (npIterator.IsA('NPCHelicopterStart'))
				{
					npchsIterator=NPCHelicopterStart(npIterator);
					if (npchsIterator.bSpawnAsReserve)
					{
					}
					if (npchsIterator.CreateNPC() != None)
					{
					}
					Log("NPC Helicopter spawn failure");
				}
				else
				{
					else
					{
						if (npIterator.IsA('NPCUAVStart'))
						{
							npcuavsIterator=NPCUAVStart(npIterator);
							if (npcuavsIterator.bSpawnAsReserve)
							{
							}
							if (npcuavsIterator.CreateNPC() != None)
							{
								Log("NPC UAV spawned");
							}
							else
							{
								Log("NPC UAV spawn failure");
							}
						}
						else
						{
							else
							{
								if (! npIterator.IsA('NPCVehicleStart'))
								{
								}
								npcvsIterator=NPCVehicleStart(npIterator);
								if (npcvsIterator.bSpawnAsReserve)
								{
								}
								if (iMaxAIVehiclesToSpawn == -1 || iAIVehiclesSpawned < iMaxAIVehiclesToSpawn)
								{
									if (npcvsIterator.VehicleClass == None)
									{
									}
									if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.T62A")
									{
										Log("t62 vehicle start, currently spawned: " $ iT62sSpawned);
										if (iT62sSpawned >= iMaxT62sToSpawn && iMaxT62sToSpawn != -1)
										{
										}
									}
									else
									{
										else
										{
											if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.BMP1_APC")
											{
												Log("BMP vehicle start, currently spawned: " $ iBMPsSpawned);
												if (iBMPsSpawned >= iMaxBMPsToSpawn && iMaxBMPsToSpawn != -1)
												{
												}
											}
											else
											{
												else
												{
													if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.BTR80APC")
													{
														Log("BTR vehicle start, currently spawned: " $ iBTRsSpawned);
														if (iBTRsSpawned >= iMaxBTRsToSpawn && iMaxBTRsToSpawn != -1)
														{
														}
													}
												}
											}
											else
											{
												Log("Creating vehicle: " $ npcvsIterator $ " of class " $ npcvsIterator.VehicleClass);
												if (npcvsIterator.CreateNPC() != None)
												{
													iAIVehiclesSpawned ++;
													if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.T62A")
													{
														iT62sSpawned ++;
													}
													else
													{
														if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.BMP1_APC")
														{
															iBMPsSpawned ++;
														}
														else
														{
															if (npcvsIterator.VehicleClass ~= "AGP_Vehicles.BTR80APC")
															{
																iBTRsSpawned ++;
															}
														}
													}
												}
											}
										}
									}
								}
							}
						}
					}
				}
				npIterator=npIterator.nextNavigationPoint;
			}
		}
		else
		{
			Log("WARNING - INI DEBUG OPTION AGP_GameInfo.bDEBUGDisableAIVehicles DISABLED AI VEHICLES");
		}
		if (anpcpsPSToSpawn.Length > 0)
		{
			if (fpNPCInitialSpawnDelay > 5)
			{
				fpNPCInitialSpawnDelay=5;
			}
			if (fpNPCSpawnDelay > 0.5)
			{
				fpNPCSpawnDelay=0.5;
			}
			SetCustomTimer(fpNPCInitialSpawnDelay,False,'NPCSpawnTimer');
		}
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			ForEach AllActors('NPCConversationPack',npccpIterator)
			{
				npccpIterator.StartConversation();
			}
		}
		ForEach AllActors('NPCAICombatController',npcaicc)
		{
			npcaicc.StartAICC();
		}
		p=Level.ControllerList;
		if (p != None)
		{
			if (p.IsA('PlayerController'))
			{
				PlayerController(p).LockPlayer(False,False);
			}
			p=p.nextController;
		}
		if (Level.Game.Stats != None && Level.Game.Stats.GameStats != None)
		{
			Level.Game.Stats.GameStats.StatEvent_RoundBegin();
		}
		if (GetNetMode() == ENetMode::NM_Standalone)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::StartMatch() - Calling StartScreenPlay() for single player"));
			StartScreenplay();
		}
		bWaitingToStartMatch=False;
		GameReplicationInfo.bMatchHasBegun=True;
		LogFileWrite("ServerStatus","Round:Started",True);
}
*/

void AAGP_GameInfo::ConfigureESSObjectives()
{
	/*
		local array<ESSObjectiveSet> aessos;
		local Controller ctrlrIterator;
		local AGP_Objective agpessobjIterator;
		local AGP_Objective agpessobjSelected;
		local int iSet;
		local int iFoundSet;
		local int iObj;
		local int iESSObjectsEnabled;
		local int iNumCoopObjectives;
		local int iNumESSObjectives;
		local bool bAnyFound;
		local Actor triggerIter;
		local EmitterSpawner esIter;
		local FlagMeshActor smIter;
		bAnyFound=False;
		ForEach AllActors('AGP_Objective',agpessobjIterator)
		{
			if (! agpessobjIterator.IsA('AGP_ESSObjective'))
			{
			}
			else
			{
				if (agpessobjIterator.IsA('AGP_CoopESSObjective'))
				{
					smIter=agpessobjIterator.getFlagReference();
					if (smIter != None)
					{
						smIter.bHidden=True;
					}
					else
					{
						ForEach AllActors('FlagMeshActor',smIter)
						{
							if (smIter.Tag == agpessobjIterator.getFlagTag())
							{
								if (! smIter.bHidden)
								{
									smIter.bHidden=True;
								}
							}
						}
					}
					iNumCoopObjectives ++;
				}
				else
				{
					iNumESSObjectives ++;
				}
				iFoundSet=-1;
				iSet=0;
				if (iSet < aessos.Length)
				{
					if (aessos[iSet].aagpobjs[0].Tag == agpessobjIterator.Tag)
					{
						iFoundSet=iSet;
					}
					else
					{
						iSet ++;
					}
				}
				if (iFoundSet == -1)
				{
					aessos.insert (0,1);
					iFoundSet=0;
				}
				aessos[iFoundSet].aagpobjs.insert (0,1);
				aessos[iFoundSet].aagpobjs[0]=agpessobjIterator;
			}
		}
		for (iSet=0; iSet<aessos.Length; iSet++)
		{
			if (aessos[iSet].aagpobjs.Length > 0)
			{
				agpessobjSelected=aessos[iSet].aagpobjs[Rand(aessos[iSet].aagpobjs.Length)];
				for (iObj=0; iObj<aessos[iSet].aagpobjs.Length; iObj++)
				{
					aessos[iSet].aagpobjs[iObj].ObjectiveOnCompass=aessos[iSet].aagpobjs[iObj].1;
					if (aessos[iSet].aagpobjs[iObj] == agpessobjSelected && ! bDisableESS)
					{
						bAnyFound=True;
						agpessobjSelected.Reset();
						agpessobjSelected.bHidden=False;
						agpessobjSelected.bDisabled=False;
						agpessobjSelected.SetCollision(True,True);
						TriggerEvent(agpessobjSelected.getBecomeActiveEvent(),Self,None);
						iESSObjectsEnabled ++;
						if (agpessobjSelected.isDangerous())
						{
							ForEach AllActors(Class'Actor',triggerIter)
							{
								if (triggerIter.IsA('ESSTrigger'))
								{
									if (triggerIter.Tag == agpessobjSelected.Tag)
									{
										triggerIter.SetLocation(agpessobjSelected.Location);
										triggerIter.SetCollisionSize(100,50);
										ForEach AllActors(Class'EmitterSpawner',esIter)
										{
											if (esIter.Tag == triggerIter.Tag)
											{
												esIter.SetLocation(triggerIter.Location);
											}
										}
									}
								}
								else
								{
								}
							}
						}
					}
					else
					{
						aessos[iSet].aagpobjs[iObj].Reset();
						aessos[iSet].aagpobjs[iObj].bHidden=True;
						aessos[iSet].aagpobjs[iObj].bDisabled=True;
						aessos[iSet].aagpobjs[iObj].SetCollision(False,False);
					}
				}
			}
		}
		if (bAnyFound)
		{
			ctrlrIterator=Level.ControllerList;
			if (ctrlrIterator != None)
			{
				if (ctrlrIterator.IsA('HumanController'))
				{
					ESSUpdateInitialAvailableStatsPerPlayer(HumanController(ctrlrIterator),iESSObjectsEnabled);
					if (iNumESSObjectives > iNumCoopObjectives)
					{
						HumanController(ctrlrIterator).ClientESSConsoleMessage("S2 Radios: Be alert for any unusual or out of place objects and report them with your <ESSObjectiveReport> command when encountered.");
						HumanController(ctrlrIterator).ClientESSPlayIntroduction(sndESSS2Introduction);
					}
				}
				ctrlrIterator=ctrlrIterator.nextController;
			}
		}
	*/
}

void AAGP_GameInfo::ESSUpdateInitialAvailableStatsPerPlayer(AHumanController* HC, int32 iESSObjectsEnabled)
{
	/*
		local int iObjects;
		UE_LOG(LogTemp, Warning, TEXT("Trying to set ESS available stats for " $ HC $ " to " $ iESSObjectsEnabled));
		if (Level.Game.Stats == None || HC.PlayerStatsIndex < 0)
		{
			Return;
		}
		for (iObjects=0; iObjects<iESSObjectsEnabled; iObjects++)
		{
			Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].StatEvent_ESSObjectAvailable();
		}
	*/
}

void AAGP_GameInfo::CalculateAIDifficultyValues()
{
	/*
		local Controller ctrlrIterator;
		local int iKillsThisRound;
		local float fpTPP;
		local float fpAKEV;
		local float fpPSRPR;
		local float fpTotalSinglePSPR;
		local float fpTotalAllPSPR;
		local float fpPSRPSAllPlayers;
		local int iRound;
		local int iPlayerCount;
		local int iRoundsPlayedSinglePlayer;
		local int iRoundsPlayedAllPlayers;
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			Return;
		}
		fpAIDifficultyLevelVisionModifer=0;
		fpAIDifficultyLevelHearingModifer=0;
		fpAIDifficultyLevelExperienceModifer=0;
		fpAIDifficultyLevelWeaponAccModifer=0;
		fpAIDifficultyLevelWeaponRangeModifer=0;
		fpAIDifficultyLevelMortarSkillModifer=0;
		fpAIDifficultyLevelMentalStateModifer=0;
		ctrlrIterator=Level.ControllerList;
		if (ctrlrIterator != None)
		{
			if (ctrlrIterator.IsA('HumanController') && HumanController(ctrlrIterator).PlayerReplicationInfo != None && ! HumanController(ctrlrIterator).PlayerReplicationInfo.bOnlySpectator && HumanController(ctrlrIterator).fpTimePlayedLastRound > 0)
			{
				iPlayerCount ++;
			}
			ctrlrIterator=ctrlrIterator.nextController;
		}
		if (iPlayerCount == 0)
		{
			Return;
		}
		if (iNPCsSpawned + iNPCSpottersSpawned == 0)
		{
			Return;
		}
		fpAKEV=iNPCsSpawned + iNPCSpottersSpawned / iPlayerCount;
		fpTotalAllPSPR=0;
		iRoundsPlayedAllPlayers=0;
		ctrlrIterator=Level.ControllerList;
		if (ctrlrIterator != None)
		{
			if (ctrlrIterator.IsA('HumanController'))
			{
				if (HumanController(ctrlrIterator).PlayerReplicationInfo == None)
				{
				}
				if (HumanController(ctrlrIterator).PlayerReplicationInfo.bOnlySpectator)
				{
				}
				if (HumanController(ctrlrIterator).fpLastRoundLength > 0)
				{
					if (HumanController(ctrlrIterator).fpLastRoundLength < TimeLimit * 60 / 4)
					{
						HumanController(ctrlrIterator).fpLastRoundLength=TimeLimit * 60 / 2;
					}
					fpTPP=HumanController(ctrlrIterator).fpTimePlayedLastRound / HumanController(ctrlrIterator).fpLastRoundLength;
				}
				else
				{
					fpTPP=0;
				}
				HumanController(ctrlrIterator).afpTimePlayedPercent[HumanController(ctrlrIterator).iAIDifficultyRoundsDataIndex]=fpTPP;
				fpPSRPR=fpTPP * 0.5 - 0.5;
				if (HumanController(ctrlrIterator).iKillsAtLastRound > HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Kills)
				{
					HumanController(ctrlrIterator).iKillsAtLastRound=0;
				}
				iKillsThisRound=HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Kills - HumanController(ctrlrIterator).iKillsAtLastRound;
				if (iKillsThisRound > fpAKEV)
				{
					fpPSRPR += 0.25;
				}
				else
				{
					fpPSRPR += iKillsThisRound / fpAKEV * 0.25;
				}
				if (HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Wins < HumanController(ctrlrIterator).iWinsAtLastRound)
				{
					HumanController(ctrlrIterator).iWinsAtLastRound=0;
				}
				if (HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Wins - HumanController(ctrlrIterator).iWinsAtLastRound > 0)
				{
					fpPSRPR += 0.25;
				}
				HumanController(ctrlrIterator).iWinsAtLastRound=HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Wins;
				HumanController(ctrlrIterator).iKillsAtLastRound=HumanController(ctrlrIterator).PlayerReplicationInfo.Score_Kills;
				HumanController(ctrlrIterator).afpSkillPerRound[HumanController(ctrlrIterator).iAIDifficultyRoundsDataIndex]=fpPSRPR;
				iRoundsPlayedSinglePlayer=0;
				fpTotalSinglePSPR=0;
				for (iRound=0; iRound<10; iRound++)
				{
					if (HumanController(ctrlrIterator).afpTimePlayedPercent[iRound] > 0)
					{
						iRoundsPlayedSinglePlayer ++;
						fpTotalSinglePSPR += HumanController(ctrlrIterator).afpSkillPerRound[iRound];
					}
				}
				iRoundsPlayedAllPlayers += iRoundsPlayedSinglePlayer;
				fpTotalAllPSPR += fpTotalSinglePSPR;
				if (++ HumanController(ctrlrIterator).iAIDifficultyRoundsDataIndex >= 10)
				{
					HumanController(ctrlrIterator).iAIDifficultyRoundsDataIndex=0;
				}
				HumanController(ctrlrIterator).fpTimePlayedLastRound=0;
				HumanController(ctrlrIterator).fpLastRoundLength=0;
			}
			ctrlrIterator=ctrlrIterator.nextController;
		}
		fpPSRPSAllPlayers=fpTotalAllPSPR / iRoundsPlayedAllPlayers;
		Log("Player Skill Rating for AI Difficulty Balancing: " $ fpPSRPSAllPlayers);
		if (fpPSRPSAllPlayers <= -0.3)
		{
			Log("AI Difficulty set to Level 0 (Easiest)");
			fpAIDifficultyLevelVisionModifer=0.75;
			fpAIDifficultyLevelHearingModifer=0.75;
			fpAIDifficultyLevelExperienceModifer=0.75;
			fpAIDifficultyLevelWeaponAccModifer=0.75;
			fpAIDifficultyLevelWeaponRangeModifer=0.75;
			fpAIDifficultyLevelMortarSkillModifer=0.75;
			fpAIDifficultyLevelMentalStateModifer=0.75;
		}
		else
		{
			if (fpPSRPSAllPlayers > -0.3 && fpPSRPSAllPlayers <= -0.1)
			{
				Log("AI Difficulty set to Level 1 (Easier)");
				fpAIDifficultyLevelVisionModifer=0.85;
				fpAIDifficultyLevelHearingModifer=0.85;
				fpAIDifficultyLevelExperienceModifer=0.85;
				fpAIDifficultyLevelWeaponAccModifer=0.85;
				fpAIDifficultyLevelWeaponRangeModifer=0.85;
				fpAIDifficultyLevelMortarSkillModifer=0.85;
				fpAIDifficultyLevelMentalStateModifer=0.85;
			}
			else
			{
				if (fpPSRPSAllPlayers > -0.1 && fpPSRPSAllPlayers <= 0.1)
				{
					Log("AI Difficulty set to Level 2 (Default)");
					fpAIDifficultyLevelVisionModifer=1;
					fpAIDifficultyLevelHearingModifer=1;
					fpAIDifficultyLevelExperienceModifer=1;
					fpAIDifficultyLevelWeaponAccModifer=1;
					fpAIDifficultyLevelWeaponRangeModifer=1;
					fpAIDifficultyLevelMortarSkillModifer=1;
					fpAIDifficultyLevelMentalStateModifer=1;
				}
				else
				{
					if (fpPSRPSAllPlayers > 0.1 && fpPSRPSAllPlayers <= 0.3)
					{
						Log("AI Difficulty set to Level 3 (Harder)");
						fpAIDifficultyLevelVisionModifer=1.15;
						fpAIDifficultyLevelHearingModifer=1.15;
						fpAIDifficultyLevelExperienceModifer=1.15;
						fpAIDifficultyLevelWeaponAccModifer=1.15;
						fpAIDifficultyLevelWeaponRangeModifer=1.15;
						fpAIDifficultyLevelMortarSkillModifer=1.15;
						fpAIDifficultyLevelMentalStateModifer=1.15;
					}
					else
					{
						if (fpPSRPSAllPlayers > 0.3)
						{
							Log("AI Difficulty set to Level 4 (Max)");
							fpAIDifficultyLevelVisionModifer=1.25;
							fpAIDifficultyLevelHearingModifer=1.25;
							fpAIDifficultyLevelExperienceModifer=1.25;
							fpAIDifficultyLevelWeaponAccModifer=1.25;
							fpAIDifficultyLevelWeaponRangeModifer=1.25;
							fpAIDifficultyLevelMortarSkillModifer=1.25;
							fpAIDifficultyLevelMentalStateModifer=1.25;
						}
					}
				}
			}
		}
	*/
}
void AAGP_GameInfo::TerminateNPCSpawning()
{
	/*
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".CompleteEndGame() Resetting NPCSpawnTimer"));
		StopCustomTimer('NPCSpawnTimer');
	*/
}

void AAGP_GameInfo::NPCSpawnTimer()
{
	/*
		if (GetStateName() == 'MatchOver')
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".NPCSpawnTimer() - match over, aborting"));
			Return;
		}
		UE_LOG(LogTemp, Warning, TEXT("NPCSpawnTimer() - Spawning NPC " $ iNPCPSSpawnIndex $ " -> " $ anpcpsPSToSpawn[iNPCPSSpawnIndex] $ " Tag: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag));
		if (anpcpsPSToSpawn[iNPCPSSpawnIndex].IsA('NPCPlayerStartCivilian'))
		{
			if (iMaxAICivilianNPCsToSpawn == -1 || iCivilianNPCsSpawned < iMaxAICivilianNPCsToSpawn)
			{
				if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != None)
				{
					UE_LOG(LogTemp, Warning, TEXT("Spawning civilian: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag $ " object: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					iCivilianNPCsSpawned ++;
				}
			}
		}
		else
		{
			if (anpcpsPSToSpawn[iNPCPSSpawnIndex].IsA('NPCMortarSpotterController'))
			{
				if (iMaxAISpotterNPCsToSpawn == -1 || iNPCSpottersSpawned < iMaxAISpotterNPCsToSpawn)
				{
					if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != None)
					{
						iNPCSpottersSpawned ++;
						UE_LOG(LogTemp, Warning, TEXT("Spawning mortar spotter # " $ iNPCSpottersSpawned $ ": " $ anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag $ " object: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					}
				}
			}
			else
			{
				if (iMaxAINPCsToSpawn > 0)
				{
					if (iNPCsSpawned >= iMaxAINPCsToSpawn && ! anpcpsPSToSpawn[iNPCPSSpawnIndex].bMustSpawn)
					{
						if (++ iNPCPSSpawnIndex < anpcpsPSToSpawn.Length)
						{
							SetCustomTimer(fpNPCSpawnDelay,False,'NPCSpawnTimer');
						}
						else
						{
							Log("Balance Information Balanced Soldier NPCs Spawned: " $ iNPCsSpawned $ ", (Must Spawn: " $ iMustSpawnNPCsSpawned $ "), Spotters: " $ iNPCSpottersSpawned $ ", Civilian: " $ iCivilianNPCsSpawned $ ", Players: " $ iPlayersSpawned);
						}
						Return;
					}
				}
				if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != None)
				{
					UE_LOG(LogTemp, Warning, TEXT("Spawning soldier: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag $ " object: " $ anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					iNPCsSpawned ++;
				}
			}
		}
		if (++ iNPCPSSpawnIndex < anpcpsPSToSpawn.Length)
		{
			SetCustomTimer(fpNPCSpawnDelay,False,'NPCSpawnTimer');
		}
		else
		{
			Log("Balance Information Balanced Soldier NPCs Spawned: " $ iNPCsSpawned $ ", (Must Spawn: " $ iMustSpawnNPCsSpawned $ "), Spotters: " $ iNPCSpottersSpawned $ ", Civilian: " $ iCivilianNPCsSpawned $ ", Players: " $ iPlayersSpawned);
		}
	*/
}

void AAGP_GameInfo::PreparePlayerForStartMatch(APlayerController* PC)
{
	/*
		PC.PlayerReplicationInfo.bOutOfLives=False;
		PC.PlayerReplicationInfo.bDead=False;
		if (PC.PlayerReplicationInfo.bIsMedic)
		{
			PC.NotifyPlayerOfMedicStatus();
		}
	*/
}

void AAGP_GameInfo::CleanupLevel()
{
	/*
		local Pawn p;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel()	Looking for bodies..."));
		ForEach DynamicActors(Class'Pawn',p)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel()	Found " $ p @ p.Controller));
			if (p.IsA('AGP_Vehicle'))
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying vehicle " $ p));
				p.Destroy();
			}
			else
			{
				if (p.IsA('SVehicle') && p.Controller != None)
				{
					if (p.Controller != None && p.Controller.IsA('NPCBaseHelicopterController'))
					{
						Log("Cleaning up Blackhawk by destroying controller");
						NPCBaseHelicopterController(p.Controller).Destroy();
					}
					else
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying svehicle with controller " $ p));
						p.Destroy();
					}
					if (p.Controller != None && HumanController(p.Controller) != None && HumanController(p.Controller).PlayerReplicationInfo != None)
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() for player " $ HumanController(p.Controller).PlayerReplicationInfo.PlayerName));
					}
					if (p.IsA('NPC_Ambient'))
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() skipping NPC_Ambient: " $ p.Controller));
					}
					else
					{
						if (p.Controller != None && ! p.IsA('FSTS_NPC'))
						{
							UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying pawn " $ p));
							p.Destroy();
						}
						else
						{

						}
					}
				}
			}
		}
	*/
}

void AAGP_GameInfo::AssignStartPoints()
{
	/*
		local NavigationPoint N;
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (N.IsA('AGP_PlayerStart'))
			{
				UE_LOG(LogTemp, Warning, TEXT("Resetting PS: " $ N));
				AGP_PlayerStart(N).Reset();
			}
			N=N.nextNavigationPoint;
		}
	*/
}

void AAGP_GameInfo::AssignClassAndRole()
{
	/*
		local Controller C;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AssignClassAndRole()"));
		C=Level.ControllerList;
		if (C != None)
		{
			if (C.IsA('AIController'))
			{
			}
			if (C.IsInState('ValidatePB') || C.IsInState('ServerAuthorizePlayer') || C.IsInState('FailedAuthorization') || C.IsInState('PlayerAuthorizationComplete'))
			{
				if (C.PlayerReplicationInfo != None)
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AssignClassAndRole " $ C.PlayerReplicationInfo.PlayerName $ " still authorizing, skipping assignment"));
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AssignClassAndRole still authorizing for player without PRI, skipping assignment"));
				}
			}
			else
			{
				if (PlayerController(C) != None && PlayerController(C).PlayerReplicationInfo.bOnlySpectator)
				{
				}
				C.TeamClassClass=GetTeamClass(C);
				C.TeamRoleClass=GetTeamRole(C);
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".AssignClassAndRole() - Got team class and role for player """ $ C.PlayerReplicationInfo.PlayerName $ """: " $ C.TeamClassClass $ ", " $ C.TeamRoleClass));
			}
			C=C.nextController;
		}
	*/
}

void AAGP_GameInfo::RecordStartMatch()
{
}
void AAGP_GameInfo::CheckClassWithPlayerStart(AController* PC)
{
}
void AAGP_GameInfo::IsClassLegal(ASoldierClass* sclass)
{
	/*
		local NavigationPoint N;
		local AGP_PlayerStart agppsFound;
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (N.IsA('AGP_PlayerStart'))
			{
				agppsFound=AGP_PlayerStart(N);
				if (agppsFound.GetSpawnClass() == sclass)
				{
					Return True;
				}
			}
			N=N.nextNavigationPoint;
		}
		if (agppsFound == None)
		{
			Return True;
		}
		Return False;
	*/
}
void AAGP_GameInfo::StartScreenplay()
{
	/*
		local Controller C;
		local HumanController HC;
		if (_Screenplay == None)
		{
			Return;
		}
		if (IsMultiPlayer())
		{
			_Screenplay.Trigger(Self,None);
			Return;
		}
		C=Level.ControllerList;
		if (C != None)
		{
			if (C.IsA('HumanController'))
			{
				HC=HumanController(C);
			}
			else
			{
				C=C.nextController;
			}
		}
		if (HC == None)
		{
		}
		_Screenplay.Trigger(HC,None);
	*/
}
bool AAGP_GameInfo::IsRequireAuthorization()
{
	return false;
}
void AAGP_GameInfo::GetTeamClass(AController* C)
{
	/*
		Return GetDefaultTeamClass();
	*/
}
void AAGP_GameInfo::GetDefaultTeamClass()
{
	/*
		Return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRifleman",Class'Class'));
	*/
}
void AAGP_GameInfo::GetTeamRole(AController* C)
{
	/*
		Return GetDefaultTeamRole();
	*/
}
void AAGP_GameInfo::GetDefaultTeamRole()
{
	/*
		Return class<Actor>(DynamicLoadObject("AGP_AI.GroupFollowerRole",Class'Class'));
	*/
}
bool AAGP_GameInfo::ShouldRespawn(APickup* Other)
{
	return Other->bPlacedPickup;
}
void AAGP_GameInfo::PickupQuery(APawn* Other, APickup* Item)
{
	/*
		Return Other.Controller.HandlePickupQuery(Item);
	*/
}
void AAGP_GameInfo::SetFirstObjective(AActor* Objective)
{
}
void AAGP_GameInfo::SetSquadTarget(int32 iTeamIndex, uint8 objnum)
{
}
void AAGP_GameInfo::ScoreAGPObjective(ATeamInfo* Team, AActor* Objective, bool abGameEnded, AAA2_PlayerState*  Scorer, bool bScorerOnly)
{
}
void AAGP_GameInfo::ScoreDecoMesh(ATeamInfo* Team, AActor Objective, int32 ScorePoints, AAA2_PlayerState*  Scorer, bool bScorerOnly)
{
}
void AAGP_GameInfo::RecordFriendlyFire(AAA2_PlayerState*  ShooterPRI, APawn* VictimPawn, int32 Score)
{
}
void AAGP_GameInfo::RestartGame()
{
	

	/*
		if (GetNetMode() == ENetMode::NM_DedicatedServer)
		{
			LogFileWrite("DevNet","LogEnd");
			LogFileClose();
		}
		RestartGame();
	*/
}
void AAGP_GameInfo::ApplicationShutdown()
{
	/*
		if (GetNetMode() == ENetMode::NM_Client)
		{
			Return;
		}
		if ('HumanController'.Default.bDontRememberUsernameAndPassword)
		{
			Log(Self $ "ApplicationShutdown() - Resetting user information on shutdown");
			'HumanController'.Default.UserName="UserName";
			'HumanController'.Default.sSavedUserName="UserName";
			HumanController(Level.GetLocalPlayerController()).ObfuscatePassword("Password");
			'HumanController'.StaticSaveConfig();
		}
	*/
}
void AAGP_GameInfo::GameEnding()
{
	/*
		GameEnding();
		if (_Screenplay != None)
		{
			_Screenplay.Destroy();
		}
	*/
}
void AAGP_GameInfo::FakeRestartGame()
{
	/*
		local Controller C;
		local Actor A;
		local NavigationPoint N;
		ForEach DynamicActors(Class'Actor',A)
		{
			if (A.IsA('Pickup'))
			{
				A.MatchEnding();
			}
			else
			{
				if (A.IsA('Emitter'))
				{
					A.MatchEnding();
				}
				else
				{
					if (A.IsA('Vehicle') || A.IsA('AGP_DestroyedVehicleModels') || A.IsA('VehicleWeapon'))
					{
						A.MatchEnding();
					}
					else
					{
						if (A.IsA('CallForSupport'))
						{
							A.Reset();
						}
					}
				}
			}
		}
		C=Level.ControllerList;
		if (C != None)
		{
			C.StartSpot=None;
			C=C.nextController;
		}
		N=Level.NavigationPointList;
		if (N != None)
		{
			if (N.IsA('AGP_PlayerStart'))
			{
				AGP_PlayerStart(N).Reset();
			}
			N=N.nextNavigationPoint;
		}
		Reset();
	*/
}
bool AAGP_GameInfo::IsMultiPlayer()
{
	return false;
}
bool AAGP_GameInfo::IsFriend(APawn* me, APawn* you)
{
	if (me == you)
	{
		return true;
	}
	return false;
}
bool AAGP_GameInfo::IsTeamFriend(uint8 Team, APawn* you)
{
	return false;
}
bool AAGP_GameInfo::IsTeamGame()
{
	return false;
}
uint8 AAGP_GameInfo::GetPlayerTeamIndex(AController* C)
{
	return 255;
}
void AAGP_GameInfo::GetScreenplay()
{
	/*
		Return _Screenplay;
	*/
}
bool AAGP_GameInfo::IsUnlimitedRespawn()
{
	return Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->bUnlimitedRespawn;
}
bool AAGP_GameInfo::IsAllowRepawn()
{
	return Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->bAllowRespawn;
}
bool AAGP_GameInfo::IsAllowLateJoin()
{
	return Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->bAllowLateJoin;
}
/*

void AAGP_GameInfo::Login(FString Portal, FString Options, FString Error)
{
		local Controller C;
		local PlayerController NewPlayer;
		local string InUserName;
		local string inClass;
		local string InSkin;
		local string InMAC;
		local string InName;
		local string InAdminName;
		local string InPassword;
		local string InChecksum;
		local string inCharacter;
		local string InSex;
		local string sInPlayerAdminPassword;
		local byte InTeam;
		local bool bSpectator;
		local bool bAdmin;
		local bool bPlayerAdmin;
		local class<Security>  MySecurityClass;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Options: """ $ Options $ """"));
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
		{
			Options=StripColor(Options);
		}
		InUserName=Left(ParseOption(Options,"UserName"),40);
		Log("Incoming username: """ $ InUserName $ """");
		inClass=ParseOption(Options,"Class");
		InSkin=ParseOption(Options,"Skin");
		InMAC=ParseOption(Options,"MAC");
		InName=Left(ParseOption(Options,"Name"),20);
		InTeam=GetIntOption(Options,"Team",255);
		InAdminName=ParseOption(Options,"AdminName");
		InPassword=ParseOption(Options,"Password");
		InChecksum=ParseOption(Options,"Checksum");
		sInPlayerAdminPassword=Level.Game.ParseOption(Options,"PAPassword");
		if (AccessControl != None)
		{
			if (AccessControl.ValidatePlayerAdmin(InUserName,sInPlayerAdminPassword))
			{
				if (Level.Game.NumAdmins < Level.Game.MaxAdmins)
				{
					bPlayerAdmin=True;
				}
			}
			else
			{
				bPlayerAdmin=False;
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() trying to login admin using password"));
			bAdmin=AccessControl.AdminLogin(NewPlayer,InPassword);
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() finished trying to login admin using password"));
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Parsing for spectator flag"));
		bSpectator=ParseOption(Options,"SpectatorOnly") ~= "true" || ParseOption(Options,"SpectatorOnly") ~= "1";
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Finished parsing spectator flag"));
		if (AtCapacity(bSpectator,bAdmin))
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Server at capacity, aborting"));
			Error=GameMessageClass.Default.MaxedOutMessage;
			Return None;
		}
		if (bAdmin)
		{
			bSpectator=True;
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() About to call ModifyLogin mutator"));
		BaseMutator.ModifyLogin(Portal,Options);
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Parsing for character type"));
		inCharacter=ParseOption(Options,"Character");
		InSex=ParseOption(Options,"Sex");
		if (bAdmin && bSpectator)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Adjusting admin privileges"));
			if (AccessControl.AdminClass == None)
			{
				if (True)
				{
					UE_LOG(LogTemp, Warning, TEXT("Creating Admin ""SuperAdmin"" class"));
					AccessControl.AdminClass=class<PlayerController>(DynamicLoadObject("AGP_Gameplay.SuperAdmin",Class'Class'));
				}
				if (AccessControl.AdminClass == None)
				{
					AccessControl.AdminClass=class<PlayerController>(DynamicLoadObject(AccessControl.AdminClassName,Class'Class'));
				}
			}
			UE_LOG(LogTemp, Warning, TEXT("Creating new user class of " $ AccessControl.AdminClass.Class));
			NewPlayer=Spawn(AccessControl.AdminClass);
		}
		else
		{
			if (PlayerControllerClass == None)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() DLO HC class"));
				PlayerControllerClass=class<PlayerController>(DynamicLoadObject(PlayerControllerClassName,Class'Class'));
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() spawning controller for player"));
			NewPlayer=Spawn(PlayerControllerClass);
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() spawned controller for player: " $ NewPlayer));
		}
		if (NewPlayer == None)
		{
			UE_LOG(LogTemp, Warning, TEXT("Couldn't spawn player controller of class " $ PlayerControllerClass));
			Error=GameMessageClass.Default.FailedSpawnMessage;
			Return None;
		}
		AccessControl.SignalPlayerQualified(NewPlayer,bAdmin);
		NewPlayer.PlayerReplicationInfo.bAdmin=bAdmin;
		NewPlayer.PlayerReplicationInfo.bPlayerAdmin=bPlayerAdmin;
		NewPlayer.PlayerReplicationInfo.PlayerMAC=InMAC;
		NewPlayer.PlayerReplicationInfo.PlayerName=InUserName;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Player is Admin: " $ NewPlayer.PlayerReplicationInfo.bAdmin));
		if (NewPlayer.PlayerReplicationInfo.bAdmin && HumanController(NewPlayer) != None)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Creating ServerInfo... "));
			HumanController(NewPlayer).ServerInfo=Spawn('AGP_ServerInfo');
		}
		NewPlayer.GameReplicationInfo=GameReplicationInfo;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() loading security class"));
		SecurityClass="AGP.AGPS";
		MySecurityClass=class<Security>(DynamicLoadObject(SecurityClass,Class'Class'));
		if (MySecurityClass != None)
		{
			NewPlayer.PlayerSecurity=Spawn(MySecurityClass,NewPlayer);
			if (NewPlayer.PlayerSecurity == None)
			{
				Log("Could not spawn security for player " $ NewPlayer,'Security');
			}
		}
		else
		{
			Log("Unknown security class [" $ SecurityClass $ "] -- System is not secure.",'Security');
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Setting default player name"));
		if (InUserName == "")
		{
			InName=DefaultPlayerName;
		}
		InUserName=Cast<AAA2_GameMode>(UGameplayStatics::GetGameMode(GetWorld()))->StripColor(InUserName);
		if (Len(InUserName) > 20)
		{
			InUserName=Left(InUserName,20);
		}
		ReplaceText(InUserName," ","_");
		ReplaceText(InUserName,"""","");
		ReplaceText(InUserName,"¤","");
		InUserName=HumanController(NewPlayer).StripBadCodes(InUserName);
		NewPlayer.PlayerReplicationInfo.PlayerName=InUserName;
		HumanController(NewPlayer).UserName=InUserName;
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Calling ChangeName"));
			C=Level.ControllerList;
			if (C != None)
			{
				if (C == NewPlayer)
				{
				}
				if (NewPlayer.PlayerReplicationInfo.PlayerName == C.PlayerReplicationInfo.PlayerName)
				{
					Log("ERROR: Duplicate login name with player already on server: """ $ NewPlayer.PlayerReplicationInfo.PlayerName $ """");
					Error="Player Name Already In Use On Server";
					NewPlayer.Destroy();
					Return None;
				}
				C=C.nextController;
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Done calling ChangeName"));
			FlushLogNative();
		}
		if (InUserName == "")
		{
			if (GetNetMode() == ENetMode::NM_DedicatedServer)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Setting name after failed to find good name"));
				Error="Username not specified in connect attempt";
				NewPlayer.Destroy();
				Return None;
			}
			else
			{
				InUserName=NewPlayer.GetAuthUserName();
			}
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Setting skin preference"));
		FlushLogNative();
		NewPlayer.SetSkinPreference(InSkin);
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Finished setting skin preference"));
		FlushLogNative();
		NewPlayer.PlayerReplicationInfo.PlayerID=CurrentID ++;
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Player ID set to " $ NewPlayer.PlayerReplicationInfo.PlayerID));
		FlushLogNative();
		if (bAdmin)
		{
			NumAdmins ++;
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Admins logged in: " $ NumAdmins));
			FlushLogNative();
		}
		if (bSpectator || NewPlayer.PlayerReplicationInfo.bOnlySpectator)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() - Setting spectator flag"));
			FlushLogNative();
			NewPlayer.PlayerReplicationInfo.bOnlySpectator=True;
			NumSpectators ++;
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Spectator joining, changing to spectator team"));
			FlushLogNative();
			ChangeTeam(NewPlayer,254);
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() player sent to spectating team"));
			FlushLogNative();
			Return NewPlayer;
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() About to change team to spectating for player"));
		if (! ChangeTeam(NewPlayer,255))
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() cannot assign player to spectator team, aborting"));
			Error=GameMessageClass.Default.FailedTeamMessage;
			NewPlayer.Destroy();
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Aborted player assignment (destroyed controller)"));
			Return None;
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Updating clients scoreboard rules"));
		UpdateClientScoreMode(NewPlayer);
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Finished updating clients scoreboard rules"));
		NumPlayers ++;
		bWelcomePending=True;
		if (GetNetMode() == ENetMode::NM_DedicatedServer || GetNetMode() == ENetMode::NM_ListenServer)
		{
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer())
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Sending welcome message for player"));
				BroadcastLocalizedMessage(GameMessageClass,1,NewPlayer.PlayerReplicationInfo);
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Finished welcome message for player"));
			}
			else
			{
				Broadcast(Self,"A new player is joining the server.");
			}
		}
		if (bDelayedStart)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Delayed start for player, returning controller"));
			Return NewPlayer;
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Login() Non-delayed start, returning player"));
		return NewPlayer;
}
*/

void AAGP_GameInfo::FinishPostLogin(APlayerController* NewPlayer)
{
}

void AAGP_GameInfo::BanPlayerAccount(APlayerController* Cheater)
{
	/*
		if (IsRequireAuthorization())
		{
			Broadcast(Self,Cheater.PlayerReplicationInfo.PlayerName @ " did something stupid!");
			Cheater.ClientDisconnect("Cheat detected!  This will be recorded in your account");
			Cheater.GotoState('FailedAuthorization');
		}
	*/
}
void AAGP_GameInfo::RestartPlayer(AController* aPlayer)
{
	Super::RestartPlayer(aPlayer);  //Mine ELiZ

	/*
		local NavigationPoint StartSpot;
		local AGP_PlayerStart astartSpot;
		local int TeamNum;
		local class<Pawn>  DefaultPlayerClass;
		local PlayerReplicationInfo aPRI;
		UE_LOG(LogTemp, Warning, TEXT(" "));
		UE_LOG(LogTemp, Warning, TEXT(" "));
		UE_LOG(LogTemp, Warning, TEXT(" "));
		UE_LOG(LogTemp, Warning, TEXT("*****************************************"));
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() " $ aPlayer));
		if (aPlayer.PlayerReplicationInfo != None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() for player " $ aPlayer.PlayerReplicationInfo.PlayerName));
		}
		if (bRestartLevel && GetNetMode() != ENetMode::NM_DedicatedServer && GetNetMode() != ENetMode::NM_ListenServer)
		{
			Return;
		}
		aPRI=aPlayer.PlayerReplicationInfo;
		if (aPRI == None || aPRI.Team == None)
		{
			TeamNum=255;
		}
		else
		{
			TeamNum=aPRI.Team.TeamIndex;
		}
		if (! aPlayer.IsA('AIController'))
		{
			if (IsTournamentMode())
			{
				if (ShouldSpectate(aPRI))
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() - TM - Forcing player into spectate mode from current state: " $ aPlayer.GetStateName()));
					EnterSpectatorMode(aPlayer);
					HumanController(aPlayer).ClientResetSpectator();
					Return;
				}
			}
			else
			{
				if (ShouldSpectate(aPRI) || ! HumanController(aPlayer).bPlayerIsReadyToPlay || ! aPlayer.IsInState('Spectating') && ! aPlayer.IsInState('GameEnded') && ! aPlayer.IsInState('Dead'))
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() - Forcing player into spectate mode from current state: " $ aPlayer.GetStateName()));
					EnterSpectatorMode(aPlayer);
					HumanController(aPlayer).ClientResetSpectator();
					Return;
				}
			}
		}
		if (aPlayer.Pawn != None)
		{
			aPlayer.Pawn.Destroy();
			aPlayer.Pawn=None;
		}
		StartSpot=FindPlayerStart(aPlayer,TeamNum);
		if (StartSpot == None)
		{
			Log("AGP_GameInfo::RestartPlayer()	No legal playerstart found.");
			EnterSpectatorMode(aPlayer);
			HumanController(aPlayer).ClientMessage("Unable to find a starting spot for you (the server may be full).  You will need to watch this round.");
			HumanController(aPlayer).ClientResetSpectator();
			Return;
		}
		else
		{
			if (StartSpot.IsA('AGP_PlayerStart'))
			{
				AGP_PlayerStart(StartSpot).UsePlayerStart();
			}
		}
		aPlayer.StartSpot=StartSpot;
		UE_LOG(LogTemp, Warning, TEXT("PawnClass=" $ aPlayer.PawnClass));
		if (aPlayer.PawnClass != None)
		{
			aPlayer.Pawn=Spawn(aPlayer.PawnClass,,,StartSpot.GetStartLocation(),StartSpot.GetStartRotation());
			UE_LOG(LogTemp, Warning, TEXT("Pawn=" $ aPlayer.Pawn));
		}
		if (aPlayer.Pawn == None)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - pawn not spawned for class " $ aPlayer.PawnClass));
			DefaultPlayerClass=GetDefaultPlayerClass(aPlayer);
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - Default PawnClass = " $ DefaultPlayerClass));
			aPlayer.Pawn=Spawn(DefaultPlayerClass,,,StartSpot.GetStartLocation(),StartSpot.GetStartRotation());
			UE_LOG(LogTemp, Warning, TEXT("Pawn=" $ aPlayer.Pawn));
		}
		UE_LOG(LogTemp, Warning, TEXT("Controller" @ aPlayer @ "got startspot" @ StartSpot @ "dfc" @ DefaultPlayerClass @ "and pawnclass" @ aPlayer.PawnClass));
		if (aPlayer.Pawn == None)
		{
			if (HumanController(aPlayer) != None)
			{
				HumanController(aPlayer).ClientMessage("Unable to create a player pawn for you (the server may be full).  You will need to watch this round.");
			}
			Log("AGP_GameInfo::RestartPlayer() Couldn't spawn Pawn of type " $ aPlayer.PawnClass $ " at " $ StartSpot);
			aPlayer.GotoState('Dead');
			Return;
		}
		aPlayer.Pawn.Anchor=StartSpot;
		aPlayer.Pawn.LastStartSpot=PlayerStart(StartSpot);
		aPlayer.Pawn.LastStartTime=GetWorld()->GetTimeSeconds();
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() " $ aPlayer $ " trying to possess " $ aPlayer.Pawn));
		aPlayer.PreviousPawnClass=aPlayer.Pawn.Class;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer calling aPlayer.Possess() [aPlayer=" $ aPlayer $ "]"));
		aPlayer.Possess(aPlayer.Pawn);
		aPlayer.PawnClass=aPlayer.Pawn.Class;
		if (AGP_PlayerStart(aPlayer.StartSpot) != None)
		{
			if (AGP_PlayerStart(aPlayer.StartSpot).GetInitialHealth() < aPlayer.Pawn.Default.Health)
			{
				aPlayer.Pawn.Health=AGP_PlayerStart(aPlayer.StartSpot).GetInitialHealth();
				aPlayer.Pawn.BleedMax=aPlayer.Pawn.Default.Health - AGP_PlayerStart(aPlayer.StartSpot).GetInitialHealth();
			}
		}
		aPlayer.Pawn.PlayTeleportEffect(True,True);
		aPlayer.ClientSetRotation(aPlayer.Pawn.Rotation);
		if (! aPlayer.IsA('AIController'))
		{
			HumanController(aPlayer).AGPHUD(True);
			HumanController(aPlayer).ClientLockPlayer(True,True);
			HumanController(aPlayer).ClientCloseMenu(False);
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer calling AddDefaultInventory(" $ aPlayer.Pawn $ ")"));
		}
		AddDefaultInventory(aPlayer.Pawn);
		if (! aPlayer.IsA('AIController'))
		{
			TriggerEvent(StartSpot.Event,StartSpot,aPlayer.Pawn);
			astartSpot=AGP_PlayerStart(StartSpot);
			if (astartSpot != None && astartSpot.StartIndex > 0)
			{
				TriggerEvent(astartSpot.ProxyList[astartSpot.StartIndex - 1].Event,astartSpot.ProxyList[astartSpot.StartIndex - 1],aPlayer.Pawn);
			}
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - forcing first person view for player"));
			HumanController(aPlayer).ClientSetBehindView(False);
		}
	*/
	UE_LOG(LogTemp, Warning, TEXT("*****************************************"));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
}

void AAGP_GameInfo::EnterSpectatorMode(AController* aPlayer)
{
	/*
		local HumanController HC;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::EnterSpectatorMode() entered for " $ aPlayer));
		HC=HumanController(aPlayer);
		if (HC != None)
		{
			if (HC.IsInState('ValidatePB') || HC.IsInState('ServerAuthorizePlayer') || HC.IsInState('FailedAuthorization') || HC.IsInState('PlayerAuthorizationComplete'))
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::EnterSpectatorMode() - User authorizing, state change skipped"));
				Return;
			}
			HC.SetStartupStage(9);
			HC.ClientGotoState('Spectating','None');
			HC.GotoState('Spectating');
		}
		else
		{
			aPlayer.Destroy();
		}
	*/
}
bool AAGP_GameInfo::ShouldSpectate(AAA2_PlayerState*  p)
{
	if (bWaitingToStartMatch || GetNetMode() == ENetMode::NM_Standalone)
	{
		return false;
	}
	if (p->isSpectator())
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.ShouldSpectate() - player is spectator"));
		return true;
	}
	if (bWaitingToStartMatch || GetNetMode() == ENetMode::NM_Standalone)
	{
		return false;
	}
	//UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::ShouldSpectate()	Match in progres: " $ p.bDead @ p.bOutOfLives));
	if (p->bDead)
	{
		return p->bOutOfLives;
	}
	else
	{
		return !Cast<AAA2_WorldSettings>(GetWorldSettings())->bAllowLateJoin;
	}
}

bool AAGP_GameInfo::CanRespawn(AController* C)
{
	if (Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->bAllowRespawn)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void AAGP_GameInfo::Killed(AController* Killer, AController* Killed, APawn* KilledPawn, UaDamageType* DamageType)
{
	/*
		local PlayerController KillerPC;
		local PlayerController KilledPC;
		if (Killer == None && Killed != None)
		{
			Killer=Killed;
		}
		if (Killer != None)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() entered for killer " $ Killer.Tag $ " with killed: " $ Killed $ " and pawn: " $ KilledPawn));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() entered for unknown killer "));
		}
		if (Killed == None || Killed.PlayerReplicationInfo == None)
		{
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() - No killed PRI, not coop, aborting scoring"));
				return;
			}
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() - No PRI for killed pawn but CoOp game"));
		}
		if (Killed != None && Killed.PlayerReplicationInfo != None)
		{
			Killed.PlayerReplicationInfo.bDead=True;
		}
		KillerPC=PlayerController(Killer);
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() Killer: " $ KillerPC));
		if (KillerPC != None)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() valid killer (player), stats index: " $ KillerPC.PlayerStatsIndex));
		}
		if (Killed != None && Level.Game.Stats != None && KillerPC != None && KillerPC.PlayerStatsIndex >= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() scoring damage type: " $ DamageType.Default.AmmoType));
			Switch(DamageType.Default.AmmoType)
			{
				case 3:
				case 4:
				case 15:
				case 2:
				Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledGrenade();
				break;
				case 14:
				Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledRocket();
				break;
				case 18:
				Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledMachineGun();
				break;
				default:
				if (KillerPC.Pawn != None && AGP_Weapon(KillerPC.Pawn.Weapon) != None && ! KillerPC.Pawn.IsA('ThrowWeapon') && ! KillerPC.Pawn.IsA('RocketWeapon'))
				{
					UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() with valid stats, weapon type: " $ AGP_Weapon(KillerPC.Pawn.Weapon).StatWeaponType));
					Switch(AGP_Weapon(KillerPC.Pawn.Weapon).StatWeaponType)
					{
						case 3:
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledPistol();
						break;
						case 4:
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledSniperRifle();
						break;
						case 5:
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledMachineGun();
						break;
						case 6:
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledAssaultRifle();
						break;
						default:
						UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() with valid stats, not directly supported weapon, defaulting to assault rifle"));
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledAssaultRifle();
						break;
					}
				}
			}
		}
		if (Killed != None && Level.Game.Stats != None)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() Killed: " $ Killed $ " by killer " $ Killer $ ", updating killer's kill stats"));
			if (KillerPC != None && KillerPC.PlayerStatsIndex >= 0 && Killer != Killed)
			{
				Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_Kill();
			}
			KilledPC=PlayerController(Killed);
			UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() KilledPC: " $ KilledPC));
			if (KilledPC != None && KilledPC.PlayerStatsIndex >= 0)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed() Player killed stats index: " $ KilledPC.PlayerStatsIndex));
				STS2_PlayerStatsInfo(Level.Game.Stats.PlayerStats[KilledPC.PlayerStatsIndex]).StatEvent_Death(KilledPC.Pawn.Location);
			}
		}
		NotifyKilled(Killer,Killed,KilledPawn);
		UE_LOG(LogTemp, Warning, TEXT(Self $ "::Killed() - Killed: " $ Killed $ "  Killer: " $ Killer $ "  KilledPawn: " $ KilledPawn));
		if (Killed == None && Killer.IsA('NPCBasePreCrewedVehicleController'))
		{
			if (KilledPawn != None && KilledPawn.TempController != None)
			{
				Killed=KilledPawn.TempController;
			}
		}
		if (Killed != None && Killed.bIsPlayer || Killed.IsA('NPCBaseSoldierController') || Killed.IsA('NPCBasePreCrewedVehicleController'))
		{
			BroadcastDeathMessage(Killer,Killed,DamageType);
			if (GameStats != None)
			{
				if (Killer == Killed || Killer == None)
				{
					if (Killer == None)
					{
						GameStats.KillEvent("K",None,Killed.PlayerReplicationInfo,DamageType);
					}
					else
					{
						GameStats.KillEvent("K",Killer.PlayerReplicationInfo,Killed.PlayerReplicationInfo,DamageType);
					}
				}
				else
				{
					if (bTeamGame && Killer.PlayerReplicationInfo != None && Killed.PlayerReplicationInfo != None && Killer.PlayerReplicationInfo.Team == Killed.PlayerReplicationInfo.Team)
					{
						GameStats.KillEvent("TK",Killer.PlayerReplicationInfo,Killed.PlayerReplicationInfo,DamageType);
					}
					else
					{
						GameStats.KillEvent("K",Killer.PlayerReplicationInfo,Killed.PlayerReplicationInfo,DamageType);
					}
				}
			}
		}
		if (Killed != None)
		{
			if (CanRespawn(Killed))
			{
				if (HumanController(Killed) != None)
				{
					HumanController(Killed).SetStartupStage(7);
				}
			}
			else
			{
				if (HumanController(Killed) != None)
				{
					HumanController(Killed).SetStartupStage(8);
				}
				if (Killed.PlayerReplicationInfo != None)
				{
					Killed.PlayerReplicationInfo.bOutOfLives=True;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT(Self $ ".Killed calling ScoreKill"));
		ScoreKill(Killer,Killed,DamageType);
		if (Killer != None && Killer.bIsPlayer && Killed != None && Killed.bIsPlayer)
		{
			LogFileWrite("ScriptLog",Killer.PlayerReplicationInfo.PlayerName $ ":Killed:" $ Killed.PlayerReplicationInfo.PlayerName $ ":" $ DamageType);
		}
	*/
}

void AAGP_GameInfo::ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType)
{
}
/*
void AAGP_GameInfo::ChangeName(AController* Other, FString S, bool bNameChange)
{
		local string O;
		local Controller C;
		local int Onum;
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::ChangeName()	Trying " $ S @ C));
		C=Level.ControllerList;
		if (C != None)
		{
			if (C == Other)
			{
			}
			if (C.IsA('NPCBaseController'))
			{
			}
			O=C.PlayerReplicationInfo.GetHumanReadableName();
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::ChangeName()	" $ O @ C));
			if (Caps(O) == Caps(S))
			{
				if (IsRequireAuthorization() && HumanController(Other).bInitialAuthComplete)
				{
					Log("Kicking duplicate name " $ PlayerController(Other).PlayerReplicationInfo.PlayerName);
					KickByController(Other,"DupName");
					Return;
				}
				if (Right(S,2) != 0)
				{
					S=Left(S,Len(S) - 2);
				}
				Onum=Right(O,2);
				Onum ++;
				if (Onum < 10)
				{
					S=S $ "0";
				}
				else
				{
					if (Onum > 99)
					{
						Onum=101;
					}
				}
				S=S $ Onum;
				ChangeName(Other,S,bNameChange);
				Return;
			}
			C=C.nextController;
		}
		ChangeName(Other,S,bNameChange);
}
*/

void AAGP_GameInfo::SimulateAuthFailure()
{
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthFailure() - Simulating auth failure"));
	ServerAuthFailures=3;
	AuthAuthenticateServerCallback(-4,0,"Auth Connection Lost");
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthFailure() - Auth flag: %s"), IsRequireAuthorization());
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthFailure() - fAuthNotAvailableLastAuthAttempt flag: %s"), fAuthNotAvailableLastAuthAttempt);
}

void AAGP_GameInfo::SimulateAuthRecovery()
{
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthRecovery() - Simulating auth failure recovery"));
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthFailure() - Auth flag: %s"), IsRequireAuthorization());
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.SimulateAuthFailure() - fAuthNotAvailableLastAuthAttempt flag: %s"), fAuthNotAvailableLastAuthAttempt);
	AuthorizeServer();
}

void AAGP_GameInfo::GetServerAuthData()
{
}
void AAGP_GameInfo::GetMapServerInfo()
{
	/*
		local Security secLocalSecurity;
		local class<Security>  scLocalSecurityClass;
		local array<String> asMD5ForMap;
		scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
		if (scLocalSecurityClass != None)
		{
			secLocalSecurity=Spawn(scLocalSecurityClass,Self);
			if (secLocalSecurity != None)
			{
				secLocalSecurity.LocalPerform(2,"../Maps/" $ Level.sLevelName $ ".aao","",asMD5ForMap);
				Return asMD5ForMap[0];
			}
		}
		Return "";
	*/
}
void AAGP_GameInfo::AuthorizeServer()
{
	/*
		local DBAuth.AuthorizeServerRequestAdapter Adapter;
		local string IP;
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer() && IsRequireAuthorization() || fAuthNotAvailableLastAuthAttempt)
		{
			IP=Class'AuthorizeServerRequestAdapter'.GetServerAuthIP();
			UE_LOG(LogTemp, Warning, TEXT("Initiating authorization of server..." @ IP $ ":" $ GetServerPort() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "MaxPlayers:" $ MaxPlayers));
			if (Level.iTour < 0 || Level.iMission < 0)
			{
				Warn("Server authorization attempt with invalid tour or mission! Tour:" @ Level.iTour @ "Mission:" @ Level.iMission);
			}
			Adapter=Spawn(Class'AuthorizeServerRequestAdapter',Self);
			Adapter.Request(IP,GetServerPort(),Level.iTour,Level.iMission,MaxPlayers,AccessControl.GetGamePassword(),GetServerAuthData());
		}
		else
		{
			if (! IsRequireAuthorization() || Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
			{
				if (bDemoExploreTheArmyMode)
				{
					SetServerMode(100,"Instant Action");
				}
			}
		}
	*/
}

void AAGP_GameInfo::AuthorizeServerNow()
{
	ServerAuthFailures=0;
	AuthorizeServer();
}

void AAGP_GameInfo::SetServerMode(int32 ServerMode, FString ServerModeName)
{
}

void AAGP_GameInfo::Timer()
{
	Super::Timer();
	if (NextAuthTime != 0)
	{
		if (NextAuthTime < GetWorld()->GetTimeSeconds())
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::Timer()	Try to auth again!"));
			NextAuthTime=0;
			AuthorizeServer();
		}
	}
}

void AAGP_GameInfo::AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
{
	UE_LOG(LogTemp, Warning, TEXT("Authorization Failure: %s"), *sMsg);
}

void AAGP_GameInfo::LogServerAuthFailure(int32 ResultCode)
{
	switch(ResultCode)
	{
		case -1:
			UE_LOG(LogTemp, Warning, TEXT("Server Authorization Failed: Incorrect Password"));
			break;
		case -2:
			UE_LOG(LogTemp, Warning, TEXT("Server Authorization Failed: Invalid Username, IP or Port"));
			//Log("	(Attempted authorization with username:" @ Class'AuthorizeServerRequestAdapter'.GetServerAuthUsername() @ "ip:" @ Class'AuthorizeServerRequestAdapter'.GetServerAuthIP() $ ":" $ GetServerPort());
			break;
		default:
			break;
	}
}

void AAGP_GameInfo::AuthAuthenticateServerCallback(int32 ResultCode, int32 ServerMode, FString ServerModeName)
{
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback() - result code: %d"),ResultCode);
	if (ResultCode >= 0)
	{
		if (fAuthNotAvailableLastAuthAttempt)
		{
			//Level.ServerTravel("?Restart",False);
		}
		SetRequireAuthorization(true);
		fAuthNotAvailableLastAuthAttempt=false;
		ServerAuthFailures=0;
		SetServerMode(ServerMode,ServerModeName);
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	Success!( %d )"), ServerAuthFailures);
		if (ServerMode == 0)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	unauthorized server, retrying again later"));
			UE_LOG(LogTemp, Log, TEXT("Disabling GLOBAL mode because auth reported this server as unauthorized."));
			//Level.SetLanOnlyServer();
			NextAuthTime=GetWorld()->GetTimeSeconds() + 24 * 60 * 60;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback() authorized server - will recheck in 10 minutes"));
			NextAuthTime=GetWorld()->GetTimeSeconds() + 10 * 60;
		}
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	Retries: %d"), ServerAuthFailures);
		if (ServerAuthFailures == -1)
		{
			ServerAuthFailures=3;
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	This many ( %d )"),ServerAuthFailures);
			ServerAuthFailures ++;
		}
		if (ServerAuthFailures >= 3)
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	Changing server mode"));
			LogServerAuthFailure(ResultCode);
			SetServerMode(0,"Auth Comms Lost");
			ServerAuthFailures=0;
			SetRequireAuthorization(false);
			fAuthNotAvailableLastAuthAttempt=true;
			NextAuthTime=GetWorld()->GetTimeSeconds() + 120;
			//UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::AuthAuthenticateServerCallback()	Failed! Try again in " @ NextAuthTime - GetWorld()->GetTimeSeconds() @ " seconds."));
			return;
		}
		NextAuthTime=GetWorld()->GetTimeSeconds() + 5;
	}
}

void AAGP_GameInfo::BroadcastDeathMessage(AController* Killer, AController* Killed, UaDamageType* DamageType)
{
	/*
		local string sNPCName;
		if (! bDeathMessages)
		{
			Return;
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			UE_LOG(LogTemp, Warning, TEXT("Damage type: """ $ DamageType $ """ mortar damage index: " $ InStr(DamageType,"Mortar")));
			if (InStr(DamageType,"Mortar") >= 0)
			{
				if (Killed != None && Killed.IsA('NPCBaseController'))
				{
					sNPCName=NPCBaseController(Killed).sNPCName;
					Broadcast(Self,ParseKillMessage("Mortar Crew",sNPCName,DamageType.Default.DeathString),'AIKiller');
				}
				else
				{
					Broadcast(Self,ParseKillMessage("Mortar Crew",Killed.PlayerReplicationInfo.PlayerName,DamageType.Default.DeathString),'AIKiller');
				}
				Return;
			}
			if (Killer.IsA('NPCBasePreCrewedVehicleController'))
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".BroadcastDeathMessage() - Vehicle class: " $ NPCBasePreCrewedVehicleController(Killer).sVehicleType));
				sNPCName=NPCBasePreCrewedVehicleController(Killer).sVehicleType;
			}
			else
			{
				if (Killer.IsA('NPCBaseController'))
				{
					sNPCName=NPCBaseController(Killer).sNPCName;
				}
			}
			if (Killed.IsA('NPCBasePreCrewedVehicleController'))
			{
				UE_LOG(LogTemp, Warning, TEXT(Self $ ".BroadcastDeathMessage() - Vehicle class: " $ NPCBasePreCrewedVehicleController(Killed).sVehicleType));
				sNPCName=NPCBasePreCrewedVehicleController(Killed).sVehicleType;
			}
			else
			{
				if (Killed.IsA('NPCBaseController'))
				{
					sNPCName=NPCBaseController(Killed).sNPCName;
				}
			}
			if (Len(sNPCName) == 0)
			{
				sNPCName="Enemy forces";
			}
			if (Killer.IsA('AIController') && Killed.IsA('PlayerController'))
			{
				if (Killed.PlayerReplicationInfo != None)
				{
					Broadcast(Self,ParseKillMessage(sNPCName,Killed.PlayerReplicationInfo.PlayerName,DamageType.Default.DeathString),'AIKiller');
				}
				else
				{
					Broadcast(Self,ParseKillMessage(sNPCName,"A player",DamageType.Default.DeathString),'AIKiller');
				}
				Return;
			}
			else
			{
				if (Killer.IsA('PlayerController') && Killed.IsA('AIController'))
				{
					if (Killer.PlayerReplicationInfo != None)
					{
						Broadcast(Self,ParseKillMessage(Killer.PlayerReplicationInfo.PlayerName,sNPCName,DamageType.Default.DeathString),'AIKilled');
					}
					else
					{
						Broadcast(Self,ParseKillMessage("a player","An enemy",DamageType.Default.DeathString),'AIKilled');
					}
					Return;
				}
				else
				{
					if (Killer.IsA('AIController') && Killed.IsA('AIController'))
					{
						Return;
					}
				}
			}
		}
		BroadcastDeathMessage(Killer,Killed,DamageType);
	*/
}

void AAGP_GameInfo::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
	Super::InitGame(MapName, Options,ErrorMessage);

	if (GetNetMode() == ENetMode::NM_DedicatedServer && ShouldDownloadTours())
	{
		UE_LOG(LogTemp, Warning, TEXT("Checking for new Tours.ini file on %s"), *ServerToursDownloadServer);
		CheckForNewToursFile();
		DisableToursDownload();
	}
}
void AAGP_GameInfo::CheckForNewToursFile()
{
	/*
		local IpDrv.HttpLink MyLink;
		local IpDrv.HttpLinkItem RequestedItem;
		MyLink=Spawn(Class'HttpLink');
		if (MyLink != None)
		{
			MyLink.SetHost(ServerToursDownloadServer,80);
			MyLink.SetLocalFilePath(".");
			RequestedItem=MyLink.RequestText("/tours.ini");
			RequestedItem.__OnReceivedText__Delegate=ReceivedToursText;
			RequestedItem.__OnReceivedCachedFile__Delegate=OnReceivedCachedTours;
		}
	*/
}
void AAGP_GameInfo::ReceivedToursText(FString Filename, FString TextChunk)
{
	/*
		local int BufferHead;
		local string Buffer;
		if (FOpenWrite("tours.ini"))
		{
			BufferHead=0;
			if (BufferHead <= Len(TextChunk))
			{
				Buffer=Mid(TextChunk,BufferHead,768);
				FWrite(Buffer);
				BufferHead += 768;
			}
			FClose();
		}
		*/
		UE_LOG(LogTemp, Warning, TEXT(" "));
		UE_LOG(LogTemp, Warning, TEXT("************************** WARNING ***************************"));
		UE_LOG(LogTemp, Warning, TEXT("* Received updated Tours.ini from the server.                *"));
		UE_LOG(LogTemp, Warning, TEXT("* Server must be restarted in order to propagate the change. *"));
		UE_LOG(LogTemp, Warning, TEXT("**************************************************************"));
}
void AAGP_GameInfo::OnReceivedCachedTours(FString ReceivedFileName)
{
	UE_LOG(LogTemp, Warning, TEXT("Tours.ini file is up-to-date."));
}
bool AAGP_GameInfo::ShouldDownloadTours()
{
	return false;	//FAKE   /ELiZ
}
void AAGP_GameInfo::DisableToursDownload()
{

}