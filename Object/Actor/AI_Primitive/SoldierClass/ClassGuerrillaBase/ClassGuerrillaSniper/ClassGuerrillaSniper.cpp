// All the original content belonged to the US Army


#include "ClassGuerrillaSniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_Vintorez_Sniper/Weapon_Vintorez_Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x39_10_Mag/Ammo_9x39_10_Mag.h"

AClassGuerrillaSniper::AClassGuerrillaSniper()
{
	ClassEquipment = {
		AWeapon_Vintorez_Sniper::StaticClass(),
		AAmmo_9x39_10_Mag::StaticClass(),
		AAmmo_9x39_10_Mag::StaticClass(),
		AAmmo_9x39_10_Mag::StaticClass(),
		AAmmo_9x39_10_Mag::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Sniper;	    //4
	_ShortName    = "GS";
	WM_Override   = {
						"WeaponMod_Vintorez_Scope", 
						"none",
						"none",
						"WeaponMod_Virtual_Harris_Bipod",
						"WeaponMod_Virtual_SPR_Suppressor"
					};
}