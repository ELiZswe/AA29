// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "GameFramework/WorldSettings.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/AA2_GameState.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"
#include "AA29/Object/Actor/Info/InternetInfo/InternetInfo.h"
#include "AA29/Object/Actor/Info/Mutator/Mutator.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"
#include "AA29/Object/Actor/DecoMesh/DecoMesh.h"
#include "AA29/Object/Actor/Controller/PlayerController/HumanController/HumanController.h"
#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "AA29/Object/Actor/Info/GameRules/GameRules.h"
#include "AA29/Object/Actor/Info/AccessControl/AccessControl.h"
#include "AA29/Object/Actor/Info/GameStats/GameStats.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Character/AGP_Character.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/Inventory/Powerups/Armor/Armor.h"
#include "AA29/Object/Actor/Info/MaplistManagerBase/MaplistManagerBase.h"
#include "AA29/Object/Actor/Info/MapList/MapList.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/Teleporter/Teleporter.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/NavigationPoint/NavigationPoint.h"
#include "AA29/Object/Actor/Info/BroadcastHandler/BroadcastHandler.h"
#include "AA29/Object/Actor/Info/VotingHandler/VotingHandler.h"
#include "AA29/Object/Actor/Info/ZoneInfo/LevelInfo/LevelInfo.h"
#include "AA29/Object/Actor/Info/AnnouncerVoice/AnnouncerVoice.h"
#include "AA29/Object/Actor/Info/LocalMessage/GameMessage/GameMessage.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Info/SceneManager/SceneManager.h"
#include "AA29/Object/Actor/Screenplay/Screenplay.h"
#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/GameProfile/GameProfile.h"
#include "AA29/Object/Manifest/Manifest.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/MaplistManagerBase/MaplistManager/MaplistManager.h"
#include "AA29/Object/ObjectPool/ObjectPool.h"
#include "AA29/Object/Actor/Info/ScoreBoard/ScoreBoard.h"
#include "AA29/Object/Actor/Info/ZoneInfo/ZoneInfo.h"
#include "AA29/Object/AdminBase/Admin/Admin.h"
#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/InventorySpot/InventorySpot.h"
#include "AA29/Object/Actor/Controller/PlayerController/MessagingSpectator/MessagingSpectator.h"

AGameInfo::AGameInfo()
{
	CallSigns.SetNum(15);
	GIPropsExtras.SetNum(2);
	GIPropDescText.SetNum(15);
	GIPropsDisplayText.SetNum(15);
	GoreLevelText.SetNum(3);
	bRestartLevel = true;
	bCanChangeSkin = true;
	bCanViewOthers = true;
	bChangeLevels = true;
	bEnableStatLogging = true;
	bAllowWeaponThrowing = true;
	bWeaponShouldViewShake = true;
	bModViewShake = true;
	GameDifficulty = 1;
	AutoAim = 0.93;
	GameSpeed = 1;
	//MapListType = "AGP_Gameplay.AGP_MapList"
	GoreLevelText = { "No Gore", "Reduced Gore", "Full Gore" };
	MaxSpectators = 2;
	MaxPlayers = 16;
	MaxAdmins = 2;
	CurrentID = 1;
	DefaultPlayerName = FText::FromString("Player");
	FearCostFallOff = 0.95;
	TimeLimit = 10;
	//DeathMessageClass = class'Engine.LocalMessage'
	//GameMessageClass = AGameMessage::StaticClass()
	//MutatorClass = "Engine.Mutator"
	//AccessControlClass = "Engine.AccessControl"
	//GameReplicationInfoClass = AGameReplicationInfo::StaticClass()
	//VoiceReplicationInfoClass = AVoiceChatReplicationInfo::StaticClass()
	//MaplistHandlerClass = AMaplistManager::StaticClass()
	GameName = "Game";
	Acronym = "???";
	GIPropsDisplayText = { "Bot Skill", "Weapons Stay", "Reduce Gore Level", "Game Speed", "Max Spectators", "Max Players", "Goal Score", "Max Lives", "Time Limit", "World Stats Logging", "Allow Weapon Throwing", "Allow Behind View", "Allow Admin Pausing", "Kick Idlers Time", "Weapons shake view" };
	GIPropDescText = { "Set the skill of your bot opponents.","When enabled, weapons will always be available for pickup.","Enable this option to reduce the amount of blood and guts you see.","Controls how fast time passes in the game.","Sets the maximum number of spectators that can watch the game.","Sets the maximum number of players that can join this server.","The game ends when someone reaches this score.","Limits how many times players can respawn after dying.","The game ends after this many minutes of play.","Enable this option to send game statistics to the UT2004 global stats server","When enabled, players can throw their current weapon out.","Controls whether players can switch to a third person view.","Controls whether administrators can pause the game.","Specifies how long to wait before kicking idle player from server.","When enabled, some weapons cause view shaking while firing." };
	GIPropsExtras = { "0.000000;Novice;1.000000;Average;2.000000;Experienced;3.000000;Skilled;4.000000;Adept;5.000000;Masterful;6.000000;Inhuman;7.000000;Godlike" };
	CallSigns = {"ALPHA","BRAVO","CHARLIE","DELTA","ECHO","FOXTROT","GOLF","HOTEL","INDIA","JULIET","KILO","LIMA","MIKE","NOVEMBER","OSCAR"};
	MaxIdleTime = 120;
	NoBindString = "[None]";
	BindColor = FColor(0, 128, 128, 255);
	bDeathMessages = true;
	bSendDistributionHistory = true;
	bSendRoundTimeInfo = true;
	
	DefaultPawnClass = AAGP_Character::StaticClass();
	HUDClass = AAGP_HUD::StaticClass();
	PlayerControllerClass = AHumanController::StaticClass();
	GameStateClass = AAA2_GameState::StaticClass();
	PlayerStateClass = AAA2_PlayerState::StaticClass();
}

void AGameInfo::StartPlay()
{
	Super::StartPlay();
	StartMatch();
}

void AGameInfo::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("AGameInfo::BeginPlay()"));
	PreBeginPlay();
	Super::BeginPlay();
}

void AGameInfo::GetSavedGames()
{
}

void AGameInfo::CreateDataObject(UObject* objClass, FString objName, FString PackageName)
{
}

void AGameInfo::DeleteDataObject(UObject* objClass, FString objName, FString PackageName)
{
}

void AGameInfo::LoadDataObject(UObject* objClass, FString objName, FString PackageName)
{
}

void AGameInfo::AllDataObjects(UObject* objClass, UObject* obj, FString PackageName)
{
}

void AGameInfo::SavePackage(FString PackageName)
{
}

void AGameInfo::DeletePackage(FString PackageName)
{
}

void AGameInfo::LoadMapList(FString aMapPrefix, TArray<FString> Maps)
{
}

bool AGameInfo::CheatsDisabled()
{
	return false;   //FAKE  /ELiZ
}

AActor* AGameInfo::GetDefaultTeamClass()
{
	return nullptr;
}
AActor* AGameInfo::GetTeamRole(AController* C)
{
	return nullptr;
}

float AGameInfo::GetProjectileMod()
{
	return 0.0f;
}

bool AGameInfo::IsMultiPlayer()
{
	return false;
}

uint8 AGameInfo::GetPlayerTeamIndex(AController* C)
{
	return 0;
}

void AGameInfo::ConnectionResolved()
{
}

AScreenplay* AGameInfo::GetScreenplay()
{
	return nullptr;
}

void AGameInfo::RequestChangeTeam(AController* Other, int32 N)
{
}

bool AGameInfo::IsRequireAuthorization()
{
	return false;	//FAKE    /ELiZ
}

void AGameInfo::SetRequireAuthorization(bool bReqAuth)
{
}

bool AGameInfo::IsSpectateFirstPersonOnly()
{
	return false;   //FAKE  /ELiZ
}

bool AGameInfo::IsSpectatePlayersOnly()
{
	return false;   //FAKE  /ELiZ
}

bool AGameInfo::IsSpectateBodies()
{
	return false;   //FAKE  /ELiZ
}

int32 AGameInfo::GetROELimit()
{
	return 0;   //FAKE  /ELiZ
}

void AGameInfo::InitiateVoteRequest(AAA2_PlayerState*  PRI, FString PlayerName, FString Reason)
{
}

void AGameInfo::CastVote(AAA2_PlayerState*  PRI)
{
}

bool AGameInfo::ActiveVote()
{
	return false;   //FAKE  /ELiZ
}

void AGameInfo::CheckDevKick(AController* Kicker, FString PlayerName)
{
}

bool AGameInfo::NotifyIdlePlayer(AController* C, float LastMovedTime)
{
	return false;   //FAKE  /ELiZ
}

void AGameInfo::NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage)
{
}

bool AGameInfo::TestForIdlePlayers(AAA2_PlayerState*  PRI)
{
	return false;   //FAKE  /ELiZ
}

int32 AGameInfo::GetTimeElapsed()
{
	return 0;    //FAKE   /ELiZ
}

ATeamInfo* AGameInfo::GetTeam(uint8 Index)
{
	return nullptr;    //FAKE   /ELiZ
}

ATeamInfo* AGameInfo::GetOtherTeam(uint8 Index)
{
	return nullptr;    //FAKE   /ELiZ
}

int32 AGameInfo::CheckHonor(AController* C)
{
	return 0;    //FAKE   /ELiZ
}

bool AGameInfo::CheckGroup(AController* C)
{
	return false;    //FAKE   /ELiZ
}

FString AGameInfo::GetLegalGroupsString()
{
	return "FAKE";    //FAKE   /ELiZ
}

int32 AGameInfo::GetMinHonor()
{
	return 0;    //FAKE   /ELiZ
}

int32 AGameInfo::GetMaxHonor()
{
	return 0;    //FAKE   /ELiZ
}

void AGameInfo::LogPlayerStart(APlayerController* PC)
{
}

void AGameInfo::LogPlayerFinish(APlayerController* PC)
{
}

void AGameInfo::SetROEKickTimer(bool bEnabled)
{
}

void AGameInfo::SetROEKick(bool bEnabled)
{
}

void AGameInfo::SetROEKickDead(bool bEnabled)
{
}

void AGameInfo::NotifyReportLogoutStarted()
{
}

void AGameInfo::NotifyReportLogoutFinished()
{
}

void AGameInfo::grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController)
{
}

void AGameInfo::FakeRestartGame()
{
}

void AGameInfo::AuthorizeServer()
{
}

void AGameInfo::AuthAuthenticateServerCallback(int32 ResultCode, int32 ServerMode, FString ServerModeName)
{
}

void AGameInfo::AuthTransmissionErrorCallback(int32 iReason, FString sMsg, FString sShortMsg)
{
}

void AGameInfo::GetPossibleCommandlineOverride(FString CommandLineFlag, FString DefaultValue)
{
}

void AGameInfo::NotifyAuthTransactionResolving(AInternetInfo* ILink, bool bHighPriority)
{
}

bool AGameInfo::IsAuthAvailable(AInternetInfo* ILink)
{
	return false;     //FAKE   /ELiZ
}

void AGameInfo::NotifyAuthTransactionComplete(AInternetInfo* ILink)
{
}

void AGameInfo::TournamentSetPlayerTeam(AAA2_PlayerState*  PRI, FString SetPlayerName, int32 SetTeamID)
{
}

void AGameInfo::TournamentSetPlayerClass(AAA2_PlayerState*  PRI, FString SetPlayerName, int32 SetUnitSlot, int32 SetPlayerClass)
{
}

void AGameInfo::TournamentSendMessage(FString S)
{
}

void AGameInfo::TournamentSendTeamCaptainOnlyMessage(FString sMsg)
{
}

void AGameInfo::TournamentSendNonTeamCaptainMessages(FString sMsg)
{
}

void AGameInfo::TournamentSetPlayerTeamByString(FString S)
{
}

void AGameInfo::TournamentSetPlayerClassByString(FString S)
{
}

bool AGameInfo::TournamentRequestSwapSides()
{
	return false;    //FAKE   /EliZ
}

void AGameInfo::TournamentAssignRandomTeams()
{
}

void AGameInfo::TournamentRequestPauseTournament()
{
}

void AGameInfo::TournamentRequestStartMatch()
{
}

void AGameInfo::TournamentRequestRestartMatch()
{
}

void AGameInfo::TournamentRequestWarmup()
{
}

void AGameInfo::TournamentRequestResetMatch()
{
}

void AGameInfo::TournamentRequestResetTournament()
{
}

void AGameInfo::TournamentSetTeamName(int32 iTeam, FString sTeamName)
{
}

bool AGameInfo::TournamentIsTournament()
{
	return false;    //FAKE   /EliZ
}

FString AGameInfo::TournamentGetTeamName(int32 iTeamIndex)
{
	return "FAKE";    //FAKE   /EliZ
}

bool AGameInfo::TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword)
{
	return false;    //FAKE   /EliZ
}

bool AGameInfo::TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex)
{
	return false;    //FAKE   /EliZ
}

void AGameInfo::TournamentTeamsReady()
{
}

void AGameInfo::TournamentResumeFromPause()
{
}

bool AGameInfo::TournamentWarmupJustEnded()
{
	return false;
}

bool AGameInfo::TournamentAreAllWeaponClassesAvailable()
{
	return false;
}

void AGameInfo::TournamentEndCurrentRound()
{
}

bool AGameInfo::TournamentIsWarmup()
{
	return false;
}

int32 AGameInfo::TournamentGetMaxTeamSize()
{
	return 0;
}

void AGameInfo::TournamentAssignClass(AAA2_PlayerState*  PRI, int32 iUnit, int32 iSlotIndex)
{
}

bool AGameInfo::TournamentEndedByMercyRule()
{
	return false;
}

ATeamInfo* AGameInfo::TournamentGetTeam(uint8 Index)
{
	return nullptr;    //FAKE   /ELiZ
}

void AGameInfo::TournamentResultsAuthCallback(int32 iResultCode)
{
}

void AGameInfo::TournamentServerINISetTeamName(int32 iTeam, FString sTeamName)
{
}

FString AGameInfo::TournamentServerINIGetTeamName(int32 iTeam)
{
	return "FAKE";    //FAKE   /ELiZ
}

void AGameInfo::TournamentSendCenteredMessage(FString sMsg)
{
}

void AGameInfo::SimulateAuthFailure()
{
}

void AGameInfo::SimulateAuthRecovery()
{
}

void AGameInfo::TournamentRequestDeadRound()
{
}

bool AGameInfo::TournamentIsDeadRound()
{
	return false;   //FAKE   /ELiZ
}

void AGameInfo::TournamentUpdateGameReplicationInfo()
{
}

void AGameInfo::TournamentSetRoundsPerMatch(int32 iNewRounds)
{
}

void AGameInfo::TournamentSetRoundsTimeLimit(int32 iNewTimeLimit)
{
}

bool AGameInfo::IsTournamentMode()
{
	return Cast<AAA2_WorldSettings>(GetWorld()->GetWorldSettings())->IsTournamentServer();
}

void AGameInfo::PreBeginPlay()
{
	StartTime=0;
	//GameReplicationInfo=Spawn(GameReplicationInfoClass);
	//Level.GRI=GameReplicationInfo;
	InitGameReplicationInfo();
	InitVoiceReplicationInfo();
	//InitLogging();
	ReadServerSettings();
}

void AGameInfo::Destroyed()
{
	//CurrentGameProfile=NULL;
	//Super::Destroyed();
}
void AGameInfo::UpdatePrecacheMaterials()
{
	//PrecacheGameTextures(Level);
}
	
void AGameInfo::UpdatePrecacheStaticMeshes()
{
	//PrecacheGameStaticMeshes(Level);
}

void AGameInfo::PrecacheGameTextures(ALevelInfo* myLevel)
{
}

void AGameInfo::PrecacheGameStaticMeshes(ALevelInfo* myLevel)
{
}

void AGameInfo::PrecacheGameAnnouncements(AAnnouncerVoice* V, bool bRewardSounds)
{
}

FString AGameInfo::FindPlayerByID(int32 PlayerID)
{
	AAA2_PlayerState* PRI = nullptr;
	PRI = GameReplicationInfo->FindPlayerByID(PlayerID);
	if (PRI != nullptr)
	{
		return PRI->PlayerName;
	}
	return "";
}

void AGameInfo::ChangeMap(int32 ContextID)
{
	AMapList* MyList = nullptr;
	AMapList* ML = nullptr;
	FString MapString = "";
	/*
	ML = class<MapList>(DynamicLoadObject(MapListType, Class'Class'));
	MyList = Spawn(ML);
	MapString = MyList.GetMap(ContextID);
	MyList.Destroy();
	*/
	if (MapString == "")
	{
		return;
	}
	//Level.ServerTravel(MapString, false);
}

bool AGameInfo::UseLowGore()
{
	return GetDefault<AGameInfo>()->bAlternateMode || GetDefault<AGameInfo>()->bLowGore || GetDefault<AGameInfo>()->GoreLevel < 2;
}

bool AGameInfo::NoBlood()
{
	return GetDefault<AGameInfo>()->GoreLevel == 0;
}

void AGameInfo::PostBeginPlay()
{
	if (MaxIdleTime > 0)
	{
		if (MaxIdleTime > 30)
		{
			MaxIdleTime = 30;
		}
	}
	if (GameStats != nullptr)
	{
		GameStats->NewGame();
		GameStats->ServerInfo();
	}
	if (DemoCommand != "")
	{
		//ConsoleCommand("demorec" @ DemoCommand,true);
	}
}

void AGameInfo::Reset()
{
	Super::Reset();
	bGameEnded=false;
	bOverTime=false;
	bWaitingToStartMatch=true;
	InitGameReplicationInfo();
	InitVoiceReplicationInfo();
}

void AGameInfo::InitLogging()
{
	if (! bEnableStatLogging || ! bLoggingGame || GetNetMode() == ENetMode::NM_Standalone || GetNetMode() == ENetMode::NM_ListenServer)
	{
		return;
	}
	if (StatsClass != nullptr)
	{
		UWorld* const World = GetWorld();
		if (World)
		{
			FActorSpawnParameters SpawnParams;
			SpawnParams.Owner = this;
			SpawnParams.Instigator = GetInstigator();
			Stats = GetWorld()->SpawnActor<AStatsInfo>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
		}
	}
}

void AGameInfo::Timer()
{
	ANavigationPoint* N = nullptr;
	int32 i = 0;
	if (bWelcomePending)
	{
		bWelcomePending = false;
		/*
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			for (i = 0; i < GameReplicationInfo.PRIArray.Num(); i++)
			{
				if ((GameReplicationInfo.PRIArray[i] != nullptr) && (!GameReplicationInfo.PRIArray[i].bWelcomed))
				{
					GameReplicationInfo.PRIArray[i].bWelcomed = true;
					if (!GameReplicationInfo.PRIArray[i].bOnlySpectator)
					{
						BroadcastLocalizedMessage(GameMessageClass, 1, GameReplicationInfo.PRIArray[i]);
					}
					else
					{
						BroadcastLocalizedMessage(GameMessageClass, 16, GameReplicationInfo.PRIArray[i]);
					}
				}
			}
		}
		*/
	}
	//BroadcastHandler.UpdateSentText();
	for (N = Cast<AAA2_WorldSettings>(GetWorldSettings())->NavigationPointList; N != nullptr; N = N->nextNavigationPoint)
	{
		N->FearCost *= FearCostFallOff;
	}
}

void AGameInfo::GameEnding()
{
	EndLogging("serverquit");
}

void AGameInfo::ApplicationShutdown()
{
}

void AGameInfo::InitGameReplicationInfo()
{
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->bTeamGame=bTeamGame;
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->GameName=GameName;
	//Cast<AAA2_GameState>(GetWorld()->GetGameState())->GameClass=Class;
	Cast<AAA2_GameState>(GetWorld()->GetGameState())->MaxLives=MaxLives;
}

void AGameInfo::InitVoiceReplicationInfo()
{
	//Log(Name @ "VoiceReplicationInfo created:" @ VoiceReplicationInfo,'VoiceChat');
}

void AGameInfo::InitMaplistHandler()
{
}

FString AGameInfo::GetNetworkNumber()
{
	return "FAKE";    //FAKE   /ELiZ
}

void AGameInfo::GetServerInfo(FServerResponseLine &ServerState)
{
	int32 RealSkillLevel;

	ServerState.ServerName=StripColor(Cast<AAA2_GameState>(GetWorld()->GetGameState())->ServerName);		//ServerState.ServerName		= StripColor(GameReplicationInfo.ServerName);
	//ServerState.MapName=Left(Level,InStr(Level,"."));
	//ServerState.GameType=Mid(Class,InStr(Class,".") + 1);
	ServerState.CurrentPlayers=GetNumPlayers();
	ServerState.MaxPlayers=MaxPlayers;
	ServerState.IP="";
	ServerState.Port=GetServerPort();
	RealSkillLevel = 0;
	if (ServerSkillLevel == "0") { RealSkillLevel = 0; }
	if (ServerSkillLevel == "1") { RealSkillLevel = 1; }
	if (ServerSkillLevel == "2") { RealSkillLevel = 2; }
	ServerState.SkillLevel=FString::FromInt(RealSkillLevel);
	ServerState.ServerInfo.SetNum(0);
	ServerState.PlayerInfo.SetNum(0);
}
int32 AGameInfo::GetNumPlayers()
{
	return NumPlayers;
}
void AGameInfo::GetServerDetails(FServerResponseLine& ServerState)
{
	AMutator* M = nullptr;
	AGameRules* G = nullptr;
	int32 i = 0;
	int32 Len = 0;
	int32 NumMutators = 0;
	FString MutatorName = "";
	bool bFound = false;
	/*
	AddServerDetail(ServerState, "ServerMode", Eval((GetWorld()->GetNetMode() == NM_ListenServer), "non-dedicated", "dedicated"));
	AddServerDetail(ServerState, "AdminName", GameReplicationInfo.AdminName);
	AddServerDetail(ServerState, "AdminEmail", GameReplicationInfo.AdminEmail);
	AddServerDetail(ServerState, "ServerVersion", Level.EngineVersion);
	if ((AccessControl != nullptr) && AccessControl.RequiresPassword())
	{
		AddServerDetail(ServerState, "GamePassword", "True");
	}
	AddServerDetail(ServerState, "GameStats", FString::FromInt((GameStats != nullptr)));
	if (AllowGameSpeedChange() && (GameSpeed != 1))
	{
		AddServerDetail(ServerState, "GameSpeed", FString::FromInt((float(int((GameSpeed * float(100)))) / 100)));
	}
	AddServerDetail(ServerState, "MaxSpectators", FString::FromInt(MaxSpectators));
	if (VotingHandler != nullptr)
	{
		VotingHandler.GetServerDetails(ServerState);
	}
	for (M = BaseMutator; M != nullptr; M = M.NextMutator)
	{
		M.GetServerDetails(ServerState);
		NumMutators++;
	}
	for (G = GameRulesModifiers; G != nullptr; G = G.NextGameRules)
	{
		G.GetServerDetails(ServerState);
	}
	for (i = 0; i < ServerState.ServerInfo.Num(); i++)
	{
		if (ServerState.ServerInfo[i].Key ~= "Mutator")
		{
			NumMutators--;
		}
	}
	if (NumMutators > 1)
	{
		for (M = BaseMutator.NextMutator; M != nullptr; M = M.NextMutator)
		{
			MutatorName = M.GetHumanReadableName();
			i = 0;
			if (i < ServerState.ServerInfo.Num())
			{
				if ((ServerState.ServerInfo[i].Value ~= MutatorName) && (ServerState.ServerInfo[i].Key ~= "Mutator"))
				{
					bFound = true;
				}
				else
				{
					i++;
				}
			}
			if (!bFound)
			{
				Len = ServerState.ServerInfo.Num();
				ServerState.ServerInfo.Num() = (Len + 1);
				ServerState.ServerInfo[i].Key = "Mutator";
				ServerState.ServerInfo[i].Value = MutatorName;
			}
		}
	}
	*/
}

void AGameInfo::GetServerPlayers(FServerResponseLine& ServerState)
{
	AMutator* M = nullptr;
	AController* C = nullptr;
	AAA2_PlayerState* PRI = nullptr;
	int32 i = 0;
	TArray<int32> TeamFlag = { 0,0 };
	/*
	i = ServerState.PlayerInfo.Num();
	TeamFlag[0] = (1 << 29);
	TeamFlag[1] = (TeamFlag[0] << 1);
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		PRI = C.PlayerReplicationInfo;
		if (((PRI != nullptr) && (!PRI.bBot)) && (Cast<AMessagingSpectator>(C) == nullptr))
		{
			ServerState.PlayerInfo.Num() = (i + 1);
			ServerState.PlayerInfo[i].PlayerNum = C.PlayerNum;
			ServerState.PlayerInfo[i].PlayerName = PRI.PlayerName;
			ServerState.PlayerInfo[i].Score = PRI.Score_Total;
			ServerState.PlayerInfo[i].Ping = (4 * PRI.Ping);
			if (bTeamGame && (PRI.Team != nullptr))
			{
				ServerState.PlayerInfo[i].StatsID = (ServerState.PlayerInfo[i].StatsID | TeamFlag[PRI.Team.TeamIndex]);
			}
			i++;
		}
	}
	for (M = BaseMutator.NextMutator; M != nullptr; M = M.NextMutator)
	{
		M.GetServerPlayers(ServerState);
	}
	*/
}

int32 AGameInfo::GetServerPort()
{
	FString Left, Right,S;

	S = Cast<AAA2_WorldSettings>(GetWorldSettings())->GetAddressURL();
	S.Split(TEXT(":"), &Left, &Right);
	return _tstoi(*Right);
}

/*
bool AGameInfo::SetPause(bool bPause, APlayerController* p)
{
		if (bPauseable || bAdminCanPause && p->IsA(UAdmin::StaticClass()) || p.PlayerReplicationInfo.bAdmin || GetNetMode() == ENetMode::NM_Standalone)
		{
			if (bPause)
			{
				Level.Pauser=p.PlayerReplicationInfo;
			}
			else
			{
				Level.Pauser=nullptr;
			}
			PauseSound(bPause);
			return true;
		}
		else
		{
			return false;
		}
}
*/

bool AGameInfo::AllowGameSpeedChange()
{
	if(GetNetMode() == ENetMode::NM_Standalone)
	{
		return true;
	}
	else
	{
		return bAllowMPGameSpeed;
	}
}

void AGameInfo::SetGameSpeed(float t)
{
	float OldSpeed = 0;
	/*
	if (! AllowGameSpeedChange())
	{
		Level.TimeDilation=1;
	}
	else
	{
		OldSpeed=GameSpeed;
		GameSpeed=FMax(t,0.1);
		Level.TimeDilation=1 * GameSpeed;
		if (GameSpeed != OldSpeed)
		{
			GetDefault<AGameInfo>()->GameSpeed=GameSpeed;
			'GameInfo'.StaticSaveConfig();
		}
	}
	SetTimer(Level.TimeDilation,true);
	*/
}

void AGameInfo::DetailChange()
{
	AActor* A = nullptr;
	AZoneInfo* Z = nullptr;
	/*
		if (Level.DetailMode == 0)
		{
			ForEach DynamicActors('Actor',A)
			{
				if (A.bHighDetail || A.bSuperHighDetail && ! A.bGameRelevant)
				{
					A.Destroy();
				}
			}
		}
		else
		{
			if (Level.DetailMode == 1)
			{
				ForEach DynamicActors('Actor',A)
				{
					if (A.bSuperHighDetail && ! A.bGameRelevant)
					{
						A.Destroy();
					}
				}
			}
		}
		ForEach AllActors('ZoneInfo',Z)
		{
			Z.LinkToSkybox();
		}
	*/
}

bool AGameInfo::GrabOption(FString &Options, FString &Result)
{
	if(Options.Left(1) =="?")
	{
		Result = Options.Mid(1);
		if (Result.Find("?") >=0)
		{
			Result = Result.Left(Result.Find("?"));
		}
		Options= Options.Mid(1);
		if (Options.Find("?") >= 0)
		{
			Result = Options.Left(Options.Find("?"));
		}
		else
		{
			Options="";
		}
		return true;
	}
	else
	{
		return false;
	}
}

void AGameInfo::GetKeyValue(FString Pair, FString &Key, FString &Value)
{
	Pair.Split(TEXT("="), &Key, &Value);
}

FString AGameInfo::ParseOption(FString Options, FString InKey)
{
	FString Pair;
	FString Key;
	FString Value;
	if (GrabOption(Options,Pair))
	{
		GetKeyValue(Pair,Key,Value);
		if (Key == InKey)
		{
			return Value;
		}
	}
	return "";
}

bool AGameInfo::HasOption(FString Options, FString InKey)
{
	FString Pair;
	FString Key;
	FString Value;
	if (GrabOption(Options,Pair))
	{
		GetKeyValue(Pair,Key,Value);
		if (Key == InKey)
		{
			return true;
		}
	}
	return false;
}

void AGameInfo::InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage)
{
		//FString InOpt;
		//FString LeftOpt;
		//int32 pos;
		//AAccessControl*  ACClass;
		//AGameRules* GRClass;
		//bool bIsTutorial;
		
		Super::InitGame(MapName, Options, ErrorMessage);

		/*
		InOpt=ParseOption(Options,"SaveGame");

		if (InOpt != "" && CurrentGameProfile == nullptr)
		{
			CurrentGameProfile=LoadDataObject('GameProfile',"GameProfile",InOpt);
			if (CurrentGameProfile != nullptr)
			{
				CurrentGameProfile.Initialize(this,InOpt);
			}
			else
			{
				Log("SINGLEPLAYER GameInfo::InitGame failed to find GameProfile" @ InOpt);
			}
			if (! CurrentGameProfile.bInLadderGame)
			{
				CurrentGameProfile=nullptr;
			}
		}
		if (CurrentGameProfile == nullptr && Left(Level,3) ~= "TUT")
		{
			bIsTutorial=true;
		}
		MaxAdmins=Min(32,GetIntOption(Options,"MaxAdmins",MaxAdmins));
		AbsoluteMaxPlayers=GetPossibleCommandlineOverride("MaxPlayers=",32);
		GetDefault<AGameInfo>()->AbsoluteMaxPlayers=AbsoluteMaxPlayers;
		MaxPlayers=Clamp(GetIntOption(Options,"MaxPlayers",MaxPlayers),0,AbsoluteMaxPlayers);
		MaxSpectators=Clamp(GetIntOption(Options,"MaxSpectators",MaxSpectators),0,32);
		GameDifficulty=FMax(0,GetIntOption(Options,"Difficulty",GameDifficulty));
		if (CurrentGameProfile != nullptr || bIsTutorial)
		{
			if (CurrentGameProfile != nullptr)
			{
				GameDifficulty=CurrentGameProfile.Difficulty;
			}
			SetGameSpeed(1);
		}
		AddMutator(MutatorClass);
		BroadcastClass=class<BroadcastHandler>(DynamicLoadObject(BroadcastHandlerClass,Class'Class'));
		GetDefault<AGameInfo>()->BroadcastClass=BroadcastClass;
		BroadcastHandler=Spawn(BroadcastClass);
		InOpt=ParseOption(Options,"AccessControl");
		if (InOpt != "")
		{
			ACClass=class<AccessControl>(DynamicLoadObject(InOpt,Class'Class'));
		}
		if (ACClass == nullptr)
		{
			ACClass=class<AccessControl>(DynamicLoadObject(AccessControlClass,Class'Class'));
			if (ACClass == nullptr)
			{
				ACClass='AccessControl';
			}
		}
		LeftOpt=ParseOption(Options,"AdminName");
		InOpt=ParseOption(Options,"AdminPassword");
		if (LeftOpt != "" && InOpt != "")
		{
			ACClass.GetDefault<AGameInfo>()->bDontAddDefaultAdmin=true;
		}
		if (GetNetMode() == ENetMode::NM_ListenServer || GetNetMode() == ENetMode::NM_DedicatedServer)
		{

			UWorld* const World = GetWorld();
			if (World)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = this;
				SpawnParams.Instigator = GetInstigator();
				AccessControl = GetWorld()->SpawnActor<AAccessControl>(FVector::ZeroVector, FRotator::ZeroRotator, SpawnParams);
			}
		}
		SetGameSpeed(1);

		InOpt=ParseOption(Options,"GameRules");
		if (InOpt != "")
		{
			Log("Game Rules" @ InOpt);
			if (InOpt != "")
			{
				pos=InStr(InOpt,",");
				if (pos > 0)
				{
					LeftOpt=Left(InOpt,pos);
					InOpt=Right(InOpt,Len(InOpt) - pos - 1);
				}
				else
				{
					LeftOpt=InOpt;
					InOpt="";
				}
				Log("Add game rules " + LeftOpt);
				GRClass=class<GameRules>(DynamicLoadObject(LeftOpt,Class'Class'));
				if (GRClass != nullptr)
				{
					if (GameRulesModifiers == nullptr)
					{
						GameRulesModifiers=Spawn(GRClass);
					}
					else
					{
						GameRulesModifiers.AddGameRules(Spawn(GRClass));
					}
				}
			}
		}
		InOpt=ParseOption(Options,"Mutator");
		if (InOpt != "")
		{
			Log("Mutators" @ InOpt);
			if (InOpt != "")
			{
				pos=InStr(InOpt,",");
				if (pos > 0)
				{
					LeftOpt=Left(InOpt,pos);
					InOpt=Right(InOpt,Len(InOpt) - pos - 1);
				}
				else
				{
					LeftOpt=InOpt;
					InOpt="";
				}
				AddMutator(LeftOpt,true);
			}
		}
		if (CurrentGameProfile == nullptr && ! bIsTutorial)
		{
			InOpt=ParseOption(Options,"GameSpeed");
			if (InOpt != "")
			{
				Log("GameSpeed" @ InOpt);
				SetGameSpeed(InOpt);
			}
		}
		InOpt=ParseOption(Options,"GamePassword");
		if (InOpt != "" && AccessControl != nullptr)
		{
			AccessControl.SetGamePassword(InOpt);
			Log("GamePassword" @ InOpt);
		}
		InOpt=ParseOption(Options,"AllowThrowing");
		if (InOpt != "")
		{
			bAllowWeaponThrowing=InOpt;
		}
		InOpt=ParseOption(Options,"AllowBehindview");
		if (InOpt != "")
		{
			bAllowBehindView=InOpt;
		}
		Log("GameInfo::InitGame : bEnableStatLogging" @ bEnableStatLogging);
		if (HasOption(Options,"DemoRec"))
		{
			DemoCommand=ParseOption(Options,"DemoRec");
		}
		if (HasOption(Options,"AttractCam"))
		{
			bAttractCam=true;
		}
		InitMaplistHandler();
		InOpt=ParseOption(Options,"VotingHandler");
		if (InOpt != "")
		{
			VotingHandlerClass=class<VotingHandler>(DynamicLoadObject(InOpt,Class'Class'));
		}
		if (VotingHandlerClass == nullptr)
		{
			if (VotingHandlerType != "")
			{
				VotingHandlerClass=class<VotingHandler>(DynamicLoadObject(VotingHandlerType,Class'Class'));
			}
			else
			{
				VotingHandlerClass=class<VotingHandler>(DynamicLoadObject("Engine.VotingHandler",Class'Class'));
			}
		}
		'GameInfo'.GetDefault<AGameInfo>()->VotingHandlerClass=VotingHandlerClass;
		if (GetNetMode() != ENetMode::NM_Standalone && VotingHandlerClass != nullptr && VotingHandlerClass.IsEnabled())
		{
			VotingHandler=Spawn(VotingHandlerClass);
			if (VotingHandler == nullptr)
			{
				Log("WARNING: Failed to spawn VotingHandler");
			}
		}
		bTestMode=HasOption(Options,"CheckErrors");
		*/
}

void AGameInfo::AddMutator(FString mutname, bool bUserAdded)
{
	AMutator* mutClass = nullptr;
	AMutator* mut = nullptr;
	/*
	if (!AllowMutator(mutname))
	{
		return;
	}
	mutClass = class<Mutator>(DynamicLoadObject(mutname, Class'Class'));
	if (mutClass == nullptr)
	{
		return;
	}
	if ((mutClass.GetDefault<AGameInfo>()->GroupName != "") && (BaseMutator != nullptr))
	{
		for (mut = BaseMutator; mut != nullptr; mut = mut.NextMutator)
		{
			if (mut.GroupName == mutClass.Default.GroupName)
			{
				Log("Not adding " + FString::FromInt(mutClass) + " because already have a mutator in the same group - " + FString::FromInt(mut));
				return;
			}
		}
	}
	for (mut = BaseMutator; mut != nullptr; mut = mut.NextMutator)
	{
		if (mut.Class == mutClass)
		{
			Log("Not adding " + FString::FromInt(mutClass) + " because this mutator is already added - " + FString::FromInt(mut));
			return;
		}
	}
	mut = Spawn(mutClass);
	if (mut == nullptr)
	{
		return;
	}
	mut.bUserAdded = bUserAdded;
	if (BaseMutator == nullptr)
	{
		BaseMutator = mut;
	}
	else
	{
		BaseMutator.AddMutator(mut);
	}
	*/
}

void AGameInfo::AddGameModifier(AGameRules* NewRule)
{
	if (NewRule == nullptr)
	{
		return;
	}
	if (GameRulesModifiers != nullptr)
	{
		GameRulesModifiers->AddGameRules(NewRule);
	}
	else
	{
		GameRulesModifiers=NewRule;
	}
}

FString AGameInfo::GetBeaconText()
{
	return Cast<AAA2_WorldSettings>(GetWorldSettings())->ComputerName + " " + Cast<AAA2_WorldSettings>(GetWorldSettings())->Title + " " + FString::FromInt(GetNumPlayers()) + "/" + FString::FromInt(MaxPlayers);
}

/*
void AGameInfo::ProcessServerTravel(FString URL, bool bItems)
{
		APlayerController* p = nullptr;
		APlayerController* LocalPlayer = nullptr;
		BaseMutator.ServerTraveling(URL,bItems);
		EndLogging("mapchange");
		Log("ProcessServerTravel:" @ URL);
		ForEach DynamicActors('PlayerController',p)
		{
			if (NetConnection(p.Player) != nullptr)
			{
				p.ClientTravel(Eval(InStr(URL,"?") > 0,Left(URL,InStr(URL,"?")),URL),2,bItems);
			}
			else
			{
				LocalPlayer=p;
				p.PreClientTravel();
			}
		}
		if (GetNetMode() == ENetMode::NM_ListenServer && LocalPlayer != nullptr)
		{
			Level.NextURL=Level.NextURL + "?Team=" + LocalPlayer.GetDefaultURL("Team") + "?Name=" + LocalPlayer.GetDefaultURL("Name") + "?Class=" + LocalPlayer.GetDefaultURL("Class") + "?Character=" + LocalPlayer.GetDefaultURL("Character");
		}
		if (GetNetMode() != ENetMode::NM_DedicatedServer && GetNetMode() != 2)
		{
			Level.NextSwitchCountdown=0;
		}
}
*/

void AGameInfo::PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	bool bSpectator = true;
	bool bAdmin = false;
	Super::PreLogin(Options, Address, UniqueId, ErrorMessage);
	FString FailCode = "0";
	bSpectator = ParseOption(Options,"SpectatorOnly") == "1";
	if (AccessControl != nullptr)
	{
		bAdmin = AccessControl->AdminLogin(nullptr, ParseOption(Options, "Password"));
	}

	if (bAdmin)
	{
		bSpectator=true;
	}
	if (AccessControl != nullptr)
	{
		AccessControl->PreLogin(Options,Address, ErrorMessage,FailCode,bSpectator,bAdmin);
	}
}

int32 AGameInfo::GetIntOption(FString Options, FString ParseString, int32 CurrentValue)
{
	FString InOpt;
	InOpt=ParseOption(Options,ParseString);
	if (InOpt != "")
	{
		return _tstoi(*InOpt);
	}
	return CurrentValue;
}

bool AGameInfo::BecomeSpectator(APlayerController* p)
{
	/*
	if (((((p->PlayerReplicationInfo == nullptr) || (!GameReplicationInfo->bMatchHasBegun)) || (NumSpectators >= MaxSpectators)) || p->IsInState("GameEnded")) || p->IsInState("RoundEnded"))
	{
		p.ReceiveLocalizedMessage(GameMessageClass, 12);
		return false;
	}
	p->PlayerReplicationInfo->bOnlySpectator = true;
	NumSpectators++;
	NumPlayers--;
	*/
	return true;
}

bool AGameInfo::AllowBecomeActivePlayer(APlayerController* p)
{
	/*
	if (((((((p->PlayerReplicationInfo == nullptr) || (!GameReplicationInfo->bMatchHasBegun)) || bMustJoinBeforeStart) || (NumPlayers >= MaxPlayers)) || (MaxLives > 0)) || p->IsInState("GameEnded")) || p->IsInState("RoundEnded"))
	{
		p->ReceiveLocalizedMessage(GameMessageClass, 13);
		return false;
	}
	*/
	return true;
}

bool AGameInfo::AtCapacity(bool bSpectator, bool bAdmin)
{
	if (GetNetMode() == ENetMode::NM_Standalone)
	{
		return false;
	}
	if (bSpectator && ! bAdmin)
	{
		return NumSpectators >= MaxSpectators && GetNetMode() != ENetMode::NM_ListenServer || NumPlayers > 0;
	}
	else
	{
		if (bAdmin)
		{
			return MaxAdmins > 0 && NumAdmins >= MaxAdmins;
		}
		else
		{
			return MaxPlayers > 0 && NumPlayers >= MaxPlayers;
		}
	}
}
void AGameInfo::InitSavedLevel()
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->GRI == nullptr)
	{
		Cast<AAA2_WorldSettings>(GetWorldSettings())->GRI= Cast<AAA2_GameState>(GetWorld()->GetGameState());
	}
	//if (Level.ObjectPool == nullptr)
	//{
	//	Level.ObjectPool=new (XLevel) UObjectPool::StaticClass();
	//}
}

/*
APlayerController* AGameInfo::Login(FString Portal, FString Options, FString& Error)
{
	return nullptr;   //FAKE   /ELiZ
}
*/

void AGameInfo::TestLevel()
{
	AActor* A = nullptr;
	AActor* Found = nullptr;
	bool bFoundErrors = false;
	/*
	ForEach AllActors('Actor',A)
	{
		bFoundErrors=bFoundErrors || A.CheckForErrors();
		if (bFoundErrors && Found == nullptr)
		{
			Found=A;
		}
	}
	if (bFoundErrors)
	{
		Found.Crash();
	}
	*/
}

void AGameInfo::StartMatch()
{
	Super::StartMatch();
}

bool AGameInfo::PlayerCanRestart(APlayerController* aPlayer)
{
	return true;
}
bool AGameInfo::PlayerCanRestartGame(APlayerController* aPlayer)
{
	return true;
}
void AGameInfo::RestartPlayer(AController* aPlayer)
{
	Super::RestartPlayer(aPlayer);  //Mine ELiZ
}

APawn* AGameInfo::GetDefaultPlayerClass(AController* C)
{
	APlayerController* PC = nullptr;
	FString PawnClassName = "";
	APawn* PawnClass = nullptr;
	PC = Cast<APlayerController>(C);
	if (PC != nullptr)
	{
		/*
		PawnClassName = PC.GetDefaultURL("Class");
		PawnClass = class<Pawn>(DynamicLoadObject(PawnClassName, Class'Class'));
		if (PawnClass != nullptr)
		{
			return PawnClass;
		}
		*/
	}
	//return class<Pawn>(DynamicLoadObject(DefaultPlayerClassName, Class'Class'));
	return nullptr;    //FAKE  /ELiZ
}

void AGameInfo::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);
	AAA2_HUD* HudClass = nullptr;
	AScoreBoard* ScoreboardClass = nullptr;
	/*
	if (! bIsSaveGame)
	{
		if (GameStats != nullptr)
		{
			GameStats.ConnectEvent(NewPlayer.PlayerReplicationInfo);
			GameStats.GameEvent("NameChange",NewPlayer.PlayerReplicationInfo.PlayerName,NewPlayer.PlayerReplicationInfo);
		}
		if (! bDelayedStart)
		{
			bRestartLevel=false;
			if (bWaitingToStartMatch)
			{
				StartMatch();
			}
			else
			{
				RestartPlayer(NewPlayer);
			}
			bRestartLevel=GetDefault<AGameInfo>()->bRestartLevel;
		}
	}
	NewPlayer.ClientSetMusic("",3);
	if (HUDType == "")
	{
		Log("No HUDType specified in GameInfo",'Log');
	}
	else
	{
		HudClass=class<HUD>(DynamicLoadObject(HUDType,Class'Class'));
		if (HudClass == nullptr)
		{
			Log("Can't find HUD class " + HUDType,'Error');
		}
	}
	if (ScoreBoardType != "")
	{
		ScoreboardClass=class<ScoreBoard>(DynamicLoadObject(ScoreBoardType,Class'Class'));
		if (ScoreboardClass == nullptr)
		{
			Log("Can't find ScoreBoard class " + ScoreBoardType,'Error');
		}
	}
	NewPlayer.ClientSetHUD(HudClass,ScoreboardClass);
	SetWeaponViewShake(NewPlayer);
	if (bIsSaveGame)
	{
		return;
	}
	if (NewPlayer.Pawn != nullptr)
	{
		NewPlayer.Pawn.ClientSetRotation(NewPlayer.Pawn.Rotation);
	}
	if (VotingHandler != nullptr)
	{
		VotingHandler.PlayerJoin(NewPlayer);
	}
	NewPlayer.ClientCapBandwidth(NewPlayer.Player.CurrentNetSpeed);
	NotifyLogin(NewPlayer.PlayerReplicationInfo.PlayerID);
	Log("New Player" @ NewPlayer.PlayerReplicationInfo.PlayerName @ "id=" + NewPlayer.GetPlayerIDHash());
	*/
}

void AGameInfo::SetWeaponViewShake(APlayerController* p)
{
	//Cast<AHumanController>(p)->ClientSetWeaponViewShake(bWeaponShouldViewShake && bModViewShake);
}

void AGameInfo::Logout(AController* Exiting)
{
	bool bMessage = false;
	int32 iDeterminedNumberOfPlayers = 0;
	AController* ctrlIterator = nullptr;
	bMessage = true;
	/*
	if (Cast<APlayerController>(Exiting) != nullptr)
	{
		DebugLog(DEBUG_Multi, "=============PLAYER IS EXITING=============");
		DebugLog(DEBUG_Multi, "Initial NumSpectators:" @ FString::FromInt(NumSpectators));
		DebugLog(DEBUG_Multi, "Initial NumAdmins:" @ FString::FromInt(NumAdmins));
		DebugLog(DEBUG_Multi, "Initial NumPlayers:" @ FString::FromInt(NumPlayers));
		if (Cast<APlayerController>(Exiting).PlayerReplicationInfo.bAdmin)
		{
			NumAdmins--;
		}
		if (Cast<APlayerController>(Exiting).PlayerReplicationInfo.bOnlySpectator)
		{
			bMessage = false;
			NumSpectators--;
			if (NumSpectators < 0)
			{
				Log("NumSpectators decreased below zero! Was:" @ FString::FromInt(NumSpectators) + ", resetting to zero.");
				NumSpectators = 0;
			}
		}
		else
		{
			Log("Player (non bonlyspectator) leaving server");
			NumPlayers--;
			if (NumPlayers < 0)
			{
				Log("Internal player count resetting to zero");
				NumPlayers = 0;
			}
			iDeterminedNumberOfPlayers = 0;
			for (ctrlIterator = Level.ControllerList; ctrlIterator != nullptr; ctrlIterator = ctrlIterator.nextController)
			{
				if ((((ctrlIterator != Exiting) && (Cast<APlayerController>(ctrlIterator) != nullptr)) && (Cast<APlayerController>(ctrlIterator).PlayerReplicationInfo != nullptr)) && (!PlayerController(ctrlIterator).PlayerReplicationInfo.bOnlySpectator))
				{
					iDeterminedNumberOfPlayers++;
				}
			}
			if (iDeterminedNumberOfPlayers != NumPlayers)
			{
				Log("Determined and calculated players don't match, resetting to calculated");
				NumPlayers = iDeterminedNumberOfPlayers;
			}
			Log("Number of players after player leaves: " + FString::FromInt(NumPlayers));
		}
		DebugLog(DEBUG_Multi, "Final NumSpectators:" @ FString::FromInt(NumSpectators));
		DebugLog(DEBUG_Multi, "Final NumAdmins:" @ FString::FromInt(NumAdmins));
		DebugLog(DEBUG_Multi, "Final NumPlayers:" @ FString::FromInt(NumPlayers));
		DebugLog(DEBUG_Multi, "=============PLAYER HAS EXITED=============");
	}
	if (bMessage && ((GetWorld()->GetNetMode() == NM_DedicatedServer) || (GetWorld()->GetNetMode() == NM_ListenServer)))
	{
		BroadcastLocalizedMessage(GameMessageClass, 4, Exiting.PlayerReplicationInfo);
	}
	if (VotingHandler != nullptr)
	{
		VotingHandler.PlayerExit(Exiting);
	}
	if (GameStats != nullptr)
	{
		GameStats.DisconnectEvent(Exiting.PlayerReplicationInfo);
	}
	*/
	NotifyLogout(Exiting);
}

void AGameInfo::NotifyLogin(int32 NewPlayerID)
{
	int32 i = 0;
	TArray<APlayerController*> PCArray = {};
	GetPlayerControllerList(PCArray);
	for (i = 0; i < PCArray.Num(); i++)
	{
		//PCArray[i]->ServerRequestBanInfo(NewPlayerID);
	}
}

void AGameInfo::NotifyLogout(AController* Exiting)
{
	/*
		AController* C = nullptr;
		APlayerController* PC = nullptr;
		BaseMutator.NotifyLogout(Exiting);
		if (Cast<APlayerController>(Exiting) != nullptr && Exiting.PlayerReplicationInfo != nullptr)
		{
			C=Level.ControllerList;
			if (C != nullptr)
			{
				PC=Cast<APlayerController>(C);
				if (PC != nullptr && PC.ChatManager != nullptr)
				{
					PC.ChatManager.UnTrackPlayer(Exiting.PlayerReplicationInfo.PlayerID);
				}
				C=C.nextController;
			}
		}
	*/
}

void AGameInfo::AcceptInventory(APawn* PlayerPawn)
{
}

void AGameInfo::AddGameSpecificInventory(APawn* p)
{
	AWeapon* newWeapon = nullptr;
	AWeapon* WeapClass = nullptr;
	AInventory* Inv = nullptr;
	/*
	WeapClass = BaseMutator.GetDefaultWeapon();
	if ((WeapClass != nullptr) && (p.FindInventoryType(WeapClass) == nullptr))
	{
		newWeapon = Spawn(WeapClass, , , p.Location);
		if (newWeapon != nullptr)
		{
			Inv = nullptr;
			for (Inv = Inventory; Inv != nullptr; Inv = Inv.Inventory)
			{
				if (Inv->IsA(AWeapon::StaticClass()) && (Cast<AWeapon>(Inv).bCanThrow == false))
				{
				}
			}
			newWeapon.GiveTo(p);
			newWeapon.bCanThrow = false;
		}
	}
	*/
}

void AGameInfo::AddDefaultInventory(APawn* PlayerPawn)
{
	AWeapon* newWeapon = nullptr;
	AWeapon* WeapClass = nullptr;
	/*
	WeapClass=BaseMutator.GetDefaultWeapon();
	if (WeapClass != nullptr && PlayerPawn.FindInventoryType(WeapClass) == nullptr)
	{
		newWeapon=Spawn(WeapClass,,,PlayerPawn.Location);
		if (newWeapon != nullptr)
		{
			newWeapon.GiveTo(PlayerPawn);
			newWeapon.bCanThrow=false;
		}
	}
	SetPlayerDefaults(PlayerPawn);
	*/
}

void AGameInfo::SetPlayerDefaults(APawn* PlayerPawn)
{
	/*
		PlayerPawn.AirControl=PlayerPawn.Default.AirControl;
		PlayerPawn.GroundSpeed=PlayerPawn.Default.GroundSpeed;
		PlayerPawn.WaterSpeed=PlayerPawn.Default.WaterSpeed;
		PlayerPawn.AirSpeed=PlayerPawn.Default.AirSpeed;
		PlayerPawn.Acceleration=PlayerPawn.Default.Acceleration;
		PlayerPawn.JumpZ=PlayerPawn.Default.JumpZ;
		//BaseMutator.ModifyPlayer(PlayerPawn);
	*/
}

void AGameInfo::NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		C.NotifyKilled(Killer, Killed, KilledPawn);
	}
	*/
}

void AGameInfo::KillEvent(FString KillType, AAA2_PlayerState*  Killer, AAA2_PlayerState*  Victim, UaDamageType* Damage)
{
	if (GameStats != nullptr)
	{
		GameStats->KillEvent(KillType,Killer,Victim,Damage);
	}
}

void AGameInfo::Killed(AController* Killer, AController* Killed, APawn* KilledPawn, UaDamageType* DamageType)
{
}

bool AGameInfo::PreventDeath(APawn* Killed, AController* Killer, UaDamageType* DamageType, FVector HitLocation)
{
	if (GameRulesModifiers == nullptr)
	{
		return false;
	}
	return GameRulesModifiers->PreventDeath(Killed,Killer,DamageType,HitLocation);
}

bool AGameInfo::PreventSever(APawn* Killed, FName BoneName, int32 Damage, UaDamageType* DamageType)
{
	if (GameRulesModifiers == nullptr)
	{
		return false;
	}
	return GameRulesModifiers->PreventSever(Killed,BoneName,Damage,DamageType);
}

void AGameInfo::BroadcastDeathMessage(AController* Killer, AController* Other, UaDamageType* DamageType)
{
	FString sLoggingDeathMessage = "";
	APawn* pawnIter = nullptr;
	/*
	if (bDeathMessages)
	{
		if (Killer == Other || Killer == nullptr)
		{
			if (Killer == Other)
			{
				if (Killer != nullptr)
				{
					sLoggingDeathMessage="Player """ + Killer.PlayerReplicationInfo.PlayerName + """ killed self";
				}
				else
				{
					sLoggingDeathMessage="Unknown player killed self";
				}
			}
			else
			{
				if (Killer != Other)
				{
					if (Killer != nullptr && Other != nullptr)
					{
						if (Killer.PlayerReplicationInfo != nullptr && Other.PlayerReplicationInfo != nullptr)
						{
							sLoggingDeathMessage="Player  """ + Other.PlayerReplicationInfo.PlayerName + """ killed by  """ + Killer.PlayerReplicationInfo.PlayerName;
						}
						else
						{
							if (Killer.PlayerReplicationInfo != nullptr)
							{
								sLoggingDeathMessage="Enemy soldier killed by """ + Killer.PlayerReplicationInfo.PlayerName + """";
							}
							else
							{
								sLoggingDeathMessage="Player  """ + Other.PlayerReplicationInfo.PlayerName + """ killed enemy soldier";
							}
						}
					}
					else
					{
						if (Killer != nullptr && Killer.PlayerReplicationInfo != nullptr)
						{
							sLoggingDeathMessage="Unknown player killed by """ + Killer.PlayerReplicationInfo.PlayerName + """";
						}
						else
						{
							if (Other != nullptr && Other.PlayerReplicationInfo != nullptr)
							{
								sLoggingDeathMessage="Player """ + Killer.PlayerReplicationInfo.PlayerName + """ killed by unknown player";
							}
							else
							{
								sLoggingDeathMessage="Unknown player killed by unknown player";
							}
						}
					}
				}
			}
			if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.3)
			{
				Level.Game.BroadcastHandler.WritePRIChatLog(None,sLoggingDeathMessage,'DeathMessage');
			}
			ForEach AllActors('Pawn',pawnIter)
			{
				if (pawnIter.Controller == Killer)
				{
					if (pawnIter.isKilledByIED())
					{
						BroadcastLocalized(this,DeathMessageClass,3,None,Other.PlayerReplicationInfo,DamageType);
						return;
					}
				}
			}
			BroadcastLocalized(this,DeathMessageClass,1,None,Other.PlayerReplicationInfo,DamageType);
		}
		else
		{
			BroadcastLocalized(this,DeathMessageClass,0,Killer.PlayerReplicationInfo,Other.PlayerReplicationInfo,DamageType);
		}
	}
	*/
}
void AGameInfo::ParseKillMessage(FString KillerName, FString VictimName, FString DeathMessage)
{
}

void AGameInfo::KickByController(AController* C, FString Reason, bool bMaybeFail)
{
	AccessControl->SetupKick(Cast<APlayerController>(C),Reason);
}

void AGameInfo::Kick(FString S, FString Reason, bool bMaybeFail)
{
	if (AccessControl != nullptr)
	{
		AccessControl->Kick(S,Reason,bMaybeFail);
	}
}

bool AGameInfo::KickBan(APlayerController* PCAdmin, FString PlayerName, FString time_to_ban_for, FString BanOptions)
{

	Ban(PCAdmin, PlayerName, time_to_ban_for, BanOptions);
	/*
	if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
	{
		Level.Game.BroadcastHandler.WritePRIChatLog(PCAdmin.PlayerReplicationInfo, "Player: \"" + PlayerName + "\"", "AdminKick");
	}
	*/
	if (AccessControl->Kick(PlayerName, "Admin",false))
	{
		return true;
	}
	else
	{
		return false;
	}
}
void AGameInfo::Ban(APlayerController* PCAdmin, FString PlayerName, FString time_to_ban_for, FString BanOptions)
{
	/*
		FString time_suffix;
		FString strBanTime;
		FString sBanEntry;
		int32 weeks;
		int32 days;
		int32 hours;
		int32 minutes;
		int32 time_units;
		AController* C = nullptr;
		APlayerController* PC = nullptr;
		FString sPBGUID;
		weeks=0;
		days=0;
		hours=0;
		minutes=0;
		time_suffix=Right(time_to_ban_for,1);
		if (Level.PBIsEnabled() != 0 && BanOptions ~= "PBGUID" || BanOptions ~= "NAME")
		{
			C=Level.ControllerList;
			if (C != nullptr)
			{
				PC=Cast<APlayerController>(C);
				if (PC != nullptr && PC.PlayerReplicationInfo.PlayerName ~= PlayerName)
				{
					sPBGUID=Level.GetPBGUID(PC);
				}
				else
				{
					C=C.nextController;
				}
			}
			DebugLog(DEBUG_Auth,"Found PBGUID """ + sPBGUID + """ for player """ + PlayerName + """");
			if (Len(sPBGUID) == 0 && BanOptions ~= "PBGUID")
			{
				PCAdmin.ClientMessage("Unable to locate player via PunkBuster for name """ + PlayerName + """");
				return;
			}
			else
			{
				if (Len(sPBGUID) > 0)
				{
					BanOptions="PBGUID";
				}
			}
		}
		else
		{
			if (BanOptions ~= "IP" || BanOptions ~= "MAC")
			{
				C=Level.ControllerList;
				if (C != nullptr)
				{
					PC=Cast<APlayerController>(C);
					if (PC != nullptr && PC.PlayerReplicationInfo.PlayerName ~= PlayerName)
					{
						if (BanOptions ~= "IP")
						{
							sBanEntry=Left(PC.GetPlayerNetworkAddress(),InStr(PC.GetPlayerNetworkAddress(),":"));
						}
						else
						{
							sBanEntry=PC.PlayerReplicationInfo.PlayerMAC;
						}
					}
					else
					{
						C=C.nextController;
					}
				}
			}
			else
			{
				sBanEntry=PlayerName;
			}
		}
		if (Level.Game.BroadcastHandler.iLogChatLevel >= Level.Game.BroadcastHandler.2)
		{
			Level.Game.BroadcastHandler.WritePRIChatLog(PCAdmin.PlayerReplicationInfo,"Player: """ + PlayerName + """ Duration: """ + time_to_ban_for + """ Options: """ + BanOptions + """",'AdminBan');
		}
		DebugLog(DEBUG_Auth,"Ban player """ + PlayerName + """ for " + time_to_ban_for);
		if (time_suffix ~= "w" || time_suffix ~= "d" || time_suffix ~= "h" || time_suffix ~= "m")
		{
			time_units=Left(time_to_ban_for,Len(time_to_ban_for) - 1);
			strBanTime=time_units;
			if (time_suffix ~= "w")
			{
				weeks=time_units;
				if (weeks > 52)
				{
					weeks=52;
				}
				strBanTime=strBanTime + " week";
			}
			else
			{
				if (time_suffix ~= "d")
				{
					days=time_units;
					if (days > 365)
					{
						days=365;
					}
					strBanTime=strBanTime + " day";
				}
				else
				{
					if (time_suffix ~= "h")
					{
						hours=time_units;
						if (hours > 8760)
						{
							hours=8760;
						}
						strBanTime=strBanTime + " hour";
					}
					else
					{
						if (time_suffix ~= "m")
						{
							minutes=time_units;
							if (minutes > 525600)
							{
								minutes=525600;
							}
							strBanTime=strBanTime + " minute";
						}
					}
				}
			}
			if (time_units > 1)
			{
				strBanTime=strBanTime + "s";
			}
		}
		else
		{
			minutes=time_to_ban_for;
			if (minutes > 525600)
			{
				minutes=525600;
			}
			strBanTime=minutes @ "minutes";
		}
		if (weeks == 0 && days == 0 && hours == 0 && minutes == 0)
		{
			strBanTime="eternity";
		}
		if (BanOptions ~= "PBGUID")
		{
			if (AccessControl.AddPBGUIDBan(sPBGUID,weeks,days,hours,minutes,PlayerName))
			{
				Log("Ban added");
				AccessControl.SaveOldBanList();
				PCAdmin.ClientMessage("Player """ + PlayerName + """ banned via PBGUID.");
			}
			else
			{
				PCAdmin.ClientMessage("Player """ + PlayerName + """ could not be banned via PBGUID due to an unknown error.");
			}
		}
		else
		{
			if (AccessControl.AddBanee(sBanEntry,BanOptions,weeks,days,hours,minutes,PlayerName))
			{
				Log("Ban added");
				AccessControl.SaveOldBanList();
				PCAdmin.ClientMessage("Player """ + PlayerName + """ banned via " + BanOptions + " using value """ + sBanEntry + """.");
			}
			else
			{
				PCAdmin.ClientMessage("Player """ + PlayerName + """ could not be banned via " + BanOptions + " due to an unknown error.");
			}
		}
	*/
}

bool AGameInfo::IsOnTeam(AController* Other, int32 TeamNum)
{
	int32 otherTeam;
	if (bTeamGame && Other != NULL)
	{
		otherTeam=Cast<AHumanController>(Other)->GetTeamNum();
		if (otherTeam == 255)
		{
			return false;
		}
		return otherTeam == TeamNum;
	}
	return false;
}

bool AGameInfo::CanSpectate(APlayerController* Viewer, bool bOnlySpectator, AActor* ViewTarget)
{
	return true;
}

int32 AGameInfo::ReduceDamage(int32 Damage, APawn* injured, APawn* instigatedBy, FVector HitLocation, FVector& Momentum, UaDamageType* DamageType)
{
	int32 OriginalDamage = 0;
	AArmor* FirstArmor = nullptr;
	AArmor* NextArmor = nullptr;
	OriginalDamage = Damage;
	/*
	if (injured.PhysicsVolume.bNeutralZone)
	{
		Damage = 0;
	}
	else
	{
		if (injured.InGodMode())
		{
			return 0;
		}
		else
		{
			if ((injured.Inventory != nullptr) && (Damage > 0))
			{
				FirstArmor = injured.Inventory.PrioritizeArmor(Damage, DamageType, HitLocation);
				if ((FirstArmor != nullptr) && (Damage > 0))
				{
					NextArmor = FirstArmor.NextArmor;
					Damage = FirstArmor.ArmorAbsorbDamage(Damage, DamageType, HitLocation);
					FirstArmor = NextArmor;
				}
			}
		}
	}
	if (GameRulesModifiers != nullptr)
	{
		return GameRulesModifiers.NetDamage(OriginalDamage, Damage, injured, instigatedBy, HitLocation, Momentum, DamageType);
	}
	*/
	return Damage;
}

bool AGameInfo::ShouldRespawn(APickup* Other)
{
	return false;   //FAKE   /ELiZ
}

bool AGameInfo::PickupQuery(APawn* Other, APickup* Item)
{
	return false;   //FAKE   /ELiZ
}

void AGameInfo::DiscardInventory(APawn* Other)
{
	Cast<AAGP_Pawn>(Other)->Weapon =NULL;
	Cast<AAGP_Pawn>(Other)->SelectedItem=NULL;
	if (Cast<AAGP_Pawn>(Other)->Inventory != NULL)
	{
		//Cast<AAGP_Pawn>(Other)->Inventory->Destroy();
	}
}

/*
void AGameInfo::ChangeName(AController* Other, FString S, bool bNameChange)
{
	AController* C = nullptr;
	if (S == "")
	{
		return;
	}
	if (! Level.IsExploreTheArmyServer())
	{
		S=StripColor(S);
	}
	Other.PlayerReplicationInfo.SetPlayerName(S);
	if (bNameChange)
	{
		for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
		{
			if ((Cast<APlayerController>(C) != nullptr) && (Viewport(Cast<APlayerController>(C).Player) != nullptr))
			{
				Cast<APlayerController>(C).ReceiveLocalizedMessage(AGameMessage::StaticClass(),2,Other.PlayerReplicationInfo);
			}
		}
	}
}
*/

bool AGameInfo::ChangeTeam(AController* Other, int32 N, bool bNewTeam)
{
	return true;
}

uint8 AGameInfo::PickTeam(uint8 Current, AController* C)
{
	return Current;
}

void AGameInfo::SendPlayer(APlayerController* aPlayer, FString URL)
{
	aPlayer->ClientTravel(URL,ETravelType::TRAVEL_Relative,true);
}

void AGameInfo::RestartGame()
{
	FString NextMap = "";
	AMapList* MyList = nullptr;
	if ((GameRulesModifiers != nullptr) && GameRulesModifiers->HandleRestartGame())
	{
		return;
	}
	if (bGameRestarted)
	{
		return;
	}
	bGameRestarted = true;
	if ((VotingHandler != nullptr) && (!VotingHandler->HandleRestartGame()))
	{
		return;
	}
	if ((bChangeLevels && (!bAlreadyChanged)) && (MapListType != ""))
	{
		bAlreadyChanged = true;
		MyList = GetMapList(MapListType);
		if (MyList != nullptr)
		{
			NextMap = MyList->GetNextMap();
			MyList->Destroy();
		}
		if (NextMap == "")
		{
			//NextMap = GetMapName(MapPrefix, NextMap, 1);
		}
		if (NextMap != "")
		{
			//Level.ServerTravel(NextMap, false);
			return;
		}
	}
	//Level.ServerTravel("?Restart", false);
}

TArray<FString> AGameInfo::GetMapRotation()
{
	if (MaplistHandler != nullptr)
	{
		return MaplistHandler->GetCurrentMapRotation();
	}
	return {};    //FAKE   /EliZ
}

AMapList* AGameInfo::GetMapList(FString MapListClassType)
{
	AMapList* MapListClass = nullptr;
	if (MapListClassType != "")
	{
		/*
		MapListClass = class<MapList>(DynamicLoadObject(MapListClassType, Class'Class'));
		if (MapListClass != nullptr)
		{
			return Spawn(MapListClass);
		}
		*/
	}
	return nullptr;
}

void AGameInfo::ChangeVoiceChannel(AAA2_PlayerState*  PRI, int32 NewChannelIndex, int32 OldChannelIndex)
{
}
void AGameInfo::Broadcast(AActor* Sender, FString Msg, FName Type)
{
	APlayerController* PC = nullptr;
	int32 i = 0;
	bool IsMuted = false;
	PC = Cast<APlayerController>(Sender);
	/*
	if (PC != nullptr && PC.PlayerReplicationInfo != nullptr)
	{
		IsMuted=false;
		i=0;
		if (i < MutedPlayers.Num())
		{
			if (MutedPlayers[i] ~= PC.PlayerReplicationInfo.PlayerName)
			{
				Log("GameInfo::AllowsBroadcast					(player is muted.)");
				IsMuted=true;
			}
			else
			{
				i ++;
			}
		}
		if (IsMuted)
		{
			return;
		}
	}
	BroadcastHandler.Broadcast(Sender,Msg,Type);
	*/
}
void AGameInfo::BroadcastTeam(AController* Sender, FString Msg, FName Type)
{
	BroadcastHandler->BroadcastTeam(Sender,Msg,Type);
}

void AGameInfo::BroadcastLocalized(AActor* Sender, AaLocalMessage* Message, int32 Switch, AAA2_PlayerState*  RelatedPRI_1, AAA2_PlayerState*  RelatedPRI_2, UObject* OptionalObject)
{
	//BroadcastHandler->AllowBroadcastLocalized(Sender,Message,Switch,RelatedPRI_1,RelatedPRI_2,OptionalObject);
}

bool AGameInfo::CheckEndGame(AAA2_PlayerState*  Winner, FString Reason)
{

	AController* p = nullptr;
	if ((GameRulesModifiers != nullptr) && (!GameRulesModifiers->CheckEndGame(Winner, Reason)))
	{
		return false;
	}
	/*
	for (p = Level.ControllerList; p != nullptr; p = p.nextController)
	{
		p.ClientGameEnded();
		p.GameHasEnded();
	}
	*/
	return true;
}

void AGameInfo::EndGame(AAA2_PlayerState*  Winner, FString Reason)
{
	if (! CheckEndGame(Winner,Reason))
	{
		bOverTime=true;
		return;
	}
	bGameEnded=true;
	//TriggerEvent('EndGame',Self,None);
	EndLogging(Reason);
}

void AGameInfo::EndLogging(FString Reason)
{
	if (GameStats == nullptr)
	{
		return;
	}
	GameStats->EndGame(Reason);
	GameStats->Destroy();
	GameStats=nullptr;
}

ANavigationPoint* AGameInfo::FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName)
{
	ANavigationPoint* N = nullptr;
	ANavigationPoint* BestStart = nullptr;
	ATeleporter* Tel = nullptr;
	float BestRating = 0;
	float NewRating = 0;
	uint8 Team = 0;
	/*
	DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - Trying to find player start");
	if ((((Player != nullptr) && (Player.StartSpot != nullptr)) && (GetWorld()->GetNetMode() == NM_Standalone)) && (bWaitingToStartMatch || ((Player.PlayerReplicationInfo != nullptr) && Player.PlayerReplicationInfo.bWaitingPlayer)))
	{
		DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - Using player's old start: " + FString::FromInt(Player.StartSpot));
		return Player.StartSpot;
	}
	if (GameRulesModifiers != nullptr)
	{
		N = GameRulesModifiers.FindPlayerStart(Player, InTeam, incomingName);
		if (N != nullptr)
		{
			DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - using player start based on game rules: " + FString::FromInt(N));
			return N;
		}
	}
	if (incomingName != "")
	{
		ForEach AllActors(ATeleporter::StaticClass(), Tel)
		{
			if (string(Tel.Tag) ~= incomingName)
			{
				return Tel;
			}
		}
	}
	if ((Player != nullptr) && (Player.PlayerReplicationInfo != nullptr))
	{
		if (Player.PlayerReplicationInfo.Team != nullptr)
		{
			Team = uint8(Player.PlayerReplicationInfo.Team.TeamIndex);
		}
		else
		{
			Team = InTeam;
		}
	}
	else
	{
		Team = InTeam;
	}
	for (N = Level.NavigationPointList; N != nullptr; N = N.nextNavigationPoint)
	{
		if (!N->IsA(APlayerStart::StaticClass()))
		{
		}
		DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - Rating player start " + FString::FromInt(N));
		NewRating = RatePlayerStart(N, Team, Player);
		DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - Rating for " + FString::FromInt(N) + " is " + FString::FromInt(NewRating) + " (best: " + FString::FromInt(BestRating) + ")");
		if (NewRating > BestRating)
		{
			BestRating = NewRating;
			BestStart = N;
		}
	}
	if ((BestStart == nullptr) || (((Cast<APlayerStart>(BestStart) == nullptr) && (Player != nullptr)) && Player.bIsPlayer))
	{
		Log("Warning - PATHS NOT DEFINED or NO PLAYERSTART with positive rating");
		BestRating = -100000000;
		ForEach AllActors(ANavigationPoint::StaticClass(), N)
		{
			NewRating = RatePlayerStart(N, 0, Player);
			if (Cast<AInventorySpot>(N) != nullptr)
			{
				NewRating -= float(50);
			}
			NewRating += (float(20) * FRand());
			if (NewRating > BestRating)
			{
				BestRating = NewRating;
				BestStart = N;
			}
		}
	}
	DebugLog(DEBUG_PlayerSpawn, FString::FromInt(this) + ".FindPlayerStart() - Using player's beststart: " + FString::FromInt(BestStart));
	*/
	return BestStart;
}

float AGameInfo::RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player)
{
	APlayerStart* p = nullptr;
	p = Cast<APlayerStart>(N);
	/*
	if (p != nullptr)
	{
		if (p->bSinglePlayerStart)
		{
			if (p->bEnabled)
			{
				return 1000;
			}
			return 20;
		}
		return 10;
	}
	*/
	return 0;
}

void AGameInfo::ScoreObjective(AAA2_PlayerState*  Scorer, float Score)
{
}
void AGameInfo::CheckScore(AAA2_PlayerState*  Scorer)
{
	if (GameRulesModifiers != nullptr && GameRulesModifiers->CheckScore(Scorer))
	{
		return;
	}
}
void AGameInfo::ScoreEvent(AAA2_PlayerState*  Who, float Points, FString Desc)
{
	if (GameStats != nullptr)
	{
		GameStats->ScoreEvent(Who,Points,Desc);
	}
}
void AGameInfo::TeamScoreEvent(int32 Team, float Points, FString Desc)
{
	if (GameStats != nullptr)
	{
		GameStats->TeamScoreEvent(Team,Points,Desc);
	}
}
void AGameInfo::ScoreKill(AController* Killer, AController* Other, UaDamageType*  DamageType)
{
	if (GameRulesModifiers != nullptr)
	{
		GameRulesModifiers->ScoreKill(Killer, Other, DamageType);
	}
	if ((Killer != nullptr) || (MaxLives > 0))
	{
		//CheckScore(Killer->PlayerReplicationInfo);
	}

}
bool AGameInfo::TooManyBots(AController* botToRemove)
{
	return false;
}

UMaterialInstance* AGameInfo::GetRandomTeamSymbol(int32 Base)
{
	return nullptr;
}

FString AGameInfo::FindTeamDesignation(AAA2_GameState* GRI, AActor* A)
{
	return "";
}

FString AGameInfo::ParseChatPercVar(AMutator* aBaseMutator, AController* Who, FString Cmd)
{
	if (aBaseMutator != nullptr)
	{
		Cmd=aBaseMutator->ParseChatPercVar(Who,Cmd);
	}
	if (Who != nullptr)
	{
		//Cmd=Who->ParseChatPercVar(Cmd);
	}
	return Cmd;
}

FString AGameInfo::ParseMessageString(AMutator* aBaseMutator, AController* Who, FString Message)
{
	return Message;
}

void AGameInfo::FillPlayInfo(APlayInfo* PlayInfo)
{
	/*
		Super::FillPlayInfo(PlayInfo);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->BotsGroup,"GameDifficulty",GetDisplayText("GameDifficulty"),0,2,"Select",GetDefault<AGameInfo>()->GIPropsExtras[0],"Xb");
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->GameGroup,"GoalScore",GetDisplayText("GoalScore"),0,0,"Text","3;0:999");
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->GameGroup,"TimeLimit",GetDisplayText("TimeLimit"),0,0,"Text","3;0:999");
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->GameGroup,"MaxLives",GetDisplayText("MaxLives"),0,0,"Text","3;0:999");
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->GameGroup,"bWeaponStay",GetDisplayText("bWeaponStay"),1,0,"Check",,,,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->RulesGroup,"bAllowWeaponThrowing",GetDisplayText("bAllowWeaponThrowing"),1,0,"Check",,,,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->RulesGroup,"bAllowBehindView",GetDisplayText("bAllowBehindview"),1,0,"Check",,,True,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->RulesGroup,"bWeaponShouldViewShake",GetDisplayText("bWeaponShouldViewShake"),1,0,"Check",,,,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->ServerGroup,"bEnableStatLogging",GetDisplayText("bEnableStatLogging"),0,1,"Check",,,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->ServerGroup,"bAdminCanPause",GetDisplayText("bAdminCanPause"),1,1,"Check",,,True,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->ServerGroup,"MaxSpectators",GetDisplayText("MaxSpectators"),1,1,"Text","3;0:32",,True,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->ServerGroup,"MaxPlayers",GetDisplayText("MaxPlayers"),0,1,"Text","3;0:32",,true);
		PlayInfo.AddSetting(GetDefault<AGameInfo>()->ServerGroup,"MaxIdleTime",GetDisplayText("MaxIdleTime"),0,1,"Text","3;0:300",,True,true);
		if (GetDefault<AGameInfo>()->GameReplicationInfoClass != nullptr)
		{
			GetDefault<AGameInfo>()->GameReplicationInfoClass.FillPlayInfo(PlayInfo);
			PlayInfo.PopClass();
		}
		if (GetDefault<AGameInfo>()->VoiceReplicationInfoClass != nullptr)
		{
			GetDefault<AGameInfo>()->VoiceReplicationInfoClass.FillPlayInfo(PlayInfo);
			PlayInfo.PopClass();
		}
		if (GetDefault<AGameInfo>()->BroadcastClass != nullptr)
		{
			GetDefault<AGameInfo>()->BroadcastClass.FillPlayInfo(PlayInfo);
		}
		else
		{
			'BroadcastHandler'.FillPlayInfo(PlayInfo);
		}
		PlayInfo.PopClass();
		if ('GameInfo'.GetDefault<AGameInfo>()->VotingHandlerClass != nullptr)
		{
			'GameInfo'.GetDefault<AGameInfo>()->VotingHandlerClass.FillPlayInfo(PlayInfo);
			PlayInfo.PopClass();
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("GameInfo::FillPlayInfo AGameInfo::StaticClass().GetDefault<AGameInfo>()->VotingHandlerClass = nullptr"));
		}
	*/
}

FString AGameInfo::GetDisplayText(FString PropName)
{
	if (PropName == "GameDifficulty")
	{
		return GIPropsDisplayText[0];	
	}
	if (PropName == "bWeaponStay")	
	{		
		return GIPropsDisplayText[1];	
	}
	if (PropName == "MaxSpectators")
	{
		return GIPropsDisplayText[4];
	}
	if (PropName == "MaxPlayers")
	{
		return GIPropsDisplayText[5];
	}
	if (PropName == "GoalScore")
	{
		return GIPropsDisplayText[6];
	}
	if (PropName == "MaxLives")
	{
		return GIPropsDisplayText[7];
	}
	if (PropName == "TimeLimit")
	{
		return GIPropsDisplayText[8];
	}
	if (PropName == "bEnableStatLogging")
	{
		return GIPropsDisplayText[9];
	}
	if (PropName == "bAllowWeaponThrowing")
	{
		return GIPropsDisplayText[10];
	}
	if (PropName == "bAllowBehindview")
	{
		return GIPropsDisplayText[11];
	}
	if (PropName == "bAdminCanPause")
	{
		return GIPropsDisplayText[12];
	}
	if (PropName == "MaxIdleTime")
	{
		return GIPropsDisplayText[13];
	}
	if (PropName == "bWeaponShouldViewShake")
	{
		return GIPropsDisplayText[14];
	}
	return "";

}
FString AGameInfo::GetDescriptionText(FString PropName)
{
	if (PropName == "GameDifficulty")
	{
		return GIPropDescText[0];
	}
	if (PropName == "bWeaponStay")
	{
		return GIPropDescText[1];
	}
	if (PropName == "MaxSpectators")
	{
		return GIPropDescText[4];
	}
	if (PropName == "MaxPlayers")
	{
		return GIPropDescText[5];
	}
	if (PropName == "GoalScore")
	{
		return GIPropDescText[6];
	}
	if (PropName == "MaxLives")
	{
		return GIPropDescText[7];
	}
	if (PropName == "TimeLimit")
	{
		return GIPropDescText[8];
	}
	if (PropName == "bEnableStatLogging")
	{
		return GIPropDescText[9];
	}
	if (PropName == "bAllowWeaponThrowing")
	{
		return GIPropDescText[10];
	}
	if (PropName == "bAllowBehindview")
	{
		return GIPropDescText[11];
	}
	if (PropName == "bAdminCanPause")
	{
		return GIPropDescText[12];
	}
	if (PropName == "MaxIdleTime")
	{
		return GIPropDescText[13];
	}
	if (PropName == "bWeaponShouldViewShake")
	{
		return GIPropDescText[14];
	}
	return GetDescriptionText(PropName);
}
bool AGameInfo::AcceptPlayInfoProperty(FString PropName)
{
	if (PropName == "MaxLives")
	{
		return false;
	}
	//return Super::AcceptPlayInfoProperty(PropName);
	return true;   //FAKE /ELiZ
}

int32 AGameInfo::OrderToIndex(int32 Order)
{
	return Order;
}

void AGameInfo::ReviewJumpSpots(FName TestLabel)
{
}

FString AGameInfo::RecommendCombo(FString ComboName)
{
	return ComboName;
}

FString AGameInfo::NewRecommendCombo(FString ComboName, AaAIController* C)
{
	FString NewComboName = "";
	
	NewComboName = RecommendCombo(ComboName);
	if (NewComboName != ComboName)
	{
		return NewComboName;
	}
	return BaseMutator->NewRecommendCombo(ComboName, C);
}

bool AGameInfo::CanEnterVehicle(AVehicle* V, APawn* p)
{
	return BaseMutator->CanEnterVehicle(V,p);
}

void AGameInfo::DriverEnteredVehicle(AVehicle* V, APawn* p)
{
	BaseMutator->DriverEnteredVehicle(V,p);
}


bool AGameInfo::CanLeaveVehicle(AVehicle* V, APawn* p)
{
	return BaseMutator->CanLeaveVehicle(V,p);
}

void AGameInfo::DriverLeftVehicle(AVehicle* V, APawn* p)
{
	BaseMutator->DriverLeftVehicle(V,p);
}

ATeamInfo* AGameInfo::otherTeam(ATeamInfo* Requester)
{
	return nullptr;
}

void AGameInfo::KillBots(int32 Num)
{
}

void AGameInfo::AdminSay(FString Msg)
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (C->IsA(APlayerController::StaticClass()))
		{
			Cast<APlayerController>(C).ClearProgressMessages();
			Cast<APlayerController>(C).SetProgressTime(6);
			Cast<APlayerController>(C).SetProgressMessage(0, Msg, Class'Canvas'.MakeColor(255, 255, 255));
		}
	}
	*/
}

void AGameInfo::RegisterVehicle(AVehicle* V)
{
	V->NextVehicle=VehicleList;
	VehicleList=V;
}

AActor* AGameInfo::FindSpecGoalFor(AAA2_PlayerState*  PRI, int32 TeamIndex)
{
	return nullptr;
}

int32 AGameInfo::GetDefenderNum()
{
	return 255;
}

void AGameInfo::SetGrammar()
{
	if (BeaconName != "")
	{
		LoadSRGrammar(BeaconName);
	}
}

void AGameInfo::LoadSRGrammar(FString Grammar)
{
}

void AGameInfo::GetPlayerControllerList(TArray<APlayerController*>& ControllerArray)
{
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	/*
	if (ControllerArray.Num() > 0)
	{
		ControllerArray.RemoveAt(0, ControllerArray.Num());
	}
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		PC = Cast<APlayerController>(C);
		if ((((((PC != nullptr) && PC.bIsPlayer) && (PC.PlayerReplicationInfo != nullptr)) && (!PC.PlayerReplicationInfo.bOnlySpectator)) && (!PC.PlayerReplicationInfo.bBot)) && (PC.Player != nullptr))
		{
			ControllerArray[ControllerArray.Num()] = PC;
		}
	}
	*/
}

void AGameInfo::ParseVoiceCommand(APlayerController* Sender, FString RecognizedString)
{
}

void AGameInfo::AdjustBotInterface(bool bSinglePlayer)
{
}

void AGameInfo::SceneStarted(ASceneManager* SM, AActor* Other)
{
}

void AGameInfo::SceneEnded(ASceneManager* SM, AActor* Other)
{
}

void AGameInfo::SceneAbort()
{
}

void AGameInfo::NoTranslocatorKeyPressed(APlayerController* PC)
{
}

TArray<FString> AGameInfo::GetAllLoadHints(bool bThisClassOnly)
{
	return {};    //FAKE    /ELiZ
}

FString AGameInfo::GetLoadingHint(APlayerController* Ref, FString MapName, FColor HintColor)
{
	FString Hint;
	int32 Attempt=0;
	if (Ref == nullptr)
	{
		return "";
	}
	while (Hint == "" && ++Attempt < 10)
	{
		Hint = ParseLoadingHint(GetNextLoadHint(MapName), Ref, HintColor);
	}
	return Hint;
}

FString AGameInfo::ParseLoadingHint(FString Hint, APlayerController* Ref, FColor HintColor)
{
	FString CurrentHint="";
	FString Cmd;
	FString Result;
	int32 pos;

	pos = pos = Hint.Find(TEXT("%"));
	if (pos == -1)
	{
		return Hint;
	}
	do
	{
		Cmd = "";
		Result = "";

		CurrentHint += Hint.Left(pos);
		Hint = Hint.Mid(pos + 1);

		pos = Hint.Find(TEXT("%"));
		if (pos == -1)
		{
			break;
		}
		Cmd = Hint.Left(pos);
		Hint = Hint.Mid(pos + 1);
		Result = GetKeyBindName(Cmd, Ref);
		if (Result == Cmd || Result == "")
		{
			break;
		}

		CurrentHint.Append(MakeColorCode(GetDefault<AGameInfo>()->BindColor));
		CurrentHint.Append(Result);
		CurrentHint.Append(MakeColorCode(HintColor));

		pos = Hint.Find(TEXT("%"));
	} while(Hint != "" && pos == -1);

	if (Result != "" && Result != Cmd)
	{
		return CurrentHint + Hint;
	}

	return "";
}
FString AGameInfo::GetKeyBindName(FString Cmd, APlayerController* Ref)
{
	FString BindStr = "";
	TArray<FString> Bindings = {};
	int32 i = 0;
	int32 idx = 0;
	int32 BestIdx = 0;
	int32 Weight = 0;
	int32 BestWeight = 0;
	/*
	if (Ref == nullptr || Cmd == "")
	{
		return Cmd;
	}
	BestIdx=-1;
	BindStr=Ref.ConsoleCommand("BINDINGTOKEY" @ """" + Cmd + """");
	if (BindStr != "")
	{
		Split(BindStr,",",Bindings);
		if (Bindings.Num() > 0)
		{
			for (i=0; i<Bindings.Num(); i++)
			{
				idx=Ref.ConsoleCommand("KEYNUMBER" @ Bindings[i]);
				if (idx != -1)
				{
					Weight=GetBindWeight(idx);
					if (Weight > BestWeight)
					{
						BestWeight=Weight;
						BestIdx=idx;
					}
				}
			}
			if (BestIdx != -1)
			{
				return Ref.ConsoleCommand("LOCALIZEDKEYNAME" @ BestIdx);
			}
		}
	}
	*/
	return Cmd;
}

FString AGameInfo::GetNextLoadHint(FString MapName)
{
	return "";
}

FString AGameInfo::MakeColorCode(FColor NewColor)
{
	FString OutColor="";
	if (NewColor.R == 0)
	{
		NewColor.R=1;
	}
	if (NewColor.G == 0)
	{
		NewColor.G=1;
	}
	if (NewColor.B == 0)
	{
		NewColor.B=1;
	}

	OutColor.AppendChar(TCHAR(27));
	OutColor.AppendChar(TCHAR(NewColor.R));
	OutColor.AppendChar(TCHAR(NewColor.G));
	OutColor.AppendChar(TCHAR(NewColor.B));
	return OutColor;
}

int32 AGameInfo::GetBindWeight(uint8 KeyNumber)
{
	if (KeyNumber == 1 || KeyNumber == 2)
	{
		return 100;
	}
	if (KeyNumber >= 48 && KeyNumber <= 90)
	{
		return 75;
	}
	if (KeyNumber == 32 || KeyNumber >= 16 && KeyNumber <= 18)
	{
		return 50;
	}
	if (KeyNumber >= 37 && KeyNumber <= 40)
	{
		return 45;
	}
	if (KeyNumber == 4)
	{
		return 40;
	}
	if (KeyNumber == 236 || KeyNumber == 237)
	{
		return 35;
	}
	if (KeyNumber == 8 || KeyNumber >= 33 && KeyNumber <= 40)
	{
		return 30;
	}
	if (KeyNumber >= 96 && KeyNumber <= 111)
	{
		return 25;
	}
	return 20;
}

bool AGameInfo::IsVehicleMutator(FString MutatorClassName)
{
	if (MutatorClassName == "Onslaught.MutBigWheels")
	{
		return true;
	}
	if (MutatorClassName == "Onslaught.MutWheeledVehicleStunts")
	{
		return true;
	}
	if (MutatorClassName == "Onslaught.MutLightweightVehicles")
	{
		return true;
	}
	if (MutatorClassName == "OnslaughtFull.MutVehicleArena")
	{
		return true;
	}
	return false;
}

bool AGameInfo::AllowMutator(FString MutatorClassName)
{
	if (MutatorClassName == GetDefault<AGameInfo>()->MutatorClass)
	{
		return true;
	}
	if (!GetDefault<AGameInfo>()->bAllowVehicles && IsVehicleMutator(MutatorClassName))
	{
		return false;
	}
	//return !GetDefault<AGameInfo>()->IsDemoBuild();
	return false;
}

void AGameInfo::AddServerDetail(FServerResponseLine& ServerState, FString RuleName, FString RuleValue)
{
	FKeyValuePair NewRule;
	NewRule.Key = RuleName;
	NewRule.Value = RuleValue;
	ServerState.ServerInfo.Add(NewRule);
}
FString AGameInfo::StripColor(FString S)
{
	int32 p;
	S.FindChar(TCHAR(27), p);		//	p = InStr(S, chr(27));
	while (p >= 0)
	{
		S.RemoveAt(p, 4);			//	S = left(S, p)$mid(S, p + 4);
		S.FindChar(TCHAR(27), p);	//p = InStr(S, Chr(27));
	}
	return S;
}
bool AGameInfo::JustStarted(float t)
{
	return GetWorld()->GetTimeSeconds() < t;
}
int32 AGameInfo::MultiMinPlayers()
{
	return 0;
}
void AGameInfo::WeakObjectives()
{
}
void AGameInfo::DisableNextObjective()
{
}
void AGameInfo::DeadUse(APlayerController* PC)
{
}
void AGameInfo::ResetDecoMeshes()
{
	UWorld* World = GetWorld();
	for (TActorIterator<ADecoMesh> It(World, ADecoMesh::StaticClass()); It; ++It)
	{
		ADecoMesh* D = *It;
		D->Reset();
	}
}
void AGameInfo::ToggleMutedPlayer(FString PlayerName)
{
	/*
		int32 i = 0;
		DebugLog(DEBUG_Multi,"Updating mute list...");
		for (i=0; i<MutedPlayers.Num(); i++)
		{
			if (MutedPlayers[i] ~= PlayerName)
			{
				DebugLog(DEBUG_Multi,"Existing name found.removing...");
				MutedPlayers->Remove(i,1);
				return;
			}
		}
		DebugLog(DEBUG_Multi,"No match found. Adding player to Mute list.");
		MutedPlayers[MutedPlayers.Num()]=PlayerName;
		DebugLog(DEBUG_Multi,"Mute List now reads as follows:");
		for (i=0; i<MutedPlayers.Num(); i++)
		{
			DebugLog(DEBUG_Multi,MutedPlayers[i]);
		}
		DebugLog(DEBUG_Multi,"Done!");
	*/
}
bool AGameInfo::SetScoreMode(FString NewScoreMode)
{
	if (NewScoreMode == "1" || NewScoreMode == "on")
	{
		ScoreMode=EServerScoreMode::SSM_On;
	}
	else
	{
		if (NewScoreMode == "0" || NewScoreMode == "off")
		{
			ScoreMode= EServerScoreMode::SSM_Off;
		}
		else
		{
			if (NewScoreMode == "round")
			{
				ScoreMode = EServerScoreMode::SSM_Round;
			}
			else
			{
				if (NewScoreMode == "match")
				{
					ScoreMode = EServerScoreMode::SSM_Match;
				}
				else
				{
					return false;
				}
			}
		}
	}
	UpdateAllClientsScoreMode();
	return true;
}

void AGameInfo::UpdateAllClientsScoreMode()
{
	AController* C = nullptr;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (!C->IsA(AaAIController::StaticClass()))
		{
			UpdateClientScoreMode(C);
		}
	}
	*/
}

void AGameInfo::UpdateClientScoreMode(AController* C)
{
	bool bAllowScores;
	bAllowScores=(ScoreMode == EServerScoreMode::SSM_On);
	if (C != nullptr && C->IsA(AHumanController::StaticClass()))
	{
		Cast<AHumanController>(C)->ClientSetScoreMode(bAllowScores);
	}
}

bool AGameInfo::PauseGame(bool bPause, APlayerController* p)
{
	if (bPause)
	{
		Cast<AAA2_WorldSettings>(GetWorldSettings())->SetPauserPlayerState(Cast<AHumanController>(p)->PlayerReplicationInfo);
		
	}
	else
	{
		Cast<AAA2_WorldSettings>(GetWorldSettings())->SetPauserPlayerState(nullptr);
	}
	return true;
}

void AGameInfo::SetLogTarget(AInternetInfo* iinfo)
{
	if (BroadcastHandler != nullptr)
	{
		BroadcastHandler->SetLogTarget(iinfo);
	}
}

void AGameInfo::ReadServerSettings()
{
	int32 i = 0;
		
	if (GetNetMode() != ENetMode::NM_DedicatedServer && GetNetMode() != ENetMode::NM_ListenServer)
	{
		return;
	}
	for (i = 0; i < ServerSetting.Max(); i++)
	{
		if (ServerSetting[i] == "AccessControl.AdminPassword")
		{
			UE_LOG(LogTemp, Log, TEXT("Removed AdminPassword from command post options."));
			ServerSetting.RemoveAt(i);
		}
		else
		{
			i ++;
		}
	}
	for (i=0; i<ServerSetting.Max(); i++)
	{
		FString Left, Right;
		ServerSetting[i].Split(TEXT("."), &Left, &Right);
		Section[i] = Left;
		Setting[i] = Right;
	}
}

bool AGameInfo::NeedPassword()
{
	return AccessControl->RequiresPassword();
}
