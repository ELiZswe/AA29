// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/SideEffect/SideEffectWeaponDrop/SideEffectWeaponDrop.h"
#include "SideEffectWeaponDropFell.generated.h"

UCLASS()
class ASideEffectWeaponDropFell : public ASideEffectWeaponDrop
{
	GENERATED_BODY()
public:
	ASideEffectWeaponDropFell();

	void ScaleByDamage(int32 Damage);
};
