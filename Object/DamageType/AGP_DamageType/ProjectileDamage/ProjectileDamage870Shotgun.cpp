// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/ProjectileDamage/ProjectileDamage870Shotgun.h"

UProjectileDamage870Shotgun::UProjectileDamage870Shotgun()
{
	bBulletHit      = true;
	AmmoType        = EAmmoType::AMMO_Shot00;
	KDamageImpulse  = 45000;
	KDeathVel       = 150;
	KDeathUpKick    = 15;
}
