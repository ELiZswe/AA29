// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassGuerrillaBase/ClassGuerrillaAK74su/ClassGuerrillaAK74su.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK74su_Rifle/Weapon_AK74su_Rifle.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_545mm_30_Mag/Ammo_545mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

AClassGuerrillaAK74su::AClassGuerrillaAK74su()
{
	ClassEquipment = {
		AWeapon_AK74su_Rifle::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AAmmo_545mm_30_Mag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M84_Stun::StaticClass(),
		AThrow_M67_Frag::StaticClass(),
		AThrow_M67_Frag::StaticClass()
	};

	nativeWeapon  = EWeaponType::WEAPON_Rifle;	    //2
	_ShortName    = "GAK";
	WM_Override   = { "WeaponMod_AKs74u_Ironsight", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Virtual_Heatshield", "WeaponMod_Cone_Suppressor" };
}
