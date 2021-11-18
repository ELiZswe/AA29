// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/SniperRifle.h"
#include "Weapon_M82_Sniper.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M82_Sniper : public ASniperRifle
{
	GENERATED_BODY()
public:
	AWeapon_M82_Sniper();

	virtual void PlayFiring() override;
};
