// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/AA2_Info.h"
#include "AA29/AA29.h"
#include "GameRules.generated.h"

class AAGP_PlayerStart;
class AAA2_PlayerState;
class APickup;
class UaDamageType;
class ANavigationPoint;

UCLASS()
class AGameRules : public AAA2_Info
{
	GENERATED_BODY()
public:
	AGameRules();

	UPROPERTY()											AGameRules* NextGameRules;									//var GameRules NextGameRules;

	void AddGameRules(AGameRules* GR);
	ANavigationPoint* FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName);
	FString GetRules();
	void GetServerDetails(FServerResponseLine& ServerState);
	bool HandleRestartGame();
	bool CheckEndGame(AAA2_PlayerState* Winner, FString Reason);
	bool CheckScore(AAA2_PlayerState* Scorer);
	bool OverridePickupQuery(APawn* Other, APickup* Item, uint8 &bAllowPickup);
	bool PreventDeath(APawn* Killed, AController* Killer, UaDamageType* DamageType, FVector HitLocation);
	bool PreventSever(APawn* Killed, FName BoneName, int32 Damage, UaDamageType* DamageType);
	void ScoreObjective(AAA2_PlayerState* Scorer, int32 Score);
	void ScoreKill(AController* Killer, AController* Killed, UaDamageType* DamageType);
	bool CriticalPlayer(AController* Other);
	int32 NetDamage(int32 OriginalDamage, int32 Damage, APawn* injured, APawn* instigatedBy, FVector HitLocation, FVector &Momentum, UaDamageType* DamageType);

};
