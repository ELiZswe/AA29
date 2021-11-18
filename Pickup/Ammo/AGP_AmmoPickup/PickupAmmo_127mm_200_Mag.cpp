// All the original content belonged to the US Army


#include "PickupAmmo_127mm_200_Mag.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_200_Mag/Ammo_127mm_200_Mag.h"

APickupAmmo_127mm_200_Mag::APickupAmmo_127mm_200_Mag()
{
	AmmoAmount     = 200;
	InventoryType  = AAmmo_127mm_200_Mag::StaticClass();
	PickupMessage  = "You got an M2 bullet box.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m249_ammo_3p.m249_ammo_3p"), NULL, LOAD_None, NULL));
}