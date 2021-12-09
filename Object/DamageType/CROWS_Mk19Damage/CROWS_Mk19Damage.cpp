// All the original content belonged to the US Army


#include "CROWS_Mk19Damage.h"

UCROWS_Mk19Damage::UCROWS_Mk19Damage()
{
	DeathString       = "%o was killed by %k's CROWS Mk19";
	bKUseOwnDeathVel  = true;
	AmmoType          = EAmmoType::AMMO_GrenadeExplosion;
	KDamageImpulse    = 35000;
	KDeathVel         = 125;
	KDeathUpKick      = 5;
	SplashDamage      = { 1500, 1100, 900, 750, 600, 500, 400, 300, 200, 100, 50 };
	DirectDamage      = { 90 };
}