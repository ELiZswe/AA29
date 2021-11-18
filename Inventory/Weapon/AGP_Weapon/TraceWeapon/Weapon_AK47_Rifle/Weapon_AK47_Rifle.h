// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "Weapon_AK47_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_AK47_Rifle : public ATraceWeapon
{
	GENERATED_BODY()
public:
	AWeapon_AK47_Rifle();

	virtual void DoChangeFireMode() override;
};
