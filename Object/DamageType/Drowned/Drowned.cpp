// All the original content belonged to the US Army


#include "Drowned.h"

UDrowned::UDrowned()
{
	DeathString     = "%o forgot to come up for air.";
	FemaleSuicide   = "%o forgot to come up for air.";
	MaleSuicide     = "%o forgot to come up for air.";
	bArmorStops     = false;
	bLocationalHit  = false;
	bCausesBlood    = false;
	FlashFog        = FVector(3125, 46875, 46875);
}


void UDrowned::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	//Return Default.PawnDamageEffect;
}