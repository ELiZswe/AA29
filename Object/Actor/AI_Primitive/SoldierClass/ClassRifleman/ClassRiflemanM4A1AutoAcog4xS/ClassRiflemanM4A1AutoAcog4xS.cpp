// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRifleman/ClassRiflemanM4A1AutoAcog4xS/ClassRiflemanM4A1AutoAcog4xS.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"

AClassRiflemanM4A1AutoAcog4xS::AClassRiflemanM4A1AutoAcog4xS()
{
	ClassEquipment	= { AWeapon_M4A1_Rifle_Mod::StaticClass() };
	_ShortName		= "M4A1Auto4x";
	WM_Override		= {
						"WeaponMod_Acog4x",
						"WeaponMod_Heatshield",
						"none",
						"none",
						"WeaponMod_Harris_Bipod",
						"WeaponMod_M4qd_Suppressor"
					};
}
