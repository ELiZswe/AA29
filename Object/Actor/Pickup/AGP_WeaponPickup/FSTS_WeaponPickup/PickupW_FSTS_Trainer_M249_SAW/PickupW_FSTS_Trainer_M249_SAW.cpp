// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_M249_SAW.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M249_SAW/FSTS_Trainer_Weapon_M249_Saw/FSTS_Trainer_Weapon_M249_Saw.h"

APickupW_FSTS_Trainer_M249_SAW::APickupW_FSTS_Trainer_M249_SAW()
{
	InventoryType         = AFSTS_Trainer_Weapon_M249_Saw::StaticClass();
	PickupMessage         = FString("You are using an M249 SAW.");
	DrawType              = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m249_sup_3p.m-m249_sup_3p"), NULL, LOAD_None, NULL));
	LandedRotationOffset  = FRotator(3.22998046875, 0, 0);
}