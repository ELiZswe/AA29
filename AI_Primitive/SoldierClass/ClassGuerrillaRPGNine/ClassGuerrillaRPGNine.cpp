// All the original content belonged to the US Army


#include "ClassGuerrillaRPGNine.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_PG7VR_Rocket/Weapon_PG7VR_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassGuerrillaRPGNine::AClassGuerrillaRPGNine()
{
	ClassEquipment = {
		AWeapon_PG7VR_Rocket::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rocket;
	_ShortName    = "RPG9";
}