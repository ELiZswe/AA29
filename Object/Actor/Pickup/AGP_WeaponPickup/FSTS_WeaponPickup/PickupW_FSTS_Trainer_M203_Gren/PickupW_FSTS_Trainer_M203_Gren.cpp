// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_M203_Gren.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/Weapon_M16A2_Rifle/Weapon_M203_Gren/FSTS_Trainer_Weapon_M203_Gren/FSTS_Trainer_Weapon_M203_Gren.h"

APickupW_FSTS_Trainer_M203_Gren::APickupW_FSTS_Trainer_M203_Gren()
{
	InventoryType			= AFSTS_Trainer_Weapon_M203_Gren::StaticClass();
	PickupMessage			= FString("You are using an M203 Grenade Launcher.");
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/m-m16a2_m203_3p.m-m16a2_m203_3p"), NULL, LOAD_None, NULL));
	LandedRotationOffset	= FRotator(0, 0, 90);
}