// All the original content belonged to the US Army


#include "ClassPistol.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"

AClassPistol::AClassPistol()
{
	ClassEquipment = {
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Pistol;
	_ShortName    = "P";
}