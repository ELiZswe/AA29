// All the original content belonged to the US Army


#include "PickupAmmo_762mm_5_Rounds.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_5_Rounds/Ammo_762mm_5_Rounds.h"

APickupAmmo_762mm_5_Rounds::APickupAmmo_762mm_5_Rounds()
{
	AmmoAmount     = 5;
	InventoryType  = AAmmo_762mm_5_Rounds::StaticClass();
	PickupMessage  = "You found rounds for the M24.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
	DrawScale      = 1.3;
}