// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_M240b.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/FSTS_Trainer_Weapon_M249_Saw/FSTS_Trainer_Weapon_M240b/FSTS_Trainer_Weapon_M240b.h"

APickupW_FSTS_Trainer_M240b::APickupW_FSTS_Trainer_M240b()
{
	InventoryType		= AFSTS_Trainer_Weapon_M240b::StaticClass();
	PickupMessage		= FString("You are using an M240B.");
	DrawType			= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_WeaponsFam/M240B/M240B.M240B"), NULL, LOAD_None, NULL));
}