// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "GameStats.generated.h"

class AController;
class AAA2_PlayerState;
class UaDamageType;
class AGameReplicationInfo;
class AFileLog;

UCLASS()
class AGameStats : public AAA2_Info
{
	GENERATED_BODY()
public:
	AGameStats();

	UPROPERTY(globalconfig)	FString					LogFileName;			//var globalconfig string LogFileName;
	UPROPERTY(globalconfig)	bool					bLocalLog;				//var globalconfig bool bLocalLog;
	UPROPERTY()				FString					Tab;					//var string Tab;
	UPROPERTY()				bool					bShowBots;				//var bool bShowBots;
	UPROPERTY()				AGameReplicationInfo*	GRI;					//var GameReplicationInfo GRI;
	UPROPERTY()				AFileLog*				TempLog;				//var FileLog TempLog;

	void GetStatsIdentifier(AController* C);
	void GetMapFileName();
	void Init();
	void Shutdown();
	void Logf(FString LogString);
	void PostBeginPlay();
	void Destroyed();
	FString TimeStamp();
	FString Header();
	FString FullTimeDate();
	FString TimeZone();
	FString MapName();
	void NewGame();
	void ServerInfo();
	void StartGame();
	void EndGame(FString Reason);
	void ConnectEvent(AAA2_PlayerState*  Who);
	void DisconnectEvent(AAA2_PlayerState*  Who);
	void ScoreEvent(AAA2_PlayerState*  Who, float Points, FString Desc);
	void TeamScoreEvent(int32 Team, float Points, FString Desc);
	void KillEvent(FString KillType, AAA2_PlayerState*  Killer, AAA2_PlayerState*  Victim, UaDamageType* Damage);
	void SpecialEvent(AAA2_PlayerState*  Who, FString Desc);
	void GameEvent(FString GEvent, FString Desc, AAA2_PlayerState*  Who);
	FString GetLogFilename();
};
