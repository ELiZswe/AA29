// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "Weapon_RPG7_Rocket.generated.h"

UCLASS()
class AWeapon_RPG7_Rocket : public ARocketWeapon
{
	GENERATED_BODY()
public:
	AWeapon_RPG7_Rocket();

	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();

};
