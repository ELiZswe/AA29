// All the original content belonged to the US Army


#include "PickupW_SVD_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_SVD_Sniper/Weapon_SVD_Sniper.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_M82_Sniper/PickupW_M82_Sniper.h"

APickupW_SVD_Sniper::APickupW_SVD_Sniper()
{
	InventoryType		= AWeapon_SVD_Sniper::StaticClass();
	PickupMessage		= FString("You found a Dragonov.");
	EnemyPickupClass	= APickupW_M82_Sniper::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	//StaticMesh			= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-dragonov_3p.m-dragonov_3p"), NULL, LOAD_None, NULL);
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-dragonov_3p.m-dragonov_3p"), NULL, LOAD_None, NULL));
}