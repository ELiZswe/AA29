// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"

AStatsInfo::AStatsInfo()
{

}

void AStatsInfo::PostBeginPlay()
{
	//Initialize();
}
void AStatsInfo::Destroyed()
{
	//Clear();
}
void AStatsInfo::Initialize()
{
	if (bInitialized)
	{
		Clear();
	}
	//DebugLog(DEBUG_Stats,"Initializing StatsInfo...");
	//GameStats=Spawn(GameStatsClass);
	bInitialized=true;
}
void AStatsInfo::Clear()
{
	/*
	DebugLog(DEBUG_Stats,"Clearing StatsInfo...");
	GameStats.Destroy();
	GameStats=None;
	if (PlayerStats.Length >= 0)
	{
		PlayerStats.remove (0,PlayerStats.Length - 1);
	}
	bInitialized=False;
	*/
}

int32 AStatsInfo::AddPlayerByName(FString PlayerName, FString EncryptedPassword)
{
	/*
	local int i;
	if (! bInitialized)
	{
		Log("StatsInfo::AddPlayer() - StatsInfo not initialized");
		return -1;
	}
	for (i=0; i<PlayerStats.Length; i++)
	{
		if (PlayerStats[i] != None && PlayerName == PlayerStats[i].PlayerName)
		{
			return i;
		}
	}
	DebugLog(DEBUG_Stats,"Adding player" @ PlayerName @ "to StatsInfo...");
	PlayerStats[PlayerStats.Length]=Spawn(PlayerStatsClass);
	PlayerStats[PlayerStats.Length - 1].PlayerName=PlayerName;
	PlayerStats[PlayerStats.Length - 1].EncryptedPassword=EncryptedPassword;
	return PlayerStats.Length - 1;
	*/
	return 0;     //FAKE   /ELiZ
}
void AStatsInfo::Aggregate()
{
	/*
	local int i;
	DebugLog(DEBUG_Stats,"Aggregating StatsInfo...");
	if (! bInitialized)
	{
		Log("StatsInfo::AddPlayer() - StatsInfo not initialized");
		Return;
	}
	if (GameStats != None)
	{
		GameStats.Aggregate();
	}
	for (i=0; i<PlayerStats.Length; i++)
	{
		if (PlayerStats[i] != None)
		{
			PlayerStats[i].Aggregate();
		}
	}
	*/
}

bool AStatsInfo::Store()
{
	return false;    //FAKE   /ELiZ
}
void AStatsInfo::IgnoreStatsThisRound()
{
	/*
	local int i;
	DebugLog(DEBUG_Stats,"Ignoring stats until end of round...");
	if (! bInitialized)
	{
		Log("StatsInfo::IgnoreStatsThisRound() - StatsInfo not initialized");
		Return;
	}
	GameStats.IgnoreStatsThisRound();
	for (i=0; i<PlayerStats.Length; i++)
	{
		if (PlayerStats[i] != None)
		{
			PlayerStats[i].IgnoreStatsThisRound();
		}
	}
	*/
}
