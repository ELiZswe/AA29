// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/TraceWeapon.h"
#include "Weapon_M16A2_Rifle.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_M16A2_Rifle : public ATraceWeapon
{
	GENERATED_BODY()
public:
	AWeapon_M16A2_Rifle();

	virtual void DoChangeFireMode() override;
	virtual void PlayIdleAnim() override;
	virtual void BeginPlay() override;
};
