// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/GrenadeExplosionDamage/GrenadeExplosionDamage.h"

UGrenadeExplosionDamage::UGrenadeExplosionDamage()
{
	DeathString  = "%o was killed by %k's grenade.";
	AmmoType     = EAmmoType::AMMO_GrenadeExplosion;
}
