// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "GameFramework/Controller.h"
#include "GameFramework/PlayerController.h"
#include "AGP_GameMultiPlayer.generated.h"

//class Controller;
//class PlayerController;


UCLASS()
class AA29_API AAGP_GameMultiPlayer : public AAGP_GameInfo
{
	GENERATED_BODY()
public:

	AAGP_GameMultiPlayer();

	UPROPERTY(globalconfig)		TArray<int32> LegalGroups;				//var globalconfig array<int> LegalGroups;
	UPROPERTY(globalconfig)		int32 MaxHonor;							//var globalconfig int MaxHonor;
	UPROPERTY(globalconfig)		int32 MinHonor;							//var globalconfig int MinHonor;
	UPROPERTY(globalconfig)		float VoteKick_Cooldown;				//var globalconfig float VoteKick_Cooldown;
	UPROPERTY()					int32 VoteKick_StartTime;				//var int VoteKick_StartTime;
	UPROPERTY()					float VoteKick_Timer;					//var float VoteKick_Timer;
	UPROPERTY()					FString VoteKick_Player;				//var string VoteKick_Player;
	UPROPERTY()					AAA2_PlayerState* VoteKick_PRI;			//var PlayerReplicationInfo VoteKick_PRI;
	UPROPERTY()					EStartupStage StartupStage;				//var AGP_GameInfo.EStartupStage StartupStage;
	UPROPERTY(globalconfig)		bool bMPCheatsEnabled;					//var globalconfig bool bMPCheatsEnabled;
	UPROPERTY()					bool bDisableQualification;				//var bool bDisableQualification;
	UPROPERTY(globalconfig)		bool bRequireAuthorization;				//var globalconfig bool bRequireAuthorization;

	virtual bool IsMultiPlayer() override;
	virtual void BeginPlay() override;
	void RestartPlayer(AController* aPlayer);
	void Timer();

	void Logout(AController* Exiting);

	//APlayerController Login(FString Portal, FString Options, FString Error);

	virtual void PostLogin(APlayerController* NewPlayer) override;
	void FinishPostLogin(APlayerController* NewPlayer);


	void UpdateClientsOfCheatAndForceclassStatus();
	void AuthorizeServer();
	void SetStartupStage(EStartupStage Stage);
	void PreparePlayerForStartMatch(APlayerController* PC);
	bool IsRequireAuthorization();
	void SetRequireAuthorization(bool bReqAuth);
	void DisableQualification();
	bool ShouldIgnoreStats();
	bool AllowGameSpeedChange();
	void GetDefaultTeamClass();
	bool CheatsDisabled();
	int32 GetMinHonor();
	int32 GetMaxHonor();
	void VerifyHonorRange();
	void CheckHonor(AController* C);
	void VerifyLegalGroups();
	void CheckGroup(AController* C);
	FString GetLegalGroupsString();
	bool IsTournamentMode();
	void EvaluatePlayerStatus(APlayerController* PC);
	
	void CheckDevKick(AController* Kicker, FString PlayerName);
	void ActiveVote();
	bool CanInitiate(AAA2_PlayerState* PRI);
	void CanInitiateFor(AAA2_PlayerState* PRI_ini, AAA2_PlayerState* PRI_for, FString Reason);
	void InitiateVoteRequest(AAA2_PlayerState* PRI, FString PlayerName, FString Reason);
	void VoteKickPlayerLeft();
	void EndVote();
	void ClearVote();
	void CastVote(AAA2_PlayerState* PRI);
	void CheckPendingVote(FString new_voter, bool bEndVote);
	int32 GetVotesRequired(int32 players);


};
