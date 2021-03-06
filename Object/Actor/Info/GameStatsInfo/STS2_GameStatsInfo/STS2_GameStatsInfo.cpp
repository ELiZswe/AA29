// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"
#include "AA29/Object/Actor/CommunicationRequestAdapter/AuthorizeServerRequestAdapter/AuthorizeServerRequestAdapter.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"

ASTS2_GameStatsInfo::ASTS2_GameStatsInfo()
{

}

/*
State IgnoringThisRound
{
	Function BeginState()
	{
		bRoundHasEnded=false;
	}
	Function IgnoreStatsThisRound()
	{
		bRoundHasEnded=false;
	}
	Function StatEvent_RoundEnd()
	{
		bRoundHasEnded=true;
	}
	Function StatEvent_RoundBegin()
	{
		if (bRoundHasEnded == true)
		{
			GotoState("None");
		}
	}
}
*/

void ASTS2_GameStatsInfo::PostBeginPlay()
{
	/*
	IP = AAuthorizeServerRequestAdapter::StaticClass().GetServerAuthIP();
	Port = Level.Game.GetServerPort();
	MapName = Level.Title;
	Level.GetLevelTourAndMissionPrivate(Level.GetLevelNamePrivate(), TourID, MissionID);
	GameVersion = GetVersionAGPMajor() + "." + GetVersionAGPMinor() + "." + GetVersionAGPTiny() + "." + GetVersionAGPSubTiny();
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->IsLeasedServer())
		{
			ServerMode = 4;
		}
		else
		{
			ServerMode = 3;
		}
	}
	else
	{
		ServerMode = 0;
	}
	*/
}
void ASTS2_GameStatsInfo::StatEvent_RoundBegin()
{
	/*
	DebugLog(DEBUG_Stats, "Round started at real time " + Cast<AAGP_GameInfo>(GetGameMode()).GetSystemTimeSeconds());
	LastRoundTimeStamp = Cast<AAGP_GameInfo>(GetGameMode()).GetSystemTimeSeconds();
	*/
}
void ASTS2_GameStatsInfo::StatEvent_RoundEnd()
{
	/*
	PlayTime += FMax(0, Cast<AAGP_GameInfo>(GetGameMode()).GetSystemTimeSeconds() - LastRoundTimeStamp);
	DebugLog(DEBUG_Stats, "Round ended at real time " + Cast<AAGP_GameInfo>(GetGameMode()).GetSystemTimeSeconds() + ", total playtime: " + PlayTime + ", round play time: " + Cast<AAGP_GameInfo>(GetGameMode()).GetSystemTimeSeconds() - LastRoundTimeStamp + " seconds");
	RoundsPlayed++;
	*/
}
void ASTS2_GameStatsInfo::IgnoreStatsThisRound()
{
	//GotoState('IgnoringThisRound');
}
