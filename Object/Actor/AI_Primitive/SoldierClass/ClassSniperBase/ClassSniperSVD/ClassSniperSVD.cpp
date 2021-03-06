// All the original content belonged to the US Army

#include "AA29/Object/Actor/AI_Primitive/SoldierClass/ClassSniperBase/ClassSniperSVD/ClassSniperSVD.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SVD_Sniper/Weapon_SVD_Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"

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
