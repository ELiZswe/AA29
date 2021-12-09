// All the original content belonged to the US Army


#include "ExplosionDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropExplosion.h"

UExplosionDamage::UExplosionDamage()
{
	SideEffects       = { ASideEffectSlowExplosion::StaticClass(), ASideEffectViewShakeExplosion::StaticClass(), ASideEffectWeaponDropExplosion::StaticClass() };
	DeathString       = "%o was blown up by %k.";
	bKUseOwnDeathVel  = true;
	AmmoType          = EAmmoType::AMMO_Explosion;
	KDamageImpulse    = 35000;
	KDeathVel         = 150;
	KDeathUpKick      = 125;
}