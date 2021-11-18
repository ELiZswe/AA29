// All the original content belonged to the US Army


#include "ClassGrenadierGP30_Op.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_GP30_Gren/Weapon_GP30_Gren.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_30_Mag/Ammo_762mm_30_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_30mm_1_Gren/Ammo_30mm_1_Gren.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassGrenadierGP30_Op::AClassGrenadierGP30_Op()
{
	ClassEquipment = {
		AWeapon_GP30_Gren::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AAmmo_30mm_1_Gren::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass()
	};
	nativeWeapon   = EWeaponType::WEAPON_Gren;
	_ShortName     = "GP";
}