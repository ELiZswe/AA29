// All the original content belonged to the US Army


#include "ProjectileDamage556mm.h"

UProjectileDamage556mm::UProjectileDamage556mm()
{
	fCaliber      = 5.56;
	bBulletHit    = true;
	AmmoType      = EAmmoType::AMMO_556mm;
	DirectDamage  = { 1000, 30, 25, 20, 25 };
}