// All the original content belonged to the US Army


#include "Classrpg.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_RPG7_Rocket.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_RPG7_PG7B/Ammo_RPG7_PG7B.h"
AClassrpg::AClassrpg()
{
	ClassEquipment = {
		AWeapon_RPG7_Rocket::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AAmmo_RPG7_PG7B::StaticClass(),
		AAmmo_RPG7_PG7B::StaticClass(),
		AAmmo_RPG7_PG7B::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rocket;
	_ShortName    = "RPG7";
}