// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDrop.h"
#include "SideEffectWeaponDropConcussion.generated.h"

UCLASS()
class ASideEffectWeaponDropConcussion : public ASideEffectWeaponDrop
{
	GENERATED_BODY()
public:
	ASideEffectWeaponDropConcussion();

	void ScaleByDamage(int32 Damage);
};
