// All the original content belonged to the US Army


#include "ClassGrenadier.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_40mm_1_Gren/Ammo_40mm_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"
AClassGrenadier::AClassGrenadier()
{
	ClassEquipment = {
		AWeapon_M203_Gren::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
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
	nativeWeapon  = EWeaponType::WEAPON_Gren;
	_ShortName    = "G";
}