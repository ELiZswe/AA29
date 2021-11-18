// All the original content belonged to the US Army


#include "ProjectileDamageM240B762mm.h"

UProjectileDamageM240B762mm::UProjectileDamageM240B762mm()
{
	fCaliber      = 7.62;
	AmmoType      = EAmmoType::AMMO_762mm;
	DirectDamage  = { 1000, 50, 40, 35, 30, 20 };
}