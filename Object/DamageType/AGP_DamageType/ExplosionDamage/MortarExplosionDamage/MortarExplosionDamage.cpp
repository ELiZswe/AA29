// All the original content belonged to the US Army


#include "MortarExplosionDamage.h"

UMortarExplosionDamage::UMortarExplosionDamage()
{
	DeathString     = "%o was killed by a mortar attack.";
	AmmoType        = EAmmoType::AMMO_GrenadeExplosion;
	KDamageImpulse  = 50000;
	KDeathVel       = 300;
	KDeathUpKick    = 350;
}