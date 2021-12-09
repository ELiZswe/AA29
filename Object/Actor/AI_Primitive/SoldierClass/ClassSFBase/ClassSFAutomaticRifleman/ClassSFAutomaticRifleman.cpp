// All the original content belonged to the US Army


#include "ClassSFAutomaticRifleman.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/Weapon_M249_SAW.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"

AClassSFAutomaticRifleman::AClassSFAutomaticRifleman()
{
	fOriginalStrength = 54;
	ClassEquipment = {
		AWeapon_M249_SAW::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AAmmo_556mm_200_Belt::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon     = EWeaponType::WEAPON_SAW;
	_ShortName       = "SFAR";
}