// All the original content belonged to the US Army


#include "ProjectileDamage127Sniper.h"

UProjectileDamage127Sniper::UProjectileDamage127Sniper()
{
	bBulletHit    = true;
	AmmoType      = EAmmoType::AMMO_127Sniper;
	DirectDamage  = { 1000, 100, 90, 80, 70, 60 };
}