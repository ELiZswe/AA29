// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "Pickup_Javelin_BST_Tube.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickup_Javelin_BST_Tube : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	APickup_Javelin_BST_Tube();

	
	UPROPERTY()		bool bCanPickUp;					//var bool bCanPickUp;

};
