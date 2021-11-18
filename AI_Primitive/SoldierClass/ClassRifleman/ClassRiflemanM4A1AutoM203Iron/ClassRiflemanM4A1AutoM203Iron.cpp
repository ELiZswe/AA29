// All the original content belonged to the US Army


#include "ClassRiflemanM4A1AutoM203Iron.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren/Ammo_40mm_1_Gren.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
AClassRiflemanM4A1AutoM203Iron::AClassRiflemanM4A1AutoM203Iron()
{
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AAmmo_40mm_1_Gren::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass()

	};
	_ShortName	= "M4A1AutoM203Iron";
	WM_Override	= {
						"WeaponMod_Ironsight",
						"WeaponMod_Heatshield",
						"none",
						"none",
						"WeaponMod_M203_Gren",
						"WeaponMod_Virtual_Cone_Suppressor"
					};
}