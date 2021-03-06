// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDrop.h"
#include "SideEffectWeaponDropShrapnel.generated.h"

UCLASS()
class ASideEffectWeaponDropShrapnel : public ASideEffectWeaponDrop
{
	GENERATED_BODY()
public:
	ASideEffectWeaponDropShrapnel();

	void ScaleByDamage(int32 Damage);
};
