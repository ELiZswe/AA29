// All the original content belonged to the US Army


#include "RocketFragDamage.h"
#include "AA29/SideEffect/SideEffectSlow\SideEffectSlowShrapnel.h"
#include "AA29/SideEffect/SideEffectViewShake\SideEffectViewShakeShrapnel.h"
#include "AA29/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropShrapnel.h"

URocketFragDamage::URocketFragDamage()
{
	SideEffects       = { ASideEffectSlowShrapnel::StaticClass(), ASideEffectViewShakeShrapnel::StaticClass(), ASideEffectWeaponDropShrapnel::StaticClass() };
	DeathString       = "%o was killed by fragments from %k's rocket.";
	bKUseOwnDeathVel  = true;
	AmmoType          = EAmmoType::AMMO_Rocket;
	KDamageImpulse    = 1000;
	KDeathVel         = 50;
	KDeathUpKick      = 5;
}