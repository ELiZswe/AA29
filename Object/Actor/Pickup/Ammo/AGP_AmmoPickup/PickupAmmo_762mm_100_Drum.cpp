// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_100_Drum.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_100_Drum/Ammo_762mm_100_Drum.h"

APickupAmmo_762mm_100_Drum::APickupAmmo_762mm_100_Drum()
{
	AmmoAmount     = 100;
	InventoryType  = AAmmo_762mm_100_Drum::StaticClass();
	PickupMessage  = "You found an RPK magazine.";
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
}
