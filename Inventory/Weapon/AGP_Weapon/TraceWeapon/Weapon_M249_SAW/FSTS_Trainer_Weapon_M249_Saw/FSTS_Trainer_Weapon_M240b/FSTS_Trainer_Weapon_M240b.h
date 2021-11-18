// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/FSTS_Trainer_Weapon_M249_Saw/FSTS_Trainer_Weapon_M249_Saw.h"
#include "FSTS_Trainer_Weapon_M240b.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_Trainer_Weapon_M240b : public AFSTS_Trainer_Weapon_M249_Saw
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_M240b();


	void GiveTo(APawn* Other, APickup* Pickup);
	virtual void PlayReloading() override;
	virtual void PlayIdleAnim() override;
	virtual void Reload() override;

};
