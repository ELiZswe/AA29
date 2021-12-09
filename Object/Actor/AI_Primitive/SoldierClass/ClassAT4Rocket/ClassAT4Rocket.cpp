// All the original content belonged to the US Army


#include "ClassAT4Rocket.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_AT4_Rocket/Weapon_AT4_Rocket.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassAT4Rocket::AClassAT4Rocket()
{
	ClassEquipment = { 
			AWeapon_M4A1_Rifle_Mod::StaticClass(), 
			AWeapon_AT4_Rocket::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AAmmo_556mm_30_Mag::StaticClass(), 
			AThrow_M67_Frag::StaticClass(), 
			AThrow_M67_Frag::StaticClass(), 
			AThrow_M67_Frag::StaticClass(), 
			AThrow_M67_Frag::StaticClass(), 
			AThrow_M83_Smoke::StaticClass(), 
			AThrow_M84_Stun::StaticClass(), 
			AThrow_M84_Stun::StaticClass() 
	};
	//MILESEquipment = "AGP_Inventory.Throw_M83_Smoke";
	nativeWeapon  = EWeaponType::WEAPON_Rocket;
	_ShortName    = "AT4";
	WM_Override   = { "WeaponMod_Ironsight", "WeaponMod_Reflex", "WeaponMod_Heatshield", "WeaponMod_Heatshield", "WeaponMod_Heatshield", "WeaponMod_Virtual_Cone_Suppressor" };
}