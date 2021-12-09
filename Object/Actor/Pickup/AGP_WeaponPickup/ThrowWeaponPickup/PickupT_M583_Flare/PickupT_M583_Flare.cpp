// All the original content belonged to the US Army


#include "PickupT_M583_Flare.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M583_Flare/Throw_M583_Flare.h"

APickupT_M583_Flare::APickupT_M583_Flare()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_thrown_3p.wpn_m14th3_incen_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_M583_Flare::StaticClass();
	PickupMessage		= FString("You found an M583 Flare Grenade.");
	EnemyPickupClass	= APickupT_M583_Flare::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn_m14th3_incen_3p.wpn_m14th3_incen_3p"), NULL, LOAD_None, NULL));
	PrePivot			= FVector(0, 0, 3);
}