// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseWeaponMod/BaseWeaponMod_AuxWeapon/BaseWeaponMod_AuxWeapon.h"
#include "WeaponMod_M203_Gren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeaponMod_M203_Gren : public ABaseWeaponMod_AuxWeapon
{
	GENERATED_BODY()
public:
	AWeaponMod_M203_Gren();

	virtual void ModNotAllowed() override;
};
