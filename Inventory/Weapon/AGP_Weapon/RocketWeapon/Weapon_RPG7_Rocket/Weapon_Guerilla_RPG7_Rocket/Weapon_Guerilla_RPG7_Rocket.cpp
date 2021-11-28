// All the original content belonged to the US Army


#include "Weapon_Guerilla_RPG7_Rocket.h"
#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/RocketWeaponPickup/PickupW_RPG7_Rocket/PickupW_Guerilla_RPG7_Rocket/PickupW_Guerilla_RPG7_Rocket.h"

AWeapon_Guerilla_RPG7_Rocket::AWeapon_Guerilla_RPG7_Rocket()
{
	PickupClass = APickupW_Guerilla_RPG7_Rocket::StaticClass();
}

EUpperBodyAnim AWeapon_Guerilla_RPG7_Rocket::GetUpperBodyLowerAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_LowerRPG_NS;
}
EUpperBodyAnim AWeapon_Guerilla_RPG7_Rocket::GetUpperBodyRaiseAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_RaiseRPG_NS;
}
EUpperBodyAnim AWeapon_Guerilla_RPG7_Rocket::GetUpperBodyReadyAnim()
{
	return EUpperBodyAnim::UBANIM_RPG_Ready_NS;
}