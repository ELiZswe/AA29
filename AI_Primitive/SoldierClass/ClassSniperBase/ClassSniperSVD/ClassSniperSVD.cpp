// All the original content belonged to the US Army


#include "ClassSniperSVD.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SVD_Sniper/Weapon_SVD_Sniper.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"

AClassSniperSVD::AClassSniperSVD()
{
	ClassEquipment = {
		AWeapon_SVD_Sniper::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass()
	};
	_ShortName = "SVD";
}