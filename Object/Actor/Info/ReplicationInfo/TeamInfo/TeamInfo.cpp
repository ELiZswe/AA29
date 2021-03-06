// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/Object/Actor/Controller/PlayerController/MessagingSpectator/MessagingSpectator.h"

ATeamInfo::ATeamInfo()
{
	TeamName = "Team";
	TeamColor = FColor(0, 0, 255, 255);
	AltTeamColor = FColor(0, 0, 200, 255);
	ColorNames = {
						"Red",
						"Blue",
						"Green",
						"Gold"
	};
	//NetUpdateFrequency = 2;
	ColorNames.SetNum(4);
	TeamList.SetNum(32);
	FTLeader.SetNum(4);
	NumDesired.SetNum(7);
	NumAvailable.SetNum(7);
	ActualList_Player.SetNum(32);
}

bool ATeamInfo::CheckIf_NoEnemy()
{
	return false;    //FAKE   /ELiZ
}

bool ATeamInfo::CheckIf_SmallGame()
{
	return false;    //FAKE   /ELiZ
}

bool ATeamInfo::CheckIf_ShortGame()
{
	return false;    //FAKE   /ELiZ
}

void ATeamInfo::FindValidFireTeams()
{
}
void ATeamInfo::TestMedics()
{
}
void ATeamInfo::SubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index)
{
}
void ATeamInfo::RemovePlayerRequest(AAA2_PlayerState*  PRI)
{
}
int32 ATeamInfo::GetWinBonus(bool bSurvived)
{
	return 0;		//Fake ELiZ
}

ATeamInfo* ATeamInfo::GetOtherTeam()
{
	return nullptr;	//Fake ELiZ
}

int32 ATeamInfo::NumAlive(bool bFT, uint8 FT)
{
	return 0;		//Fake ELiZ
}

void ATeamInfo::ScoreRound(bool bWon)
{
}

int32 ATeamInfo::CountActivePlayers()
{
	return 0;		//Fake ELiZ
}
void ATeamInfo::LogTeamStructure()
{
}
AAA2_PlayerState* ATeamInfo::GetSquadLeader(AAA2_PlayerState*  PRI)
{
	return nullptr;  //Fake /ELIZ
}
AAA2_PlayerState* ATeamInfo::GetFTLeader(AAA2_PlayerState*  PRI)
{
	return nullptr;  //Fake /ELIZ
}
AAA2_PlayerState* ATeamInfo::GetAnyTeamMember()
{
	return nullptr;  //Fake /ELIZ
}
AAA2_PlayerState* ATeamInfo::GetFTLeaderFromList(int32 Index)
{
	return nullptr;  //Fake /ELIZ
}
AAA2_PlayerState* ATeamInfo::GetFromList(int32 Index)
{
	return nullptr;  //Fake /ELIZ
}
void ATeamInfo::CountDesiredPlayerStarts()
{
}

AActor* ATeamInfo::GetAvailableClass()
{
	return nullptr;  //Fake /ELIZ
}

bool ATeamInfo::removeSubordinate(AAA2_PlayerState*  Remove)
{
	return false;  //Fake /ELIZ
}

bool ATeamInfo::replaceSubordinate(AAA2_PlayerState*  old_sub, AAA2_PlayerState*  new_sub)
{
	return false;  //Fake /ELIZ
}

void ATeamInfo::printTeam()
{
}

void ATeamInfo::TeamReset()
{
}

int32 ATeamInfo::GetNumLeadersAvailable()
{
	return 0;  //Fake /ELIZ
}

int32 ATeamInfo::GetNumLeadersDesired()
{
	return 0;  //Fake /ELIZ
}

int32 ATeamInfo::GetNumMedicsAvailable()
{
	return 0;  //Fake /ELIZ
}

int32 ATeamInfo::GetNumMedicsDesired()
{
	return 0;  //Fake /ELIZ
}

int32 ATeamInfo::GetNumClasses()
{
	return 0;  //Fake /ELIZ
}

bool ATeamInfo::IsClassAvailable(int32 Index)
{
	return false;  //Fake /ELIZ
}

int32 ATeamInfo::UseAltClass(int32 Index)
{
	return 0;  //Fake /ELIZ
}

bool ATeamInfo::IsSquadLeader(int32 Index)
{
	return false;  //Fake /ELIZ
}

bool ATeamInfo::IsFTLeader(int32 Index)
{
	return false;  //Fake /ELIZ
}

FString ATeamInfo::GetClassDisplayName(int32 Index)
{
	return "";  //Fake /ELIZ
}

UObject* ATeamInfo::GetClass(int32 Index)
{
	return nullptr;  //Fake /ELIZ
}

int32 ATeamInfo::GetPlayerUnitID(AAA2_PlayerState*  PRI)
{
	return 0;  //Fake /ELIZ
}

int32 ATeamInfo::GetPlayerIndex(AAA2_PlayerState*  PRI)
{
	return 0;  //Fake /ELIZ
}

void ATeamInfo::SubmitSwapRequest()
{
}

void ATeamInfo::SubmitPauseRequest()
{
}

void ATeamInfo::SubmitResumeRequest()
{
}
bool ATeamInfo::BelongsOnTeam(APawn* PawnClass)
{
	return true;
}

FString ATeamInfo::GetHumanReadableName() const
{
	if (TeamName == GetDefault<ATeamInfo>()->TeamName)
	{
		if (TeamIndex < 4)
		{
			return ColorNames[TeamIndex];
		}
		//return TeamName @ TeamIndex;
	}
	return TeamName;
}

bool ATeamInfo::AddToTeam(AController* Other)
{
	AController* p = nullptr;
	bool bSuccess = false;
	/*
	if ((!Other.PbCanPlayerJoin()) && (TeamIndex != 255))
	{
		return false;
	}
	if (Other == nullptr)
	{
		Log("Added none to team!!!");
		return false;
	}
	if (Cast<AMessagingSpectator>(Other) != nullptr)
	{
		Log("Messaging spectator so returning false", "VoiceChat");
		return false;
	}
	Size++;
	Other.PlayerReplicationInfo.Team = this;
	Other.PlayerReplicationInfo.NetUpdateTime = (GetWorld()->GetTimeSeconds() - 1);
	bSuccess = false;
	if (Other->IsA(APlayerController::StaticClass()))
	{
		Other.PlayerReplicationInfo.TeamID = 0;
	}
	else
	{
		Other.PlayerReplicationInfo.TeamID = 1;
	}
	if (!bSuccess)
	{
		bSuccess = true;
		for (p = Level.ControllerList; p != nullptr; p = p.nextController)
		{
			if (((p.bIsPlayer && (p != Other)) && (p.PlayerReplicationInfo.Team == Other.PlayerReplicationInfo.Team)) && (p.PlayerReplicationInfo.TeamID == Other.PlayerReplicationInfo.TeamID))
			{
				bSuccess = false;
			}
		}
		if (!bSuccess)
		{
			Other.PlayerReplicationInfo.TeamID = (Other.PlayerReplicationInfo.TeamID + 1);
		}
	}
	DebugLog(DEBUG_Multi, FString::FromInt(this) + "AddToTeam() done");
	*/
	return true;
}
void ATeamInfo::RemoveFromTeam(AController* Other)
{
	Size --;
}
void ATeamInfo::SetCharacters(TArray<FString> Chars)
{
}
void ATeamInfo::GetAllCharacters(TArray<FString>& Chars)
{
}
