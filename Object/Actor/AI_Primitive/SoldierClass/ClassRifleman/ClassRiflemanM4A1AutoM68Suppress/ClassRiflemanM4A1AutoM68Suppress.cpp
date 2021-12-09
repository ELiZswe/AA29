// All the original content belonged to the US Army


#include "ClassRiflemanM4A1AutoM68Suppress.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"

AClassRiflemanM4A1AutoM68Suppress::AClassRiflemanM4A1AutoM68Suppress()
{
	ClassEquipment  = { AWeapon_M4A1_Rifle_Mod::StaticClass() };
	_ShortName      = "M4A1AutoM68Suppressed";
	WM_Override     = {
						"WeaponMod_M68_Aimpoint",
						"WeaponMod_Heatshield",
						"none",
						"none",
						"WeaponMod_Heatshield",
						"WeaponMod_M4qd_Suppressor"
					};
}