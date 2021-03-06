// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "AA29/MyEnums.h"
#include "RocketWeaponPickup.generated.h"

class AInventory;
UCLASS()
class ARocketWeaponPickup : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	ARocketWeaponPickup();
	
	UPROPERTY()		EAmmoState AmmoState;					//var EAmmoState AmmoState;

	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	bool IsReplicationComplete();
	void NotifyReplicationComplete();
	void SwapAmmoRound();
	bool MaybeSetStaticMesh();
};



