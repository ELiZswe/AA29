// All the original content belonged to the US Army


#include "PickupAmmo_RPG7_PG7VR.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_PG7VR_Rocket/Ammo_PG7VR_Rocket.h"

APickupAmmo_RPG7_PG7VR::APickupAmmo_RPG7_PG7VR()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_PG7VR_Rocket::StaticClass();
	PickupMessage  = "You found a PG7VR round for the RPG7.";
	DrawType       = EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
}