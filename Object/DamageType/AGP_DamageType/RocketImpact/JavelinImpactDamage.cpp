// All the original content belonged to the US Army


#include "JavelinImpactDamage.h"

UJavelinImpactDamage::UJavelinImpactDamage()
{
	AltDeathString   = "%o got blown up by %k's launched missile.";
	DeathString      = "%o got blown up by %k's launched missile.";
	DirectDamage     = { 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000, 1000 };
}


/*
void UJavelinImpactDamage::DeathMessage(PlayerReplicationInfo Killer, PlayerReplicationInfo Victim)
{
	if (Victim.myPawn != None && Victim.myPawn.IsA('Vehicle'))
	{
		Return Default.AltDeathString;
	}
	else
	{
		Return Default.DeathString;
	}
}
*/