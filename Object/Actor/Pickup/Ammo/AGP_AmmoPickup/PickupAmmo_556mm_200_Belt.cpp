// All the original content belonged to the US Army


#include "PickupAmmo_556mm_200_Belt.h"
#include "AA29/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_200_Belt/Ammo_556mm_200_Belt.h"

APickupAmmo_556mm_200_Belt::APickupAmmo_556mm_200_Belt()
{
	AmmoAmount     = 200;
	InventoryType  = AAmmo_556mm_200_Belt::StaticClass();
	PickupMessage  = "You got an M249 bullet box.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m249_ammo_3p.m249_ammo_3p"), NULL, LOAD_None, NULL));
}