// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassRiflemanAK/ClassRiflemanAK.h"

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK47_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_30_Mag/Ammo_762mm_30_Mag.h"

AClassRiflemanAK::AClassRiflemanAK()
{
	ClassEquipment = {
		AWeapon_AK47_Rifle::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass(),
		AAmmo_762mm_30_Mag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rifle;
	_ShortName    = "R";
}
