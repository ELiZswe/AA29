// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/GameInfo/AGP_GameInfo/AGP_GameMultiPlayer/AGP_GameDeathMatch/AGP_GameTeam/AGP_GameTeam.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_GameTeamObjective.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_GameTeamObjective : public AAGP_GameTeam
{
	GENERATED_BODY()
public:
	AAGP_GameTeamObjective();

	
	UPROPERTY(globalconfig)								int32 ForceObjectiveSlot;						//var globalconfig int ForceObjectiveSlot;
	UPROPERTY(globalconfig)								FName ForceObjectiveGroupTag;					//var globalconfig name ForceObjectiveGroupTag;
	UPROPERTY(EditAnywhere, Category = "LoadingHints")	TArray<FString> ObjectiveHints;					//var(LoadingHints) localized array<String> ObjectiveHints;
	UPROPERTY(EditAnywhere)								FString VoiceReplicationInfoType;				//var() string VoiceReplicationInfoType;
	UPROPERTY(globalconfig)								bool bAllowNonTeamChat;							//var globalconfig bool bAllowNonTeamChat;
	UPROPERTY(globalconfig)								bool bAllowPrivateChat;							//var globalconfig bool bAllowPrivateChat;
	UPROPERTY()											FString DefaultVoiceChannel;					//var string DefaultVoiceChannel;
	UPROPERTY()											TArray<FName> RandomTags;						//var array<name> RandomTags;
	UPROPERTY()											TSubclassOf<AAGP_Objective> firstObjective;		//var AGP.AGP_Objective firstObjective;

	virtual void BeginPlay();
	virtual void PostBeginPlay();
	virtual void StartMatch();
	virtual void EndGame(AAA2_PlayerState* Winner, FString Reason) override;
//	APlayerController* Login(FString Portal, FString Options, FString Error);
	void PreLogin(const FString& Options, const FString& Address, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage);

	void InitVoiceReplicationInfo();
	void ChangeVoiceChannel(AAA2_PlayerState* PRI, int32 NewChannelIndex, int32 OldChannelIndex);
	void SetupRandomObjectives();
	bool ShouldAddToList(AAGP_Objective* Add);
	void SelectRandomObjectives();
	void DumpObjectives();
	void SelectObjectiveForTag(FName Tag);
	void ScoreAGPObjective(ATeamInfo* Team, AActor* Objective, bool _bGameEnded, AAA2_PlayerState* Scorer, bool bScorerOnly);
	void ScoreDecoMesh(ATeamInfo* Team, AActor* Objective, int32 ScorePoints, AAA2_PlayerState* Scorer, bool bScorerOnly);
	void ScoreKill(AController* Killer, AController* Other, UaDamageType* DamageType);
	void SetSquadTarget(int32 iTeamIndex, uint8 objnum);
	void CheckScore(AAA2_PlayerState* Scorer);
	void PendingEndGame(AAA2_PlayerState* Winner, FString Reason, int32 EndTime);
	bool CheckTeamWon(uint8 Team);
	void CheckIfGameOver();
	void ResetAllObjectives();
	void FakeRestartGame();
	int32 GetAliveTeam();
	TSubclassOf<AAGP_Objective> GetNextObjective(uint8 Team, bool Attacking);
	void SetFirstObjective(AActor* Objective);
	void grenadeNotifier(AActor* Explosive, UaDamageType* DamageType, AController* KillerController);
	FString GetNextLoadHint(FString MapName);
	TArray<FString> GetAllLoadHints(bool bThisClassOnly);

	
};
