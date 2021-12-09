// All the original content belonged to the US Army


#include "PickupAmmo_12gauge_7_Rounds.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_12gauge_7_Rounds/Ammo_12gauge_7_Rounds.h"

APickupAmmo_12gauge_7_Rounds::APickupAmmo_12gauge_7_Rounds()
{
	AmmoAmount     = 7;
	InventoryType  = AAmmo_12gauge_7_Rounds::StaticClass();
	PickupMessage  = "You found rounds for the M870.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
	DrawScale      = 1.3;
}
