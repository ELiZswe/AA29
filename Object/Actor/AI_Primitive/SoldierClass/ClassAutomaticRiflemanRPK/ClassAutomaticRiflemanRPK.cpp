// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassAutomaticRiflemanRPK/ClassAutomaticRiflemanRPK.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_RPK_SAW/Weapon_RPK_SAW.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_100_Drum/Ammo_762mm_100_Drum.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"

AClassAutomaticRiflemanRPK::AClassAutomaticRiflemanRPK()
{
	fOriginalStrength  = 54;
	ClassEquipment     = {
		AWeapon_RPK_SAW::StaticClass(),
		AAmmo_762mm_100_Drum::StaticClass(),
		AAmmo_762mm_100_Drum::StaticClass(),
		AAmmo_762mm_100_Drum::StaticClass(),
		AAmmo_762mm_100_Drum::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};
	nativeWeapon       = EWeaponType::WEAPON_SAW; //3
	_ShortName         = "RPK";
}
