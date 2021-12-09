// All the original content belonged to the US Army


#include "ClassSF18E.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/Weapon_M249_SAW.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassSF18E::AClassSF18E()
{
	fOriginalStrength = 54;
	ClassEquipment = {
		AWeapon_M249_SAW::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_SAW;
	_ShortName    = "18E";
}