// All the original content belonged to the US Army


#include "PickupW_FSTS_Trainer_MK19_AGL.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/ProjWeapon/FSTS_Trainer_Weapon_MK19_AGL/FSTS_Trainer_Weapon_MK19_AGL.h"

APickupW_FSTS_Trainer_MK19_AGL::APickupW_FSTS_Trainer_MK19_AGL()
{
	InventoryType	= AFSTS_Trainer_Weapon_MK19_AGL::StaticClass();
	PickupMessage	= "You are using an MK-19.";
	DrawType		= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_WeaponsFam/MK19/MK19_w-tripod.MK19_w-tripod"), NULL, LOAD_None, NULL));
}