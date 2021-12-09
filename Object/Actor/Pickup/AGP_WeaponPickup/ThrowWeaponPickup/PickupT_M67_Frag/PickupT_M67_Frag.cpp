// All the original content belonged to the US Army


#include "PickupT_M67_Frag.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_RGD5_Frag/PickupT_RGD5_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"

APickupT_M67_Frag::APickupT_M67_Frag()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m67_thrown_3p.m-m67_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_M67_Frag::StaticClass();
	PickupMessage		= FString("You found an M67 Frag Grenade.");
	EnemyPickupClass	= APickupT_RGD5_Frag::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m67_3p.m-m67_3p"), NULL, LOAD_None, NULL));
}