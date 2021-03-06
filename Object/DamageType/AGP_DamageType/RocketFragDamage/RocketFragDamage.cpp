// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/RocketFragDamage/RocketFragDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow/SideEffectSlowShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake/SideEffectViewShakeShrapnel.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropShrapnel.h"

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
