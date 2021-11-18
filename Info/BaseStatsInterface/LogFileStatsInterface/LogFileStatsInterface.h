// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/BaseStatsInterface/BaseStatsInterface.h"
#include "LogFileStatsInterface.generated.h"

class AAA2_GameState;
class AFileLog;
class APlayerReplicationInfo;
class ATeamInfo;

UCLASS()
class AA29_API ALogFileStatsInterface : public ABaseStatsInterface
{
	GENERATED_BODY()
public:
	ALogFileStatsInterface();


	UPROPERTY(globalconfig)		FString LogFileName;					//var globalconfig string LogFileName;
	UPROPERTY(config)			TArray<uint8> SuppressStat;				//var config array<byte> SuppressStat;
	UPROPERTY(config)			float LogFileLifespanMinutes;			//var config float LogFileLifespanMinutes;
	UPROPERTY()					FString Delimiter;						//var string Delimiter;
	UPROPERTY()					FString Tab;							//var string Tab;
	UPROPERTY()					AAA2_GameState* GRI;					//var GameReplicationInfo GRI;
	UPROPERTY()					AFileLog* TempLog;						//var FileLog TempLog;
	UPROPERTY()					int32 MinimumLifespan;					//var int MinimumLifespan;
	UPROPERTY()					float LogFileStartTime;					//var float LogFileStartTime;
	UPROPERTY()					bool bLogFileOpen;						//var bool bLogFileOpen;
	UPROPERTY()					AFileLog* LogFile;						//var FileLog LogFile;

	void PostBeginPlay();
	void Destroyed();
	void Init();
	void Shutdown();
	void GetLogFilename();
	void Logf(FString S);
	void Flush();
	void TimeStamp();
	void Header();
	void SubHeader();
	void FullTimeDate();
	void TimeZone();
	void MapName();
	void NewGame();
	void GameInfo();
	void ServerInfo();
	void EndGame(FString Reason);
	void NewLogFile(FString Filename);
	void SuppressEvent(int32 EventKey);
	void GetActorStamp(AActor* Info);
	void GetTimeStamp();
	void StartEventLine(int32 Key, AActor* A);
	void AddField(FString existing_line, FString Info);
	void NotifyRoundEnded();
	void RecordLogOn(AController* C);
	void RecordLogOut(AController* C);
	void RecordKickPlayer(AController* C, FString Reason);
	void RecordVoteKickInitiate(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote, FString Reason);
	void RecordVoteKickCast(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote);
	void RecordTeamRoundBegin(ATeamInfo* t);
	void RecordTeamRoundEnd(ATeamInfo* t, bool bWon);
	void RecordStartMatch(FString Message);
	void RecordEndMatch(FString Message);
	void RecordStartPlayer(AController* C, FString Message);
	void RecordPlayerRoundBegin(AAA2_PlayerState* PRI, ATeamInfo* t);
	void RecordPlayerRoundEnd(AAA2_PlayerState* PRI, ATeamInfo* t, bool bWon);
	void RecordFireTrace(APawn* p, AWeapon* W);
	void RecordFireProjectile(APawn* p, AWeapon* W);
	void RecordFireThrow(APawn* p, AWeapon* W);
	void RecordTakeDamage(APawn* p, AController* Killer, AActor* ResponsibleActor, UaDamageType* DamageType, FString BoneName, int32 DamageDealt, int32 ROE, bool bDead);
	void RecordKilled(APawn* p, APawn* Killer, UaDamageType* DamageType);
	void RecordMedicTreatement(APawn* p, APawn* Healer, int32 HealthSaved, int32 Severity, int32 HealScore);
	void RecordMedicFailure(APawn* p, APawn* Healer, int32 HealthNotSaved, int32 Severity);
	void RecordObjectiveAccomplished(APawn* p, ABaseObjective* O);
	void RecordObjectiveInterrupted(APawn* p, ABaseObjective* O);
	void RecordMissionBegin(AController* C, FString Message);
	void RecordMissionComplete(AController* C, FString Message);
	void RecordStationComplete(AController* C, FString Message);
	void RecordCommoMessage(AController* C, AaLocalMessage* CommoType, int32 Index);
	void RecordCommoSay(AController* C, FName CommoType, FString Message);
	void RecordPlayer(AController* C, FString Message);
	void RecordPlayerLocation(AController* C, FString Message);
	void RecordSpecial(AActor* A, FString Message);


};
