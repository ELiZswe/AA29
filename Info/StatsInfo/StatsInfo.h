// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/ReplicationInfo/ReplicationInfo.h"
#include "StatsInfo.generated.h"

class APlayerStatsInfo;
class AGameStatsInfo;
/**
 * 
 */
UCLASS()
class AA29_API AStatsInfo : public AAA2_Info
{
	GENERATED_BODY()
public:
	AStatsInfo();



	UPROPERTY()		TArray<APlayerStatsInfo*> PlayerStats;					//var array<PlayerStatsInfo> PlayerStats;
	UPROPERTY()		AGameStatsInfo* GameStats;								//var GameStatsInfo GameStats;
	UPROPERTY()		APlayerStatsInfo* PlayerStatsClass;						//var class<PlayerStatsInfo> PlayerStatsClass;
	UPROPERTY()		AGameStatsInfo* GameStatsClass;							//var class<GameStatsInfo> GameStatsClass;
	UPROPERTY()		bool bInitialized;										//var bool bInitialized;

	void PostBeginPlay();
	void Destroyed();
	void Initialize();
	void Clear();
	void AddPlayerByName(FString PlayerName, FString EncryptedPassword);
	void Aggregate();
	void Store();
	void IgnoreStatsThisRound();


};
