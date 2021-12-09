// All the original content belonged to the US Army


#include "ProjectileDamage762mm.h"

UProjectileDamage762mm::UProjectileDamage762mm()
{
	fCaliber        = 7.62;
	bBulletHit      = true;
	AmmoType        = EAmmoType::AMMO_762mm;
	KDamageImpulse  = 35000;
	KDeathVel       = 125;
	DirectDamage    = { 1000, 45, 35, 25, 15, 10 };
}