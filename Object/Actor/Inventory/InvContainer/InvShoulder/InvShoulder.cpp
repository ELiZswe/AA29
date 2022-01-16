// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/InvContainer/InvShoulder/InvShoulder.h"

#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"

AInvShoulder::AInvShoulder()
{
	_iMaxCapacity = 1;
	thename = "InvShoulder";
}

bool AInvShoulder::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	if (p_item->IsA(AJavelin_Tube::StaticClass()))
	{
		return false;
	}
	if (p_item->IsA(AWeapon::StaticClass()))
	{
		return p_item->_bLarge;
	}
	*/
	return false;
}
void AInvShoulder::NextInventoryItem()
{
}
