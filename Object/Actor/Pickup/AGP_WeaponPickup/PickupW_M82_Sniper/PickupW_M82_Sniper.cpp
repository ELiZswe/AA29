// All the original content belonged to the US Army


#include "PickupW_M82_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M82_Sniper/Weapon_M82_Sniper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_SVD_Sniper/PickupW_SVD_Sniper.h"

APickupW_M82_Sniper::APickupW_M82_Sniper()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_M82_Sniper::StaticClass();
	PickupMessage			= FString("You found an M82 Barrett Sniper Rifle.");
	EnemyPickupClass		= APickupW_SVD_Sniper::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m82a1_3p.m-m82a1_3p"), NULL, LOAD_None, NULL));
}