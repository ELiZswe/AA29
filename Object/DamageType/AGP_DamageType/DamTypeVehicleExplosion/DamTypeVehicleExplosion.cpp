// All the original content belonged to the US Army

#include "AA29/Object/DamageType/AGP_DamageType/DamTypeVehicleExplosion/DamTypeVehicleExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow\SideEffectSlowExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake\SideEffectViewShakeExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop\SideEffectWeaponDropExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectSlow/SideEffectSlowExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectViewShake/SideEffectViewShakeExplosion.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropExplosion.h"

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

void UDamTypeVehicleExplosion::GetHitEffects(AxEmitter*& HitEffects, int32 VictimHealth)
{
}

