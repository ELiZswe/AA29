// All the original content belonged to the US Army


#include "DamTypeVehicleExplosion.h"
#include "AA29/SideEffect/SideEffectSlow\SideEffectSlowExplosion.h"
#include "AA29/SideEffect/SideEffectViewShake\SideEffectViewShakeExplosion.h"
#include "AA29/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropExplosion.h"

UDamTypeVehicleExplosion::UDamTypeVehicleExplosion()
{
	SideEffects      = { ASideEffectSlowExplosion::StaticClass(), ASideEffectViewShakeExplosion::StaticClass(), ASideEffectWeaponDropExplosion::StaticClass() };
	DeathString      = "%k took out %o with a vehicle explosion.";
	FemaleSuicide    = "%o was a little too close to the vehicle she blew up.";
	MaleSuicide      = "%o was a little too close to the vehicle he blew up.";
	bDetonatesGoop   = true;
	bThrowRagdoll    = true;
	bFlaming         = true;
	GibPerterbation  = 0.15;
}
/*
void UDamTypeVehicleExplosion::GetHitEffects(AxEmitter* HitEffects, int32 VictimHealth)
{

}
*/