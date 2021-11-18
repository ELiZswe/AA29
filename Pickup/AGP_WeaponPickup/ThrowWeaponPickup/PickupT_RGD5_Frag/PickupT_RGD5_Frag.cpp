// All the original content belonged to the US Army


#include "PickupT_RGD5_Frag.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_RGD5_Frag/Throw_RGD5_Frag.h"
#include "AA29/Pickup/AGP_WeaponPickup/ThrowWeaponPickup/PickupT_M67_Frag/PickupT_M67_Frag.h"

APickupT_RGD5_Frag::APickupT_RGD5_Frag()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-rgd-5_thrown_3p.m-rgd-5_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_RGD5_Frag::StaticClass();
	PickupMessage		= FString("You found an RGD5 Grenade.");
	EnemyPickupClass	= APickupT_M67_Frag::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_uipom2s_3P_closed.wpn2_uipom2s_3P_closed"), NULL, LOAD_None, NULL));
}