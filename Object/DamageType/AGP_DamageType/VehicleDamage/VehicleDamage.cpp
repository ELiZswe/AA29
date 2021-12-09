// All the original content belonged to the US Army


#include "VehicleDamage.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropConcussion.h"

UVehicleDamage::UVehicleDamage()
{
	SideEffects         = { ASideEffectSlowConcussion::StaticClass(), ASideEffectViewShakeConcussion::StaticClass(), ASideEffectWeaponDropConcussion::StaticClass() };
	DeathString         = "%o was killed when his vehicle was destroyed by %k.";
	bLocationalHit      = false;
	bKUseOwnDeathVel    = true;
	DamageBleedPercent  = 0;
	KDamageImpulse      = 0;
}