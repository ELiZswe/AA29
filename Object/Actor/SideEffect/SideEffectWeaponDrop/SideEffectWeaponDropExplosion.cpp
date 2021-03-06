// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropExplosion.h"

ASideEffectWeaponDropExplosion::ASideEffectWeaponDropExplosion()
{
	EffectDuration = 3;
}

void ASideEffectWeaponDropExplosion::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
}

