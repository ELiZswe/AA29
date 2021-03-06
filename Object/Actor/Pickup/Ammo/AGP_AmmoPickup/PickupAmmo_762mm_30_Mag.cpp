// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_762mm_30_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_762mm_30_Mag/Ammo_762mm_30_Mag.h"

APickupAmmo_762mm_30_Mag::APickupAmmo_762mm_30_Mag()
{
	AmmoAmount     = 30;
	InventoryType  = AAmmo_762mm_30_Mag::StaticClass();
	PickupMessage  = "You got an AK-47 banana clip.";
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AA2_Weapons/CLips/m24_ammo_box.m24_ammo_box"), NULL, LOAD_None, NULL));
}
