// All the original content belonged to the US Army


#include "ClassGuerrillaRPG.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_Guerilla_RPG7_Rocket/Weapon_Guerilla_RPG7_Rocket.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_RPG7_PG7B/Ammo_RPG7_PG7B.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"

AClassGuerrillaRPG::AClassGuerrillaRPG()
{
	ClassEquipment = {
		AWeapon_Guerilla_RPG7_Rocket::StaticClass(),
		AAmmo_RPG7_PG7B::StaticClass(),
		AAmmo_RPG7_PG7B::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rocket;
	_ShortName    = "GRPG";
}