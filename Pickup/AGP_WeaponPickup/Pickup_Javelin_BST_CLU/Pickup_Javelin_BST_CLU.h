// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "Pickup_Javelin_BST_CLU.generated.h"

/**
 * 
 */

UCLASS()
class AA29_API APickup_Javelin_BST_CLU : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	APickup_Javelin_BST_CLU();

	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)		bool bCanPickUp;				//var bool bCanPickUp;


	void SpawnCopy(APawn* Other, bool bRealInventory);
	void AnnouncePickup(APawn* Receiver);


};
