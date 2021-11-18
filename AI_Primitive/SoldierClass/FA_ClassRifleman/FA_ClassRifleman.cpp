// All the original content belonged to the US Army


#include "FA_ClassRifleman.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/FSTS_Weapon_M16A2_Rifle/FSTS_Weapon_M16A2_Rifle.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/FA_Ammo_556_30_Mag_Blanks/FA_Ammo_556_30_Mag_Blanks.h"

AFA_ClassRifleman::AFA_ClassRifleman()
{
	ClassEquipment = {
		AFSTS_Weapon_M16A2_Rifle::StaticClass(), 
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass(),
		AFA_Ammo_556_30_Mag_Blanks::StaticClass()
	};
	nativeWeapon  = EWeaponType::WEAPON_Rifle;	    //2
	_ShortName    = "FSTS_R";
}