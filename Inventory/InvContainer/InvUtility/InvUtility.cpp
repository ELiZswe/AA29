// All the original content belonged to the US Army


#include "InvUtility.h"
#include "AA29/Inventory/DummyItem/Item_Bullseye/Item_Bullseye.h"
#include "AA29/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"


AInvUtility::AInvUtility()
{
	_iMaxCapacity = 10;
	thename = "InvUtility";
}

bool AInvUtility::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	return (p_item->IsA(AAGP_ObjectiveInventory::StaticClass()) || p_item->IsA(AItem_Bullseye::StaticClass()));
	*/
	return false;   //FAKE    ELiZ

}