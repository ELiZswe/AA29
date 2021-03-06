// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/GameReplicationInfo/GameReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VoiceChatReplicationInfo/VoiceChatReplicationInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/VehicleReplicationInfo/VehicleReplicationInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/PlayInfo/PlayInfo.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"

AGameReplicationInfo::AGameReplicationInfo()
{
	asTournamentTeamName.SetNum(2);
	FlagHolder.SetNum(2);
	GRIPropDescText.SetNum(4);
	GRIPropsDisplayText.SetNum(4);
	TeamSymbols.SetNum(2);
	Teams.SetNum(2);
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
}


static const int32 PROPNUM = 4;
/*
replication
{
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bStopCountDown, bMatchHasBegun, bShouldShowScoreboard, Teams, Winner, FlagPos, FlagState, FlagTarget, MatchID;
	reliable if ((((!bNetInitial) && bNetDirty) && (Role == ROLE_Authority)))
		RemainingMinute;
	reliable if ((bNetInitial && (Role == ROLE_Authority)))
		GameName, GameClass, bTeamGame, bNoTeamSkins, bForceTeamSkins, bForceNoPlayerLights, bAllowPlayerLights, bFastWeaponSwitching, bNoTeamChanges, GoalScore, TimeLimit, MaxLives, MinNetPlayers, WeaponBerserk, ServerName, ShortName, AdminName, AdminEmail, ServerRegion, MessageOfTheDay, VoiceReplicationInfo, TeamSymbols, BotDifficulty, iDelayedStartTimeRemaining;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		MOTDLine1, MOTDLine2, MOTDLine3, MOTDLine4, MOTDDisplaySeconds, bForceShadowsOff, bAllowForceclassing, bForceClassUsedInRound, bTempDisableRoundScoring;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		RoundsPerMatch, MatchesBeforeCycle;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		RemainingRounds, SpecTeam, bRoundIsSuspended;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		RemainingTime, ElapsedTime;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		bHUDHideAmmoCount, bHUDHideWeaponStatus, bHUDHideWeapon, bHUDHideGrenades, bHUDHideHealth, bHUDHideMedical, bHUDHideCombatEffect, bHUDHideOptics, bHUDHideCompass, bHUDHideTimer, bHUDHideObjectives, bHUDHideRadar, bHUDHideSupport;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		sTournamentState, bTournamentInProgress, bTournamentWarmupJustEnded, bTournamentInWarmup, TournamentCountDownTime, sTournamentResultsFileName, asTournamentTeamName;
	reliable if ((bNetDirty && (Role == ROLE_Authority)))
		sTournamentName, sLeagueName, iTournamentRoundDelayTime, iTournamentRequestDelayTime, iTournamentWarmupDuration, iTournamentSwapTime, iTournamentSwapLimit, iTournamentPauseLimit, bTournamentMercyRule, bTournamentOpenAllWeaponClassSlots, bTournamentTeamCaptainsAllowed, bTournamentTeamPasswordsRequired, bTournamentTieSuddenDeath, bTournamentTieScore, bTournamentEnableRandomTeamAssignments, bDisableFragGrenades, bDisableFlashbangs, bDisableSmokeGrenades, bDisableThermiteGrenades, bDisable203Grenades, iSpotterBaseGridX, iSpotterBaseGridY;
}
*/

void AGameReplicationInfo::PostNetBeginPlay()
{
	AAA2_PlayerState* PRI = nullptr;
	/*
	Level.GRI = this;
	if (VoiceReplicationInfo == nullptr)
	{
		ForEach DynamicActors(AVoiceChatReplicationInfo::StaticClass(), VoiceReplicationInfo)
		{
		}
	}
	ForEach DynamicActors(APlayerReplicationInfo::StaticClass(), PRI)
	{
		AddPRI(PRI);
	}
	if (GetNetMode() == ENetMode::NM_Client)
	{
		TeamSymbolNotify();
	}
	*/
}

void AGameReplicationInfo::TeamSymbolNotify()
{
	AActor* A = nullptr;
	if (TeamSymbols[0] == nullptr)
	{
		return;
	}
	bTeamSymbolsUpdated = true;
	/*
	ForEach AllActors(Class'Actor', A)
	{
		A.SetGRI(this);
	}
	*/
}

void AGameReplicationInfo::UpdatePrecacheMaterials()
{
	//LeveL->AddPrecacheMaterial(TeamSymbols[0]);
	//LeveL->AddPrecacheMaterial(TeamSymbols[1]);
}

void AGameReplicationInfo::PostBeginPlay()
{
	/*
	Super::PostBeginPlay();
	MessageOfTheDay = Repl(MessageOfTheDay, Chr(160), FString::FromInt(" "));
	if (GetNetMode() ==ENetMode::NM_Client)
	{
		ServerName = "";
		AdminName = "";
		AdminEmail = "";
		MessageOfTheDay = "";
	}
	SecondCount = GetWorld()->GetTimeSeconds();
	SetTimer(Level.TimeDilation, true);
	*/
}

void AGameReplicationInfo::Reset()
{
	Super::Reset();
	Winner = nullptr;
}

void AGameReplicationInfo::Timer()
{
	int32 i = 0;
	TArray<AAA2_PlayerState*> OldHolder = { nullptr,nullptr };
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	/*
	if ((GetNetMode() == ENetMode::NM_Client) || (GetNetMode() == ENetMode::NM_Standalone))
	{
		if (bRoundIsSuspended == false)
		{
			if ((GetWorld()->GetTimeSeconds() - SecondCount) >= Level.TimeDilation)
			{
				ElapsedTime++;
				if (RemainingMinute != 0)
				{
					RemainingTime = RemainingMinute;
					RemainingMinute = 0;
				}
				if (bCountUp)
				{
					if (!bStopCountDown)
					{
						RemainingTime++;
					}
				}
				else
				{
					if ((RemainingTime > 0) && (!bStopCountDown))
					{
						RemainingTime--;
					}
				}
				SecondCount += Level.TimeDilation;
			}
			if (!bTeamSymbolsUpdated)
			{
				TeamSymbolNotify();
			}
		}
		else
		{
			Log(string(this) @ "GameReplicationInfo::Timer bRoundIsSuspended=true and SecsTillRoundResume=" + FString::FromInt(SecsTillRoundResume));
			if (SecsTillRoundResume > 0)
			{
				SecsTillRoundResume -= 1;
				if (SecsTillRoundResume > 0)
				{
					for (C = Level.ControllerList; C != nullptr; C = C.nextController)
					{
						PC = Cast<APlayerController>(C);
						if (PC != nullptr)
						{
							PC.ClientMessage("The round will resume in " + FString::FromInt(SecsTillRoundResume) + " seconds");
						}
					}
				}
				else
				{
					for (C = Level.ControllerList; C != nullptr; C = C.nextController)
					{
						PC = Cast<APlayerController>(C);
						if (PC != nullptr)
						{
							PC.ClientMessage("The round has resumed!");
						}
					}
					bRoundIsSuspended = false;
				}
			}
		}
	}
	else
	{
		if (GetNetMode() != ENetMode::NM_Standalone)
		{
			OldHolder[0] = FlagHolder[0];
			OldHolder[1] = FlagHolder[1];
			FlagHolder[0] = nullptr;
			FlagHolder[1] = nullptr;
			for (i = 0; i < PRIArray.Num(); i++)
			{
				if ((PRIArray[i].HasFlag != nullptr) && (PRIArray[i].Team != nullptr))
				{
					FlagHolder[PRIArray[i].Team.TeamIndex] = PRIArray[i];
				}
			}
			for (i = 0; i < 2; i++)
			{
				if (OldHolder[i] != FlagHolder[i])
				{
					for (C = Level.ControllerList; C != nullptr; C = C.nextController)
					{
						if (Cast<APlayerController>(C) != nullptr)
						{
							Cast<APlayerController>(C).ClientUpdateFlagHolder(FlagHolder[i], i);
						}
					}
				}
			}
		}
	}
	*/
}

AAA2_PlayerState* AGameReplicationInfo::FindPlayerByID(int32 PlayerID)
{
	int32 i = 0;
	for (i = 0; i < PRIArray.Num(); i++)
	{
		/*
		if (PRIArray[i]->PlayerID == PlayerID)
		{
			return PRIArray[i];
		}
		*/
	}
	return nullptr;
}

void AGameReplicationInfo::AddPRI(AAA2_PlayerState* PRI)
{
	uint8 NewVoiceID = 0;
	int32 i = 0;
	
	if ((GetNetMode() == ENetMode::NM_ListenServer) || (GetNetMode() == ENetMode::NM_DedicatedServer))
	{
		for (i = 0; i < PRIArray.Num(); i++)
		{
			if (PRIArray[i]->VoiceID == NewVoiceID)
			{
				i = -1;
				NewVoiceID++;
			}
		}
		if (NewVoiceID >= 32)
		{
			NewVoiceID = 0;
		}
		PRI->VoiceID = NewVoiceID;
	}
	PRIArray[PRIArray.Num()] = PRI;
}

void AGameReplicationInfo::AddVRI(AVehicleReplicationInfo* VRI)
{
	VRIArray[VRIArray.Num()] = VRI;
}

void AGameReplicationInfo::RemovePRI(AAA2_PlayerState* PRI)
{
	int32 i = 0;
	/*
	for (i = 0; i < PRIArray.Num(); i++)
	{
		if (PRIArray[i] == PRI)
		{
			PRIArray.RemoveAt(i, 1);
			return;
		}
	}
	Log("GameReplicationInfo::RemovePRI() pri=" + FString::FromInt(PRI) + " not found.", "Error");
	*/
}

void AGameReplicationInfo::RemoveVRI(AVehicleReplicationInfo* VRI)
{
	int32 i = 0;
	/*
	for (i = 0; i < VRIArray.Num(); i++)
	{
		if (VRIArray[i] == VRI)
		{
			VRIArray.RemoveAt(i, 1);
			return;
		}
	}
	Log("GameReplicationInfo::RemoveVRI() vri=" + FString::FromInt(VRI) + " not found.", "Error");
	*/
}

void AGameReplicationInfo::GetPRIArray(TArray<AAA2_PlayerState>& pris)
{
	int32 i = 0;
	int32 Num = 0;
	/*
	pris.RemoveAt(0, pris.Num());
	for (i = 0; i < PRIArray.Num(); i++)
	{
		if (PRIArray[i] != nullptr)
		{
			pris[Num++] = PRIArray[i];
		}
	}
	*/
}

void AGameReplicationInfo::FillPlayInfo(UPlayInfo* PlayInfo)
{
	int32 i = 0;
	//Super::FillPlayInfo(PlayInfo);
	PlayInfo->AddSetting(GetDefault<AGameReplicationInfo>()->ServerGroup, "ServerName", GetDefault<AGameReplicationInfo>()->GRIPropsDisplayText[i++], 255, 1, "Text", "60", "", true, false);
	PlayInfo->AddSetting(GetDefault<AGameReplicationInfo>()->ServerGroup, "AdminName", GetDefault<AGameReplicationInfo>()->GRIPropsDisplayText[i++], 255, 1, "Text", "40", "", true, true);
	PlayInfo->AddSetting(GetDefault<AGameReplicationInfo>()->ServerGroup, "AdminEmail", GetDefault<AGameReplicationInfo>()->GRIPropsDisplayText[i++], 255, 1, "Text", "60", "", true, true);
	PlayInfo->AddSetting(GetDefault<AGameReplicationInfo>()->ServerGroup, "MessageOfTheDay", GetDefault<AGameReplicationInfo>()->GRIPropsDisplayText[i++], 251, 1, "Custom", "255;;GUI2K4.MOTDConfigPage","", true, true);
}

FString AGameReplicationInfo::GetDescriptionText(FString PropName)
{
	/*
	switch (PropName)
	{
	case "ServerName":
		return GetDefault<AGameReplicationInfo>()->GRIPropDescText[0];
	case "AdminName":
		return GetDefault<AGameReplicationInfo>()->GRIPropDescText[1];
	case "AdminEmail":
		return GetDefault<AGameReplicationInfo>()->GRIPropDescText[2];
	case "MessageOfTheDay":
		return GetDefault<AGameReplicationInfo>()->GRIPropDescText[3];
	default:
		return Super::GetDescriptionText(PropName);
	}
	*/
	return "FAKE";   //FAKE   /ELiZ
}

void AGameReplicationInfo::ASDebugLog(APlayerController* PC)
{
}

void AGameReplicationInfo::SuspendRound(bool bEnabled)
{
	AController* C = nullptr;
	APlayerController* PC = nullptr;
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->bCoOpGame && Cast<AAA2_WorldSettings>(GetWorldSettings())->IsOfficialServer())
	{
		return;
	}
	/*
	Log(string(this) @ "GameReplicationInfo::SuspendRound bEnabled=" + FString::FromInt(bEnabled));
	if (bEnabled != bRoundIsSuspended)
	{
		if (bRoundIsSuspended == true)
		{
			if (SecsTillRoundResume == 0)
			{
				Log(string(this) @ "GameReplicationInfo::SuspendRound Setting SecsTillRoundResume=5");
				SecsTillRoundResume = 5;
			}
		}
		else
		{
			bRoundIsSuspended = true;
			SecsTillRoundResume = 0;
			for (C = Level.ControllerList; C != nullptr; C = C.nextController)
			{
				PC = Cast<APlayerController>(C);
				if (PC != nullptr)
				{
					PC.ClientMessage("The round has been suspended by an admin!");
				}
			}
		}
	}
	*/
}

void AGameReplicationInfo::SetTournamentTeamName(int32 Team, FString NewName)
{
	if (Team != 255)
	{
		asTournamentTeamName[Team] = NewName;
	}
}

FString AGameReplicationInfo::GetTournamentTeamName(int32 Team)
{
	if (Team != 255)
	{
		return asTournamentTeamName[Team];
	}
	return "";
}

bool AGameReplicationInfo::DisableFragGrenades()
{
	if ((!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()) && (!bDGO))
	{
		return false;
	}
	return bDisableFragGrenades;
}

bool AGameReplicationInfo::DisableFlashbangs()
{
	if ((!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()) && (!bDGO))
	{
		return false;
	}
	return bDisableFlashbangs;
}

bool AGameReplicationInfo::DisableSmokeGrenades()
{
	if ((!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()) && (!bDGO))
	{
		return false;
	}
	return bDisableSmokeGrenades;
}

bool AGameReplicationInfo::DisableThermiteGrenades()
{
	if ((!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()) && (!bDGO))
	{
		return false;
	}
	return bDisableThermiteGrenades;
}

bool AGameReplicationInfo::Disable203Grenades()
{
	if ((!Cast<AAA2_WorldSettings>(GetWorldSettings())->IsTournamentServer()) && (!bDGO))
	{
		return false;
	}
	return bDisable203Grenades;
}
