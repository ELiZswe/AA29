// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ExplosionDamage/BackBlastDamage/BackBlastDamage.h"

UBackBlastDamage::UBackBlastDamage()
{
	DeathString   = "%o was killed by %k's rocket backblast.";
	AmmoType      = EAmmoType::AMMO_Rocket;
}
