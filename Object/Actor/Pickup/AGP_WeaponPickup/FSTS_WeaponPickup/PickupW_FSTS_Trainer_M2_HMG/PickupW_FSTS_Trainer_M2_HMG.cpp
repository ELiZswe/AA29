// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_M2_HMG.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/FSTS_Trainer_Weapon_M2_HMG/FSTS_Trainer_Weapon_M2_HMG.h"

APickupW_FSTS_Trainer_M2_HMG::APickupW_FSTS_Trainer_M2_HMG()
{
	InventoryType	= AFSTS_Trainer_Weapon_M2_HMG::StaticClass();
	PickupMessage	= FString("You are using an M2 HMG.");
	DrawType		= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_WeaponsFam/M2/M2_w_tripod.M2_w_tripod"), NULL, LOAD_None, NULL));
}