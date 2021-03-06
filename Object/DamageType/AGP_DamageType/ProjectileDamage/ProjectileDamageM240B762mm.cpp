// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamageM240B762mm.h"

UProjectileDamageM240B762mm::UProjectileDamageM240B762mm()
{
	fCaliber      = 7.62;
	AmmoType      = EAmmoType::AMMO_762mm;
	DirectDamage  = { 1000, 50, 40, 35, 30, 20 };
}
