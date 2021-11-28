// All the original content belonged to the US Army


#include "PickupW_M249_SAW.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/Weapon_M249_SAW.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_RPK_SAW/PickupW_RPK_SAW.h"

APickupW_M249_SAW::APickupW_M249_SAW()
{
	InventoryType		= AWeapon_M249_SAW::StaticClass();
	PickupMessage		= FString("You found an M249 SAW.");
	EnemyPickupClass	= APickupW_RPK_SAW::StaticClass();
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m249_3p.m-m249_3p"), NULL, LOAD_None, NULL));
}