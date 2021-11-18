// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/Weapon_M249_SAW.h"
#include "FSTS_Trainer_Weapon_M249_Saw.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_Trainer_Weapon_M249_Saw : public AWeapon_M249_SAW
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_M249_Saw();

	void GiveTo(APawn* Other, APickup* Pickup);
	void AddClip(AAmmunition* AmmoClass);
};
