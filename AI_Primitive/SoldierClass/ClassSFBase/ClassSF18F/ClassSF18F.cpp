// All the original content belonged to the US Army


#include "ClassSF18F.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_20_Mag_SPR/Ammo_556mm_20_Mag_SPR.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SPR_Sniper/Weapon_SPR_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
AClassSF18F::AClassSF18F()
{
	fOriginalStrength = 54;
	ClassEquipment = {
		AWeapon_SPR_Sniper::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AAmmo_556mm_20_Mag_SPR::StaticClass(),
		AThrow_M14_Incendiary::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Sniper;
	_ShortName    = "18F";
	WM_Override   = {
						"WeaponMod_VariX_Scope",
						"none",
						"none",
						"none",
						"WeaponMod_Harris_Bipod",
						"WeaponMod_SPR_Suppressor"
					};
}