// All the original content belonged to the US Army


#include "CROWS_50CalDamage.h"

UCROWS_50CalDamage::UCROWS_50CalDamage()
{
	DeathString       = "%o was killed by %k's CROWS 50Cal";
	bKUseOwnDeathVel  = true;
	AmmoType          = EAmmoType::AMMO_50Cal;
	KDamageImpulse    = 12000;
	KDeathVel         = 150;
	KDeathUpKick      = 15;
	SplashDamage      = { 300, 200, 160, 100, 30, 10 };
	DirectDamage      = { 600, 300, 200, 120, 80, 40, 2, 1 };
}