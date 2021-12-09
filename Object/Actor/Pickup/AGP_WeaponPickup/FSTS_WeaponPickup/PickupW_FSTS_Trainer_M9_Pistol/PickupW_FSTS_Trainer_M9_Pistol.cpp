// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_M9_Pistol.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/FSTS_Weapon_M9_Pistol/FSTS_Weapon_M9_Pistol.h"

APickupW_FSTS_Trainer_M9_Pistol::APickupW_FSTS_Trainer_M9_Pistol()
{
	InventoryType			= AFSTS_Weapon_M9_Pistol::StaticClass();
	PickupMessage			= FString("You are using an M9 Pistol.");
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/weapons_3p/wpn2_m9_beretta_3p.wpn2_m9_beretta_3p"), NULL, LOAD_None, NULL));
	LandedRotationOffset	= FRotator(0, 0, 90);
}