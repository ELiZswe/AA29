// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/GameStatsInfo/STS2_GameStatsInfo/STS2_GameStatsInfo.h"

ASTS2_GameStatsInfo::ASTS2_GameStatsInfo()
{

}


void ASTS2_GameStatsInfo::PostBeginPlay()
{
	/*
	IP = Class'AuthorizeServerRequestAdapter'.GetServerAuthIP();
	Port = Level.Game.GetServerPort();
	MapName = Level.Title;
	Level.GetLevelTourAndMissionPrivate(Level.GetLevelNamePrivate(), TourID, MissionID);
	GameVersion = GetVersionAGPMajor() $ "." $ GetVersionAGPMinor() $ "." $ GetVersionAGPTiny() $ "." $ GetVersionAGPSubTiny();
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
	DebugLog(DEBUG_Stats, "Round started at real time " $ AGP_GameInfo(Level.Game).GetSystemTimeSeconds());
	LastRoundTimeStamp = AGP_GameInfo(Level.Game).GetSystemTimeSeconds();
	*/
}
void ASTS2_GameStatsInfo::StatEvent_RoundEnd()
{
	/*
	PlayTime += FMax(0, AGP_GameInfo(Level.Game).GetSystemTimeSeconds() - LastRoundTimeStamp);
	DebugLog(DEBUG_Stats, "Round ended at real time " $ AGP_GameInfo(Level.Game).GetSystemTimeSeconds() $ ", total playtime: " $ PlayTime $ ", round play time: " $ AGP_GameInfo(Level.Game).GetSystemTimeSeconds() - LastRoundTimeStamp $ " seconds");
	++RoundsPlayed;
	*/
}
void ASTS2_GameStatsInfo::IgnoreStatsThisRound()
{
	/*
	GotoState('IgnoringThisRound');
	*/
}
