// All the original content belonged to the US Army


#include "ProjectileDamageBTR60127mm.h"

UProjectileDamageBTR60127mm::UProjectileDamageBTR60127mm()
{
	fCaliber        = 12.7;
	DeathString     = "%o was killed by a vehicle.";
	AmmoType        = EAmmoType::AMMO_127HMG;
	KDamageImpulse  = 35000;
	KDeathVel       = 125;
	DirectDamage    = { 1000, 100, 90, 80, 70, 60, 50 };
}