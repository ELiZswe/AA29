// All the original content belonged to the US Army

#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDropFell.h"

ASideEffectWeaponDropFell::ASideEffectWeaponDropFell()
{
	EffectDuration = 1;
}

void ASideEffectWeaponDropFell::ScaleByDamage(int32 Damage)
{
	EffectDuration = (EffectDuration + (float(Damage) / 100));
}
