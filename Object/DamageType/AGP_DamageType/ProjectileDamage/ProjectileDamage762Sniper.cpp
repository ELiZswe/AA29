// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage762Sniper.h"

UProjectileDamage762Sniper::UProjectileDamage762Sniper()
{
	DeathString     = "%o was sniped by %k.";
	AmmoType        = EAmmoType::AMMO_762Sniper;
	KDamageImpulse  = 40000;
	KDeathUpKick    = 10;
	DirectDamage    = { 1000, 70, 60, 50, 40, 30 };
}
