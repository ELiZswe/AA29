// All the original content belonged to the US Army


#include "ClassSniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M82_Sniper/Weapon_M82_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
AClassSniper::AClassSniper()
{
	ClassEquipment = {
		AWeapon_M82_Sniper::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AAmmo_127mm_10_Mag::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass()
	};
}