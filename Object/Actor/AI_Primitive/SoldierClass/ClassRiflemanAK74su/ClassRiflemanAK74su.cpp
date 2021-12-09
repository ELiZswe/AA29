// All the original content belonged to the US Army


#include "ClassRiflemanAK74su.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_545mm_30_Mag/Ammo_545mm_30_Mag.h"

AClassRiflemanAK74su::AClassRiflemanAK74su()
{
	ClassEquipment = {
		AWeapon_AK74su_Rifle::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rifle;
	_ShortName    = "R";
	WM_Override   = { "WeaponMod_AKs74u_Ironsight", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Cone_Suppressor" };
}