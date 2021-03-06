// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "FSTS_WeaponPickup.generated.h"

class AInventory;
UCLASS()
class AFSTS_WeaponPickup : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
		AFSTS_WeaponPickup();

		void SetAllowPickup(bool bAllow);
		void SetupCopy(AInventory* Copy, APawn* Other);
};
