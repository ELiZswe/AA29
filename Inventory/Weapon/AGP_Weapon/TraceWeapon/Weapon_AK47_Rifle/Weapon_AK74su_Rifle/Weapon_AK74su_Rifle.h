// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK47_Rifle.h"
#include "Weapon_AK74su_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_AK74su_Rifle : public AWeapon_AK47_Rifle
{
	GENERATED_BODY()
public:
	AWeapon_AK74su_Rifle();

	bool ShouldDoDelayedEject();
	void DiscardShell();

};
