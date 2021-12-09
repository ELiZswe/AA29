// All the original content belonged to the US Army


#include "PickupW_M2_HMG.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/FixedWeapon/Weapon_M2_HMG/Weapon_M2_HMG.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_AK47_Rifle/PickupW_AK47_Rifle.h"

APickupW_M2_HMG::APickupW_M2_HMG()
{
	InventoryType		= AWeapon_M2_HMG::StaticClass();
	PickupMessage		= FString("You found an M2 Heavy Machine Gun!");
	EnemyPickupClass	= APickupW_AK47_Rifle::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
}