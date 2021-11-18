// All the original content belonged to the US Army


#include "InvHands.h"
#include "AA29/Inventory/Weapon/Weapon.h"

AInvHands::AInvHands()
{
	_iMaxCapacity = 1;
	thename = "InvHands";
}


// helper func that checks whether the container has space for the given item
// overrides InvContainer because HandsOnly items are legal here
bool AInvHands::FindInventorySpace(TSubclassOf<AInventory> p_item)
{
	
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory) 
	{
		//Log("InvHands: itemallowable is "$ItemAllowable(p_item));
		//Log("InvHands: isfull is "$isFull());
	}
	//return (ItemAllowable(p_item) && !(isFull()));
	return false;			//Fake / ELIZ
}

bool AInvHands::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	/*
	//agp:aafa [mwd] added below if statement to check if container should be used at all (02/24/05)
	if (!IsContainerAvailable(p_item))
	{
		return false;
	}
	else
	{
		return p_item->IsA(AWeapon::StaticClass());
	}
	*/
	return false; //FAKE /ELiZ
}

//agp:aafa [mwd] added below function to see if this container should be used at all  (02/24/05)
bool AInvHands::IsContainerAvailable(TSubclassOf<AInventory> p_item)
{
	/*
	//this container is not available if you are picking up a loaded
	//javelin AND you already have a javelin tube
	if (!p_item.IsA('Weapon_Javelin'))
	{
		return true;
	}
	else if (!AGP_Pawn(Owner).getInvContainerAltShoulder().isEmpty())
	{
		if (AGP_Weapon(p_item).AmmoType == None)
		{
			return true;
		}
		else if (AGP_Weapon(p_item).AmmoType.AmmoAmount > 0)
		{
			return false;
		}
	}
	return true;
	*/
	return false;			//Fake / ELIZ
}

// =====================================================
// AGP function NextInventoryItem
//
// Hands only hold one item, so this is a no-op.
// Super function moves the 'current' pointer to the next
// in the chain.
//
// by:  capps 
// =====================================================
void AInvHands::NextInventoryItem()
{
}
