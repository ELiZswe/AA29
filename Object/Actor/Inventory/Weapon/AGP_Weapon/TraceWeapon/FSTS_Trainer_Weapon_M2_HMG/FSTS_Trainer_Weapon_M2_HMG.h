// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "FSTS_Trainer_Weapon_M2_HMG.generated.h"

class APickup;
UCLASS()
class AFSTS_Trainer_Weapon_M2_HMG : public ATraceWeapon
{
	GENERATED_BODY()
public:
	AFSTS_Trainer_Weapon_M2_HMG();

	void GiveTo(APawn* Other, APickup* Pickup);
};
