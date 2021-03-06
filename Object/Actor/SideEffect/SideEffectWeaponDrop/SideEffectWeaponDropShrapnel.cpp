// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropShrapnel.h"

ASideEffectWeaponDropShrapnel::ASideEffectWeaponDropShrapnel()
{
	EffectDuration = 2;
}

void ASideEffectWeaponDropShrapnel::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
}
