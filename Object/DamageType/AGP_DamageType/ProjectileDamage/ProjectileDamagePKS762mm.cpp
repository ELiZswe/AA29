// All the original content belonged to the US Army


#include "ProjectileDamagePKS762mm.h"

UProjectileDamagePKS762mm::UProjectileDamagePKS762mm()
{
	fCaliber      = 7.62;
	AmmoType      = EAmmoType::AMMO_762mm;
	DirectDamage  = { 1000, 50, 40, 35, 30, 2 };
}