// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameMultiPlayer.h"
#include "AGP_GameDeathMatch.generated.h"

class AAA2_PlayerState;
class ANavigationPoint;

UCLASS()
class AA29_API AAGP_GameDeathMatch : public AAGP_GameMultiPlayer
{
	GENERATED_BODY()
public:
	AAGP_GameDeathMatch();

	UPROPERTY()				bool bScoresShownForRound;					//var bool bScoresShownForRound;
	UPROPERTY()				int32 iDelayTimeForScoreboard;				//var int iDelayTimeForScoreboard;
	UPROPERTY()				bool bWarningBeforeCycle;					//var bool bWarningBeforeCycle;
	UPROPERTY()				int32 iServerCycleWarningTime;				//var int iServerCycleWarningTime;
	UPROPERTY()				int32 bNumReportLogoutsPending;				//var int bNumReportLogoutsPending;
	UPROPERTY()				float fReportLogoutsStartTime;				//var float fReportLogoutsStartTime;
	UPROPERTY(globalconfig)	bool bTournamentMode;						//var globalconfig bool bTournamentMode;
	UPROPERTY()				int32 RestartWait;							//var int RestartWait;
	UPROPERTY()				float EndTime;								//var float EndTime;
	UPROPERTY()				int ElapsedTime;							//var int ElapsedTime;
	UPROPERTY()				int RemainingTime;							//var int RemainingTime;
	UPROPERTY()				bool bRunOverTime;							//var bool bRunOverTime;
	UPROPERTY()				int32 CountDown;							//var int CountDown;
	UPROPERTY(globalconfig)	int32 IdlePlayerKickRounds;					//var globalconfig int IdlePlayerKickRounds;
	UPROPERTY(globalconfig)	int32 IdlePlayerKickTime;					//var globalconfig int IdlePlayerKickTime;
	UPROPERTY(globalconfig)	bool bKickIdleSpectators;					//var globalconfig bool bKickIdleSpectators;
	UPROPERTY(globalconfig)	bool bKickIdlePlayersRounds;				//var globalconfig bool bKickIdlePlayersRounds;
	UPROPERTY(globalconfig)	bool bKickIdlePlayersTimed;					//var globalconfig bool bKickIdlePlayersTimed;
	UPROPERTY(globalconfig)	int32 MatchesBeforeCycle;					//var globalconfig int MatchesBeforeCycle;
	UPROPERTY(globalconfig)	int32 RoundsPerMatch;						//var globalconfig int RoundsPerMatch;
	UPROPERTY(globalconfig)	bool bCycleMaps;							//var globalconfig bool bCycleMaps;
	UPROPERTY(globalconfig)	int32 InitialWarmupTime;					//var globalconfig int InitialWarmupTime;
	UPROPERTY()				bool bInitialMatch;							//var bool bInitialMatch;
	UPROPERTY()				int32 NetWait;								//var int NetWait;
	UPROPERTY(globalconfig)	int32 MinNetPlayers;						//var globalconfig int MinNetPlayers;
	UPROPERTY()				bool bWaitForNetPlayers;					//var bool bWaitForNetPlayers;
	UPROPERTY()				bool bPlayersMustBeReady;					//var bool bPlayersMustBeReady;
	UPROPERTY()				ANavigationPoint* LastSpawnPoint;			//var NavigationPoint LastSpawnPoint;
	UPROPERTY()				int32 pendingEndTime;						//var int pendingEndTime;
	UPROPERTY()				AAA2_PlayerState* pendingWinner;			//var PlayerReplicationInfo pendingWinner;
	UPROPERTY()				FString pendingReason;						//var string pendingReason;
	UPROPERTY()				bool bPendingEnd;							//var bool bPendingEnd;


	virtual void BeginPlay() override;
	virtual void PostBeginPlay() override;
	virtual void StartMatch() override;
	virtual void EndGame(AAA2_PlayerState* Winner, FString Reason) override;

	void InitGame(const FString& MapName, const FString& Options, FString& ErrorMessage);

	void Reset();

	void Logout(AController* Exiting);
	virtual void PostLogin(APlayerController* NewPlayer) override;


	void InitGameReplicationInfo();
	void PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 EndTime);
	bool CheckDontEndGame(FString Reason);
	void ResetVariables();
	void CheckEndGame(AAA2_PlayerState* Winner, FString Reason);
	AAGP_Viewpoint* GetWinningViewpoint(AAA2_PlayerState* Winner);
	bool ShouldShowScores();
	void UpdateScoreboardVisibility();
	bool SetScoreMode(FString NewScoreMode);
	void CleanupForMatchEnd();
	void FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName);
	//void RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player);
	bool IsTournamentMode();
	bool IsTeamGame();
	float GetTimeElapsed();
	int32 GetRoundsPerMatch();
	int32 GetMatchesBeforeCycle();
	bool WholeMatchOver();
	void ResetRemainingRounds();
	void ZeroRemainingRounds();
	void ResetMatchesBeforeCycle();
	void NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage);
	void ResetMatchScores();
	void ResetRoundScores();
	void CompleteEndGame();
	bool ShouldSpectate(AAA2_PlayerState* p);
	void NotifyRoundOver();
	bool ConfirmReady();
	void StopNPCControllers();
	void ShowTournamentCountDown();
	void TournamentServerINISetTeamName(int32 iTeam, FString sTeamName);
	void TournamentServerINIGetTeamName(int32 iTeam);


};
