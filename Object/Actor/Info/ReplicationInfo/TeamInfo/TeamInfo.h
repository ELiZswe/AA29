// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/ReplicationInfo.h"

#include "AA29/MyEnums.h"
#include "TeamInfo.generated.h"

class AAA2_PlayerState;

UCLASS()
class ATeamInfo : public AReplicationInfo
{
	GENERATED_BODY()
public:
	ATeamInfo();

	UPROPERTY()										FString TeamName;								//var localized string TeamName;
	UPROPERTY()										int32 Size;										//var int Size;								//number of players on this team in the level	
	UPROPERTY()										int32 MaxSize;									//var int MaxSize;
	UPROPERTY()										float Score;									//var float Score;
	UPROPERTY()										int32 TeamIndex;								//var int TeamIndex;
	UPROPERTY()										FColor TeamColor;								//var Object.Color TeamColor;
	UPROPERTY()										FColor AltTeamColor;							//var Object.Color AltTeamColor;
	UPROPERTY()										AActor* HomeBase;								//var Actor HomeBase;						// key objective associated with this team
	UPROPERTY(EditAnywhere, BluePrintReadOnly)		APawn* DefaultPlayerClass;						//var() class<Pawn> DefaultPlayerClass;
	UPROPERTY()										TArray<FString> ColorNames;						//var localized string ColorNames;


	/************************/
	/*	BEGIN AGP VARIABLES	*/
	/************************/
	UPROPERTY()										TArray<AAA2_PlayerState*> TeamList;				//var PlayerReplicationInfo TeamList;
	UPROPERTY()										AAA2_PlayerState* SquadLeader;					//var PlayerReplicationInfo SquadLeader;
	UPROPERTY()										TArray<AAA2_PlayerState*> FTLeader;				//var PlayerReplicationInfo FTLeader;
	UPROPERTY()										int32 teamScore;								//var int teamScore;
	UPROPERTY()										uint8 yRifleType;								//var byte yRifleType;
	UPROPERTY()										TArray<uint8> NumAvailable;						//var byte NumAvailable;					//How many of each class are currently available
	UPROPERTY()										uint8 NumLeadersAvailable;						//var byte NumLeadersAvailable;
	UPROPERTY()										uint8 NumMedicsAvailable;						//var byte NumMedicsAvailable;
	UPROPERTY()										TArray<uint8> NumDesired;						//var byte NumDesired;						//How many of each class are currently desired
	UPROPERTY()										uint8 NumLeadersDesired;						//var byte NumLeadersDesired;
	UPROPERTY()										uint8 NumMedicsDesired;							//var byte NumMedicsDesired;
	UPROPERTY()										TArray<AAA2_PlayerState*> ActualList_Player;	//var PlayerReplicationInfo ActualList_Player;
	UPROPERTY()										int32 NumRequestSlots;							//var int NumRequestSlots;
	UPROPERTY()										bool bTournamentTeamCaptainSelected;			//var bool bTournamentTeamCaptainSelected;
	UPROPERTY()										bool bTournamentTeamRosterLocked;				//var bool bTournamentTeamRosterLocked;
	UPROPERTY()										bool bTournamentTeamReady;						//var bool bTournamentTeamReady;
	UPROPERTY()										bool bTournamentRequestDeadRound;				//var bool bTournamentRequestDeadRound;

	bool CheckIf_NoEnemy();
	bool CheckIf_SmallGame();
	bool CheckIf_ShortGame();
	void FindValidFireTeams();
	void TestMedics();
	void SubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index);
	void RemovePlayerRequest(AAA2_PlayerState*  PRI);
	int32 GetWinBonus(bool bSurvived);
	ATeamInfo* GetOtherTeam();
	virtual int32 NumAlive(bool bFT, uint8 FT);
	void ScoreRound(bool bWon);
	int32 CountActivePlayers();
	void LogTeamStructure();
	AAA2_PlayerState* GetSquadLeader(AAA2_PlayerState*  PRI);
	AAA2_PlayerState* GetFTLeader(AAA2_PlayerState*  PRI);
	AAA2_PlayerState* GetAnyTeamMember();
	AAA2_PlayerState* GetFTLeaderFromList(int32 Index);
	AAA2_PlayerState* GetFromList(int32 Index);
	void CountDesiredPlayerStarts();
	AActor* GetAvailableClass();
	bool removeSubordinate(AAA2_PlayerState*  Remove);
	bool replaceSubordinate(AAA2_PlayerState*  old_sub, AAA2_PlayerState*  new_sub);
	void printTeam();
	void TeamReset();
	int32 GetNumLeadersAvailable();
	int32 GetNumLeadersDesired();
	int32 GetNumMedicsAvailable();
	int32 GetNumMedicsDesired();
	int32 GetNumClasses();
	bool IsClassAvailable(int32 Index);
	int32 UseAltClass(int32 Index);
	bool IsSquadLeader(int32 Index);
	bool IsFTLeader(int32 Index);
	FString GetClassDisplayName(int32 Index);
	UObject* GetClass(int32 Index);
	int32 GetPlayerUnitID(AAA2_PlayerState*  PRI);
	int32 GetPlayerIndex(AAA2_PlayerState*  PRI);
	void SubmitSwapRequest();
	void SubmitPauseRequest();
	void SubmitResumeRequest();
	bool BelongsOnTeam(APawn* PawnClass);
	FString GetHumanReadableName() const;
	bool AddToTeam(AController* Other);
	void RemoveFromTeam(AController* Other);
	void SetCharacters(TArray<FString> Chars);
	void GetAllCharacters(TArray<FString> Chars);
};
