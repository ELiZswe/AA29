// All the original content belonged to the US Army

#include "AA29/Object/Actor/DBMBS/DBMBS.h"
#include "AA29/AA2_WorldSettings.h"
#include "AA29/AA2_GameMode.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSUpdateServerStateRequestAdapter/MBSUpdateServerStateRequestAdapt.h"
#include "AA29/Object/Actor/Info/GameInfo/GameInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSServerLoginRequestAdapter/MBSServerLoginRequestAdapter.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/MBSPingMBSServerRequestAdapter/MBSPingMBSServerRequestAdapter.h"

ADBMBS::ADBMBS()
{
	PrimaryActorTick.bCanEverTick = true;
	QueryPort = 20025;
	PingTimeToMBSServer = 9999;
	//bHidden = true;
}

void ADBMBS::BeginPlay()
{
	Super::BeginPlay();
	
}

//void ADBMBS::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//}

//native Function InitMBS();
bool ADBMBS::InitMBS()
{
	return false;    //FAKE  /ELiZ
}

//native Function DeinitMBS();
void ADBMBS::DeinitMBS()
{

}
//native Function UpdateServerDescription();
void ADBMBS::UpdateServerDescription()
{

}
//native Function UpdateMBSGameLoopTickCalculator();
void ADBMBS::UpdateMBSGameLoopTickCalculator()
{

}

//native Function GetOperatingSystem();
FString ADBMBS::GetOperatingSystem()
{
	return "FALSE";    //FAKE   /ELiZ
}

int32 ADBMBS::GetServerPort()
{
	//return Level.Game.GetServerPort();
	return 0;    //FAKE  /ELiZ
}

int32 ADBMBS::GetMaxPlayers()
{
	//return Level.Game.MaxPlayers + Level.Game.MaxSpectators;
	return 0;    //FAKE  /ELiZ
}

int32 ADBMBS::GetNumPlayers()
{
	//return Level.Game.NumPlayers + Level.Game.NumSpectators;
	return 0;    //FAKE  /ELiZ
}

void ADBMBS::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UpdateMBSGameLoopTickCalculator();
}
void ADBMBS::HandleLegacyQueryPort()
{
	/*
	int32 LegacyQueryPort;
	if (QueryPort == 20025 && -1 == GetPrivateProfileInt("System", "DBAuth.DBMBS", "QueryPort"))
	{
		LegacyQueryPort = GetPrivateProfileInt("System", "Andromeda.AndromedaMBS", "QueryPort");
		if (LegacyQueryPort != -1)
		{
			QueryPort = LegacyQueryPort;
		}
	}
	*/
}
void ADBMBS::PostBeginPlay()
{
	/*
	ServerIP = 'AuthorizeServerRequestAdapter'.GetServerAuthIP();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLanOnlyServer())
	{
		Log("Lan server. Not initializing DBMBS.");
		Destroy();
		return;
	}
	HandleLegacyQueryPort();
	if (InitMBS())
	{
		SetTimer(1, true);
	}
	else
	{
		Log("Failed to initialize DBMBS.");
	}
	*/
}

void ADBMBS::Login()
{
	AMBSServerLoginRequestAdapter* Adapter = nullptr;
	/*
	Adapter = Spawn('MBSServerLoginRequestAdapter', this);
	Adapter.Request('AuthorizeServerRequestAdapter'.GetServerAuthUsername(), 'AuthorizeServerRequestAdapter'.GetServerAuthPassword(), 'AuthorizeServerRequestAdapter'.GetServerAuthIP(), GetServerPort(), QueryPort, GetMaxPlayers());
	*/
}
void ADBMBS::Destroyed()
{
	DeinitMBS();
}
void ADBMBS::Timer()
{
	UpdateServerDescription();
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsAuthorizedServer() && !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer() && !Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		return;
	}
	if (!bLoggedIn)
	{
		Login();
		PingMBSServer();
		bLoggedIn = true;
		return;
	}
	++TimesTimerOccured;
	if (TimesTimerOccured > 60)
	{
		SendStateToMBS();
		PingMBSServer();
		TimesTimerOccured = 0;
	}
}
void ADBMBS::GetPlayerAttributes(TArray<FKeyValuePair> &Attributes, APlayerController* C)
{
	Attributes.SetNum(0);
	//C->AddMBSAttributes(Attributes);
}
void ADBMBS::AddPlayers(AMBSUpdateServerStateRequestAdapt* Adapter)
{
	AController* C = nullptr;
	int32 PortPos = 0;
	FString IPAddress = "";
	TArray<FKeyValuePair> PlayerAttributes ={};
	/*
	for (C=Level.ControllerList; C!=nullptr; C=C.nextController)
	{
		if (((nullptr != Cast<APlayerController>(C)) && (nullptr != C.PlayerReplicationInfo)) && ((! Level.Game.IsRequireAuthorization()) || PlayerController(C).bInitialAuthComplete))
		{
			IPAddress=Cast<APlayerController>(C).GetPlayerNetworkAddress();
			PortPos=InStr(IPAddress,":");
			GetPlayerAttributes(PlayerAttributes,PlayerController(C));
			Adapter.AddPlayer(Cast<APlayerController>(C).GetAuthUserName(),Left(IPAddress,PortPos),C.PlayerReplicationInfo.Ping,PlayerAttributes);
		}
	}
	*/
}

void ADBMBS::AddAttribute(TArray<FKeyValuePair> &Attributes, FString Key, FString Value)
{
	FKeyValuePair tmpAttribute;
	tmpAttribute.Key = Key;
	tmpAttribute.Value = Value;
	Attributes.Add(tmpAttribute);
}
FString ADBMBS::EscapeColorCodes(FString S)
{
	//return Class'Object'.Base64Encode(S);
	return "";   //FAKE /ELiZ
}
FString ADBMBS::UnescapeColorCodes(FString S)
{
	//return Class'Object'.Base64Decode(S);
	return "";   //FAKE /ELiZ
}
void ADBMBS::GetServerAttributes(TArray<FKeyValuePair> &ServerAttributes)
{
	/*
	FString sServerName;
	FString sServerDisplayName;
	AddAttribute(ServerAttributes, "gameName", "armygame");
	if (Level.Game.GameReplicationInfo.bAllowForceclassing)
	{
		sServerName = "(FC) " + AGameInfo::StaticClass().StripColor(Level.Game.GameReplicationInfo.ServerName);
		sServerDisplayName = EscapeColorCodes("(FC) " + Level.Game.GameReplicationInfo.ServerName);
		AddAttribute(ServerAttributes, "forceclassing", "Y");
		DebugLog(DEBUG_Auth, "Server name adjusted to encoded """ + sServerDisplayName + """ from ""(FC) " + Level.Game.GameReplicationInfo.ServerName + """");
	}
	else
	{
		sServerName = AGameInfo::StaticClass().StripColor(Level.Game.GameReplicationInfo.ServerName);
		sServerDisplayName = Level.Game.GameReplicationInfo.ServerName;
		if (Left(sServerDisplayName, 4) ~= "(FC)")
		{
			sServerDisplayName = Mid(sServerDisplayName, 4);
			Log("MBS overriding server display name to remove invalid forceclass prefix");
		}
		sServerDisplayName = EscapeColorCodes(sServerDisplayName);
		if (Left(sServerName, 4) ~= "(FC)")
		{
			sServerName = Mid(sServerName, 4);
			Log("MBS overriding server name to remove invalid forceclass prefix");
		}
		AddAttribute(ServerAttributes, "forceclassing", "N");
	}
	*/
	//AddAttribute(ServerAttributes, "serverName", sServerName);
	//AddAttribute(ServerAttributes, "serverNameDisplay", sServerDisplayName);
	//AddAttribute(ServerAttributes, "requiresPassword", BoolToIntString(Level.Game.NeedPassword()));
	//AddAttribute(ServerAttributes, "tour", Cast<AAA2_WorldSettings>(GetWorldSettings())->iTour);
	//AddAttribute(ServerAttributes, "mission", Cast<AAA2_WorldSettings>(GetWorldSettings())->iMission);
	AddAttribute(ServerAttributes, "tourCategory", Cast<AAA2_WorldSettings>(GetWorldSettings())->TourCategory);
	//AddAttribute(ServerAttributes, "punkbuster", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->PBIsEnabled()));
	AddAttribute(ServerAttributes, "mapName", Cast<AAA2_WorldSettings>(GetWorldSettings())->Title);
	//AddAttribute(ServerAttributes, "gameType", GetItemName(Level.Game.Class));
	AddAttribute(ServerAttributes, "official", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()));
	AddAttribute(ServerAttributes, "leased", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer()));
	AddAttribute(ServerAttributes, "miles", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsMILES()));
	//AddAttribute(ServerAttributes, "cheats", BoolToIntString(!Level.Game.CheatsDisabled()));
	//AddAttribute(ServerAttributes, "minHonor", Cast<AAA2_GameMode>(GetGameMode())->GetMinHonor());
	//AddAttribute(ServerAttributes, "maxHonor", Cast<AAA2_GameMode>(GetGameMode())->GetMaxHonor());
	//AddAttribute(ServerAttributes, "groups", Cast<AAA2_GameMode>(GetGameMode())->GetLegalGroupsString());
	//AddAttribute(ServerAttributes, "roundsPerMatch", Level.Game.GameReplicationInfo.RoundsPerMatch);
	//AddAttribute(ServerAttributes, "currentRound", Level.Game.GameReplicationInfo.RoundsPerMatch - Level.Game.GameReplicationInfo.RemainingRounds);
	//AddAttribute(ServerAttributes, "missionTimeRemaining", Level.Game.GameReplicationInfo.RemainingTime);
	AddAttribute(ServerAttributes, "tournament", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()));
	//AddAttribute(ServerAttributes, "adminName", Level.Game.GameReplicationInfo.AdminName);
	//AddAttribute(ServerAttributes, "adminEmail", Level.Game.GameReplicationInfo.AdminEmail);
	//AddAttribute(ServerAttributes, "maxSpectators", Level.Game.MaxSpectators);
	//AddAttribute(ServerAttributes, "numSpectators", Level.Game.NumSpectators);
	AddAttribute(ServerAttributes, "exploreTheArmy", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->IsExploreTheArmyServer()));
	//AddAttribute(ServerAttributes, "operatingSystem", GetOperatingSystem());
	AddAttribute(ServerAttributes, "coop", BoolToIntString(Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame));
	
}
FString ADBMBS::BoolToIntString(bool Value)
{
	if (Value)
	{
		return "1";
	}
	else
	{
		return "0";
	}
}
void ADBMBS::SendStateToMBS()
{
	AMBSUpdateServerStateRequestAdapt* Adapter = nullptr;
	TArray<FKeyValuePair> ServerAttributes = {};
	/*
	Adapter = Spawn('MBSUpdateServerStateRequestAdapter', this);
	AddPlayers(Adapter);
	GetServerAttributes(ServerAttributes);
	Adapter.Request('AuthorizeServerRequestAdapter'.GetServerAuthUsername(), 'AuthorizeServerRequestAdapter'.GetServerAuthPassword(), 'AuthorizeServerRequestAdapter'.GetServerAuthIP(), GetServerPort(), QueryPort, GetNumPlayers(), GetMaxPlayers(), GetPingTimeToReport(), ServerAttributes);
	*/
}

void ADBMBS::PingMBSServer()
{
	AMBSPingMBSServerRequestAdapter* Adapter = nullptr;
	/*
	Adapter = Spawn('MBSPingMBSServerRequestAdapter', this);
	Adapter.Request('AuthorizeServerRequestAdapter'.GetServerAuthIP());
	*/
}

int32 ADBMBS::CalculateAveragePlayerPing()
{
	AController* C = nullptr;
	int32 PlayerPingSum = 0;
	int32 PlayerCount = 0;
	/*
	for (C = Level.ControllerList; C != nullptr; C = C.nextController)
	{
		if (((nullptr != Cast<APlayerController>(C)) && (nullptr != C.PlayerReplicationInfo)) && ((!Level.Game.IsRequireAuthorization()) || PlayerController(C).bInitialAuthComplete))
		{
			PlayerPingSum += C.PlayerReplicationInfo.Ping;
			PlayerCount++;
		}
	}
	if (PlayerCount > 0)
	{
		return (PlayerPingSum / PlayerCount);
	}
	*/
	return 0;
}
int32 ADBMBS::GetPingTimeToReport()
{
	int32 AveragePlayerPing;
	AveragePlayerPing = CalculateAveragePlayerPing();
	if (AveragePlayerPing == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Reporting to MBS server measured ping time to MBS server: %d"),PingTimeToMBSServer);
		return PingTimeToMBSServer;
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Reporting to MBS server average player ping time: %d"),AveragePlayerPing);
		return AveragePlayerPing;
	}
}
void ADBMBS::SetPingTime(int32 Ping)
{
	UE_LOG(LogTemp, Warning, TEXT("Ping to MBS server measured: %d ms"), Ping);
	PingTimeToMBSServer = Ping;
	if (!InitialPingComplete)
	{
		InitialPingComplete = true;
		SendStateToMBS();
	}
}
