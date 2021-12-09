// All the original content belonged to the US Army


#include "ClassRiflemanM4A1AutoIron.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"

AClassRiflemanM4A1AutoIron::AClassRiflemanM4A1AutoIron()
{
	ClassEquipment		= { AWeapon_M4A1_Rifle_Mod::StaticClass() };
	_ShortName			= "M4A1AutoIron";
	WM_Override			= { 
							"WeaponMod_Ironsight", 
							"none",
							"WeaponMod_Heatshield",
							"WeaponMod_Heatshield",
							"WeaponMod_Heatshield",
							"WeaponMod_Virtual_Cone_Suppressor" 
						};
}