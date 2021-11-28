// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeamObjective/AGP_GameTeamObjective.h"
#include "AGP_GameTournament.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_GameTournament : public AAGP_GameTeamObjective
{
	GENERATED_BODY()
public:
	AAGP_GameTournament();


	static const uint8 TMMAXSPECTATORS = 32;
	static const uint8 TMMAXADMINS = 32;
	static const uint8 TMMAXTEAMS = 2;
	static const uint8 TMMAXPLAYERS = 32;


	UPROPERTY()					FTournamentTeamResults attrTournamentFinalResults;	//var AGP_GameTournament.TournamentTeamResults attrTournamentFinalResults;
	UPROPERTY()					FTournamentPlayerStats atpsTournamentPlayerStats;	//var AGP_GameTournament.TournamentPlayerStats atpsTournamentPlayerStats;
	UPROPERTY()					FString asTournamentSpectators;						//var string asTournamentSpectators;
	UPROPERTY()					FString asTournamentAdministrators;					//var string asTournamentAdministrators;
	UPROPERTY()					bool bTeamsSwapped;									//var bool bTeamsSwapped;
	UPROPERTY()					bool bJustEndedDeadRound;							//var bool bJustEndedDeadRound;
	UPROPERTY()					bool bCurrentRoundIsDead;							//var bool bCurrentRoundIsDead;
	UPROPERTY()					int32 iDelayScoreboardDisplayTime;					//var int iDelayScoreboardDisplayTime;
	UPROPERTY()					bool bShowScoresOnClients;							//var bool bShowScoresOnClients;
	UPROPERTY()					int32 iTournamentForcedRestartTimer;				//var int iTournamentForcedRestartTimer;
	UPROPERTY()					bool bTournamentForcedRestartPending;				//var bool bTournamentForcedRestartPending;
	UPROPERTY()					bool bTournamentSuddenDeath;						//var bool bTournamentSuddenDeath;
	UPROPERTY()					FString sResultsBaseFileName;						//var string sResultsBaseFileName;
	UPROPERTY()					int32 iEndOfTournamentDelayBeforeResultsShown;		//var int iEndOfTournamentDelayBeforeResultsShown;
	UPROPERTY()					int32 iTournamentPauseLength;						//var int iTournamentPauseLength;
	UPROPERTY()					bool bTournamentRunning;							//var bool bTournamentRunning;
	UPROPERTY()					bool bFirstRunAfterWarmup;							//var bool bFirstRunAfterWarmup;
	UPROPERTY()					bool bInPauseNow;									//var bool bInPauseNow;
	UPROPERTY()					int32 iRoundDelayTimeCounter;						//var int iRoundDelayTimeCounter;
	UPROPERTY()					int32 iLastRoundSwappedOn;							//var int iLastRoundSwappedOn;
	UPROPERTY()					int32 iSwappingRound;								//var int iSwappingRound;
	UPROPERTY()					int32 iTotalRoundsTied;								//var int iTotalRoundsTied;
	UPROPERTY()					int32 iTotalRoundsPlayed;							//var int iTotalRoundsPlayed;
	UPROPERTY()					FString sWinningReason;								//var string sWinningReason;
	UPROPERTY()					FString sWinningTeamName;							//var string sWinningTeamName;
	UPROPERTY()					int32 aiTournamentTeamScores;						//var int aiTournamentTeamScores;
	UPROPERTY()					int32 iTournamentRoundTime;							//var int iTournamentRoundTime;
	UPROPERTY()					int32 iTournamentMaxRounds;							//var int iTournamentMaxRounds;
	UPROPERTY()					bool bTournamentReadyToContinue;					//var bool bTournamentReadyToContinue;
	UPROPERTY()					bool bTournamentWarmupStarted;						//var bool bTournamentWarmupStarted;
	UPROPERTY()					bool bEndPauseNow;									//var bool bEndPauseNow;
	UPROPERTY()					bool bTournamentWarmupPending;						//var bool bTournamentWarmupPending;
	UPROPERTY()					bool bTournamentRestartPending;						//var bool bTournamentRestartPending;
	UPROPERTY()					bool bTournamentSwapPending;						//var bool bTournamentSwapPending;
	UPROPERTY()					bool bTournamentPausePending;						//var bool bTournamentPausePending;
	UPROPERTY()					bool bTournamentStatisticallyOver;					//var bool bTournamentStatisticallyOver;
	UPROPERTY(globalconfig)		int32 bTournamentEnableRandomTeamAssignments;		//var globalconfig bool bTournamentEnableRandomTeamAssignments;
	UPROPERTY(globalconfig)		int32 bTournamentTieScore;							//var globalconfig bool bTournamentTieScore;
	UPROPERTY(globalconfig)		int32 bTournamentTieSuddenDeath;					//var globalconfig bool bTournamentTieSuddenDeath;
	UPROPERTY(globalconfig)		int32 bTournamentTeamPasswordsRequired;				//var globalconfig bool bTournamentTeamPasswordsRequired;
	UPROPERTY(globalconfig)		int32 bTournamentTeamCaptainsAllowed;				//var globalconfig bool bTournamentTeamCaptainsAllowed;
	UPROPERTY(globalconfig)		int32 bTournamentOpenAllWeaponClassSlots;			//var globalconfig bool bTournamentOpenAllWeaponClassSlots;
	UPROPERTY(globalconfig)		int32 bTournamentMercyRule;							//var globalconfig bool bTournamentMercyRule;
	UPROPERTY(globalconfig)		int32 iTournamentPauseLimit;						//var globalconfig int iTournamentPauseLimit;
	UPROPERTY(globalconfig)		int32 iTournamentSwapLimit;							//var globalconfig int iTournamentSwapLimit;
	UPROPERTY(globalconfig)		int32 iTournamentSwapTime;							//var globalconfig int iTournamentSwapTime;
	UPROPERTY(globalconfig)		int32 iTournamentWarmupDuration;					//var globalconfig int iTournamentWarmupDuration;
	UPROPERTY(globalconfig)		int32 iTournamentRoundDelayTime;					//var globalconfig int iTournamentRoundDelayTime;
	UPROPERTY(globalconfig)		int32 iTournamentRequestDelayTime;					//var globalconfig int iTournamentRequestDelayTime;
	UPROPERTY(globalconfig)		FString asTournamentTeamName;						//var globalconfig string asTournamentTeamName;
	UPROPERTY(globalconfig)		FString sLeagueName;								//var globalconfig string sLeagueName;
	UPROPERTY(globalconfig)		FString sTournamentName;							//var globalconfig string sTournamentName;
	UPROPERTY(globalconfig)		FString sMatchName;									//var globalconfig string sMatchName;
	UPROPERTY()					FString sTournamentResultsFileName;					//var string sTournamentResultsFileName;
	UPROPERTY()					FString sTournamentState;							//var string sTournamentState;

	//virtual void PostBeginPlay() override;

	void TournamentSetRoundsPerMatch(int32 iNewRounds);
	void TournamentSetRoundsTimeLimit(int32 iNewTimeLimit);
	void TournamentServerINISetTeamName(int32 iTeam, FString sTeamName);
	void InitGameReplicationInfo();
	void TournamentUpdateGameReplicationInfo();
	void TournamentResetMatchData();
	//APlayerController* Login(FString Portal, FString Options, FString Error);
	void Logout(AController* Exiting);
	void TournamentTeamHasPlayers(int32 iTeamIndex);
	void TournamentRequestResetMatch();
	void TournamentRequestWarmup();
	void TournamentPerformRestartMatch();
	void TournamentGetTeam(uint8 Index);
	void TournamentAreAllWeaponClassesAvailable();
	void TournamentEndedByMercyRule();
	void TournamentRequestResetTournament();
	bool TournamentIsTournament();
	void TournamentJoinSpectatorTeam(APlayerController* PC, int32 iTeamIndex);
	void TournamentJoinTeam(APlayerController* PC, int32 iTeamIndex, FString sPassword);
	void TournamentGetTeamName(int32 iTeamIndex);
	void TournamentSetTeamName(int32 iTeamIndex, FString sTeamName);
	void TournamentAssignRandomTeams();
	void TournamentRequestSwapSides();
	void TournamentChangeTeam(AController* ctrlrPlayer, int32 iTeamIndex);
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
	void TournamentIsWarmup();
	void CheckEndGame(AAA2_PlayerState* Winner, FString Reason);
	void ShouldIgnoreStats();
	void AddAllPlayersToStatsInfo();
	void ResetTMMatchScores();
	void StartMatch();
	void TournamentAddNameToAdministratorList(FString sPlayerName);
	void TournamentAddNameToSpectatorList(FString sPlayerName);
	void NotifyRoundOver();
	void TournamentTransmitResultsToAuthServer();
	void TournamentResultsAuthCallback(int32 iResultCode);
	void TournamentGetConnectedPlayerCount();
	void TournamentGetConnectedTeam(int32 iTeamIndex);
	void ShowCountDown(int32 iTimerLeft, FString sTimerType);
	void PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 EndTime);
	void EndGame(AAA2_PlayerState* Winner, FString Reason);
	void GiveCredit_Wins();
	void NotifyIdlePlayerRounds(AController* C, int32 nIdleRounds, bool bMessage);
	void WholeMatchOver();
	void TournamentSendMessage(FString S);
	void TournamentSendCenteredMessage(FString sMsg);
	void TournamentSendTeamCaptainOnlyMessage(FString sMsg);
	void TournamentSendNonTeamCaptainMessages(FString sMsg);
	void TournamentGetMaxTeamSize();
	void TournamentStatHelperFindPlayerIndex(APlayerController* PC);
	void TournamentUpdatePlayerStats(APlayerController* PC);
	void TournamentGenerateResults(AHumanController* HC, FString sBaseFileName);
	void TournamentUpdateTeamResults(int32 iTeamIndex);
	void TournamentWriteResults(AHumanController* HC, FString sText);
	void TournamentIsDeadRound();
	void TournamentRequestDeadRound();
	void CompleteEndGame();
	void DisableObjectivesForMissionPlanning();


};
