// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M16A2_Rifle.h"
#include "Weapon_M4A1_Rifle_Mod.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M4A1_Rifle_Mod : public AWeapon_M16A2_Rifle
{
	GENERATED_BODY()
public:
	AWeapon_M4A1_Rifle_Mod();


	void SetClipCount(uint8 clip, int32 Count, bool bAuxAmmo);
	virtual void DoChangeFireMode() override;
	bool ShouldDoDelayedEject();
	void DiscardShell();
	
};
