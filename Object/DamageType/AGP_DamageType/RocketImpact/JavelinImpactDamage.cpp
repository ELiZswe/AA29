// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/RocketImpact/JavelinImpactDamage.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/Pawn/Vehicle/Vehicle.h"

UJavelinImpactDamage::UJavelinImpactDamage()
{
	AltDeathString   = "%o got blown up by %k's launched missile.";
	DeathString      = "%o got blown up by %k's launched missile.";
	DirectDamage     = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
}

FString UJavelinImpactDamage::DeathMessage(AAA2_PlayerState* Killer, AAA2_PlayerState* Victim)
{
	if (Victim->myPawn != nullptr && Victim->myPawn->IsA(AVehicle::StaticClass()))
	{
		return GetDefault<UJavelinImpactDamage>()->AltDeathString;
	}
	else
	{
		return GetDefault<UJavelinImpactDamage>()->DeathString;
	}
}
