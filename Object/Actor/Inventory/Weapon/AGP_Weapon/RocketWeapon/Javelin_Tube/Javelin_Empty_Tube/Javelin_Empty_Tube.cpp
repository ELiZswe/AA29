// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Empty_Tube/Javelin_Empty_Tube.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Empty_Tube/Pickup_Empty_Tube.h"

AJavelin_Empty_Tube::AJavelin_Empty_Tube()
{
	PickupClass = APickup_Empty_Tube::StaticClass();
}
