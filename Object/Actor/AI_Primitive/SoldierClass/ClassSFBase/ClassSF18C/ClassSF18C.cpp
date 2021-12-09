// All the original content belonged to the US Army


#include "ClassSF18C.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren_Mod/Ammo_40mm_1_Gren_Mod.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"

AClassSF18C::AClassSF18C()
{
	fOriginalStrength = 54;
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AThrow_M14_Incendiary::StaticClass(),
		AThrow_M14_Incendiary::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AAmmo_40mm_1_Gren_Mod::StaticClass(),
		AAmmo_40mm_1_Gren_Mod::StaticClass(),
		AAmmo_40mm_1_Gren_Mod::StaticClass(),
		AAmmo_40mm_1_Gren_Mod::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Gren;
	_ShortName    = "18C";
	WM_Override   = {
						"WeaponMod_Ironsight",
						"WeaponMod_Reflex",
						"none",
						"none",
						"WeaponMod_M203_Gren", 
						"none"
					};
}