// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "Weapon_AT4_Rocket.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AWeapon_AT4_Rocket : public ARocketWeapon
{
	GENERATED_BODY()
public:
	AWeapon_AT4_Rocket();

	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();
};
