// All the original content belonged to the US Army


#include "ClassSniper24_US.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"

AClassSniper24_US::AClassSniper24_US()
{
	ClassEquipment = {
		AWeapon_M24_Sniper::StaticClass(),
		AWeapon_M9_Pistol::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AAmmo_762mm_5_Rounds::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AThrow_M83_Smoke::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass(),
		AAmmo_9x19mm_15_Mag::StaticClass()
	};
}