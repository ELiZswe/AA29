// All the original content belonged to the US Army


#include "PickupT_FSTS_TrainerMILESGrenade.h"
#include "AA29/Inventory/Weapon\AGP_Weapon\ThrowWeapon\Throw_M67_Frag\Throw_MILES_Grenade\Throw_MILES_Grenade.h"

APickupT_FSTS_TrainerMILESGrenade::APickupT_FSTS_TrainerMILESGrenade()
{
	InventoryType	= AThrow_MILES_Grenade::StaticClass();
	PickupMessage	= FString("You found an MILES Simulation Grenade.");
	DrawType		= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Weapons/weapons_3p/m-miles_m67_3p_group.m-miles_m67_3p_group"), NULL, LOAD_None, NULL));
}