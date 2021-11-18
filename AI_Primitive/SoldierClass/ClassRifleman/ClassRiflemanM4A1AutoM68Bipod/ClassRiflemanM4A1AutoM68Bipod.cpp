// All the original content belonged to the US Army


#include "ClassRiflemanM4A1AutoM68Bipod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"

AClassRiflemanM4A1AutoM68Bipod::AClassRiflemanM4A1AutoM68Bipod()
{
	ClassEquipment  = { AWeapon_M4A1_Rifle_Mod::StaticClass() };
	_ShortName      = "M4A1AutoM68";
	WM_Override     = { 
						"WeaponMod_M68_Aimpoint", 
						"WeaponMod_Heatshield", 
						"none",
						"WeaponMod_Harris_Bipod",
						"WeaponMod_Virtual_Cone_Suppressor" 
						};
}