// All the original content belonged to the US Army


#include "ClassSniperMos.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M83_Smoke/Throw_M83_Smoke.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_MosinNagant_Sniper/Weapon_MosinNagant_Sniper.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"

AClassSniperMos::AClassSniperMos()
{
	ClassEquipment = {
		AWeapon_MosinNagant_Sniper::StaticClass(),
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
	};
}