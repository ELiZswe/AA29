// All the original content belonged to the US Army


#include "ProjectileDamageUS50cal.h"

UProjectileDamageUS50cal::UProjectileDamageUS50cal()
{
	fCaliber        = 12.7;
	AmmoType        = EAmmoType::AMMO_127HMG;
	KDamageImpulse  = 35000;
	KDeathVel       = 125;
	DirectDamage    = { 1000, 200, 180, 70, 60, 50, 10 };
}