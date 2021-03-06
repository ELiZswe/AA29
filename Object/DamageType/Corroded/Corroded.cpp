// All the original content belonged to the US Army

#include "AA29/Object/DamageType/Corroded/Corroded.h"
#include "AA29/Object/Actor/Effects/Effects.h"

UCorroded::UCorroded()
{
	DeathString     = "%o was dissolved by %k's.";
	FemaleSuicide   = "%o dissolved in slime.";
	MaleSuicide     = "%o dissolved in slime.";
	bLocationalHit  = false;
	FlashFog        = FVector(450, 700, 230);
}

AEffects* UCorroded::GetPawnDamageEffect(FVector HitLocation, float Damage, FVector Momentum, APawn* Victim, bool bLowDetail)
{
	return GetDefault<UCorroded>()->PawnDamageEffect;
}
