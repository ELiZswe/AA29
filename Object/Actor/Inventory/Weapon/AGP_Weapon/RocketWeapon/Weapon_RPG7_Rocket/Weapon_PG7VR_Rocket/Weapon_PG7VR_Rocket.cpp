// All the original content belonged to the US Army


#include "Weapon_PG7VR_Rocket.h"
#include "AA29/Object/Actor/BaseAmmoRound/AmmoRound_PG7VR_Rocket.h"
#include "AA29/Object/Actor/Inventory/Ammunition/AGP_Ammunition/Ammo_PG7VR_Rocket/Ammo_PG7VR_Rocket.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_PG7VR_Rocket/PickupW_PG7VR_Rocket.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_PG7VR_Rocket/AttachW_PG7VR_Rocket.h"

AWeapon_PG7VR_Rocket::AWeapon_PG7VR_Rocket()
{
	MaxClips         = 3;
	AmmoRoundClass   = AAmmoRound_PG7VR_Rocket::StaticClass();
	AmmoName         = AAmmo_PG7VR_Rocket::StaticClass();
	PickupClass      = APickupW_PG7VR_Rocket::StaticClass();
	AttachmentClass  = { AAttachW_PG7VR_Rocket::StaticClass() };
	ItemName         = "RGP7_PG7VR";
}