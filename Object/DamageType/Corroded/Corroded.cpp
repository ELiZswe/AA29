// All the original content belonged to the US Army


#include "Corroded.h"

UCorroded::UCorroded()
{
	DeathString     = "%o was dissolved by %k's.";
	FemaleSuicide   = "%o dissolved in slime.";
	MaleSuicide     = "%o dissolved in slime.";
	bLocationalHit  = false;
	FlashFog        = FVector(450, 700, 230);
}



void UCorroded::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	//Return Default.PawnDamageEffect;
}