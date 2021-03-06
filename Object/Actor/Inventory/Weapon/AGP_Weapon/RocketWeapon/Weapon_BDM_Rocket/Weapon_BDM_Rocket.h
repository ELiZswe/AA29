// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/RocketWeapon.h"
#include "Weapon_BDM_Rocket.generated.h"

UCLASS()
class AWeapon_BDM_Rocket : public ARocketWeapon
{
	GENERATED_BODY()
public:
	AWeapon_BDM_Rocket();


	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();

};
