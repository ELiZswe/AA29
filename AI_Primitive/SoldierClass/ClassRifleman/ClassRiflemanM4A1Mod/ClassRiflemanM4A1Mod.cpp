// All the original content belonged to the US Army


#include "ClassRiflemanM4A1Mod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"

AClassRiflemanM4A1Mod::AClassRiflemanM4A1Mod()
{
	ClassEquipment  = { AWeapon_M4A1_Rifle_Mod::StaticClass() };
	_ShortName      = "M4A1Mod";
}