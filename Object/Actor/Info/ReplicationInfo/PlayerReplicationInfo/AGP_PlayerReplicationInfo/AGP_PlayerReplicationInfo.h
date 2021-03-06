// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/PlayerReplicationInfo/PlayerReplicationInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "AGP_PlayerReplicationInfo.generated.h"

class ATeamInfo;
UCLASS()
class AAGP_PlayerReplicationInfo : public AAA2_PlayerState
{
	GENERATED_BODY()
public:
	AAGP_PlayerReplicationInfo();
	
	void Reset();
	FString GetSquadName();
	bool EquivalentName(FString Name);
	void NotifyPromotion(bool bFTL, uint8 yFT);
	void NotifyNoScore(FName Reason);
	void NotifyClientMessage(FString Message);
	void CalculateWeight(float maxScore);
	float GetWeight();
	int32 GetHonor();
	bool HasGroupIcon();
	uint8 GetGroup();
	void SetGroup(uint8 newgroup);
	void SUToggle();
	bool SuperUser(bool bCheckEnabled);
	bool Administrator();
	int32 GetExperience();
	int32 GetCumRounds();
	int32 GetPlayTime();
	AController* GetController();
	void ResetPerRound();
	int32 GetRoundScore_Total();
	int32 GetRoundScore_Leadership();
	int32 GetRoundScore_Wins();
	int32 GetRoundScore_Objectives();
	int32 GetRoundScore_Deaths();
	int32 GetRoundScore_Kills();
	int32 GetRoundScore_ROE();
	void ClientNotifyLostMedic();
	int32 GetGoalScore();
	void UpdateScore();
	void PScoreKill();
	void PScoreDeath();
	void PScoreFF(int32 newscore);
	bool CheckROE();
	void ScoreDecoMesh(int32 DestroyPoints);
	void PScoreObjective(int32 newscore);
	void ScoreRound(bool bWon);
	float GetMultiplier();
	int32 GetSLBonus();
	int32 GetFTLBonus();
	APlayerStart* GetPlayerStart();
	int32 CalculateLeaderScore();
	int32 CalculateLeaderPenalty();
	void IncrementCumulativeScores();
	int32 CalculateExperience();
	bool hasSoldiersCharacter();
	bool IsFriend(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	bool IsEnemy(AAA2_PlayerState* Other, ATeamInfo* otherTeam);
	void TeamReset();
	FVector GetPawnLocation();
	void ServerSetMyPawn(APawn* new_pawn);
	void WaitingForPawn(AAA2_PlayerState* PRI);
	void FoundWaitingForPawn(APawn* p);
	APawn* GetMyPawn();
	bool isDead();
	bool isSpectator();
	bool IsSquadLeader();
	bool isTeamLeader();
	AAA2_PlayerState* GetSquadLeader();
	AAA2_PlayerState* GetFTLeader();
	void SubmitPlayerRequest(int32 UnitID, int32 Index);
	void RemovePlayerRequest(AAA2_PlayerState* PRI);
};
