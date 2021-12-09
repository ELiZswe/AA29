// All the original content belonged to the US Army


#include "PickupAmmo_127mm_10_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_127mm_10_Mag/Ammo_127mm_10_Mag.h"

APickupAmmo_127mm_10_Mag::APickupAmmo_127mm_10_Mag()
{
	InventoryType = AAmmo_127mm_10_Mag::StaticClass();
	PickupMessage = "You got an M82 sniper rifle clip.";
}