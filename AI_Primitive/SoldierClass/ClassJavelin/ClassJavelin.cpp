// All the original content belonged to the US Army


#include "ClassJavelin.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M4A1_Rifle_Mod/Weapon_M4A1_Rifle_Mod.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_30_Mag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"

AClassJavelin::AClassJavelin()
{
	ClassEquipment = {
		AWeapon_M4A1_Rifle_Mod::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AAmmo_556mm_30_Mag::StaticClass(),
		AWEAPON_Javelin::StaticClass(),
		AJavelin_Tube::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Javelin;
	_ShortName    = "J";
}