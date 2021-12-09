// All the original content belonged to the US Army


#include "RocketExplosionDamage.h"

URocketExplosionDamage::URocketExplosionDamage()
{
	DeathString     = "%o was killed by %k's rocket.";
	AmmoType        = EAmmoType::AMMO_Rocket;
	KDamageImpulse  = 50000;
	KDeathVel       = 300;
	KDeathUpKick    = 350;
}