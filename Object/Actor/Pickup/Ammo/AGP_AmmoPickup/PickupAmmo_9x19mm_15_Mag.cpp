// All the original content belonged to the US Army


#include "PickupAmmo_9x19mm_15_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_9x19mm_15_Mag/Ammo_9x19mm_15_Mag.h"

APickupAmmo_9x19mm_15_Mag::APickupAmmo_9x19mm_15_Mag()
{
	AmmoAmount     = 15;
	InventoryType  = AAmmo_9x19mm_15_Mag::StaticClass();
	PickupMessage  = "You found a 15 round Mag for the M9.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
}