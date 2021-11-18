// All the original content belonged to the US Army


#include "RocketDemolitionDamage.h"

URocketDemolitionDamage::URocketDemolitionDamage()
{
	DeathString     = "%o was killed by %k's rocket.";
	AmmoType        = EAmmoType::AMMO_Rocket;
	KDamageImpulse  = 60000;
	KDeathVel       = 450;
	KDeathUpKick    = 450;
}