// All the original content belonged to the US Army


#include "TeamInfo.h"

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

void ATeamInfo::CheckIf_NoEnemy()
{
}
void ATeamInfo::CheckIf_SmallGame()
{
}
void ATeamInfo::CheckIf_ShortGame()
{
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
void ATeamInfo::GetWinBonus(bool bSurvived)
{
}
ATeamInfo* ATeamInfo::GetOtherTeam()
{
	return NULL;	//Fake ELiZ
}
int32 ATeamInfo::NumAlive(bool bFT, uint8 FT)
{
	return 0;		//Fake ELiZ
}
void ATeamInfo::ScoreRound(bool bWon)
{
}
void ATeamInfo::CountActivePlayers()
{
}
void ATeamInfo::LogTeamStructure()
{
}
AAA2_PlayerState* ATeamInfo::GetSquadLeader(AAA2_PlayerState*  PRI)
{
	return NULL;  //Fake /ELIZ
}
AAA2_PlayerState* ATeamInfo::GetFTLeader(AAA2_PlayerState*  PRI)
{
	return NULL;  //Fake /ELIZ
}
void ATeamInfo::GetAnyTeamMember()
{
}
void ATeamInfo::GetFTLeaderFromList(int32 Index)
{
}
void ATeamInfo::GetFromList(int32 Index)
{
}
void ATeamInfo::CountDesiredPlayerStarts()
{
}
void ATeamInfo::GetAvailableClass()
{
}
void ATeamInfo::removeSubordinate(AAA2_PlayerState*  Remove)
{
}
void ATeamInfo::replaceSubordinate(AAA2_PlayerState*  old_sub, AAA2_PlayerState*  new_sub)
{
}
void ATeamInfo::printTeam()
{
}
void ATeamInfo::TeamReset()
{
}
void ATeamInfo::GetNumLeadersAvailable()
{
}
void ATeamInfo::GetNumLeadersDesired()
{
}
void ATeamInfo::GetNumMedicsAvailable()
{
}
void ATeamInfo::GetNumMedicsDesired()
{
}
void ATeamInfo::GetNumClasses()
{
}
void ATeamInfo::IsClassAvailable(int32 Index)
{
}
void ATeamInfo::UseAltClass(int32 Index)
{
}
void ATeamInfo::IsSquadLeader(int32 Index)
{
}
void ATeamInfo::IsFTLeader(int32 Index)
{
}
void ATeamInfo::GetClassDisplayName(int32 Index)
{
}
void ATeamInfo::GetClass(int32 Index)
{
}
void ATeamInfo::GetPlayerUnitID(AAA2_PlayerState*  PRI)
{
}
void ATeamInfo::GetPlayerIndex(AAA2_PlayerState*  PRI)
{
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
/*
void ATeamInfo::GetHumanReadableName()
{
	if (TeamName == Default.TeamName)
	{
		if (TeamIndex < 4)
		{
			Return ColorNames[TeamIndex];
		}
		Return TeamName @ TeamIndex;
	}
	Return TeamName;
}
*/
void ATeamInfo::AddToTeam(AController* Other)
{
	/*
		local Controller p;
		local bool bSuccess;
		if (! Other.PbCanPlayerJoin() && TeamIndex != 255)
		{
			Return False;
		}
		if (Other == None)
		{
			Log("Added none to team!!!");
			Return False;
		}
		if (MessagingSpectator(Other) != None)
		{
			Log("Messaging spectator so returning false",'VoiceChat');
			Return False;
		}
		Size ++;
		Other.PlayerReplicationInfo.Team=Self;
		Other.PlayerReplicationInfo.NetUpdateTime=GetWorld()->GetTimeSeconds() - 1;
		bSuccess=False;
		if (Other.IsA('PlayerController'))
		{
			Other.PlayerReplicationInfo.TeamID=0;
		}
		else
		{
			Other.PlayerReplicationInfo.TeamID=1;
		}
		if (! bSuccess)
		{
			bSuccess=True;
			p=Level.ControllerList;
			if (p != None)
			{
				if (p.bIsPlayer && p != Other && p.PlayerReplicationInfo.Team == Other.PlayerReplicationInfo.Team && p.PlayerReplicationInfo.TeamID == Other.PlayerReplicationInfo.TeamID)
				{
					bSuccess=False;
				}
				p=p.nextController;
			}
			if (! bSuccess)
			{
				Other.PlayerReplicationInfo.TeamID=Other.PlayerReplicationInfo.TeamID + 1;
			}
		}
		DebugLog(DEBUG_Multi,Self $ "AddToTeam() done");
		Return True;
	*/
}
void ATeamInfo::RemoveFromTeam(AController* Other)
{
	Size --;
}
void ATeamInfo::SetCharacters(TArray<FString> Chars)
{
}
void ATeamInfo::GetAllCharacters(TArray<FString> Chars)
{
}