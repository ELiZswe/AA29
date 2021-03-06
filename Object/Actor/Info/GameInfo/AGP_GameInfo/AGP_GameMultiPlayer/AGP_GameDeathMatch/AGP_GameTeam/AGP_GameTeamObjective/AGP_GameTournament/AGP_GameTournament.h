// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTeamObjective.h"
#include "AGP_GameTournament.generated.h"

class AHumanController;
class ATeamInfo;
UCLASS()
class  AAGP_GameTournament : public AAGP_GameTeamObjective
{
	GENERATED_BODY()
public:
	AAGP_GameTournament();

	UPROPERTY()					TArray<FTournamentTeamResults>	attrTournamentFinalResults;					//var AGP_GameTournament.TournamentTeamResults attrTournamentFinalResults;
	UPROPERTY()					TArray<FTournamentPlayerStats>	atpsTournamentPlayerStats;					//var AGP_GameTournament.TournamentPlayerStats atpsTournamentPlayerStats;
	UPROPERTY()					TArray<FString>					asTournamentSpectators;						//var string asTournamentSpectators;
	UPROPERTY()					TArray<FString>					asTournamentAdministrators;					//var string asTournamentAdministrators;
	UPROPERTY()					bool					bTeamsSwapped;								//var bool bTeamsSwapped;
	UPROPERTY()					bool					bJustEndedDeadRound;						//var bool bJustEndedDeadRound;
	UPROPERTY()					bool					bCurrentRoundIsDead;						//var bool bCurrentRoundIsDead;
	UPROPERTY()					int32					iDelayScoreboardDisplayTime;				//var int iDelayScoreboardDisplayTime;
	UPROPERTY()					bool					bShowScoresOnClients;						//var bool bShowScoresOnClients;
	UPROPERTY()					int32					iTournamentForcedRestartTimer;				//var int iTournamentForcedRestartTimer;
	UPROPERTY()					bool					bTournamentForcedRestartPending;			//var bool bTournamentForcedRestartPending;
	UPROPERTY()					bool					bTournamentSuddenDeath;						//var bool bTournamentSuddenDeath;
	UPROPERTY()					FString					sResultsBaseFileName;						//var string sResultsBaseFileName;
	UPROPERTY()					int32					iEndOfTournamentDelayBeforeResultsShown;	//var int iEndOfTournamentDelayBeforeResultsShown;
	UPROPERTY()					int32					iTournamentPauseLength;						//var int iTournamentPauseLength;
	UPROPERTY()					bool					bTournamentRunning;							//var bool bTournamentRunning;
	UPROPERTY()					bool					bFirstRunAfterWarmup;						//var bool bFirstRunAfterWarmup;
	UPROPERTY()					bool					bInPauseNow;								//var bool bInPauseNow;
	UPROPERTY()					int32					iRoundDelayTimeCounter;						//var int iRoundDelayTimeCounter;
	UPROPERTY()					int32					iLastRoundSwappedOn;						//var int iLastRoundSwappedOn;
	UPROPERTY()					int32					iSwappingRound;								//var int iSwappingRound;
	UPROPERTY()					int32					iTotalRoundsTied;							//var int iTotalRoundsTied;
	UPROPERTY()					int32					iTotalRoundsPlayed;							//var int iTotalRoundsPlayed;
	UPROPERTY()					FString					sWinningReason;								//var string sWinningReason;
	UPROPERTY()					FString					sWinningTeamName;							//var string sWinningTeamName;
	UPROPERTY()					TArray<int32>					aiTournamentTeamScores;						//var int aiTournamentTeamScores;
	UPROPERTY()					int32					iTournamentRoundTime;						//var int iTournamentRoundTime;
	UPROPERTY()					int32					iTournamentMaxRounds;						//var int iTournamentMaxRounds;
	UPROPERTY()					bool					bTournamentReadyToContinue;					//var bool bTournamentReadyToContinue;
	UPROPERTY()					bool					bTournamentWarmupStarted;					//var bool bTournamentWarmupStarted;
	UPROPERTY()					bool					bEndPauseNow;								//var bool bEndPauseNow;
	UPROPERTY()					bool					bTournamentWarmupPending;					//var bool bTournamentWarmupPending;
	UPROPERTY()					bool					bTournamentRestartPending;					//var bool bTournamentRestartPending;
	UPROPERTY()					bool					bTournamentSwapPending;						//var bool bTournamentSwapPending;
	UPROPERTY()					bool					bTournamentPausePending;					//var bool bTournamentPausePending;
	UPROPERTY()					bool					bTournamentStatisticallyOver;				//var bool bTournamentStatisticallyOver;
	UPROPERTY(globalconfig)		bool					bTournamentEnableRandomTeamAssignments;		//var globalconfig bool bTournamentEnableRandomTeamAssignments;
	UPROPERTY(globalconfig)		bool					bTournamentTieScore;						//var globalconfig bool bTournamentTieScore;
	UPROPERTY(globalconfig)		bool					bTournamentTieSuddenDeath;					//var globalconfig bool bTournamentTieSuddenDeath;
	UPROPERTY(globalconfig)		bool					bTournamentTeamPasswordsRequired;			//var globalconfig bool bTournamentTeamPasswordsRequired;
	UPROPERTY(globalconfig)		bool					bTournamentTeamCaptainsAllowed;				//var globalconfig bool bTournamentTeamCaptainsAllowed;
	UPROPERTY(globalconfig)		bool					bTournamentOpenAllWeaponClassSlots;			//var globalconfig bool bTournamentOpenAllWeaponClassSlots;
	UPROPERTY(globalconfig)		bool					bTournamentMercyRule;						//var globalconfig bool bTournamentMercyRule;
	UPROPERTY(globalconfig)		int32					iTournamentPauseLimit;						//var globalconfig int iTournamentPauseLimit;
	UPROPERTY(globalconfig)		int32					iTournamentSwapLimit;						//var globalconfig int iTournamentSwapLimit;
	UPROPERTY(globalconfig)		int32					iTournamentSwapTime;						//var globalconfig int iTournamentSwapTime;
	UPROPERTY(globalconfig)		int32					iTournamentWarmupDuration;					//var globalconfig int iTournamentWarmupDuration;
	UPROPERTY(globalconfig)		int32					iTournamentRoundDelayTime;					//var globalconfig int iTournamentRoundDelayTime;
	UPROPERTY(globalconfig)		int32					iTournamentRequestDelayTime;				//var globalconfig int iTournamentRequestDelayTime;
	UPROPERTY(globalconfig)		TArray<FString>			asTournamentTeamName;						//var globalconfig FString asTournamentTeamName[2];
	UPROPERTY(globalconfig)		FString					sLeagueName;								//var globalconfig string sLeagueName;
	UPROPERTY(globalconfig)		FString					sTournamentName;							//var globalconfig string sTournamentName;
	UPROPERTY(globalconfig)		FString					sMatchName;									//var globalconfig string sMatchName;
	UPROPERTY()					FString					sTournamentResultsFileName;					//var string sTournamentResultsFileName;
	UPROPERTY()					FString					sTournamentState;							//var string sTournamentState;

	//virtual void PostBeginPlay() override;

	void TournamentSetRoundsPerMatch(int32 iNewRounds);
	void TournamentSetRoundsTimeLimit(int32 iNewTimeLimit);
	void TournamentServerINISetTeamName(int32 iTeam, FString sTeamName);
	void InitGameReplicationInfo();
	void TournamentUpdateGameReplicationInfo();
	void TournamentResetMatchData();
	//APlayerController* Login(FString Portal, FString Options, FString& Error);
	void Logout(AController* Exiting);
	bool TournamentTeamHasPlayers(int32 iTeamIndex);
	void TournamentRequestResetMatch();
	void TournamentRequestWarmup();
	void TournamentPerformRestartMatch();
	ATeamInfo* TournamentGetTeam(uint8 Index);
	bool TournamentAreAllWeaponClassesAvailable();
	bool TournamentEndedByMercyRule();
	void TournamentRequestResetTournament();
	bool TournamentIsTournament();
	bool TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex);
	bool TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword);
	FString TournamentGetTeamName(int32 iTeamIndex);
	void TournamentSetTeamName(int32 iTeamIndex, FString sTeamName);
	void TournamentAssignRandomTeams();
	bool TournamentRequestSwapSides();
	bool TournamentChangeTeam(AController* ctrlrPlayer, int32 iTeamIndex);
	void TournamentAssignClass(AAA2_PlayerState* PRI, int32 iUnitID, int32 iSlotIndex);
	void SwapSides();
	void SwapPlayer(AHumanController* HC, int32 iOldTeam, int32 iNewTeam);
	void TournamentResumeFromPause();
	void TournamentRequestPauseTournament();
	void TournamentPause();
	void TournamentResume();
	void TournamentResetTeamCaptainsReadyFlag();
	void TournamentSwapTeamCaptainSelectedFlag();
	void TournamentRequestStartMatch();
	void TournamentRequestRestartMatch();
	void TournamentRequestStartWarmup();
	bool TournamentIsWarmup();
	bool CheckEndGame(AAA2_PlayerState* Winner, FString Reason);
	bool ShouldIgnoreStats();
	void AddAllPlayersToStatsInfo();
	void ResetTMMatchScores();
	void StartMatch();
	void TournamentAddNameToAdministratorList(FString sPlayerName);
	void TournamentAddNameToSpectatorList(FString sPlayerName);
	void NotifyRoundOver();
	void TournamentTransmitResultsToAuthServer();
	void TournamentResultsAuthCallback(int32 iResultCode);
	int32 TournamentGetConnectedPlayerCount();
	int32 TournamentGetConnectedTeam(int32 iTeamIndex);
	void ShowCountDown(int32 iTimerLeft, FString sTimerType);
	void PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 EndTime);
	void EndGame(AAA2_PlayerState* Winner, FString Reason);
	bool GiveCredit_Wins();
	void NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage);
	bool WholeMatchOver();
	void TournamentSendMessage(FString S);
	void TournamentSendCenteredMessage(FString sMsg);
	void TournamentSendTeamCaptainOnlyMessage(FString sMsg);
	void TournamentSendNonTeamCaptainMessages(FString sMsg);
	int32 TournamentGetMaxTeamSize();
	int32 TournamentStatHelperFindPlayerIndex(APlayerController* PC);
	void TournamentUpdatePlayerStats(APlayerController* PC);
	void TournamentGenerateResults(AHumanController* HC, FString sBaseFileName);
	void TournamentUpdateTeamResults(int32 iTeamIndex);
	void TournamentWriteResults(AHumanController* HC, FString sText);
	bool TournamentIsDeadRound();
	void TournamentRequestDeadRound();
	void CompleteEndGame();
	void DisableObjectivesForMissionPlanning();
};
