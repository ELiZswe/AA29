// All the original content belonged to the US Army

#include "AA29/Object/DamageType/Drowned/Drowned.h"
#include "AA29/Object/Actor/Effects/Effects.h"

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

AEffects* UDrowned::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	return GetDefault<UDrowned>()->PawnDamageEffect;
}
