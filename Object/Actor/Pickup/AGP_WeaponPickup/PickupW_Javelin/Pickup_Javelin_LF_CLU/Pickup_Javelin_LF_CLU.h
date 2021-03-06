// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_Javelin/PickupW_Javelin.h"
#include "Pickup_Javelin_LF_CLU.generated.h"

class AInventory;
UCLASS()
class APickup_Javelin_LF_CLU : public APickupW_Javelin
{
	GENERATED_BODY()
public:
	APickup_Javelin_LF_CLU();
	
	UPROPERTY()		bool bCanPickUp;					//var bool bCanPickUp;

	AInventory* SpawnCopy(APawn* Other, bool bRealInventory);
	void AnnouncePickup(APawn* Receiver);
};
