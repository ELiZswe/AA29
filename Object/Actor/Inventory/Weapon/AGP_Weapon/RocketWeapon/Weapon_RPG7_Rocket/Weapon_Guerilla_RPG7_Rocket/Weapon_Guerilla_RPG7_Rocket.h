// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_RPG7_Rocket.h"
#include "Weapon_Guerilla_RPG7_Rocket.generated.h"

UCLASS()
class AWeapon_Guerilla_RPG7_Rocket : public AWeapon_RPG7_Rocket
{
	GENERATED_BODY()
public:
	AWeapon_Guerilla_RPG7_Rocket();


	EUpperBodyAnim GetUpperBodyLowerAnim();
	EUpperBodyAnim GetUpperBodyRaiseAnim();
	EUpperBodyAnim GetUpperBodyReadyAnim();

};
