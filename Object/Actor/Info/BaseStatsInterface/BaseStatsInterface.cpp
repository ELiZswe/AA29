// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/BaseStatsInterface/BaseStatsInterface.h"

ABaseStatsInterface::ABaseStatsInterface()
{
}

void ABaseStatsInterface::NewGame()
{
}
void ABaseStatsInterface::GameInfo()
{
}
void ABaseStatsInterface::ServerInfo()
{
}
void ABaseStatsInterface::StartGame()
{
}
void ABaseStatsInterface::EndGame(FString Reason)
{
}
void ABaseStatsInterface::NotifyRoundEnded()
{
}
void ABaseStatsInterface::RecordLogOn(AController* C)
{
}
void ABaseStatsInterface::RecordLogOut(AController* C)
{
}
void ABaseStatsInterface::RecordKickPlayer(AController* C, FString Reason)
{
}
void ABaseStatsInterface::RecordVoteKickInitiate(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote, FString Reason)
{
}
void ABaseStatsInterface::RecordVoteKickCast(AAA2_PlayerState* PRI, AAA2_PlayerState* Vote)
{
}
void ABaseStatsInterface::RecordTeamRoundBegin(ATeamInfo* t)
{
}
void ABaseStatsInterface::RecordTeamRoundEnd(ATeamInfo* t, bool bWon)
{
}
void ABaseStatsInterface::RecordStartMatch(FString Message)
{
}
void ABaseStatsInterface::RecordEndMatch(FString Message)
{
}
void ABaseStatsInterface::RecordStartPlayer(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordPlayerRoundBegin(AAA2_PlayerState* PRI, ATeamInfo* t)
{
}
void ABaseStatsInterface::RecordPlayerRoundEnd(AAA2_PlayerState* PRI, ATeamInfo* t, bool bWon)
{
}
void ABaseStatsInterface::RecordFireTrace(APawn* p, AWeapon* W)
{
}
void ABaseStatsInterface::RecordFireProjectile(APawn* p, AWeapon* W)
{
}
void ABaseStatsInterface::RecordFireThrow(APawn* p, AWeapon* W)
{
}
void ABaseStatsInterface::RecordTakeDamage(APawn* p, AController* Killer, AActor* ResponsibleActor, UaDamageType* DamageType, FString BoneName, int32 DamageDealt, int32 ROE, bool bDied)
{
}
void ABaseStatsInterface::RecordKilled(APawn* p, APawn* Killer, UaDamageType* DamageType)
{
}
void ABaseStatsInterface::RecordMedicTreatement(APawn* p, APawn* Healer, int32 HealthSaved, int32 Severity, int32 HealScore)
{
}
void ABaseStatsInterface::RecordMedicFailure(APawn* p, APawn* Healer, int32 HealthNotSaved, int32 Severity)
{
}
void ABaseStatsInterface::RecordObjectiveAccomplished(APawn* p, ABaseObjective* O)
{
}
void ABaseStatsInterface::RecordObjectiveInterrupted(APawn* p, ABaseObjective* O)
{
}
void ABaseStatsInterface::RecordMissionBegin(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordMissionComplete(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordStationComplete(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordCommoMessage(AController* C, AaLocalMessage* CommoType, int32 Index)
{
}
void ABaseStatsInterface::RecordCommoSay(AController* C, FName CommoType, FString Message)
{
}
void ABaseStatsInterface::RecordPlayer(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordPlayerLocation(AController* C, FString Message)
{
}
void ABaseStatsInterface::RecordSpecial(AActor* A, FString Message)
{
}