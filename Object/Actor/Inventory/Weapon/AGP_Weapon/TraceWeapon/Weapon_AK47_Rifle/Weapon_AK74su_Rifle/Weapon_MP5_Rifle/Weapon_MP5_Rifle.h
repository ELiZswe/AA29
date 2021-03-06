// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"
#include "Weapon_MP5_Rifle.generated.h"

UCLASS()
class AWeapon_MP5_Rifle : public AWeapon_AK74su_Rifle
{
	GENERATED_BODY()
public:
	AWeapon_MP5_Rifle();

	bool ShouldDoDelayedEject();
	void DiscardShell();

};
