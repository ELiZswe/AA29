// All the original content belonged to the US Army


#include "MilesDamage.h"

UMilesDamage::UMilesDamage()
{
	DeathString          = "%o was tagged by %k.";
	PawnDamageSounds     = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/miles/WeaponFX_MILES_Hit.WeaponFX_MILES_Hit"), NULL, LOAD_None, NULL) };
	LowGoreDamageSounds  = { LoadObject<USoundBase>(NULL, TEXT("/Game/AmericasArmy/Sounds/S_AA2_WeaponFX/miles/WeaponFX_MILES_Hit.WeaponFX_MILES_Hit"), NULL, LOAD_None, NULL) };
	DamageBleedPercent   = 0;
}