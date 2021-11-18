// All the original content belonged to the US Army


#include "InvShoulder.h"

#include "AA29/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"

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