// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Weapon_RPG7_Rocket/Weapon_NPC_RPG7_Rocket/Weapon_NPC_RPG7_Rocket.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/RocketWeaponAttachment/AttachW_RPG7_Rocket/AttachW_NPC_RPG7_Rocket/AttachW_NPC_RPG7_Rocket.h"

AWeapon_NPC_RPG7_Rocket::AWeapon_NPC_RPG7_Rocket()
{
	AttachmentClass = { AAttachW_NPC_RPG7_Rocket::StaticClass() };
}

