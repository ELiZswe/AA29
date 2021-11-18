// All the original content belonged to the US Army


#include "ProjectileDamage545mm.h"

UProjectileDamage545mm::UProjectileDamage545mm()
{
	fCaliber        = 5.45;
	bBulletHit      = true;
	AmmoType        = EAmmoType::AMMO_545mm;
	KDamageImpulse  = 12000;
	KDeathVel       = 110;
	DirectDamage    = { 1000, 30, 25, 20, 25 };
}