// All the original content belonged to the US Army


#include "InvHip.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/WEAPON_Javelin.h"

AInvHip::AInvHip()
{
	_iMaxCapacity = 1;
	thename = "InvHip";
}


bool AInvHip::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	if (p_item->IsA(AWEAPON_Javelin::StaticClass()))
	{
		return true;
	}
	*/
	return false;
}
void AInvHip::NextInventoryItem()
{
}