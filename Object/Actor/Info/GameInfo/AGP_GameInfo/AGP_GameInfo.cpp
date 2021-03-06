// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCHelicopterStart/NPCHelicopterStart.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCVehicleStart/NPCVehicleStart.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCUAVStart/NPCUAVStart.h"
#include "AA29/Object/Actor/Info/StatsInfo/STS2_DBAuthStatsInfo/STS2_DBAuthStatsInfo.h"
#include "AA29/Object/Actor/NPCConversationPack/NPCConversationPack.h"
#include "AA29/Object/Actor/Keypoint/AIScript/ScriptedSequence/ScriptedTrigger/ScriptedTrigger.h"
#include "AA29/Object/Actor/Emitter/EmitterSpawner/EmitterSpawner.h"
#include "AA29/Object/Actor/StaticMeshActor/FlagMeshActor/FlagMeshActor.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/Actor/Controller/AA2_Controller.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/PlayerStart/AGP_PlayerStart/AGP_PlayerStart.h"
#include "AA29/Object/Actor/AI_Primitive/AI_Interface/AI_Interface.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/NPCAICombatController/NPCAICombatController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStart.h"
#include "AA29/Object/Actor/AI_Primitive/SoldierClass/SoldierClass.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeServerRequestAdapter/AuthorizeServerRequestAdapter.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetLink/TcpLink/HttpLink/HttpLink.h"
#include "AA29/Object/Actor/Info/Security/Security.h"
#include "AA29/Object/HttpLinkItem/HttpLinkItem.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/AGP_Weapon.h"
#include "AA29/Object/Actor/Info/StatsInfo/STS2_DBAuthStatsInfo/STS2_DBAuthStatsInfo.h"
#include "AA29/Object/Actor/Info/AGP_ServerInfo/AGP_ServerInfo.h"
#include "AA29/Object/Actor/EventLab/EventLab.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseHelicopterController/NPCBaseHelicopterController.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/VehicleWeapon/VehicleWeapon.h"
#include "GameFramework/WorldSettings.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_CoopESSObjective/AGP_CoopESSObjective.h"
#include "AA29/Object/Actor/AGP_DestroyedVehicleModels/AGP_DestroyedVehicleModels.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_TriggeredObjective/AGP_ActivatedObjective/AGP_ESSObjective/AGP_ESSObjective.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/AGP_Vehicle/AGP_Vehicle.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/AGPVehicleStart/AGPVehicleStart.h"
#include "AA29/Object/Actor/CallForSupport/CallForSupport.h"
#include "AA29/Object/Actor/Triggers/Trigger/ESSTrigger/ESSTrigger.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/FSTS_Pawn/FSTS_NPC.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/NPC_Ambient/NPC_Ambient.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCBaseSoldierController.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBaseSoldierController/NPCMortarSpotterController/NPCMortarSpotterController.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/NPCPlayerStart/NPCPlayerStartCivilian/NPCPlayerStartCivilian.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "AA29/Object/Actor/Pawn/Vehicle/SVehicle/SVehicle.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/ThrowWeapon.h"
#include "Particles/Emitter.h"
#include "AA29/Object/Actor/Controller/AIController/NPCBaseController/NPCBasePreCrewedVehicleController/NPCBasePreCrewedVehicleControlle.h"

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
	//StatsClass = ASTS2_DBAuthStatsInfo::StaticClass();
}

/*
State MatchOver
{
	Function BeginState()
	{
		Super::BeginState();
		TerminateNPCSpawning();
	}
}
*/

void AAGP_GameInfo::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
}

void AAGP_GameInfo::EvaluatePlayerStatus(APlayerController* PC)
{
}

float AAGP_GameInfo::GetSystemTimeSeconds()
{
	return 0;    //FAKE   /ELiZ
}
void AAGP_GameInfo::PrecacheGameTextures(ALevelInfo* myLevel)
{
	/*
	myLeveL->AddPrecacheMaterial(Texture'BlobTexture');
	myLeveL->AddPrecacheMaterial(Texture'GRADIENT_Fade');
	myLeveL->AddPrecacheMaterial(Texture'fx_decal_dirt');
	myLeveL->AddPrecacheMaterial(Texture'fx_part_con');
	myLeveL->AddPrecacheMaterial(Texture'fx_smk_ball01');
	myLeveL->AddPrecacheMaterial(Texture'fx_part_smokeanim01');
	myLeveL->AddPrecacheMaterial(Texture'fx2_part_dirtbits');
	myLeveL->AddPrecacheMaterial(Texture'FX_dust_hitA');
	myLeveL->AddPrecacheMaterial(Texture'fx_smk_ball03');
	myLeveL->AddPrecacheMaterial(Texture'fx2_part_dirtclumps');
	myLeveL->AddPrecacheMaterial(Texture'fx_smk_ball02');
	myLeveL->AddPrecacheMaterial(Texture'fx_smk_ball04');
	myLeveL->AddPrecacheMaterial(Texture'fx2_part_spark01');
	myLeveL->AddPrecacheMaterial(Texture'fx_flash_tracer_new1a');
	myLeveL->AddPrecacheMaterial(Texture'fx2_cor_05');
	myLeveL->AddPrecacheMaterial(Texture'fx_particle_startblast01');
	myLeveL->AddPrecacheMaterial(Texture'Fade');
	myLeveL->AddPrecacheMaterial(Texture'skn_env_cubmap');
	myLeveL->AddPrecacheMaterial(Texture'skn_weap_hands_Cauc');
	myLeveL->AddPrecacheMaterial(Texture'skn_weap_camosleeve_Frst');
	myLeveL->AddPrecacheMaterial(Texture'skn_weap_camosleeve_new_frst');
	if (myCast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_pants_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_pants_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_camo_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_pants_camo_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_shirt_camo_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_pants_camo_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_c');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_d');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_e');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_f');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_commando_face_g');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_face_h');
		myLeveL->AddPrecacheMaterial(Texture't_char_commando_hands_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_hands_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_face_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_pants_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_shirt_a');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_pants_b');
		myLeveL->AddPrecacheMaterial(Texture't_char_enemy_infantry_shirt_b');
		myLeveL->AddPrecacheMaterial(Texture'Civ_HAND_MaleA');
		myLeveL->AddPrecacheMaterial(Texture'Civ_HAND_MaleB');
		myLeveL->AddPrecacheMaterial(Texture'Civ_HAND_MaleC');
		myLeveL->AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleA');
		myLeveL->AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleB');
		myLeveL->AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleC');
		myLeveL->AddPrecacheMaterial(Texture'CivilianA_FACE_Cauc_MaleD');
		myLeveL->AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_black');
		myLeveL->AddPrecacheMaterial(Texture'Civ_PANTS_Jeans_Blue');
		myLeveL->AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_Brown');
		myLeveL->AddPrecacheMaterial(Texture'Civ_PANTS_Slacks_Green');
		myLeveL->AddPrecacheMaterial(Texture'Civ_SHIRT_blue');
		myLeveL->AddPrecacheMaterial(Texture'Civ_SHIRT_Vest_WhiteA');
		myLeveL->AddPrecacheMaterial(Texture'Civ_SHIRT_WhiteA');
		myLeveL->AddPrecacheMaterial(Texture'Civ_SHIRT_yellow');
	}
	PrecacheGameTextures(myLevel);
	*/
}

void AAGP_GameInfo::PrecacheGameStaticMeshes(ALevelInfo* myLevel)
{
	/*
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
	*/
}

void AAGP_GameInfo::PreBeginPlay()
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
	//		LogFileWrite("DevNet",GameReplicationInfo.ServerName + ":" + Left(Level,InStr(Level,".")));
	//	}
	//}
}

void AAGP_GameInfo::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AAGP_GameInfo::BeginPlay()"));
	Super::BeginPlay();
	AScreenplay* S = nullptr;
	/*
		switch(ForceGameplay)
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
		_Screenplay=nullptr;
		ForEach AllActors(AScreenplay::StaticClass(),S)
		{
			_Screenplay=S;
			GOTO JL00A6;
	JL00A6:
		}
		if (_Screenplay == nullptr)
		{
			return;
		}
		*/
}

void AAGP_GameInfo::DisableQualification()
{
}

void AAGP_GameInfo::PostBeginPlay()
{
	//Super::PostBeginPlay();
}

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
	AHumanController* HC = nullptr;
	int32 i = 0;
	int32 t = 0;
	/*
	if (Stats != nullptr)
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
					if (GameReplicationInfo.Teams[t].ActualList_Player[i] != nullptr)
					{
						HC=Cast<AHumanController>(GameReplicationInfo.Teams[t].ActualList_Player[i].Owner);
						if (Stats != nullptr && HC != nullptr)
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

int32 AAGP_GameInfo::GetStatForPlayer(AHumanController* HC, FString sStatName)
{
	/*
	if (HC->PlayerStatsIndex >= 0)
	{
		switch(sStatName)
		{
			case "CapturedObjectives":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryCapturedObjectives();
			case "CapturedObjectiveDeaths":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryCapturedObjectiveDeaths();
			case "Healed":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryHealed();
			case "UsedMedic":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryUsedMedic();
			case "MedPacksUsed":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryMedPacksUsed();
			case "TimePlayedSeconds":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryTimePlayedSeconds();
			case "TimeAliveSeconds":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryTimeAliveSeconds();
			case "RoundsStarted":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundStarted();
			case "RoundsSurvivedWon":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundsSurvivedWon();
			case "RoundsSurvivedLost":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryRoundsSurvivedLost();
			case "ShotsFiredMachineGun":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredMachineGun();
			case "ShotsFiredAssaultRifle":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredAssaultRifle();
			case "ShotsFiredPistol":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredPistol();
			case "ShotsFiredGrenade":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredGrenade();
			case "ShotsFiredSniper":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredSniper();
			case "ShotsFiredRocket":
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsFiredRocket();
			case "ShotsHitMachineGun":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitMachineGun();
			case "ShotsHitAssaultRifle":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitAssaultRifle();
			case "ShotsHitPistol":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitPistol();
			case "ShotsHitGrenade":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitGrenade();
			case "ShotsHitSniper":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitSniper();
			case "ShotsHitRocket":
			if (! Level.Game.bDeathMessages)
			{
				return -1;
			}
			return Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].QueryShotsHitRocket();
			default:
		}
	}
	*/
	return 0;
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
		if (A->IsA(AEventLab::StaticClass()))
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
void AAGP_GameInfo::StartMatch()
{
	APlayerController* PC = nullptr;
	AController* p = nullptr;
	AActor* A = nullptr;
	APawn* DeleteMe = nullptr;
	ANPCPlayerStart* npcpsIterator = nullptr;
	ANPCVehicleStart* npcvsIterator = nullptr;
	ANPCHelicopterStart* npchsIterator = nullptr;
	ANPCUAVStart* npcuavsIterator = nullptr;
	ANPCConversationPack* npccpIterator = nullptr;
	int32 iPlayerVehiclesSpawned = 0;
	ANavigationPoint* npIterator = nullptr;
	ANPCAICombatController* npcaicc = nullptr;
	AScriptedTrigger* triggerIter = nullptr;
	/*
	DebugLog(DEBUG_Multi, "AGP_GameInfo::StartMatch() - Entered");
	GameReplicationInfo.bTempDisableRoundScoring = false;
	GameReplicationInfo.iSpotterBaseGridY = (Rand(5) * 10);
	GameReplicationInfo.iSpotterBaseGridY = (Rand(5) * 10);
	CalculateAIDifficultyValues();
	StopCustomTimer("NPCSpawnTimer");
	DebugLog(DEBUG_Multi, "AGP_GameInfo::StartMatch() - Entered");
	if (GameStats != nullptr)
	{
		GameStats.StartGame();
	}
	InitLogging();
	CleanupLevel();
	ForEach AllActors(Class'Actor', A)
	{
		A.MatchStarting();
	}
	GameReplicationInfo.bForceClassUsedInRound = GameReplicationInfo.bAllowForceclassing;
	UpdateClientsOfCheatAndForceclassStatus();
	AssignStartPoints();
	AssignClassAndRole();
	iPlayersSpawned = 0;
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		if (p->IsA(AaAIController::StaticClass()))
		{
		}
		DebugLog(DEBUG_PlayerSpawn, "AGP_GameInfo::StartMatch() - Trying to start " + FString::FromInt(p));
		PC = Cast<APlayerController>(p);
		if (PC != nullptr)
		{
			if (bGameEnded)
			{
				return;
			}
			DeleteMe = PC.Pawn;
			PC.Pawn = nullptr;
			if ((((PC.IsInState("ValidatePB") || PC.IsInState("ServerAuthorizePlayer")) || PC.IsInState("FailedAuthorization")) || PC.IsInState("UnauthorizedJoinComplete")) || PC.IsInState("PlayerAuthorizationComplete"))
			{
				DebugLog(DEBUG_PlayerSpawn, "Player validating or authorizing and not ready to play");
			}
			else
			{
				PreparePlayerForStartMatch(PC);
				DebugLog(DEBUG_PlayerSpawn, "AGP_GameInfo::StartMatch() - about to call RestartPlayer()");
				Cast<AHumanController>(PC).CleanupLevel();
				if (!PC.PlayerReplicationInfo.bOnlySpectator)
				{
					RestartPlayer(PC);
					if (PC.Pawn != nullptr)
					{
						LogPlayerStart(PC);
						iPlayersSpawned++;
					}
					else
					{
						EnterSpectatorMode(PC);
						Cast<AHumanController>(PC).ClientResetSpectator();
					}
				}
				else
				{
					EnterSpectatorMode(PC);
					Cast<AHumanController>(PC).ClientResetSpectator();
				}
				if (DeleteMe != nullptr)
				{
					DeleteMe.Controller = nullptr;
					DeleteMe.Destroy();
				}
			}
		}
	}
	AddAllPlayersToStatsInfo();
	ConfigureESSObjectives();
	ForEach AllActors(AScriptedTrigger::StaticClass(), triggerIter)
	{
		triggerIter.Reset();
	}
	if (ShouldIgnoreStats())
	{
		Stats.IgnoreStatsThisRound();
	}
	RecordStartMatch();
	if (!bDEBUGDisablePlayerVehicles)
	{
		iPlayerVehiclesSpawned = 0;
		for (npIterator = Level.NavigationPointList; npIterator != nullptr; npIterator = npIterator.nextNavigationPoint)
		{
			if ((iPlayerVehiclesSpawned == iMaxPlayerVehiclesToSpawn) && (iMaxPlayerVehiclesToSpawn > 0))
			{
			}
			if (!npIterator->IsA(AAGPVehicleStart::StaticClass()))
			{
			}
			AGPVehicleStart(npIterator).CreateVehicle();
			iPlayerVehiclesSpawned++;
		}
	}
	else
	{
		Log("WARNING - INI DEBUG AGP_GameInfo.bDEBUGDisablePlayerVehicles OPTION DISABLED PLAYER VEHICLES");
	}
	iNPCsSpawned = 0;
	if (fpMaxNPCToPlayerRatio > 2.5)
	{
		Log("Using configuration set NPC to player ratio");
		iMaxAINPCsToSpawn = int((fpMaxNPCToPlayerRatio * float((iPlayersSpawned + 1))));
		Log("NPC to Player Ratio set to " + FString::FromInt(fpMaxNPCToPlayerRatio));
	}
	else
	{
		if (Level.fpMaxNPCToPlayerRatio > 0)
		{
			iMaxAINPCsToSpawn = int((Level.fpMaxNPCToPlayerRatio * float((iPlayersSpawned + 1))));
		}
	}
	if ((iMaxAINPCsToSpawn < 25) && (iMaxAINPCsToSpawn != -1))
	{
		Log("AI limited to 25 by balance/ratio rules");
		iMaxAINPCsToSpawn = 25;
	}
	anpcpsPSToSpawn.RemoveAt(0, anpcpsPSToSpawn.Num());
	iNPCsSpawned = 0;
	iNPCPSSpawnIndex = 0;
	iNPCSpottersSpawned = 0;
	iCivilianNPCsSpawned = 0;
	iMustSpawnNPCsSpawned = 0;
	for (npIterator = Level.NavigationPointList; npIterator != nullptr; npIterator = npIterator.nextNavigationPoint)
	{
		if (!npIterator->IsA(ANPCPlayerStart::StaticClass()))
		{
		}
		npcpsIterator = NPCPlayerStart(npIterator);
		if (npcpsIterator.bSpawnAsReserve)
		{
		}
		if (!npcpsIterator.bSpawnable)
		{
		}
		if (npcpsIterator.bCanDelaySpawn && (GetNetMode() != ENetMode::NM_Standalone))
		{
			anpcpsPSToSpawn.insert(0, 1);
			anpcpsPSToSpawn[0] = npcpsIterator;
		}
		else
		{
			if (npcpsIterator->IsA(ANPCPlayerStartCivilian::StaticClass()))
			{
				if ((iMaxAICivilianNPCsToSpawn == -1) || (iCivilianNPCsSpawned < iMaxAICivilianNPCsToSpawn))
				{
					if (npcpsIterator.CreateNPC() != nullptr)
					{
						DebugLog(DEBUG_AISpawn, "Spawned civilian: " + FString::FromInt(npcpsIterator.Tag) + " object: " + FString::FromInt(npcpsIterator));
						iCivilianNPCsSpawned++;
					}
				}
			}
			else
			{
				if (npcpsIterator->IsA(ANPCMortarSpotterController::StaticClass()))
				{
					if (((iMaxAISpotterNPCsToSpawn == -1) || npcpsIterator.bMustSpawn) || (iNPCSpottersSpawned < iMaxAISpotterNPCsToSpawn))
					{
						if (npcpsIterator.CreateNPC() != nullptr)
						{
							DebugLog(DEBUG_AISpawn, "Spawned mortar: " + FString::FromInt(npcpsIterator.Tag) + " object: " + FString::FromInt(npcpsIterator));
							if (npcpsIterator.bMustSpawn)
							{
								iMustSpawnNPCsSpawned++;
							}
							iNPCSpottersSpawned++;
						}
					}
				}
				else
				{
					if (iMaxAINPCsToSpawn > 0)
					{
						if ((iNPCsSpawned >= iMaxAINPCsToSpawn) && (!npcpsIterator.bMustSpawn))
						{
						}
					}
					else
					{
						if (npcpsIterator.CreateNPC() != nullptr)
						{
							DebugLog(DEBUG_AISpawn, "Spawning soldier : " + FString::FromInt(npcpsIterator.Tag) + " object: " + FString::FromInt(npcpsIterator));
							if (npcpsIterator.bMustSpawn)
							{
								iMustSpawnNPCsSpawned++;
							}
							iNPCsSpawned++;
						}
					}
				}
			}
		}
	}
	iAIVehiclesSpawned = 0;
	iT62sSpawned = 0;
	iBMPsSpawned = 0;
	iBTRsSpawned = 0;
	if (!bDEBUGDisableAIVehicles)
	{
		for (npIterator = Level.NavigationPointList; npIterator != nullptr; npIterator = npIterator.nextNavigationPoint)
		{
			if (npIterator->IsA(ANPCHelicopterStart::StaticClass()))
			{
				npchsIterator = NPCHelicopterStart(npIterator);
				if (npchsIterator.bSpawnAsReserve)
				{
				}
				if (npchsIterator.CreateNPC() != nullptr)
				{
				}
				Log("NPC Helicopter spawn failure");
			}
			else
			{
	else
	{
		if (npIterator->IsA(ANPCUAVStart::StaticClass()))
		{
			npcuavsIterator = NPCUAVStart(npIterator);
			if (npcuavsIterator.bSpawnAsReserve)
			{
			}
			if (npcuavsIterator.CreateNPC() != nullptr)
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
		if (!npIterator->IsA(ANPCVehicleStart::StaticClass()))
		{
		}
		npcvsIterator = NPCVehicleStart(npIterator);
		if (npcvsIterator.bSpawnAsReserve)
		{
		}
		if ((iMaxAIVehiclesToSpawn == -1) || (iAIVehiclesSpawned < iMaxAIVehiclesToSpawn))
		{
			if (npcvsIterator.VehicleClass == nullptr)
			{
			}
			if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.T62A")
			{
				Log("t62 vehicle start, currently spawned: " + FString::FromInt(iT62sSpawned));
				if ((iT62sSpawned >= iMaxT62sToSpawn) && (iMaxT62sToSpawn != -1))
				{
				}
			}
			else
			{
			else
			{
				if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.BMP1_APC")
				{
					Log("BMP vehicle start, currently spawned: " + FString::FromInt(iBMPsSpawned));
					if ((iBMPsSpawned >= iMaxBMPsToSpawn) && (iMaxBMPsToSpawn != -1))
					{
					}
				}
				else
				{
		else
		{
			if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.BTR80APC")
			{
				Log("BTR vehicle start, currently spawned: " + FString::FromInt(iBTRsSpawned));
				if ((iBTRsSpawned >= iMaxBTRsToSpawn) && (iMaxBTRsToSpawn != -1))
				{
				}
			}
		}
				}
		else
		{
			Log("Creating vehicle: " + FString::FromInt(npcvsIterator) + " of class " + FString::FromInt(npcvsIterator.VehicleClass));
			if (npcvsIterator.CreateNPC() != nullptr)
			{
				iAIVehiclesSpawned++;
				if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.T62A")
				{
					iT62sSpawned++;
				}
				else
				{
					if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.BMP1_APC")
					{
						iBMPsSpawned++;
					}
					else
					{
						if (string(npcvsIterator.VehicleClass) ~= "AGP_Vehicles.BTR80APC")
						{
							iBTRsSpawned++;
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
		}
	}
	else
	{
		Log("WARNING - INI DEBUG OPTION AGP_GameInfo.bDEBUGDisableAIVehicles DISABLED AI VEHICLES");
	}
	if (anpcpsPSToSpawn.Num() > 0)
	{
		if (fpNPCInitialSpawnDelay > 5)
		{
			fpNPCInitialSpawnDelay = 5;
		}
		if (fpNPCSpawnDelay > 0.5)
		{
			fpNPCSpawnDelay = 0.5;
		}
		SetCustomTimer(fpNPCInitialSpawnDelay, false, "NPCSpawnTimer");
	}
	if (!Level.bCoOpGame)
	{
		ForEach AllActors(ANPCConversationPack::StaticClass(), npccpIterator)
		{
			npccpIterator.StartConversation();
		}
	}
	ForEach AllActors(ANPCAICombatController::StaticClass(), npcaicc)
	{
		npcaicc.StartAICC();
	}
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		if (p->IsA(APlayerController::StaticClass()))
		{
			Cast<APlayerController>(p).LockPlayer(false, false);
		}
	}
	if ((Level.Game.Stats != nullptr) && (Level.Game.Stats.GameStats != nullptr))
	{
		Level.Game.Stats.GameStats.StatEvent_RoundBegin();
	}
	if (GetWorld()->GetNetMode() == NM_Standalone)
	{
		DebugLog(DEBUG_Multi, "AGP_GameInfo::StartMatch() - Calling StartScreenPlay() for single player");
		StartScreenplay();
	}
	bWaitingToStartMatch = false;
	GameReplicationInfo.bMatchHasBegun = true;
	LogFileWrite("ServerStatus", "Round:Started", true);
	*/
}

void AAGP_GameInfo::ConfigureESSObjectives()
{
	TArray<FESSObjectiveSet> aessos;
	AController* ctrlrIterator = nullptr;
	AAGP_Objective* agpessobjIterator = nullptr;
	AAGP_Objective* agpessobjSelected = nullptr;
	int32 iSet = 0;
	int32 iFoundSet = 0;
	int32 iObj = 0;
	int32 iESSObjectsEnabled = 0;
	int32 iNumCoopObjectives = 0;
	int32 iNumESSObjectives = 0;
	bool bAnyFound = false;
	AActor* triggerIter = nullptr;
	AEmitterSpawner* esIter = nullptr;
	AFlagMeshActor* smIter = nullptr;
	/*
	bAnyFound = false;
	ForEach AllActors(AAGP_Objective::StaticClass(), agpessobjIterator)
	{
		if (!agpessobjIterator->IsA(AAGP_ESSObjective::StaticClass()))
		{
			continue;
		}
		if (agpessobjIterator->IsA(AAGP_CoopESSObjective::StaticClass()))
		{
			smIter = agpessobjIterator.getFlagReference();
			if (smIter != nullptr)
			{
				smIter.bHidden = true;
			}
			else
			{
				ForEach AllActors(AFlagMeshActor::StaticClass(), smIter)
				{
					if (smIter.Tag == agpessobjIterator.getFlagTag())
					{
						if (!smIter.bHidden)
						{
							smIter.bHidden = true;
						}
					}
				}
			}
			iNumCoopObjectives++;
		}
		else
		{
			iNumESSObjectives++;
		}
		iFoundSet = -1;
		iSet = 0;
		if (iSet < aessos.Num())
		{
			if (aessos[iSet].aagpobjs[0].Tag == agpessobjIterator.Tag)
			{
				iFoundSet = iSet;
			}
			else
			{
				iSet++;
			}
		}
		if (iFoundSet == -1)
		{
			aessos.insert(0, 1);
			iFoundSet = 0;
		}
		aessos[iFoundSet].aagpobjs.insert(0, 1);
		aessos[iFoundSet].aagpobjs[0] = agpessobjIterator;
	}
	for (iSet = 0; iSet < aessos.Num(); iSet++)
	{
		if (aessos[iSet].aagpobjs.Num() > 0)
		{
			agpessobjSelected = aessos[iSet].aagpobjs[Rand(aessos[iSet].aagpobjs.Num())];
			for (iObj = 0; iObj < aessos[iSet].aagpobjs.Num(); iObj++)
			{
				aessos[iSet].aagpobjs[iObj].ObjectiveOnCompass = aessos[iSet].aagpobjs[iObj].1;
				if ((aessos[iSet].aagpobjs[iObj] == agpessobjSelected) && (!bDisableESS))
				{
					bAnyFound = true;
					agpessobjSelected.Reset();
					agpessobjSelected.bHidden = false;
					agpessobjSelected.bDisabled = false;
					agpessobjSelected.SetCollision(true, true);
					TriggerEvent(agpessobjSelected.getBecomeActiveEvent(), this, nullptr);
					iESSObjectsEnabled++;
					if (agpessobjSelected.isDangerous())
					{
						ForEach AllActors(Class'Actor', triggerIter)
						{
							if (triggerIter->IsA(AESSTrigger::StaticClass()))
							{
								if (triggerIter.Tag == agpessobjSelected.Tag)
								{
									triggerIter.SetLocation(agpessobjSelected.Location);
									triggerIter.SetCollisionSize(100, 50);
									ForEach AllActors(AEmitterSpawner::StaticClass(), esIter)
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
					aessos[iSet].aagpobjs[iObj].bHidden = true;
					aessos[iSet].aagpobjs[iObj].bDisabled = true;
					aessos[iSet].aagpobjs[iObj].SetCollision(false, false);
				}
			}
		}
	}
	if (bAnyFound)
	{
		for (ctrlrIterator = Level.ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator.nextController)
		{
			if (ctrlrIterator->IsA(AHumanController::StaticClass()))
			{
				ESSUpdateInitialAvailableStatsPerPlayer(Cast<AHumanController>(ctrlrIterator), iESSObjectsEnabled);
				if (iNumESSObjectives > iNumCoopObjectives)
				{
					Cast<AHumanController>(ctrlrIterator)->ClientESSConsoleMessage("S2 Radios: Be alert for any unusual or out of place objects and report them with your <ESSObjectiveReport> command when encountered.");
					Cast<AHumanController>(ctrlrIterator)->ClientESSPlayIntroduction(sndESSS2Introduction);
				}
			}
		}
	}
	*/
}

void AAGP_GameInfo::ESSUpdateInitialAvailableStatsPerPlayer(AHumanController* HC, int32 iESSObjectsEnabled)
{
	/*
		int32 iObjects;
		UE_LOG(LogTemp, Warning, TEXT("Trying to set ESS available stats for " + HC + " to " + iESSObjectsEnabled));
		if (Level.Game.Stats == nullptr || HC.PlayerStatsIndex < 0)
		{
			return;
		}
		for (iObjects=0; iObjects<iESSObjectsEnabled; iObjects++)
		{
			Level.Game.Stats.PlayerStats[HC.PlayerStatsIndex].StatEvent_ESSObjectAvailable();
		}
	*/
}

void AAGP_GameInfo::CalculateAIDifficultyValues()
{
	AAA2_Controller* ctrlrIterator = nullptr;
	int32 iKillsThisRound = 0;
	float fpTPP = 0;
	float fpAKEV = 0;
	float fpPSRPR = 0;
	float fpTotalSinglePSPR = 0;
	float fpTotalAllPSPR = 0;
	float fpPSRPSAllPlayers = 0;
	int32 iRound = 0;
	int32 iPlayerCount = 0;
	int32 iRoundsPlayedSinglePlayer = 0;
	int32 iRoundsPlayedAllPlayers = 0;
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
	{
		return;
	}
	fpAIDifficultyLevelVisionModifer = 0;
	fpAIDifficultyLevelHearingModifer = 0;
	fpAIDifficultyLevelExperienceModifer = 0;
	fpAIDifficultyLevelWeaponAccModifer = 0;
	fpAIDifficultyLevelWeaponRangeModifer = 0;
	fpAIDifficultyLevelMortarSkillModifer = 0;
	fpAIDifficultyLevelMentalStateModifer = 0;
	/*
	for (ctrlrIterator = Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator->nextController)
	{
		if (((ctrlrIterator->IsA(AHumanController::StaticClass()) && (Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo != nullptr)) && (!Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->bOnlySpectator)) && (Cast<AHumanController>(ctrlrIterator)->fpTimePlayedLastRound > 0))
		{
			iPlayerCount++;
		}
	}
	*/
	if (iPlayerCount == 0)
	{
		return;
	}
	if ((iNPCsSpawned + iNPCSpottersSpawned) == 0)
	{
		return;
	}
	fpAKEV = (float((iNPCsSpawned + iNPCSpottersSpawned)) / float(iPlayerCount));
	fpTotalAllPSPR = 0;
	iRoundsPlayedAllPlayers = 0;
	/*
	for (ctrlrIterator = Cast<AAA2_WorldSettings>(GetWorldSettings())->ControllerList; ctrlrIterator != nullptr; ctrlrIterator = ctrlrIterator->nextController)
	{
		if (ctrlrIterator->IsA(AHumanController::StaticClass()))
		{
			if (Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo == nullptr)
			{
			}
			if (Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->bOnlySpectator)
			{
			}
			if (Cast<AHumanController>(ctrlrIterator)->fpLastRoundLength > 0)
			{
				if (Cast<AHumanController>(ctrlrIterator)->fpLastRoundLength < (float((TimeLimit * 60)) / 4))
				{
					Cast<AHumanController>(ctrlrIterator)->fpLastRoundLength = (float((TimeLimit * 60)) / 2);
				}
				fpTPP = (Cast<AHumanController>(ctrlrIterator)->fpTimePlayedLastRound / Cast<AHumanController>(ctrlrIterator)->fpLastRoundLength);
			}
			else
			{
				fpTPP = 0;
			}
			Cast<AHumanController>(ctrlrIterator)->afpTimePlayedPercent[Cast<AHumanController>(ctrlrIterator)->iAIDifficultyRoundsDataIndex] = fpTPP;
			fpPSRPR = ((fpTPP * 0.5) - 0.5);
			if (Cast<AHumanController>(ctrlrIterator)->iKillsAtLastRound > Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Kills)
			{
				Cast<AHumanController>(ctrlrIterator)->iKillsAtLastRound = 0;
			}
			iKillsThisRound = (Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Kills - Cast<AHumanController>(ctrlrIterator)->iKillsAtLastRound);
			if (float(iKillsThisRound) > fpAKEV)
			{
				fpPSRPR += 0.25;
			}
			else
			{
				fpPSRPR += ((float(iKillsThisRound) / fpAKEV) * 0.25);
			}
			if (Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Wins < Cast<AHumanController>(ctrlrIterator)->iWinsAtLastRound)
			{
				Cast<AHumanController>(ctrlrIterator)->iWinsAtLastRound = 0;
			}
			if ((Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Wins - Cast<AHumanController>(ctrlrIterator)->iWinsAtLastRound) > 0)
			{
				fpPSRPR += 0.25;
			}
			Cast<AHumanController>(ctrlrIterator)->iWinsAtLastRound = Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Wins;
			Cast<AHumanController>(ctrlrIterator)->iKillsAtLastRound = Cast<AHumanController>(ctrlrIterator)->PlayerReplicationInfo->Score_Kills;
			Cast<AHumanController>(ctrlrIterator)->afpSkillPerRound[Cast<AHumanController>(ctrlrIterator)->iAIDifficultyRoundsDataIndex] = fpPSRPR;
			iRoundsPlayedSinglePlayer = 0;
			fpTotalSinglePSPR = 0;
			for (iRound = 0; iRound < 10; iRound++)
			{
				if (Cast<AHumanController>(ctrlrIterator)->afpTimePlayedPercent[iRound] > 0)
				{
					iRoundsPlayedSinglePlayer++;
					fpTotalSinglePSPR += Cast<AHumanController>(ctrlrIterator)->afpSkillPerRound[iRound];
				}
			}
			iRoundsPlayedAllPlayers += iRoundsPlayedSinglePlayer;
			fpTotalAllPSPR += fpTotalSinglePSPR;
			if ((++Cast<AHumanController>(ctrlrIterator)->iAIDifficultyRoundsDataIndex) >= 10)
			{
				Cast<AHumanController>(ctrlrIterator)->iAIDifficultyRoundsDataIndex = 0;
			}
			Cast<AHumanController>(ctrlrIterator)->fpTimePlayedLastRound = 0;
			Cast<AHumanController>(ctrlrIterator)->fpLastRoundLength = 0;
		}
	}
	*/
	fpPSRPSAllPlayers = (fpTotalAllPSPR / float(iRoundsPlayedAllPlayers));
	//Log("Player Skill Rating for AI Difficulty Balancing: " + FString::FromInt(fpPSRPSAllPlayers));
	if (fpPSRPSAllPlayers <= -0.3)
	{
		//Log("AI Difficulty set to Level 0 (Easiest)");
		fpAIDifficultyLevelVisionModifer = 0.75;
		fpAIDifficultyLevelHearingModifer = 0.75;
		fpAIDifficultyLevelExperienceModifer = 0.75;
		fpAIDifficultyLevelWeaponAccModifer = 0.75;
		fpAIDifficultyLevelWeaponRangeModifer = 0.75;
		fpAIDifficultyLevelMortarSkillModifer = 0.75;
		fpAIDifficultyLevelMentalStateModifer = 0.75;
	}
	else
	{
		if ((fpPSRPSAllPlayers > -0.3) && (fpPSRPSAllPlayers <= -0.1))
		{
			//Log("AI Difficulty set to Level 1 (Easier)");
			fpAIDifficultyLevelVisionModifer = 0.85;
			fpAIDifficultyLevelHearingModifer = 0.85;
			fpAIDifficultyLevelExperienceModifer = 0.85;
			fpAIDifficultyLevelWeaponAccModifer = 0.85;
			fpAIDifficultyLevelWeaponRangeModifer = 0.85;
			fpAIDifficultyLevelMortarSkillModifer = 0.85;
			fpAIDifficultyLevelMentalStateModifer = 0.85;
		}
		else
		{
			if ((fpPSRPSAllPlayers > -0.1) && (fpPSRPSAllPlayers <= 0.1))
			{
				//Log("AI Difficulty set to Level 2 (Default)");
				fpAIDifficultyLevelVisionModifer = 1;
				fpAIDifficultyLevelHearingModifer = 1;
				fpAIDifficultyLevelExperienceModifer = 1;
				fpAIDifficultyLevelWeaponAccModifer = 1;
				fpAIDifficultyLevelWeaponRangeModifer = 1;
				fpAIDifficultyLevelMortarSkillModifer = 1;
				fpAIDifficultyLevelMentalStateModifer = 1;
			}
			else
			{
				if ((fpPSRPSAllPlayers > 0.1) && (fpPSRPSAllPlayers <= 0.3))
				{
					//Log("AI Difficulty set to Level 3 (Harder)");
					fpAIDifficultyLevelVisionModifer = 1.15;
					fpAIDifficultyLevelHearingModifer = 1.15;
					fpAIDifficultyLevelExperienceModifer = 1.15;
					fpAIDifficultyLevelWeaponAccModifer = 1.15;
					fpAIDifficultyLevelWeaponRangeModifer = 1.15;
					fpAIDifficultyLevelMortarSkillModifer = 1.15;
					fpAIDifficultyLevelMentalStateModifer = 1.15;
				}
				else
				{
					if (fpPSRPSAllPlayers > 0.3)
					{
						//Log("AI Difficulty set to Level 4 (Max)");
						fpAIDifficultyLevelVisionModifer = 1.25;
						fpAIDifficultyLevelHearingModifer = 1.25;
						fpAIDifficultyLevelExperienceModifer = 1.25;
						fpAIDifficultyLevelWeaponAccModifer = 1.25;
						fpAIDifficultyLevelWeaponRangeModifer = 1.25;
						fpAIDifficultyLevelMortarSkillModifer = 1.25;
						fpAIDifficultyLevelMentalStateModifer = 1.25;
					}
				}
			}
		}
	}
}

void AAGP_GameInfo::TerminateNPCSpawning()
{
	/*
		UE_LOG(LogTemp, Warning, TEXT(Self + ".CompleteEndGame() Resetting NPCSpawnTimer"));
		StopCustomTimer('NPCSpawnTimer');
	*/
}

void AAGP_GameInfo::NPCSpawnTimer()
{
	/*
		if (GetStateName() == 'MatchOver')
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".NPCSpawnTimer() - match over, aborting"));
			return;
		}
		UE_LOG(LogTemp, Warning, TEXT("NPCSpawnTimer() - Spawning NPC " + iNPCPSSpawnIndex + " -> " + anpcpsPSToSpawn[iNPCPSSpawnIndex] + " Tag: " + anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag));
		if (anpcpsPSToSpawn[iNPCPSSpawnIndex]->IsA(ANPCPlayerStartCivilian::StaticClass()))
		{
			if (iMaxAICivilianNPCsToSpawn == -1 || iCivilianNPCsSpawned < iMaxAICivilianNPCsToSpawn)
			{
				if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Spawning civilian: " + anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag + " object: " + anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					iCivilianNPCsSpawned ++;
				}
			}
		}
		else
		{
			if (anpcpsPSToSpawn[iNPCPSSpawnIndex]->IsA(ANPCMortarSpotterController::StaticClass()))
			{
				if (iMaxAISpotterNPCsToSpawn == -1 || iNPCSpottersSpawned < iMaxAISpotterNPCsToSpawn)
				{
					if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != nullptr)
					{
						iNPCSpottersSpawned ++;
						UE_LOG(LogTemp, Warning, TEXT("Spawning mortar spotter # " + iNPCSpottersSpawned + ": " + anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag + " object: " + anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					}
				}
			}
			else
			{
				if (iMaxAINPCsToSpawn > 0)
				{
					if (iNPCsSpawned >= iMaxAINPCsToSpawn && ! anpcpsPSToSpawn[iNPCPSSpawnIndex].bMustSpawn)
					{
						if (++ iNPCPSSpawnIndex < anpcpsPSToSpawn.Num())
						{
							SetCustomTimer(fpNPCSpawnDelay,false,'NPCSpawnTimer');
						}
						else
						{
							Log("Balance Information Balanced Soldier NPCs Spawned: " + iNPCsSpawned + ", (Must Spawn: " + iMustSpawnNPCsSpawned + "), Spotters: " + iNPCSpottersSpawned + ", Civilian: " + iCivilianNPCsSpawned + ", Players: " + iPlayersSpawned);
						}
						return;
					}
				}
				if (anpcpsPSToSpawn[iNPCPSSpawnIndex].CreateNPC() != nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("Spawning soldier: " + anpcpsPSToSpawn[iNPCPSSpawnIndex].Tag + " object: " + anpcpsPSToSpawn[iNPCPSSpawnIndex]));
					iNPCsSpawned ++;
				}
			}
		}
		if (++ iNPCPSSpawnIndex < anpcpsPSToSpawn.Num())
		{
			SetCustomTimer(fpNPCSpawnDelay,false,'NPCSpawnTimer');
		}
		else
		{
			Log("Balance Information Balanced Soldier NPCs Spawned: " + iNPCsSpawned + ", (Must Spawn: " + iMustSpawnNPCsSpawned + "), Spotters: " + iNPCSpottersSpawned + ", Civilian: " + iCivilianNPCsSpawned + ", Players: " + iPlayersSpawned);
		}
	*/
}

void AAGP_GameInfo::PreparePlayerForStartMatch(APlayerController* PC)
{
	/*
		PC.PlayerReplicationInfo.bOutOfLives=false;
		PC.PlayerReplicationInfo.bDead=false;
		if (PC.PlayerReplicationInfo.bIsMedic)
		{
			PC.NotifyPlayerOfMedicStatus();
		}
	*/
}

void AAGP_GameInfo::CleanupLevel()
{
	APawn* p = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel()	Looking for bodies..."));
	ForEach DynamicActors(Class'Pawn',p)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel()	Found " + p @ p.Controller));
		if (p->IsA(AAGP_Vehicle::StaticClass()))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying vehicle " + p));
			p.Destroy();
		}
		else
		{
			if (p->IsA(ASVehicle::StaticClass()) && p.Controller != nullptr)
			{
				if (p.Controller != nullptr && p.Controller->IsA(ANPCBaseHelicopterController::StaticClass()))
				{
					Log("Cleaning up Blackhawk by destroying controller");
					Cast<ANPCBaseHelicopterController>(p.Controller).Destroy();
				}
				else
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying svehicle with controller " + p));
					p.Destroy();
				}
				if (p.Controller != nullptr && Cast<AHumanController>(p->Controller) != nullptr && Cast<AHumanController>(p->Controller).PlayerReplicationInfo != nullptr)
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() for player " + Cast<AHumanController>(p->Controller).PlayerReplicationInfo.PlayerName));
				}
				if (p->IsA(ANPC_Ambient::StaticClass()))
				{
					UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() skipping NPC_Ambient: " + p.Controller));
				}
				else
				{
					if (p.Controller != nullptr && ! p->IsA(AFSTS_NPC::StaticClass()))
					{
						UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::CleanupLevel() destroying pawn " + p));
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
	ANavigationPoint* N = nullptr;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		if (N->IsA(AAGP_PlayerStart::StaticClass()))
		{
			//DebugLog(DEBUG_PlayerSpawn, "Resetting PS: " + FString::FromInt(N));
			Cast<AAGP_PlayerStart>(N)->Reset();
		}
	}
}

void AAGP_GameInfo::AssignClassAndRole()
{
	AController* C = nullptr;
	/*
	DebugLog(DEBUG_PlayerSpawn, "AGP_GameInfo::AssignClassAndRole()");
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(AaAIController::StaticClass()))
		{
		}
		if (((C.IsInState("ValidatePB") || C.IsInState("ServerAuthorizePlayer")) || C.IsInState("FailedAuthorization")) || C.IsInState("PlayerAuthorizationComplete"))
		{
			if (C.PlayerReplicationInfo != nullptr)
			{
				DebugLog(DEBUG_Auth, "AGP_GameInfo::AssignClassAndRole " + C.PlayerReplicationInfo.PlayerName + " still authorizing, skipping assignment");
			}
			else
			{
				DebugLog(DEBUG_Auth, "AGP_GameInfo::AssignClassAndRole still authorizing for player without PRI, skipping assignment");
			}
		}
		else
		{
			if ((Cast<APlayerController>(C) != nullptr) && PlayerController(C).PlayerReplicationInfo.bOnlySpectator)
			{
			}
			C.TeamClassClass = GetTeamClass(C);
			C.TeamRoleClass = GetTeamRole(C);
			DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".AssignClassAndRole() - Got team class and role for player \"" + C.PlayerReplicationInfo.PlayerName + "\": " + FString::FromInt(C.TeamClassClass) + ", " + FString::FromInt(C.TeamRoleClass));
		}
	}
	*/
}

void AAGP_GameInfo::RecordStartMatch()
{
}

void AAGP_GameInfo::CheckClassWithPlayerStart(AController* PC)
{
}

bool AAGP_GameInfo::IsClassLegal(ASoldierClass* sclass)
{
	ANavigationPoint* N = nullptr;
	AAGP_PlayerStart* agppsFound = nullptr;
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		if (N->IsA(AAGP_PlayerStart::StaticClass()))
		{
			agppsFound = Cast<AAGP_PlayerStart>(N);
			/*
			if (agppsFound->GetSpawnClass() == sclass)
			{
				return true;
			}
			*/
		}
	}
	if (agppsFound == nullptr)
	{
		return true;
	}
	return false;
}
void AAGP_GameInfo::StartScreenplay()
{
	AController* C = nullptr;
	AHumanController* HC = nullptr;
	/*
	if (_Screenplay == nullptr)
	{
		return;
	}
	if (IsMultiPlayer())
	{
		_Screenplay.Trigger(this,None);
		return;
	}
	C=Level.ControllerList;
	if (C != nullptr)
	{
		if (C->IsA(AHumanController::StaticClass()))
		{
			HC=Cast<AHumanController>(C);
		}
		else
		{
			C=C.nextController;
		}
	}
	if (HC == nullptr)
	{
	}
	_Screenplay.Trigger(HC,None);
	*/
}

bool AAGP_GameInfo::IsRequireAuthorization()
{
	return false;
}

AActor* AAGP_GameInfo::GetTeamClass(AController* C)
{
	return GetDefaultTeamClass();
}

AActor* AAGP_GameInfo::GetDefaultTeamClass()
{
	//return class<Actor>(DynamicLoadObject("AGP_Characters.ClassRifleman",Class'Class'));
	return nullptr;    //FAKE   /ELiZ
}

AActor* AAGP_GameInfo::GetTeamRole(AController* C)
{
	return GetDefaultTeamRole();
}
AActor* AAGP_GameInfo::GetDefaultTeamRole()
{
	//return class<Actor>(DynamicLoadObject("AGP_AI.GroupFollowerRole",Class'Class'));
	return nullptr;    //FAKE   /ELiZ
}
bool AAGP_GameInfo::ShouldRespawn(APickup* Other)
{
	return Other->bPlacedPickup;
}
bool AAGP_GameInfo::PickupQuery(APawn* Other, APickup* Item)
{
	//return Other.Controller.HandlePickupQuery(Item);
	return false;    //FAKE   /EliZ
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
			return;
		}
		if ('HumanController'.Default.bDontRememberUsernameAndPassword)
		{
			Log(Self + "ApplicationShutdown() - Resetting user information on shutdown");
			'HumanController'.Default.UserName="UserName";
			'HumanController'.Default.sSavedUserName="UserName";
			Cast<AHumanController>(Level.GetLocalPlayerController()).ObfuscatePassword("Password");
			'HumanController'.StaticSaveConfig();
		}
	*/
}
void AAGP_GameInfo::GameEnding()
{
	Super::GameEnding();
	if (_Screenplay != nullptr)
	{
		_Screenplay->Destroy();
	}
}
void AAGP_GameInfo::FakeRestartGame()
{
	AController* C = nullptr;
	AActor* A = nullptr;
	ANavigationPoint* N = nullptr;
	/*
	ForEach DynamicActors(Class'Actor', A)
	{
		if (A->IsA(APickup::StaticClass()))
		{
			A.MatchEnding();
		}
		else
		{
			if (A->IsA(AEmitter::StaticClass()))
			{
				A.MatchEnding();
			}
			else
			{
				if ((A->IsA(AVehicle::StaticClass()) || A->IsA(AAGP_DestroyedVehicleModels::StaticClass())) || A->IsA(AVehicleWeapon::StaticClass()))
				{
					A.MatchEnding();
				}
				else
				{
					if (A->IsA(ACallForSupport::StaticClass()))
					{
						A.Reset();
					}
				}
			}
		}
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		C.StartSpot = nullptr;
	}
	*/
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		if (N->IsA(AAGP_PlayerStart::StaticClass()))
		{
			Cast<AAGP_PlayerStart>(N)->Reset();
		}
	}
	Reset();
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

AScreenplay* AAGP_GameInfo::GetScreenplay()
{
	return _Screenplay;
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
APlayerController* AAGP_GameInfo::Login(FString Portal, FString Options, FString& Error)
{
	AController* C = nullptr;
	APlayerController* NewPlayer = nullptr;
	FString InUserName = "";
	FString inClass = "";
	FString InSkin = "";
	FString InMAC = "";
	FString InName = "";
	FString InAdminName = "";
	FString InPassword = "";
	FString InChecksum = "";
	FString inCharacter = "";
	FString InSex = "";
	FString sInPlayerAdminPassword = "";
	uint8 InTeam = 0;
	bool bSpectator = false;
	bool bAdmin = false;
	bool bPlayerAdmin = false;
	ASecurity* MySecurityClass = nullptr;
	DebugLog(DEBUG_Login,string(this) + ".Login() Options: \"" + Options + "\"");
	if (! Level.IsExploreTheArmyServer())
	{
		Options=StripColor(Options);
	}
	InUserName=Left(ParseOption(Options,"UserName"),40);
	Log("Incoming username: \"" + InUserName + "\"");
	inClass=ParseOption(Options,"Class");
	InSkin=ParseOption(Options,"Skin");
	InMAC=ParseOption(Options,"MAC");
	InName=Left(ParseOption(Options,"Name"),20);
	InTeam=byte(GetIntOption(Options,"Team",255));
	InAdminName=ParseOption(Options,"AdminName");
	InPassword=ParseOption(Options,"Password");
	InChecksum=ParseOption(Options,"Checksum");
	sInPlayerAdminPassword=Level.Game.ParseOption(Options,"PAPassword");
	if (AccessControl != nullptr)
	{
		if (AccessControl.ValidatePlayerAdmin(InUserName,sInPlayerAdminPassword))
		{
			if (Level.Game.NumAdmins < Level.Game.MaxAdmins)
			{
				bPlayerAdmin=true;
			}
		}
		else
		{
			bPlayerAdmin=false;
		}
		DebugLog(DEBUG_Login,string(this) + ".Login() trying to login admin using password");
		bAdmin=AccessControl.AdminLogin(NewPlayer,InPassword);
		DebugLog(DEBUG_Login,string(this) + ".Login() finished trying to login admin using password");
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() Parsing for spectator flag");
	bSpectator=((ParseOption(Options,"SpectatorOnly") ~= "true") || (ParseOption(Options,"SpectatorOnly") ~= "1"));
	DebugLog(DEBUG_Login,string(this) + ".Login() Finished parsing spectator flag");
	if (AtCapacity(bSpectator,bAdmin))
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() Server at capacity, aborting");
		Error=GameMessageClass.Default.MaxedOutMessage;
		return nullptr;
	}
	if (bAdmin)
	{
		bSpectator=true;
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() About to call ModifyLogin mutator");
	BaseMutator.ModifyLogin(Portal,Options);
	DebugLog(DEBUG_Login,string(this) + ".Login() Parsing for character type");
	inCharacter=ParseOption(Options,"Character");
	InSex=ParseOption(Options,"Sex");
	if (bAdmin && bSpectator)
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() Adjusting admin privileges");
		if (AccessControl.AdminClass == nullptr)
		{
			if (true)
			{
				DebugLog(DEBUG_Login,"Creating Admin \"SuperAdmin\" class");
				AccessControl.AdminClass=class<PlayerController>(DynamicLoadObject("AGP_Gameplay.SuperAdmin",Class'Class'));
			}
			if (AccessControl.AdminClass == nullptr)
			{
				AccessControl.AdminClass=class<PlayerController>(DynamicLoadObject(AccessControl.AdminClassName,Class'Class'));
			}
		}
		DebugLog(DEBUG_Login,"Creating new user class of " + FString::FromInt(AccessControl.AdminClass.Class));
		NewPlayer=Spawn(AccessControl.AdminClass);
	}
	else
	{
		if (PlayerControllerClass == nullptr)
		{
			DebugLog(DEBUG_Login,string(this) + ".Login() DLO HC class");
			PlayerControllerClass=class<PlayerController>(DynamicLoadObject(PlayerControllerClassName,Class'Class'));
		}
		DebugLog(DEBUG_Login,string(this) + ".Login() spawning controller for player");
		NewPlayer=Spawn(PlayerControllerClass);
		DebugLog(DEBUG_Login,string(this) + ".Login() spawned controller for player: " + FString::FromInt(NewPlayer));
	}
	if (NewPlayer == nullptr)
	{
		DebugLog(DEBUG_Login,"Couldn't spawn player controller of class " + FString::FromInt(PlayerControllerClass));
		Error=GameMessageClass.Default.FailedSpawnMessage;
		return nullptr;
	}
	AccessControl.SignalPlayerQualified(NewPlayer,bAdmin);
	NewPlayer.PlayerReplicationInfo.bAdmin=bAdmin;
	NewPlayer.PlayerReplicationInfo.bPlayerAdmin=bPlayerAdmin;
	NewPlayer.PlayerReplicationInfo.PlayerMAC=InMAC;
	NewPlayer.PlayerReplicationInfo.PlayerName=InUserName;
	DebugLog(DEBUG_Login,string(this) + ".Login() Player is Admin: " + FString::FromInt(NewPlayer.PlayerReplicationInfo.bAdmin));
	if (NewPlayer.PlayerReplicationInfo.bAdmin && (Cast<AHumanController>(NewPlayer) != nullptr))
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() Creating ServerInfo... ");
		Cast<AHumanController>(NewPlayer).ServerInfo=Spawn(AAGP_ServerInfo::StaticClass());
	}
	NewPlayer.GameReplicationInfo=GameReplicationInfo;
	DebugLog(DEBUG_Login,string(this) + ".Login() loading security class");
	SecurityClass="AGP.AGPS";
	MySecurityClass=class<Security>(DynamicLoadObject(SecurityClass,Class'Class'));
	if (MySecurityClass != nullptr)
	{
		NewPlayer.PlayerSecurity=Spawn(MySecurityClass,NewPlayer);
		if (NewPlayer.PlayerSecurity == nullptr)
		{
			Log("Could not spawn security for player " + FString::FromInt(NewPlayer),"Security");
		}
	}
	else
	{
		Log("Unknown security class [" + SecurityClass + "] -- System is not secure.","Security");
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() Setting default player name");
	if (InUserName == "")
	{
		InName=DefaultPlayerName;
	}
	InUserName=Level.Game.StripColor(InUserName);
	if (Len(InUserName) > 20)
	{
		InUserName=Left(InUserName,20);
	}
	ReplaceText(InUserName," ","_");
	ReplaceText(InUserName,"\"","");
	ReplaceText(InUserName,"¤","");
	InUserName=Cast<AHumanController>(NewPlayer).StripBadCodes(InUserName);
	NewPlayer.PlayerReplicationInfo.PlayerName=InUserName;
	Cast<AHumanController>(NewPlayer).UserName=InUserName;
	if (GetNetMode() != ENetMode::NM_Standalone)
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() Calling ChangeName");
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if (C == NewPlayer)
			{
			}
			if (NewPlayer.PlayerReplicationInfo.PlayerName == C.PlayerReplicationInfo.PlayerName)
			{
				Log("ERROR: Duplicate login name with player already on server: \"" + NewPlayer.PlayerReplicationInfo.PlayerName + "\"");
				Error="Player Name Already In Use On Server";
				NewPlayer.Destroy();
				return nullptr;
			}
		}
		DebugLog(DEBUG_Login,string(this) + ".Login() Done calling ChangeName");
		FlushLogNative();
	}
	if (InUserName == "")
	{
		if (GetWorld()->GetNetMode() == NM_DedicatedServer)
		{
			DebugLog(DEBUG_Login,string(this) + ".Login() Setting name after failed to find good name");
			Error="Username not specified in connect attempt";
			NewPlayer.Destroy();
			return nullptr;
		}
		else
		{
			InUserName=NewPlayer.GetAuthUserName();
		}
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() Setting skin preference");
	FlushLogNative();
	NewPlayer.SetSkinPreference(InSkin);
	DebugLog(DEBUG_Login,string(this) + ".Login() Finished setting skin preference");
	FlushLogNative();
	NewPlayer.PlayerReplicationInfo.PlayerID=CurrentID ++;
	DebugLog(DEBUG_Login,string(this) + ".Login() Player ID set to " + FString::FromInt(NewPlayer.PlayerReplicationInfo.PlayerID));
	FlushLogNative();
	if (bAdmin)
	{
		NumAdmins ++;
		DebugLog(DEBUG_Login,string(this) + ".Login() Admins logged in: " + FString::FromInt(NumAdmins));
		FlushLogNative();
	}
	if (bSpectator || NewPlayer.PlayerReplicationInfo.bOnlySpectator)
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() - Setting spectator flag");
		FlushLogNative();
		NewPlayer.PlayerReplicationInfo.bOnlySpectator=true;
		NumSpectators ++;
		DebugLog(DEBUG_Login,string(this) + ".Login() Spectator joining, changing to spectator team");
		FlushLogNative();
		ChangeTeam(NewPlayer,254);
		DebugLog(DEBUG_Login,string(this) + ".Login() player sent to spectating team");
		FlushLogNative();
		return NewPlayer;
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() About to change team to spectating for player");
	if (! ChangeTeam(NewPlayer,255))
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() cannot assign player to spectator team, aborting");
		Error=GameMessageClass.Default.FailedTeamMessage;
		NewPlayer.Destroy();
		DebugLog(DEBUG_Login,string(this) + ".Login() Aborted player assignment (destroyed controller)");
		return nullptr;
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() Updating clients scoreboard rules");
	UpdateClientScoreMode(NewPlayer);
	DebugLog(DEBUG_Login,string(this) + ".Login() Finished updating clients scoreboard rules");
	NumPlayers ++;
	bWelcomePending=true;
	if ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GetWorld()->GetNetMode() == NM_ListenServer))
	{
		if (! Level.IsExploreTheArmyServer())
		{
			DebugLog(DEBUG_Login,string(this) + ".Login() Sending welcome message for player");
			BroadcastLocalizedMessage(GameMessageClass,1,NewPlayer.PlayerReplicationInfo);
			DebugLog(DEBUG_Login,string(this) + ".Login() Finished welcome message for player");
		}
		else
		{
			Broadcast(this,"A new player is joining the server.");
		}
	}
	if (bDelayedStart)
	{
		DebugLog(DEBUG_Login,string(this) + ".Login() Delayed start for player, returning controller");
		return NewPlayer;
	}
	DebugLog(DEBUG_Login,string(this) + ".Login() Non-delayed start, returning player");
	return NewPlayer;
*/

void AAGP_GameInfo::FinishPostLogin(APlayerController* NewPlayer)
{
}

void AAGP_GameInfo::BanPlayerAccount(APlayerController* Cheater)
{
	/*
		if (IsRequireAuthorization())
		{
			Broadcast(this,Cheater.PlayerReplicationInfo.PlayerName @ " did something stupid!");
			Cheater.ClientDisconnect("Cheat detected!  This will be recorded in your account");
			Cheater.GotoState('FailedAuthorization');
		}
	*/
}

void AAGP_GameInfo::RestartPlayer(AController* aPlayer)
{
	Super::RestartPlayer(aPlayer);  //Mine ELiZ
	ANavigationPoint* StartSpot = nullptr;
	AAGP_PlayerStart* astartSpot = nullptr;
	int32 TeamNum = 0;
	APawn* DefaultPlayerClass = nullptr;
	AAA2_PlayerState* aPRI = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT("*****************************************"));
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() " + aPlayer));
	if (aPlayer.PlayerReplicationInfo != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() for player " + aPlayer.PlayerReplicationInfo.PlayerName));
	}
	if (bRestartLevel && GetNetMode() != ENetMode::NM_DedicatedServer && GetNetMode() != ENetMode::NM_ListenServer)
	{
		return;
	}
	aPRI=aPlayer.PlayerReplicationInfo;
	if (aPRI == nullptr || aPRI.Team == nullptr)
	{
		TeamNum=255;
	}
	else
	{
		TeamNum=aPRI.Team.TeamIndex;
	}
	if (! aPlayer->IsA(AaAIController::StaticClass()))
	{
		if (IsTournamentMode())
		{
			if (ShouldSpectate(aPRI))
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() - TM - Forcing player into spectate mode from current state: " + aPlayer.GetStateName()));
				EnterSpectatorMode(aPlayer);
				Cast<AHumanController>(aPlayer).ClientResetSpectator();
				return;
			}
		}
		else
		{
			if (ShouldSpectate(aPRI) || ! Cast<AHumanController>(aPlayer).bPlayerIsReadyToPlay || ! aPlayer.IsInState('Spectating') && ! aPlayer.IsInState('GameEnded') && ! aPlayer.IsInState('Dead'))
			{
				UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() - Forcing player into spectate mode from current state: " + aPlayer.GetStateName()));
				EnterSpectatorMode(aPlayer);
				Cast<AHumanController>(aPlayer).ClientResetSpectator();
				return;
			}
		}
	}
	if (aPlayer.Pawn != nullptr)
	{
		aPlayer.Pawn.Destroy();
		aPlayer.Pawn=nullptr;
	}
	StartSpot=FindPlayerStart(aPlayer,TeamNum);
	if (StartSpot == nullptr)
	{
		Log("AGP_GameInfo::RestartPlayer()	No legal playerstart found.");
		EnterSpectatorMode(aPlayer);
		Cast<AHumanController>(aPlayer).ClientMessage("Unable to find a starting spot for you (the server may be full).  You will need to watch this round.");
		Cast<AHumanController>(aPlayer).ClientResetSpectator();
		return;
	}
	else
	{
		if (StartSpot->IsA(AAGP_PlayerStart::StaticClass()))
		{
			AGP_PlayerStart(StartSpot).UsePlayerStart();
		}
	}
	aPlayer.StartSpot=StartSpot;
	UE_LOG(LogTemp, Warning, TEXT("PawnClass=" + aPlayer.PawnClass));
	if (aPlayer.PawnClass != nullptr)
	{
		aPlayer.Pawn=Spawn(aPlayer.PawnClass,,,StartSpot.GetStartLocation(),StartSpot.GetStartRotation());
		UE_LOG(LogTemp, Warning, TEXT("Pawn=" + aPlayer.Pawn));
	}
	if (aPlayer.Pawn == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - pawn not spawned for class " + aPlayer.PawnClass));
		DefaultPlayerClass=GetDefaultPlayerClass(aPlayer);
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - Default PawnClass = " + DefaultPlayerClass));
		aPlayer.Pawn=Spawn(DefaultPlayerClass,,,StartSpot.GetStartLocation(),StartSpot.GetStartRotation());
		UE_LOG(LogTemp, Warning, TEXT("Pawn=" + aPlayer.Pawn));
	}
	UE_LOG(LogTemp, Warning, TEXT("Controller" @ aPlayer @ "got startspot" @ StartSpot @ "dfc" @ DefaultPlayerClass @ "and pawnclass" @ aPlayer.PawnClass));
	if (aPlayer.Pawn == nullptr)
	{
		if (Cast<AHumanController>(aPlayer) != nullptr)
		{
			Cast<AHumanController>(aPlayer).ClientMessage("Unable to create a player pawn for you (the server may be full).  You will need to watch this round.");
		}
		Log("AGP_GameInfo::RestartPlayer() Couldn't spawn Pawn of type " + aPlayer.PawnClass + " at " + StartSpot);
		aPlayer.GotoState('Dead');
		return;
	}
	aPlayer.Pawn.Anchor=StartSpot;
	aPlayer.Pawn.LastStartSpot=PlayerStart(StartSpot);
	aPlayer.Pawn.LastStartTime=GetWorld()->GetTimeSeconds();
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer() " + aPlayer + " trying to possess " + aPlayer.Pawn));
	aPlayer.PreviousPawnClass=aPlayer.Pawn.Class;
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer calling aPlayer.Possess() [aPlayer=" + aPlayer + "]"));
	aPlayer.Possess(aPlayer.Pawn);
	aPlayer.PawnClass=aPlayer.Pawn.Class;
	if (Cast<AAGP_PlayerStart>(aPlayer.StartSpot) != nullptr)
	{
		if (Cast<AAGP_PlayerStart>(aPlayer.StartSpot).GetInitialHealth() < aPlayer.Pawn.Default.Health)
		{
			aPlayer.Pawn.Health=Cast<AAGP_PlayerStart>(aPlayer.StartSpot).GetInitialHealth();
			aPlayer.Pawn.BleedMax=aPlayer.Pawn.Default.Health - AGP_PlayerStart(aPlayer.StartSpot).GetInitialHealth();
		}
	}
	aPlayer.Pawn.PlayTeleportEffect(true,true);
	aPlayer.ClientSetRotation(aPlayer.Pawn.Rotation);
	if (! aPlayer->IsA(AaAIController::StaticClass()))
	{
		Cast<AHumanController>(aPlayer).AGPHUD(true);
		Cast<AHumanController>(aPlayer).ClientLockPlayer(true,true);
		Cast<AHumanController>(aPlayer).ClientCloseMenu(false);
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::RestartPlayer calling AddDefaultInventory(" + aPlayer.Pawn + ")"));
	}
	AddDefaultInventory(aPlayer.Pawn);
	if (! aPlayer->IsA(AaAIController::StaticClass()))
	{
		TriggerEvent(StartSpot.Event,StartSpot,aPlayer.Pawn);
		astartSpot=Cast<AAGP_PlayerStart>(StartSpot);
		if (astartSpot != nullptr && astartSpot.StartIndex > 0)
		{
			TriggerEvent(astartSpot.ProxyList[astartSpot.StartIndex - 1].Event,astartSpot.ProxyList[astartSpot.StartIndex - 1],aPlayer.Pawn);
		}
		UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo.RestartPlayer() - forcing first person view for player"));
		Cast<AHumanController>(aPlayer).ClientSetBehindView(false);
	}
	*/
	UE_LOG(LogTemp, Warning, TEXT("*****************************************"));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
	UE_LOG(LogTemp, Warning, TEXT(" "));
}

void AAGP_GameInfo::EnterSpectatorMode(AController* aPlayer)
{
	AHumanController* HC = nullptr;
	/*
	UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::EnterSpectatorMode() entered for " + aPlayer));
	HC=Cast<AHumanController>(aPlayer);
	if (HC != nullptr)
	{
		if (HC.IsInState('ValidatePB') || HC.IsInState('ServerAuthorizePlayer') || HC.IsInState('FailedAuthorization') || HC.IsInState('PlayerAuthorizationComplete'))
		{
			UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::EnterSpectatorMode() - User authorizing, state change skipped"));
			return;
		}
		HC.SetStartupStage(9);
		HC.ClientGotoState('Spectating',"None");
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
	//UE_LOG(LogTemp, Warning, TEXT("AGP_GameInfo::ShouldSpectate()	Match in progres: " + p.bDead @ p.bOutOfLives));
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
	APlayerController* KillerPC = nullptr;
	APlayerController* KilledPC = nullptr;
	/*
		if (Killer == nullptr && Killed != nullptr)
		{
			Killer=Killed;
		}
		if (Killer != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() entered for killer " + Killer.Tag + " with killed: " + Killed + " and pawn: " + KilledPawn));
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() entered for unknown killer "));
		}
		if (Killed == nullptr || Killed.PlayerReplicationInfo == nullptr)
		{
			if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() - No killed PRI, not coop, aborting scoring"));
				return;
			}
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() - No PRI for killed pawn but CoOp game"));
		}
		if (Killed != nullptr && Killed.PlayerReplicationInfo != nullptr)
		{
			Killed.PlayerReplicationInfo.bDead=true;
		}
		KillerPC=Cast<APlayerController>(Killer);
		UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() Killer: " + KillerPC));
		if (KillerPC != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() valid killer (player), stats index: " + KillerPC.PlayerStatsIndex));
		}
		if (Killed != nullptr && Level.Game.Stats != nullptr && KillerPC != nullptr && KillerPC.PlayerStatsIndex >= 0)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() scoring damage type: " + DamageType.Default.AmmoType));
			switch(DamageType.Default.AmmoType)
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
				if (KillerPC.Pawn != nullptr && Cast<AAGP_Weapon>(KillerPC.Pawn.Weapon) != nullptr && ! KillerPC.Pawn->IsA(AThrowWeapon::StaticClass()) && ! KillerPC.Pawn->IsA(ARocketWeapon::StaticClass()))
				{
					UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() with valid stats, weapon type: " + Cast<AAGP_Weapon>(KillerPC.Pawn.Weapon).StatWeaponType));
					switch(Cast<AAGP_Weapon>(KillerPC.Pawn.Weapon).StatWeaponType)
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
						UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() with valid stats, not directly supported weapon, defaulting to assault rifle"));
						Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_ShotKilledAssaultRifle();
						break;
					}
				}
			}
		}
		if (Killed != nullptr && Level.Game.Stats != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() Killed: " + Killed + " by killer " + Killer + ", updating killer's kill stats"));
			if (KillerPC != nullptr && KillerPC.PlayerStatsIndex >= 0 && Killer != Killed)
			{
				Level.Game.Stats.PlayerStats[KillerPC.PlayerStatsIndex].StatEvent_Kill();
			}
			KilledPC=Cast<APlayerController>(Killed);
			UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() KilledPC: " + KilledPC));
			if (KilledPC != nullptr && KilledPC.PlayerStatsIndex >= 0)
			{
				UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed() Player killed stats index: " + KilledPC.PlayerStatsIndex));
				STS2_PlayerStatsInfo(Level.Game.Stats.PlayerStats[KilledPC.PlayerStatsIndex]).StatEvent_Death(KilledPC.Pawn.Location);
			}
		}
		NotifyKilled(Killer,Killed,KilledPawn);
		UE_LOG(LogTemp, Warning, TEXT(Self + "::Killed() - Killed: " + Killed + "  Killer: " + Killer + "  KilledPawn: " + KilledPawn));
		if (Killed == nullptr && Killer->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
		{
			if (KilledPawn != nullptr && KilledPawn.TempController != nullptr)
			{
				Killed=KilledPawn.TempController;
			}
		}
		if (Killed != nullptr && Killed.bIsPlayer || Killed->IsA(ANPCBaseSoldierController::StaticClass()) || Killed->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
		{
			BroadcastDeathMessage(Killer,Killed,DamageType);
			if (GameStats != nullptr)
			{
				if (Killer == Killed || Killer == nullptr)
				{
					if (Killer == nullptr)
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
					if (bTeamGame && Killer.PlayerReplicationInfo != nullptr && Killed.PlayerReplicationInfo != nullptr && Killer.PlayerReplicationInfo.Team == Killed.PlayerReplicationInfo.Team)
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
		if (Killed != nullptr)
		{
			if (CanRespawn(Killed))
			{
				if (Cast<AHumanController>(Killed) != nullptr)
				{
					Cast<AHumanController>(Killed).SetStartupStage(7);
				}
			}
			else
			{
				if (Cast<AHumanController>(Killed) != nullptr)
				{
					Cast<AHumanController>(Killed).SetStartupStage(8);
				}
				if (Killed.PlayerReplicationInfo != nullptr)
				{
					Killed.PlayerReplicationInfo.bOutOfLives=true;
				}
			}
		}
		UE_LOG(LogTemp, Warning, TEXT(Self + ".Killed calling ScoreKill"));
		ScoreKill(Killer,Killed,DamageType);
		if (Killer != nullptr && Killer.bIsPlayer && Killed != nullptr && Killed.bIsPlayer)
		{
			LogFileWrite("ScriptLog",Killer.PlayerReplicationInfo.PlayerName + ":Killed:" + Killed.PlayerReplicationInfo.PlayerName + ":" + DamageType);
		}
	*/
}

void AAGP_GameInfo::ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType)
{
}
/*

void AAGP_GameInfo::ChangeName(AController* Other, FString S, bool bNameChange)
{
	FString O = "";
	AController* C = nullptr;
	int32 Onum = 0;
	DebugLog(DEBUG_Multi,"AGP_GameInfo::ChangeName()	Trying " + S @ FString::FromInt(C));
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (C == Other)
		{
		}
		if (C->IsA(ANPCBaseController::StaticClass()))
		{
		}
		O=C.PlayerReplicationInfo.GetHumanReadableName();
		DebugLog(DEBUG_Multi,"AGP_GameInfo::ChangeName()	" + O @ FString::FromInt(C));
		if (Caps(O) == Caps(S))
		{
			if (IsRequireAuthorization() && Cast<AHumanController>(Other).bInitialAuthComplete)
			{
				Log("Kicking duplicate name " + PlayerController(Other).PlayerReplicationInfo.PlayerName);
				KickByController(Other,"DupName");
				return;
			}
			if (int(Right(S,2)) != 0)
			{
				S=Left(S,(Len(S) - 2));
			}
			Onum=int(Right(O,2));
			Onum ++;
			if (Onum < 10)
			{
				S=S + "0";
			}
			else
			{
				if (Onum > 99)
				{
					Onum=101;
				}
			}
			S=S + FString::FromInt(Onum);
			ChangeName(Other,S,bNameChange);
			return;
		}
	}
	Super::ChangeName(Other,S,bNameChange);
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

FString AAGP_GameInfo::GetServerAuthData()
{
	return "FAKE";    //FAKE   /ELiZ
}

FString AAGP_GameInfo::GetMapServerInfo()
{
	ASecurity* secLocalSecurity = nullptr;
	ASecurity* scLocalSecurityClass = nullptr;
	TArray<FString> asMD5ForMap = {};
	/*
	scLocalSecurityClass=class<Security>(DynamicLoadObject("Engine.Security",Class'Class'));
	if (scLocalSecurityClass != nullptr)
	{
		secLocalSecurity=Spawn(scLocalSecurityClass,Self);
		if (secLocalSecurity != nullptr)
		{
			secLocalSecurity.LocalPerform(2,"../Maps/" + Level.sLevelName + ".aao","",asMD5ForMap);
			return asMD5ForMap[0];
		}
	}
	*/
	return "";
}
void AAGP_GameInfo::AuthorizeServer()
{
	AAuthorizeServerRequestAdapter* Adapter = nullptr;
	/*
		FString IP;
		if (! Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer() && IsRequireAuthorization() || fAuthNotAvailableLastAuthAttempt)
		{
			IP=AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthIP();
			UE_LOG(LogTemp, Warning, TEXT("Initiating authorization of server..." @ IP + ":" + GetServerPort() @ "Tour:" @ Level.iTour @ "Mission:" @ Level.iMission @ "MaxPlayers:" + MaxPlayers));
			if (Level.iTour < 0 || Level.iMission < 0)
			{
				Warn("Server authorization attempt with invalid tour or mission! Tour:" @ Level.iTour @ "Mission:" @ Level.iMission);
			}
			Adapter=Spawn(AAuthorizeServerRequestAdapter::StaticClass(),Self);
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
			//Log("	(Attempted authorization with username:" @ AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthUsername() @ "ip:" @ AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthIP() + ":" + GetServerPort());
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
			//Level.ServerTravel("?Restart",false);
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
		FString sNPCName;
		if (! bDeathMessages)
		{
			return;
		}
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame)
		{
			UE_LOG(LogTemp, Warning, TEXT("Damage type: """ + DamageType + """ mortar damage index: " + InStr(DamageType,"Mortar")));
			if (InStr(DamageType,"Mortar") >= 0)
			{
				if (Killed != nullptr && Killed->IsA(ANPCBaseController::StaticClass()))
				{
					sNPCName=NPCBaseController(Killed).sNPCName;
					Broadcast(this,ParseKillMessage("Mortar Crew",sNPCName,DamageType.Default.DeathString),'AIKiller');
				}
				else
				{
					Broadcast(this,ParseKillMessage("Mortar Crew",Killed.PlayerReplicationInfo.PlayerName,DamageType.Default.DeathString),'AIKiller');
				}
				return;
			}
			if (Killer->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
			{
				UE_LOG(LogTemp, Warning, TEXT(Self + ".BroadcastDeathMessage() - Vehicle class: " + Cast<ANPCBasePreCrewedVehicleControlle>(Killer).sVehicleType));
				sNPCName=NPCBasePreCrewedVehicleController(Killer).sVehicleType;
			}
			else
			{
				if (Killer->IsA(ANPCBaseController::StaticClass()))
				{
					sNPCName=NPCBaseController(Killer).sNPCName;
				}
			}
			if (Killed->IsA(ANPCBasePreCrewedVehicleControlle::StaticClass()))
			{
				UE_LOG(LogTemp, Warning, TEXT(Self + ".BroadcastDeathMessage() - Vehicle class: " + Cast<ANPCBasePreCrewedVehicleControlle>(Killed).sVehicleType));
				sNPCName=NPCBasePreCrewedVehicleController(Killed).sVehicleType;
			}
			else
			{
				if (Killed->IsA(ANPCBaseController::StaticClass()))
				{
					sNPCName=NPCBaseController(Killed).sNPCName;
				}
			}
			if (Len(sNPCName) == 0)
			{
				sNPCName="Enemy forces";
			}
			if (Killer->IsA(AaAIController::StaticClass()) && Killed->IsA(APlayerController::StaticClass()))
			{
				if (Killed.PlayerReplicationInfo != nullptr)
				{
					Broadcast(this,ParseKillMessage(sNPCName,Killed.PlayerReplicationInfo.PlayerName,DamageType.Default.DeathString),'AIKiller');
				}
				else
				{
					Broadcast(this,ParseKillMessage(sNPCName,"A player",DamageType.Default.DeathString),'AIKiller');
				}
				return;
			}
			else
			{
				if (Killer->IsA(APlayerController::StaticClass()) && Killed->IsA(AaAIController::StaticClass()))
				{
					if (Killer.PlayerReplicationInfo != nullptr)
					{
						Broadcast(this,ParseKillMessage(Killer.PlayerReplicationInfo.PlayerName,sNPCName,DamageType.Default.DeathString),'AIKilled');
					}
					else
					{
						Broadcast(this,ParseKillMessage("a player","An enemy",DamageType.Default.DeathString),'AIKilled');
					}
					return;
				}
				else
				{
					if (Killer->IsA(AaAIController::StaticClass()) && Killed->IsA(AaAIController::StaticClass()))
					{
						return;
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
	AHttpLink* MyLink = nullptr;
	UHttpLinkItem* RequestedItem = nullptr;
	/*
	MyLink=Spawn(AHttpLink::StaticClass());
	if (MyLink != nullptr)
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
	int32 BufferHead = 0;
	FString Buffer = "";
	/*
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

bool AAGP_GameInfo::DisableToursDownload()
{
	return false;	//FAKE   /ELiZ
}
