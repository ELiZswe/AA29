// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ProjWeapon/ProjWeapon.h"
#include "FSTS_Trainer_Weapon_MK19_AGL.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_Trainer_Weapon_MK19_AGL : public AProjWeapon
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_MK19_AGL();

	void GiveTo(APawn* Other, APickup* Pickup);
};
