// All the original content belonged to the US Army


#include "ClassSFSniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SPR_Sniper/Weapon_SPR_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_20_Mag_SPR/Ammo_556mm_20_Mag_SPR.h"

AClassSFSniper::AClassSFSniper()
{
	ClassEquipment = {
		AWeapon_SPR_Sniper::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
	};
	nativeWeapon  = EWeaponType::WEAPON_Sniper;
	_ShortName    = "SFS";
	WM_Override   = {
						"WeaponMod_VariX_Scope",
						"none",
						"none",
						"none",
						"WeaponMod_Harris_Bipod",
						"WeaponMod_SPR_Suppressor"
					};
}