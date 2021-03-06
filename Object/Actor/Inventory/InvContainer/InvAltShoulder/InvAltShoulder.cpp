// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/InvContainer/InvAltShoulder/InvAltShoulder.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_Tube.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

AInvAltShoulder::AInvAltShoulder()
{
	_iMaxCapacity = 1;
	thename = "InvAltShoulder";
}

/* ======================================================================================
 * AGP function ItemAllowable
 * Helper func that checks whether the container could contain the given item
 *
 * input:  Inventory p_item
 * output:  bool
 * notes:   Overrides InvContainer.ItemAllowable().  Now FindInventorySpace
 * is same in all InvContainers.
 * last modified by:  capps
 * ======================================================================================
 */

bool AInvAltShoulder::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	if (p_item->IsA(AJavelin_Tube::StaticClass()) && IsContainerAvailable())
	{
		return p_item->_bLarge;
	}
	else
	{
		return false;
	}
	*/
	return false;    //FAKE   /ELiZ
}

//agp:aafa [mwd] added below function to see if this container should be used at all  (02/16/05)
bool AInvAltShoulder::IsContainerAvailable()
{
	/*
	if (Cast<AAGP_Pawn>(GetOwner())->Weapon != nullptr)
	{
		return !AGP_Pawn(GetOwner())->Weapon.CheckJavelinTube();
	}
	else
	{
		return true;
	}
	*/
	return false;		//Fake /ELIZ
}
/* ======================================================================================
 * AGP function NextInventoryItem
 *
 * notes:
 *	Shouler only holds one item, so this is a no-op.
 *	Super function moves the 'current' pointer to the next
 *	in the chain.
 * last modified by: capps
 * ======================================================================================
 */
void AInvAltShoulder::NextInventoryItem()
{
}
