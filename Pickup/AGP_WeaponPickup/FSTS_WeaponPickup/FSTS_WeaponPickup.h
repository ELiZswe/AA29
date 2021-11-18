// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "FSTS_WeaponPickup.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AFSTS_WeaponPickup : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
		AFSTS_WeaponPickup();

		UPROPERTY(EditAnywhere, BlueprintReadWrite)		int32 PickupAmmo;									//var() int PickupAmmo;
		UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bAllowPickup;									//var() bool bAllowPickup;

		void SetAllowPickup(bool bAllow);
		void SetupCopy(AInventory* Copy, APawn* Other);
};
