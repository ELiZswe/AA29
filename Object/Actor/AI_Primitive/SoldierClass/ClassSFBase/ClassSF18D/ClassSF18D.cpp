// All the original content belonged to the US Army


#include "ClassSF18D.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AClassSF18D::AClassSF18D()
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
	nativeWeapon  = EWeaponType::WEAPON_Rifle;
	_ShortName    = "18D";
	WM_Override   = {
						"WeaponMod_Ironsight",
						"WeaponMod_Reflex",
						"none",
						"none",
						"none",
						"none"
					};
}

void AClassSF18D::addClassInventory(bool bMaybeSkip)
{
	addClassInventory(bMaybeSkip);
	Cast<AAGP_Pawn>(myPawn)->_InvMedPacks = 6;
	Cast<AAGP_Pawn>(myPawn)->_InvSelfHealMedPacks = 1;
	Cast<AAGP_Pawn>(myPawn)->fHealDivisor *= 2;
}