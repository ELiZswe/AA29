// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/StatsInfo/StatsInfo.h"
#include "AA29/Object/Actor/Info/GameStatsInfo/GameStatsInfo.h"
#include "AA29/Object/Actor/Info/PlayerStatsInfo/PlayerStatsInfo.h"

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
	GameStats=nullptr;
	if (PlayerStats.Num() >= 0)
	{
		PlayerStats->Remove(0,PlayerStats.Num() - 1);
	}
	bInitialized=false;
	*/
}

int32 AStatsInfo::AddPlayerByName(FString PlayerName, FString EncryptedPassword)
{
	/*
	int32 i = 0;
	if (! bInitialized)
	{
		Log("StatsInfo::AddPlayer() - StatsInfo not initialized");
		return -1;
	}
	for (i=0; i<PlayerStats.Num(); i++)
	{
		if (PlayerStats[i] != nullptr && PlayerName == PlayerStats[i].PlayerName)
		{
			return i;
		}
	}
	DebugLog(DEBUG_Stats,"Adding player" @ PlayerName @ "to StatsInfo...");
	PlayerStats[PlayerStats.Num()]=Spawn(PlayerStatsClass);
	PlayerStats[PlayerStats.Num() - 1].PlayerName=PlayerName;
	PlayerStats[PlayerStats.Num() - 1].EncryptedPassword=EncryptedPassword;
	return PlayerStats.Num() - 1;
	*/
	return 0;     //FAKE   /ELiZ
}
void AStatsInfo::Aggregate()
{
	/*
	int32 i = 0;
	DebugLog(DEBUG_Stats,"Aggregating StatsInfo...");
	if (! bInitialized)
	{
		Log("StatsInfo::AddPlayer() - StatsInfo not initialized");
		return;
	}
	if (GameStats != nullptr)
	{
		GameStats.Aggregate();
	}
	for (i=0; i<PlayerStats.Num(); i++)
	{
		if (PlayerStats[i] != nullptr)
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
	int32 i = 0;
	DebugLog(DEBUG_Stats,"Ignoring stats until end of round...");
	if (! bInitialized)
	{
		Log("StatsInfo::IgnoreStatsThisRound() - StatsInfo not initialized");
		return;
	}
	GameStats.IgnoreStatsThisRound();
	for (i=0; i<PlayerStats.Num(); i++)
	{
		if (PlayerStats[i] != nullptr)
		{
			PlayerStats[i].IgnoreStatsThisRound();
		}
	}
	*/
}
