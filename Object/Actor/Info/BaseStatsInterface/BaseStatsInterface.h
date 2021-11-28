// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "BaseStatsInterface.generated.h"

class AWeapon;
class ATeamInfo;
class ABaseObjective;
class UaDamageType;
class AaLocalMessage;
class APlayerReplicationInfo;

UCLASS()
class AA29_API ABaseStatsInterface : public AAA2_Info
{
	GENERATED_BODY()
public:

	ABaseStatsInterface();


	void NewGame();
	void GameInfo();
	void ServerInfo();
	void StartGame();
	void EndGame(FString Reason);
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
	void RecordTakeDamage(APawn* p, AController* Killer, AActor* ResponsibleActor, UaDamageType* DamageType, FString BoneName, int32 DamageDealt, int32 ROE, bool bDied);
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
