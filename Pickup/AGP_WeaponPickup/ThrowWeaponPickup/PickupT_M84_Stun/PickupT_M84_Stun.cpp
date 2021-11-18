// All the original content belonged to the US Army


#include "PickupT_M84_Stun.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M84_Stun/Throw_M84_Stun.h"

APickupT_M84_Stun::APickupT_M84_Stun()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-flashbang_3p.m-flashbang_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_M84_Stun::StaticClass();
	PickupMessage		= FString("You found an FlashBang Grenade.");
	EnemyPickupClass	= APickupT_M84_Stun::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-flashbang_3p.m-flashbang_3p"), NULL, LOAD_None, NULL));
	PrePivot			= FVector(0, 0, 3);
}
/*
void APickupT_M84_Stun::StaticPrecache(LevelInfo L)
{
	L.AddPrecacheMaterial(Texture'skn_weap_flashbang');
	StaticPrecache(L);
}
*/