// All the original content belonged to the US Army


#include "PickupW_GP30_Gren.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_GP30_Gren/Weapon_GP30_Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_M203_Gren/PickupW_M203_Gren.h"

APickupW_GP30_Gren::APickupW_GP30_Gren()
{
	InventoryType		= AWeapon_GP30_Gren::StaticClass();
	PickupMessage		= FString("You've found an AK47-GP30");
	EnemyPickupClass	= APickupW_M203_Gren::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-ak74_gp30_40mm_3p.m-ak74_gp30_40mm_3p"), NULL, LOAD_None, NULL));
}