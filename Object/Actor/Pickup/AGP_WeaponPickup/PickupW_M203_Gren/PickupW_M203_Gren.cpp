// All the original content belonged to the US Army


#include "PickupW_M203_Gren.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/Weapon_M203_Gren.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_GP30_Gren/PickupW_GP30_Gren.h"

APickupW_M203_Gren::APickupW_M203_Gren()
{
	InventoryType		= AWeapon_M203_Gren::StaticClass();
	PickupMessage		= FString("You found an M203 Assault Rifle.");
	EnemyPickupClass	= APickupW_GP30_Gren::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m16a2_m203_3p.m-m16a2_m203_3p"), NULL, LOAD_None, NULL));
}