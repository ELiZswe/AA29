// All the original content belonged to the US Army


#include "PickupW_MosinNagant_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_MosinNagant_Sniper/Weapon_MosinNagant_Sniper.h"
#include "AA29/Pickup/AGP_WeaponPickup/PickupW_M24_Sniper/PickupW_M24_Sniper.h"

APickupW_MosinNagant_Sniper::APickupW_MosinNagant_Sniper()
{
	CollisionHeightDropped	= 4;
	InventoryType			= AWeapon_MosinNagant_Sniper::StaticClass();
	PickupMessage			= FString("You found a Mosin Nagant Sniper Rifle.");
	EnemyPickupClass		= APickupW_M24_Sniper::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-mosin_nagant_sniper_rifle_3p.m-mosin_nagant_sniper_rifle_3p"), NULL, LOAD_None, NULL));
}