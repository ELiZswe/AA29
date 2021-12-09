// All the original content belonged to the US Army


#include "PickupT_FSTS_Trainer_M67_Frag.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ThrowWeapon/Throw_M67_Frag/Throw_M67_Frag.h"

APickupT_FSTS_Trainer_M67_Frag::APickupT_FSTS_Trainer_M67_Frag()
{
	InventoryType	= AThrow_M67_Frag::StaticClass();
	PickupMessage	= "You found an M67 Frag Grenade.";
	DrawType		= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/meshes/M_AA2_Weapons/weapons_3p/m-m67_3p.m-m67_3p"), NULL, LOAD_None, NULL));
}
