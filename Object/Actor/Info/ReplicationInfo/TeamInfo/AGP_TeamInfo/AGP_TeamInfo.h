// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/MyEnums.h"
#include "AGP_TeamInfo.generated.h"

class AAGP_PlayerStart;
class AAA2_PlayerStart;
class AHumanController;
class AAGP_Objective;
class APSSet;

UCLASS()
class AA29_API AAGP_TeamInfo : public ATeamInfo
{
	GENERATED_BODY()
	
public:
		AAGP_TeamInfo();

		UPROPERTY()			bool bDead;										//var bool bDead;
		static const int32 CLASS_None = -1;
		static const int32 CLASS_Rifleman = 0;
		static const int32 CLASS_Grenadier = 1;
		static const int32 CLASS_Sniper = 2;
		static const int32 CLASS_Sniper24 = 3;
		static const int32 CLASS_AutoRifleman = 4;
		static const int32 CLASS_SquadLeader = 5;
		static const int32 CLASS_FTLeader = 6;
		static const int32 NUM_CLASSES = 7;
		//static const int32 CLASS_RiflemanM4	= 5;	//agp [cmb] not used [6/19/2002]
		static const int32 RIFLE_None = -1;
		static const int32 RIFLE_M16A2 = 0;
		static const int32 RIFLE_M4A1 = 1;
		static const int32 RIFLE_M4A1Auto = 2;
		static const int32 RIFLE_M249Only = 3;

		UPROPERTY()			bool bSpectatorTeam;									//var bool bSpectatorTeam;

		//agp [cmb] These are used for assigning PlayerStarts at the start of a match [6/19/2002]
		UPROPERTY()			TArray<float> PlayerWeight;								//var float PlayerWeight;
		UPROPERTY()			TArray<uint8> FTCount;									//var byte FTCount;								//The number of members each FT has
		UPROPERTY()			TArray<uint8> FTEnabled;								//var byte FTEnabled;							//!!!!!
		UPROPERTY()			TArray<AAA2_PlayerState*> Temp;							//var PlayerReplicationInfo Temp;				//A temporary list of players
		UPROPERTY()			int32 tsize;											//var int tsize;								//The size of the Temp list
		UPROPERTY()			int32 nSLeaders;										//var int nSLeaders;							//The number of SLs and FTLs that must be assigned
		UPROPERTY()			int32 nFTLeaders;										//var int nFTLeaders;							//The number of SLs and FTLs that must be assigned
		UPROPERTY()			TSubclassOf<AAGP_PlayerStart> PSList;					//var AGP.AGP_PlayerStart PSList;				//The list of currently available PSs
		UPROPERTY()			bool bVIP;												//var bool bVIP;								//The SL is a VIP!
		
		//agp [cmb] FOR REQUEST LIST [5/28/2003]
		UPROPERTY()			TArray<AAA2_PlayerState*>	RequestList_Player;			//var PlayerReplicationInfo RequestList_Player;
		UPROPERTY()			TArray<uint8>				RequestList_UnitID;			//var byte RequestList_UnitID;
		UPROPERTY()			TArray<uint8>				RequestList_Index;			//var byte RequestList_Index;
		UPROPERTY()			TArray<AAGP_PlayerStart*>	RequestList_StartSpot;		//var AGP.AGP_PlayerStart RequestList_StartSpot;
		UPROPERTY()			TArray<AAA2_PlayerState*>	NoRequest;					//var PlayerReplicationInfo NoRequest;
		UPROPERTY()			TArray<int32>				NoRequest_Timer;			//var int NoRequest_Timer;
		UPROPERTY()			int32 ReadyTimer;										//var int ReadyTimer;
		UPROPERTY()			int32 ShowScoresTime;									//var int ShowScoresTime;
		UPROPERTY()			ATeamInfo* otherTeam;									//var TeamInfo otherTeam;
		UPROPERTY()			bool bTeamReady;										//var bool bTeamReady;
		UPROPERTY()			TArray<FsPendingRequest> PendingRequests;				//var array<sPendingRequest> PendingRequests;
		UPROPERTY()			float LinkUpdateFrequency;								//var float LinkUpdateFrequency;
		UPROPERTY()			float LinkTimerCount;									//var float LinkTimerCount;
		UPROPERTY()			float LinkTimerThreshold;								//var float LinkTimerThreshold;
		UPROPERTY()			float MaxLinkDistance;									//var float MaxLinkDistance;
		UPROPERTY()			float MaxIndirectLinkDistance;							//var float MaxIndirectLinkDistance;
		UPROPERTY()			int32 TracingPlayerIndex;								//var int TracingPlayerIndex;
	

		void SetupTeam();
		void SetupRequestList();
		void GeneratePSList();
		void AddToPSList(AAGP_PlayerStart* Add);
		void InsertPS(AAGP_PlayerStart* Prev, AAGP_PlayerStart* ins, AAGP_PlayerStart* Next);
		void Compare(AAGP_PlayerStart* PS1, AAGP_PlayerStart* PS2);
		int32 CompareScore(EWeaponType W);
		AAGP_PlayerStart* GetStartSpot(uint8 UnitID, uint8 Index);
		int32 CountAdmins();
		AAA2_PlayerState* GetAdmin(int32 Index);
		int32 CountSpectators();
		AAA2_PlayerState* GetSpectator(int32 Index);
		int32 CountUnassigned();
		int32 CountAssigned();
		AAA2_PlayerState* GetUnassigned(int32 Index);
		AAA2_PlayerState* GetAssigned(int32 Index);
		AAA2_PlayerState* GetNoRequest(int32 Index);
		int32 GetNoRequestTimer(int32 Index);
		AAA2_PlayerState* GetPlayerRequest(int32 UnitID, int32 Index);
		AAGP_PlayerStart* GetPlayerStart(int32 UnitID, int32 Index);
		AAA2_PlayerState* GetPlayerActual(int32 UnitID, int32 Index);
		AAA2_PlayerState* GetPlayerPending(int32 UnitID, int32 Index);
		int32 GetPendingRequestIndex(AAA2_PlayerState*  PRI);
		int32 GetPlayerRequestIndex(AAA2_PlayerState*  PRI);
		int32 GetPlayerUnitID(AAA2_PlayerState*  PRI);
		int32 GetPlayerIndex(AAA2_PlayerState*  PRI);
		int32 CountActivePlayers();
		bool IsFTEmpty(uint8 UnitID);
		int32 GetRealIndex(int32 UnitID, int32 Index);
		void SubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index);
		void AssignPlayerRequest(AAA2_PlayerState*  PRI, int32 Index);
		void RemovePlayerRequest(AAA2_PlayerState*  PRI);
		bool ShouldSwap(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2);
		bool WantsToSwap(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2);
		void SwapPlayerRequests(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2);
		bool CanSelect(AAA2_PlayerState*  PRI);
		void ClearPlayerRequests(AAA2_PlayerState*  PRI);
		void CheckSwaps(int32 swap_index);
		void AddToNoRequestList(AAA2_PlayerState*  PRI, bool bSortAdd);
		bool BetterThan(AAA2_PlayerState*  PRI1, AAA2_PlayerState*  PRI2);
		void RemoveFromNoRequestList(AAA2_PlayerState*  PRI);
		void FindPSStartIndexes(APSSet* UseSet);
		void AssignStartPoints();
		void VerifyVIP();
		void MatchEndReset();
		bool ConfirmReady();
		void Timer();
		void CheckPendingRequests(AAA2_PlayerState*  PRI);
		void SubmitPendingRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index);
		void ShowClassSelectionMenu();
		void SetupTimers();
		void ResetAllRequests();
		void CalculatePlayerWeights();
		void MatchStarting();
		void RecordStartMatch();
		void CountFireTeams();
		bool IsEnabled(uint8 Team);
		void DisableFT(uint8 Team);
		int32 EnableFT(uint8 Team);
		void FindValidFireTeams();
		void CountAvailablePlayerStarts();
		void DumpAvailablePS();
		void CountDesiredPlayerStarts();
		void PrintPSList(FString S);
		void OLD_GeneratePSList();
		void OLD_AddToPSList(AAGP_PlayerStart* Add);
		void OLD_InsertPS(AAGP_PlayerStart* Prev, AAGP_PlayerStart* ins, AAGP_PlayerStart* Next);
		void PrintTeamList(FString S);
		void SortPlayerList();
		void RandomizePlayers();
		void DoAssignment(AAGP_PlayerStart* PS);
		void AssignLeaders();
		void ForceLeaders(bool bSquad, int32 discrepancy);
		void AssignClass(UObject* aClass);
		bool ClassNotAvailable(UObject* aClass);
		bool EquivalentClasses(UObject* c1, UObject* c2);
		void AssignLeftovers();
		void GetPS(AAA2_PlayerState*  PRI);
		void IsPVT(AAGP_PlayerStart* PS);
		void IsRiflePVT(AAGP_PlayerStart* PS);
		void CanBeMedic(AAGP_PlayerStart* PS);
		void TestMedics();
		void AssignMedics();
		void OLD_AssignStartPoints();
		FString GetFireteamDisplayName(int32 Index);
		FString GetFireteamLetter(int32 Index);
		int32 GetNumLeadersAvailable();
		int32 GetNumLeadersDesired();
		int32 GetNumMedicsAvailable();
		int32 GetNumMedicsDesired();
		int32 GetNumClasses();
		bool IsClassAvailable(int32 Index);
		int32 UseAltClass(int32 Index);
		FString GetRifle(bool bLeader);
		FString GetClassDisplayName(int32 Index);
		bool IsSquadLeader(int32 Index);
		bool IsFTLeader(int32 Index);
		UObject* GetClass(int32 Index);
		int32 GetIndex(UObject* aClass);
		void AssignClassAndRole();
		void AssignTeamClassAndRole(AController* C);
		void AssignSquadLeader(AController* C);
		void AssignFTLeader(AController* C, uint8 FT);
		AAA2_PlayerState* GetAnyTeamMember();
		virtual AAA2_PlayerState* GetSquadLeader(AAA2_PlayerState*  PRI) override;
		virtual AAA2_PlayerState* GetFTLeader(AAA2_PlayerState*  PRI) override;
		AAA2_PlayerState* GetFromList(int32 Index);
		AAA2_PlayerState* GetFTLeaderFromList(int32 Index);
		void VerifyTeamStructure();
		int32 Test(AAA2_PlayerState*  PRI);
		void printTeam();
		ATeamInfo* GetOtherTeam();
		void TeamReset();
		void ScoreRound(bool bWon);
		int32 GetTotalScore();
		int32 GetWinBonus(bool bSurvived);
		bool GiveCredit_Wins();
		bool GiveCredit_Objectives();
		bool CheckIf_NoEnemy();
		bool CheckIf_SmallGame();
		bool CheckIf_ShortGame();
		void ResetScores();
		void AddToTeamSP(APawn* Other);
		void AddToTeam(AController* Other);
		void VerifyDesiredClass(AHumanController* HC);
		void RemoveFromTeam(AController* Other);
		AController* GetSwapPlayer();
		void NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn);
		void ReplaceSquadLeader(AAA2_PlayerState*  killa, bool bStartOfRound);
		void LogTeamStructure();
		void ReplaceTeamLeader(uint8 FT, AAA2_PlayerState*  Killer, bool bStartOfRound);
		void FindBestFTLeader(uint8 FT, AAA2_PlayerState*  Killer, bool bStartOfRound);
		void FindBestSquadLeader(bool bStartOfRound);
		void TeamDead();
		virtual int32 NumAlive(bool bFT, uint8 FT) override;
		virtual void ScoreDecoMesh(AAA2_PlayerState*  Scorer, int32 ScorePoints, bool bScorerOnly);

		void ScoreAGPObjective(AAGP_Objective* obj, AAA2_PlayerState*  Scorer, bool bScorerOnly);
		void ScoreDefendObjective(AAGP_Objective* obj, AAA2_PlayerState*  Scorer);
		void PrintRequestList();
		void TournamentSubmitPlayerRequest(AAA2_PlayerState*  PRI, int32 UnitID, int32 Index);
		void SubmitSwapRequest();
		void SubmitPauseRequest();
		void SubmitResumeRequest();
		void Tick(float DeltaTime);
		void LinkTick(float DeltaTime);
		void AlertTeamToEnemyLocations(float alertTime);



};
