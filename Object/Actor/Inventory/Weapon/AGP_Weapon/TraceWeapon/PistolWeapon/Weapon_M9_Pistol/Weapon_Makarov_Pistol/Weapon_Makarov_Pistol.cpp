// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/Weapon_M9_Pistol/Weapon_Makarov_Pistol/Weapon_Makarov_Pistol.h"
#include "AA29/Object/Actor/InventoryAttachment/WeaponAttachment/BaseWeaponAttachment/PistolWeaponAttachment/AttachW_Makarov_Pistol/AttachW_Makarov_Pistol.h"

AWeapon_Makarov_Pistol::AWeapon_Makarov_Pistol()
{
	AttachmentClass = { AAttachW_Makarov_Pistol::StaticClass() };
}
