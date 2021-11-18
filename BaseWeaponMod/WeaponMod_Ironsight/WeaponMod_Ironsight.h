// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseWeaponMod/BaseWeaponMod.h"
#include "WeaponMod_Ironsight.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeaponMod_Ironsight : public ABaseWeaponMod
{
	GENERATED_BODY()
public:
	AWeaponMod_Ironsight();
	virtual void SetupScope() override;
};
