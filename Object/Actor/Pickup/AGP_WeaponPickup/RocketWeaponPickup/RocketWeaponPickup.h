// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/AGP_WeaponPickup.h"
#include "RocketWeaponPickup.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class EAmmoState : uint8
{
	AMMSTATE_None           UMETA(DisplayName = "AMMSTATE_None "),
	AMMSTATE_On         UMETA(DisplayName = "AMMSTATE_On"),
	AMMSTATE_Off   UMETA(DisplayName = "AMMSTATE_Off")
};


UCLASS()
class AA29_API ARocketWeaponPickup : public AAGP_WeaponPickup
{
	GENERATED_BODY()
public:
	ARocketWeaponPickup();


	
	UPROPERTY()		EAmmoState AmmoState;					//var EAmmoState AmmoState;


	void InitDroppedPickupFor(AInventory* Inv, bool bFreeze);
	void IsReplicationComplete();
	void NotifyReplicationComplete();
	void SwapAmmoRound();
	void MaybeSetStaticMesh();

};



