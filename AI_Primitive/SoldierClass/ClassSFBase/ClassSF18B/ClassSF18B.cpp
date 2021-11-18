// All the original content belonged to the US Army


#include "ClassSF18B.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"

AClassSF18B::AClassSF18B()
{
	fOriginalStrength = 54;
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};


	nativeWeapon  = EWeaponType::WEAPON_Rifle;	    //2
	_ShortName    = "18B";
	WM_Override   = {
						"WeaponMod_Acog4x",
						"WeaponMod_Heatshield",
						"none",
						"none",
						"WeaponMod_Harris_Bipod",
						"WeaponMod_M4qd_Suppressor"
					};
}


void AClassSF18B::addClassInventory(bool bMaybeSkip)
{
	Super::addClassInventory(bMaybeSkip);
}