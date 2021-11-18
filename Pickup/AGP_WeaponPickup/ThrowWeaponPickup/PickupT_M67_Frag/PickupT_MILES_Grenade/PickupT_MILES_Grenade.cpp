// All the original content belonged to the US Army


#include "PickupT_MILES_Grenade.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"

APickupT_MILES_Grenade::APickupT_MILES_Grenade()
{
	liveStaticMesh		= LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-miles_m67_thrown_3p.m-miles_m67_thrown_3p"), NULL, LOAD_None, NULL);
	InventoryType		= AThrow_MILES_Grenade::StaticClass();
	PickupMessage		= FString("You found an MILES Simulation Grenade.");
	EnemyPickupClass	= APickupT_MILES_Grenade::StaticClass();
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-miles_m67_3p.m-miles_m67_3p"), NULL, LOAD_None, NULL));
}