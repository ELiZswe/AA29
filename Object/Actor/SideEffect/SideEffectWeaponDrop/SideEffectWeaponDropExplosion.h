// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDrop.h"
#include "SideEffectWeaponDropExplosion.generated.h"

UCLASS()
class ASideEffectWeaponDropExplosion : public ASideEffectWeaponDrop
{
	GENERATED_BODY()
public:
	ASideEffectWeaponDropExplosion();

	void ScaleByDamage(int32 Damage);
};
