// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseWeaponMod/BaseWeaponMod_AuxWeapon/BaseWeaponMod_AuxWeapon.h"
#include "WeaponMod_Flare_Gren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeaponMod_Flare_Gren : public ABaseWeaponMod_AuxWeapon
{
	GENERATED_BODY()
public:
	AWeaponMod_Flare_Gren();

	virtual void ModNotAllowed() override;
	
};
