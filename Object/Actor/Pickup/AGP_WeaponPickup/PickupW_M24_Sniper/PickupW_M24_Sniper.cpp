// All the original content belonged to the US Army


#include "PickupW_M24_Sniper.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/SniperRifle/Weapon_M24_Sniper/Weapon_M24_Sniper.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_MosinNagant_Sniper/PickupW_MosinNagant_Sniper.h"

APickupW_M24_Sniper::APickupW_M24_Sniper()
{
	InventoryType		= AWeapon_M24_Sniper::StaticClass();
	PickupMessage		= FString("You found an M24 Sniper Rifle.");
	EnemyPickupClass	= APickupW_MosinNagant_Sniper::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m24_3p.m-m24_3p"), NULL, LOAD_None, NULL));
}