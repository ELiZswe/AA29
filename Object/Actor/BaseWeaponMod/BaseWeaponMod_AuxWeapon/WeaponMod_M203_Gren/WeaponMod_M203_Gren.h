// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseWeaponMod/BaseWeaponMod_AuxWeapon/BaseWeaponMod_AuxWeapon.h"
#include "WeaponMod_M203_Gren.generated.h"

UCLASS()
class AWeaponMod_M203_Gren : public ABaseWeaponMod_AuxWeapon
{
	GENERATED_BODY()
public:
	AWeaponMod_M203_Gren();

	bool ModNotAllowed();
};
