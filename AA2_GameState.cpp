// All the original content belonged to the US Army


#include "AA2_GameState.h"
#include "AA29/AA2_WorldSettings.h"

AAA2_GameState::AAA2_GameState()
{
	bStopCountDown = true;
	WeaponBerserk = 1;
	ServerName = "Another ArmyOps Server";
	ShortName = "ArmyOps Server";
	MOTDLine1 = "Welcome to America's Army";
	MOTDDisplaySeconds = 5;
	GRIPropsDisplayText = { 
							"Server Name",
							"Admin Name",
							"Admin E-Mail",
							 "MOTD" 
	};
	GRIPropDescText = {
						"Server name shown on server browser.",
						"Server administrator's name",
						"Server administrator's email address.",
						"Message of the Day"
	};
	BotDifficulty = -1;
	Teams.SetNum(2);
}

void AAA2_GameState::BeginPlay()
{
	Super::BeginPlay();
	
	if (GetLocalRole() == ROLE_Authority)
	{
		GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Cyan, TEXT("Server game state"));
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Cyan, TEXT("Client game state"));
	}
	
}

void AAA2_GameState::PostNetBeginPlay()
{
	/*
	local AAA2_PlayerState PRI;
	Level.GRI=Self;
	if (VoiceReplicationInfo == None)
	{
		ForEach DynamicActors('VoiceChatReplicationInfo',VoiceReplicationInfo)
		{
		}
	}
	ForEach DynamicActors('AAA2_PlayerState',PRI)
	{
		AddPRI(PRI);
	}
	if (GetNetMode() == ENetMode::NM_Client)
	{
		TeamSymbolNotify();
	}
	*/
}
void AAA2_GameState::TeamSymbolNotify()
{
	/*
	local Actor A;
	if (TeamSymbols[0] == None)
	{
		Return;
	}
	bTeamSymbolsUpdated=True;
	ForEach AllActors('Actor',A)
	{
		A.SetGRI(Self);
	}
	*/
}
void AAA2_GameState::UpdatePrecacheMaterials()
{
	/*
	Level.AddPrecacheMaterial(TeamSymbols[0]);
	Level.AddPrecacheMaterial(TeamSymbols[1]);
	*/
}
void AAA2_GameState::PostBeginPlay()
{
	/*
	PostBeginPlay();
	MessageOfTheDay=Repl(MessageOfTheDay,Chr(160),' ');
	if (GetNetMode() == ENetMode::NM_Client)
	{
		ServerName="";
		AdminName="";
		AdminEmail="";
		MessageOfTheDay="";
	}
	SecondCount=GetWorld()->GetTimeSeconds();
	SetTimer(Level.TimeDilation,True);
	*/
}
void AAA2_GameState::Reset()
{
	Super::Reset();
	Winner=nullptr;
}
void AAA2_GameState::Timer()
{
	/*
	local int i;
	local AAA2_PlayerState OldHolder;
	local Controller C;
	local PlayerController PC;
	if (GetNetMode() == ENetMode::NM_Client || GetNetMode() == ENetMode::NM_Standalone)
	{
		if (bRoundIsSuspended == false)
		{
			if (GetWorld()->GetTimeSeconds() - SecondCount >= Level.TimeDilation)
			{
				ElapsedTime ++;
				if (RemainingMinute != 0)
				{
					RemainingTime=RemainingMinute;
					RemainingMinute=0;
				}
				if (bCountUp)
				{
					if (! bStopCountDown)
					{
						RemainingTime ++;
					}
				}
				else
				{
					if (RemainingTime > 0 && ! bStopCountDown)
					{
						RemainingTime --;
					}
				}
				SecondCount += Level.TimeDilation;
			}
			if (! bTeamSymbolsUpdated)
			{
				TeamSymbolNotify();
			}
		}
		else
		{
			Log(Self @ "GameReplicationInfo::Timer bRoundIsSuspended=true and SecsTillRoundResume=" $ SecsTillRoundResume);
			if (SecsTillRoundResume > 0)
			{
				SecsTillRoundResume -= 1;
				if (SecsTillRoundResume > 0)
				{
					C=Level.ControllerList;
					if (C != None)
					{
						PC=PlayerController(C);
						if (PC != None)
						{
							PC.ClientMessage("The round will resume in " $ SecsTillRoundResume $ " seconds");
						}
						C=C.nextController;
					}
				}
				else
				{
					C=Level.ControllerList;
					if (C != None)
					{
						PC=PlayerController(C);
						if (PC != None)
						{
							PC.ClientMessage("The round has resumed!");
						}
						C=C.nextController;
					}
					bRoundIsSuspended=False;
				}
			}
		}
	}
	else
	{
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			OldHolder[0]=FlagHolder[0];
			OldHolder[1]=FlagHolder[1];
			FlagHolder[0]=None;
			FlagHolder[1]=None;
			for (i=0; i<PRIArray.Length; i++)
			{
				if (PRIArray[i].HasFlag != None && PRIArray[i].Team != None)
				{
					FlagHolder[PRIArray[i].Team.TeamIndex]=PRIArray[i];
				}
			}
			for (i=0; i<2; i++)
			{
				if (OldHolder[i] != FlagHolder[i])
				{
					C=Level.ControllerList;
					if (C != None)
					{
						if (PlayerController(C) != None)
						{
							PlayerController(C).ClientUpdateFlagHolder(FlagHolder[i],i);
						}
						C=C.nextController;
					}
				}
			}
		}
	}
	*/
}
void AAA2_GameState::FindPlayerByID(int32 PlayerID)
{
	/*
	local int i;
	for (i=0; i<PRIArray.Length; i++)
	{
		if (PRIArray[i].PlayerID == PlayerID)
		{
			Return PRIArray[i];
		}
	}
	Return None;
	*/
}
void AAA2_GameState::AddPRI(AAA2_PlayerState* PRI)
{
	/*
	local byte NewVoiceID;
	local int i;
	if (GetNetMode() == ENetMode::NM_ListenServer || GetNetMode() == ENetMode::NM_DedicatedServer)
	{
		for (i=0; i<PRIArray.Length; i++)
		{
			if (PRIArray[i].VoiceID == NewVoiceID)
			{
				i=-1;
				NewVoiceID ++;
			}
		}
		if (NewVoiceID >= 32)
		{
			NewVoiceID=0;
		}
		PRI.VoiceID=NewVoiceID;
	}
	PRIArray[PRIArray.Length]=PRI;
	*/
}
/*
void AddVRI (VehicleReplicationInfo VRI)
{
	VRIArray[VRIArray.Length]=VRI;
}
*/
void AAA2_GameState::RemovePRI(AAA2_PlayerState* PRI)
{
	/*
	local int i;
	for (i=0; i<PRIArray.Length; i++)
	{
		if (PRIArray[i] == PRI)
		{
			PRIArray.remove (i,1);
			Return;
		}
	}
	Log("GameReplicationInfo::RemovePRI() pri=" $ PRI $ " not found.",'Error');
	*/
}
/*
void AAA2_GameState::RemoveVRI (VehicleReplicationInfo VRI)
{
	local int i;
	for (i=0; i<VRIArray.Length; i++)
	{
		if (VRIArray[i] == VRI)
		{
			VRIArray.remove (i,1);
			Return;
		}
	}
	Log("GameReplicationInfo::RemoveVRI() vri=" $ VRI $ " not found.",'Error');
}
*/
void AAA2_GameState::GetPRIArray(TArray<AAA2_PlayerState*> pris)
{
	/*
	local int i;
	local int Num;
	pris.remove (0,pris.Length);
	for (i=0; i<PRIArray.Length; i++)
	{
		if (PRIArray[i] != None)
		{
			pris[Num ++]=PRIArray[i];
		}
	}
	*/
}
void AAA2_GameState::FillPlayInfo(APlayInfo* PlayInfo)
{
	/*
	local int i;
	FillPlayInfo(PlayInfo);
	PlayInfo.AddSetting(Default.ServerGroup,"ServerName",Default.GRIPropsDisplayText[i ++],255,1,"Text","60",,True);
	PlayInfo.AddSetting(Default.ServerGroup,"AdminName",Default.GRIPropsDisplayText[i ++],255,1,"Text","40",,True,True);
	PlayInfo.AddSetting(Default.ServerGroup,"AdminEmail",Default.GRIPropsDisplayText[i ++],255,1,"Text","60",,True,True);
	PlayInfo.AddSetting(Default.ServerGroup,"MessageOfTheDay",Default.GRIPropsDisplayText[i ++],251,1,"Custom","255;;GUI2K4.MOTDConfigPage",,True,True);
	*/
}
FString AAA2_GameState::GetDescriptionText(FString PropName)
{
	if (PropName == "ServerName")		{ return GetDefault<AAA2_GameState>()->GRIPropDescText[0]; }
	if (PropName == "AdminName")		{ return GetDefault<AAA2_GameState>()->GRIPropDescText[1]; }
	if (PropName == "AdminEmail")		{ return GetDefault<AAA2_GameState>()->GRIPropDescText[2]; }
	if (PropName == "MessageOfTheDay")	{ return GetDefault<AAA2_GameState>()->GRIPropDescText[3]; }

	//return  GetDescriptionText(PropName);
	return "";
}
void AAA2_GameState::ASDebugLog(APlayerController* PC)
{
}
void AAA2_GameState::SuspendRound(bool bEnabled)
{
	/*
	local Controller C;
	local PlayerController PC;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		Return;
	}
	Log(Self @ "GameReplicationInfo::SuspendRound bEnabled=" $ bEnabled);
	if (bEnabled != bRoundIsSuspended)
	{
		if (bRoundIsSuspended == true)
		{
			if (SecsTillRoundResume == 0)
			{
				Log(Self @ "GameReplicationInfo::SuspendRound Setting SecsTillRoundResume=5");
				SecsTillRoundResume=5;
			}
		}
		else
		{
			bRoundIsSuspended=True;
			SecsTillRoundResume=0;
			C=Level.ControllerList;
			if (C != None)
			{
				PC=PlayerController(C);
				if (PC != None)
				{
					PC.ClientMessage("The round has been suspended by an admin!");
				}
				C=C.nextController;
			}
		}
	}
	*/
}
void AAA2_GameState::SetTournamentTeamName(int32 Team, FString NewName)
{
	if (Team != 255)
	{
		asTournamentTeamName[Team] = NewName;
	}
}
FString AAA2_GameState::GetTournamentTeamName(int32 Team)
{
	if (Team != 255)
	{
		return asTournamentTeamName[Team];
	}
	return "";
}
bool AAA2_GameState::DisableFragGrenades()
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() && !bDGO)
	{
		return false;
	}
	return bDisableFragGrenades;
}
bool AAA2_GameState::DisableFlashbangs()
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() && !bDGO)
	{
		return false;
	}
	return bDisableFlashbangs;
}
bool AAA2_GameState::DisableSmokeGrenades()
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() && !bDGO)
	{
		return false;
	}
	return bDisableSmokeGrenades;
}
bool AAA2_GameState::DisableThermiteGrenades()
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() && !bDGO)
	{
		return false;
	}
	return bDisableThermiteGrenades;
}
bool AAA2_GameState::Disable203Grenades()
{
	if (!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer() && !bDGO)
	{
		return false;
	}
	return bDisable203Grenades;
}
