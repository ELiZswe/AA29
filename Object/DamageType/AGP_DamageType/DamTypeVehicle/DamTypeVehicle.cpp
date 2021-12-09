// All the original content belonged to the US Army


#include "DamTypeVehicle.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeConcussion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropConcussion.h"
UDamTypeVehicle::UDamTypeVehicle()
{
	SideEffects           = { ASideEffectSlowConcussion::StaticClass(), ASideEffectViewShakeConcussion::StaticClass(), ASideEffectWeaponDropConcussion::StaticClass() };
	DeathString           = "%o had an accident.";
	FemaleSuicide         = "%o had an accident.";
	MaleSuicide           = "%o had an accident.";
	bArmorStops           = false;
	bLocationalHit        = false;
	bOverrideDamageValues = true;
}