// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameDeathMatch.h"
#include "AGP_GameTeam.generated.h"

class AAGP_TeamInfo;
class AAGP_Viewpoint;
class AAGP_PlayerStart;
class ANavigationPoint;

UCLASS()
class AA29_API AAGP_GameTeam : public AAGP_GameDeathMatch
{
	GENERATED_BODY()
public:
	AAGP_GameTeam();

	UPROPERTY(globalconfig)					int32 ForcePSSetTeamSlot;					//var globalconfig int ForcePSSetTeamSlot;
	UPROPERTY(globalconfig)					FName ForcePSSetTag;						//var globalconfig name ForcePSSetTag;
	UPROPERTY(globalconfig)					bool bForcePSSet;							//var globalconfig bool bForcePSSet;
	UPROPERTY(globalconfig)					bool bEnableROEKickDeath;					//var globalconfig bool bEnableROEKickDeath;
	UPROPERTY(globalconfig)					bool bEnableROEKick;						//var globalconfig bool bEnableROEKick;
	UPROPERTY(globalconfig)					bool bEnableROEKickTimer;					//var globalconfig bool bEnableROEKickTimer;
	UPROPERTY(globalconfig)					bool bSpectateBodies;						//var globalconfig bool bSpectateBodies;
	UPROPERTY(globalconfig)					bool bSpectateFriendsOnly;					//var globalconfig bool bSpectateFriendsOnly;
	UPROPERTY(globalconfig)					bool bSpectateFirstPersonOnly;				//var globalconfig bool bSpectateFirstPersonOnly;
	UPROPERTY(globalconfig)					bool bSpectatePlayersOnly;					//var globalconfig bool bSpectatePlayersOnly;
	UPROPERTY(globalconfig)					bool bNeverAutoBalance;						//var globalconfig bool bNeverAutoBalance;
	UPROPERTY(globalconfig)					bool bAutoBalanceBetweenRounds;				//var globalconfig bool bAutoBalanceBetweenRounds;
	UPROPERTY(globalconfig)					bool bPlayersBalanceTeams;					//var globalconfig bool bPlayersBalanceTeams;
	UPROPERTY(globalconfig)					int32 MaxTeamSize;							//var globalconfig int MaxTeamSize;
	UPROPERTY()								TArray<APSSet*> LastPSSet;					//var array<PSSet> LastPSSet;


	//public variables
	UPROPERTY()								TArray<AAGP_TeamInfo*> Teams;				//var AGP_TeamInfo Teams;									//numTeams
	UPROPERTY()								AAGP_TeamInfo* SpecTeam;					//var AGP_TeamInfo SpecTeam;
	UPROPERTY(globalconfig)					int32 FFScoreLimit;							//var globalconfig int FFScoreLimit;						//once a player reaches this point in a match, do bad things.

	//agp [cmb] PSSets are used to group sets of PlayerStarts and/or PSProxies [6/18/2004]
	UPROPERTY()								TArray<APSSet*> PSSets;						//var array<PSSet> PSSets;									//agp [cmb] This is the list of ALL legal PSSets in the level [6/18/2004]
	UPROPERTY()								TArray<APSSet*> CurrentPSSet;				//var PSSet CurrentPSSet;									//agp [cmb] This is the spawnpoint currently being used by each team [6/18/2004]



	virtual void BeginPlay() override;
	virtual void PostBeginPlay() override;
	virtual void EndGame(AAA2_PlayerState* Winner, FString Reason) override;

	virtual bool IsFriend(APawn* me, APawn* you);
	virtual bool IsTeamFriend(uint8 Team, APawn* you);


	void Logout(AController* Exiting);


	void FindPSSets();
	void LogPlayerStart(APlayerController* PC);
	void LogPlayerFinish(APlayerController* PC);
	void SetupTeams();
	void MaybeAutoBalanceTeams();
	void AutoBalanceTeams();
	bool SwapAPlayer(ATeamInfo* Big, ATeamInfo* Small);
	int32 GetSmallerTeamIndex(int32 prefer);
	bool ValidSet(APSSet* NewSet, uint8 Team);
	void FindCurrentSets();
	void AssignStartPoints();
	void AssignClassAndRole();
	void RecordStartMatch();
	void CheckClassWithPlayerStart(AController* PC);
	AAGP_PlayerStart* FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName);
	int32 RatePlayerStart(ANavigationPoint* N, uint8 Team, AController* Player);
	uint8 PickTeam(uint8 Num, AController* C);
	void CompleteEndGame();
	AAGP_Viewpoint* GetWinningViewpoint(AAA2_PlayerState* Winner);
	void DoAuthenticationCheckOnWinningTeam(AAA2_PlayerState* Winner);
	void ResetMatchScores();
	void CheckScore(AAA2_PlayerState* Scorer);
	void CheckFriendlyFireLimit(AAA2_PlayerState* Scorer);
	bool CanRespawn(AController* C);
	void ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType);
	void RecordFriendlyFire(AAA2_PlayerState* ShooterPRI, APawn* VictimPawn, int32 FFScore);
	void NotifyKilled(AController* Killer, AController* Killed, APawn* KilledPawn);
	void EnterSpectatorMode(AController* aPlayer);
	void RequestChangeTeam(AController* Other, int32 Num);
	int32 GetAutoRequest(int32 curr);
	void MustBeSpecTeam(AController* Other);
	void ChangeTeam(AController* Other, int32 Num, bool bNewTeam);
	void FillSwapRequests();
	void RemoveNotOnTeam(TArray<AController*> SwapList, ATeamInfo* Team);
	void RemoveBest(TArray<AController*> SwapList);
	void NotifyRoundOver();
	bool ConfirmReady();
	void CanSpectate(APlayerController* Viewer, bool bOnlySpectator, AActor* ViewTarget);
	bool IsSpectatePlayersOnly();
	bool IsSpectateFirstPersonOnly();
	bool IsSpectateBodies();
	bool IsTeamGame();
	AAGP_TeamInfo* GetTeam(uint8 Index);
	AAGP_TeamInfo* GetOtherTeam(uint8 Index);
	uint8 GetPlayerTeamIndex(AController* C);
	virtual float GetROELimit();
	void SetROEKickTimer(bool bEnabled);
	void SetROEKick(bool bEnabled);
	void SetROEKickDead(bool bEnabled);
	void TournamentSetPlayerTeamByString(FString S);
	void TournamentSetPlayerClassByString(FString S);
	void TournamentSetPlayerTeam(AAA2_PlayerState* PRI, FString SetPlayerName, int32 SetTeamID);
	void TournamentSetPlayerClass(AAA2_PlayerState* PRI, FString SetPlayerName, int32 SetUnitSlot, int32 SetPlayerClass);


};
