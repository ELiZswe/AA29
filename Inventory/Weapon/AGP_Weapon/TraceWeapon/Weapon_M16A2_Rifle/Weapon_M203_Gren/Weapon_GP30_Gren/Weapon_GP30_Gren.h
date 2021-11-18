// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_M203_Gren.h"
#include "Weapon_GP30_Gren.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_GP30_Gren : public AWeapon_M203_Gren
{
	GENERATED_BODY()
public:
	AWeapon_GP30_Gren();

	virtual void DoChangeFireMode() override;
	virtual void SelectGrenadeMode() override;
	virtual void SelectNormalMode() override;

};
