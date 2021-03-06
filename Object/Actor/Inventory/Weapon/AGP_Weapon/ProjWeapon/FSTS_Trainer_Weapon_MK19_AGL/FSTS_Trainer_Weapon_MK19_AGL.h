// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ProjWeapon/ProjWeapon.h"
#include "FSTS_Trainer_Weapon_MK19_AGL.generated.h"

class APickup;
UCLASS()
class AFSTS_Trainer_Weapon_MK19_AGL : public AProjWeapon
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_MK19_AGL();

	void GiveTo(APawn* Other, APickup* Pickup);
};
