// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/GameRules/GameRules.h"
#include "AA29/AA29.h"
#include "AA29/Object/DamageType/aDamageType.h"

UGameRules::UGameRules()
{

}

void UGameRules::AddGameRules(UGameRules* GR)
{
	if (NextGameRules == nullptr)
	{
		NextGameRules = GR;
	}
	else
	{
		NextGameRules->AddGameRules(GR);
	}
}
AAGP_PlayerStart* UGameRules::FindPlayerStart(AController* Player, uint8 InTeam, FString incomingName)
{
	if (NextGameRules != nullptr)
	{
		return NextGameRules->FindPlayerStart(Player, InTeam, incomingName);
	}
	return nullptr;
}
FString UGameRules::GetRules()
{
	FString ResultSet;
	if (NextGameRules == nullptr)
	{
		ResultSet +=  NextGameRules->GetRules();
	}
	return ResultSet;
}
/*
void UGameRules::GetServerDetails(FServerResponseLine &ServerState)
{
}
*/
bool UGameRules::HandleRestartGame()
{
	if (NextGameRules != nullptr && NextGameRules->HandleRestartGame())
	{
		return true;
	}
	return false;
}
bool UGameRules::CheckEndGame(AAA2_PlayerState* Winner, FString Reason)
{
	if (NextGameRules != nullptr)
	{
		return NextGameRules->CheckEndGame(Winner, Reason);
	}
	return true;
}
bool UGameRules::CheckScore(AAA2_PlayerState* Scorer)
{
	if (NextGameRules != nullptr)
	{
		return NextGameRules->CheckScore(Scorer);
	}
	return false;
}
bool UGameRules::OverridePickupQuery(APawn* Other, APickup* Item, uint8 &bAllowPickup)
{
	if (NextGameRules != nullptr && NextGameRules->OverridePickupQuery(Other, Item, bAllowPickup))
	{
		return true;
	}
	return false;
}
bool UGameRules::PreventDeath(APawn* Killed, AController* Killer, UaDamageType*  DamageType, FVector HitLocation)
{
	if (NextGameRules != nullptr && NextGameRules->PreventDeath(Killed, Killer, DamageType, HitLocation))
	{
		return true;
	}
	return false;
}
bool UGameRules::PreventSever(APawn* Killed, FName BoneName, int32 Damage, UaDamageType* DamageType)
{
	if (NextGameRules != nullptr && NextGameRules->PreventSever(Killed, BoneName, Damage, DamageType))
	{
		return true;
	}
	return false;
}
void UGameRules::ScoreObjective(AAA2_PlayerState* Scorer, int32 Score)
{
	if (NextGameRules != nullptr)
	{
		NextGameRules->ScoreObjective(Scorer, Score);
	}
}
void UGameRules::ScoreKill(AController* Killer, AController* Killed, UaDamageType* DamageType)
{
	if (NextGameRules != nullptr)
	{
		NextGameRules->ScoreKill(Killer, Killed, DamageType);
	}
}
bool UGameRules::CriticalPlayer(AController* Other)
{
	if (NextGameRules != nullptr && NextGameRules->CriticalPlayer(Other))
	{
		return true;
	}
	return false;
}
int32 UGameRules::NetDamage(int32 OriginalDamage, int32 Damage, APawn* injured, APawn* instigatedBy, FVector HitLocation, FVector &Momentum, UaDamageType* DamageType)
{
	if (NextGameRules != nullptr)
	{
		return NextGameRules->NetDamage(OriginalDamage, Damage, injured, instigatedBy, HitLocation, Momentum, DamageType);
	}
	return Damage;
}
