// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_30mm_1_Gren.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_30mm_1_Gren/Ammo_30mm_1_Gren.h"

APickupAmmo_30mm_1_Gren::APickupAmmo_30mm_1_Gren()
{
	AmmoAmount     = 1;
	InventoryType  = AAmmo_30mm_1_Gren::StaticClass();
	PickupMessage  = "You got an 30mm Grenade.";
}
