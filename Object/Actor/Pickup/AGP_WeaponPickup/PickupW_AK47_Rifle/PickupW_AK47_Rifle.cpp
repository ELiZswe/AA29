// All the original content belonged to the US Army


#include "PickupW_AK47_Rifle.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_AK47_Rifle/Weapon_AK47_Rifle.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M16A2_Rifle/PickupW_M16A2_Rifle.h"

APickupW_AK47_Rifle::APickupW_AK47_Rifle()
{
	InventoryType		= AWeapon_AK47_Rifle::StaticClass();
	PickupMessage		= FString("You found an AK-47.");
	EnemyPickupClass	= APickupW_M16A2_Rifle::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-ak47_3p.m-ak47_3p"), NULL, LOAD_None, NULL));
}