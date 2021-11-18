// All the original content belonged to the US Army


#include "InvHolster.h"
#include "AA29/Inventory/Weapon/AGP_Weapon/TraceWeapon/PistolWeapon/PistolWeapon.h"

AInvHolster::AInvHolster()
{
	_iMaxCapacity = 1;
	thename = "InvHolster";
}

bool AInvHolster::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	return p_item->IsA(APistolWeapon::StaticClass());
	*/
	return false;  //FAKE /ELiZ
}