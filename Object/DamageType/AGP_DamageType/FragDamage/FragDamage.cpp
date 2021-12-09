// All the original content belonged to the US Army


#include "FragDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropShrapnel.h"


UFragDamage::UFragDamage()
{
	SideEffects       = { ASideEffectSlowShrapnel::StaticClass(), ASideEffectViewShakeShrapnel::StaticClass(), ASideEffectWeaponDropShrapnel::StaticClass() };
	DeathString       = "%o was killed by fragments from %k's grenade.";
	bKUseOwnDeathVel  = true;
	AmmoType          = EAmmoType::AMMO_Frag;
	KDamageImpulse    = 1000;
	KDeathVel         = 50;
	KDeathUpKick      = 5;
}