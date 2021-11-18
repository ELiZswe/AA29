// All the original content belonged to the US Army


#include "ClassJavelinTube.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M14_Incendiary/Throw_M14_Incendiary.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassJavelinTube::AClassJavelinTube()
{
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AJavelin_Tube::StaticClass(),
		AThrow_M14_Incendiary::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Javelin;
	_ShortName    = "JT";
}