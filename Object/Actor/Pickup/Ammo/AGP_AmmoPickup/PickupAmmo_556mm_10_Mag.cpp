// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/Ammo/AGP_AmmoPickup/PickupAmmo_556mm_10_Mag.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_556mm_30_Mag/Ammo_556mm_10_Mag/Ammo_556mm_10_Mag.h"

APickupAmmo_556mm_10_Mag::APickupAmmo_556mm_10_Mag()
{
	AmmoAmount     = 10;
	InventoryType  = AAmmo_556mm_10_Mag::StaticClass();
}
