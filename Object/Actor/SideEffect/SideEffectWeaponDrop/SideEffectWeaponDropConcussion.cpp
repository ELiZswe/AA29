// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropConcussion.h"

ASideEffectWeaponDropConcussion::ASideEffectWeaponDropConcussion()
{
	EffectDuration = 2;
}

void ASideEffectWeaponDropConcussion::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
}

