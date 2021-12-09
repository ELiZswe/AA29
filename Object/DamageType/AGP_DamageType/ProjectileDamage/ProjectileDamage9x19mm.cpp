// All the original content belonged to the US Army


#include "ProjectileDamage9x19mm.h"

UProjectileDamage9x19mm::UProjectileDamage9x19mm()
{
	fCaliber      = 9;
	bBulletHit    = true;
	AmmoType      = EAmmoType::AMMO_9x19mm;
	DirectDamage  = { 1000, 30, 25, 15 };
}