// All the original content belonged to the US Army


#include "InvContainer.h"

AInvContainer::AInvContainer()
{
	_iMaxCapacity = 50;
	thename = "Default InvContainer";
}


bool AInvContainer::IsFull()
{
	return _iUsedCapacity >= _iMaxCapacity;
}
bool AInvContainer::isEmpty()
{
	return _iUsedCapacity == 0;
}
void AInvContainer::Destroyed()
{
	/*

	local Inventory dprev;
	local Inventory dnext;
	DebugLog(DEBUG_Inv, "IC::D()	Destroying . . . " $ Self);
	dprev = getFirstItem();
	if (dprev != None)
	{
		DebugLog(DEBUG_Inv, "IC::D()	" $ Self @ Prev);
		dnext = dprev.Next;
		dprev.Destroy();
		dprev = Next;
	}
	_currentItem = None;
	_headItem = None;
	nextContainer = None;
	Destroyed();
*/
}

int32 AInvContainer::getMaxCapcity()
{
	return _iMaxCapacity;
}

TSubclassOf<AInventory> AInvContainer::getFirstItem()
{
	if (isEmpty())
	{
		return NULL ;
	}
	_currentItem = _headItem;
	return _currentItem;
}

TSubclassOf<AInventory> AInvContainer::getNextItem()
{
	if (_currentItem == NULL)
	{
		return NULL;
	}
	if (_currentItem->Next == NULL)
	{
		return NULL;
	}
	else
	{
		_currentItem = Cast<AInventory>(_currentItem)->Next;
	}
	return _currentItem;
}

int32 AInvContainer::getUsedCapacity()
{
	return _iUsedCapacity;
}

TSubclassOf<AInventory> AInvContainer::getItemAtIndex(int32 Index)
{
	TSubclassOf<AInventory> Item;
	int32 Position;
	if (Index > _iUsedCapacity)
	{
		return NULL;
	}
	Item = getFirstItem();
	for (Position = 0; Position < Index; Position++)
	{
		Item = getNextItem();
	}
	return Item;
}
TSubclassOf<AInventory> AInvContainer::getCurrentItem()
{
	return _currentItem;
}
bool AInvContainer::FindInventoryItem(TSubclassOf<AInventory> p_item)
{
	/*
	AInventory* curritem;
	if (isEmpty())
	{
		return false;
		//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		//{
		//	Log("InvContainer:  " @ thename @ " was empty.");
		//}
	}
	curritem = _headItem;
	if (curritem == p_item)
	{
		//if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		//{
		//	Log("InvContainer:  " @ thename @ " found...");
		//}
		return true;
	}
	if (curritem != NULL)
	{
		curritem = curritem->Next;
	}
	if (curritem == NULL)
	{
		return false;
	}
	else
	{
		return true;
	}
	*/
	return true;   //FAKE ELiZ
}

void AInvContainer::setCurrentItem(TSubclassOf<AInventory> p_item)
{
	/*
	if (Self.FindInventoryItem(p_item))
	{
		_currentItem = p_item;
	}
	*/
}
bool AInvContainer::DeleteItem(TSubclassOf<AInventory> p_item)
{
	/*
	//if (!Self.FindInventoryItem(p_item))
	//{
	//	return false;
	//}
	if (p_item == _headItem)
	{
		if (_iUsedCapacity == 1)
		{
			_headItem = NULL;
		}
		else
		{
			Cast<AInventory>(p_item)->Next->Prev = Cast<AInventory>(p_item)->Next;
			_headItem = Cast<AInventory>(p_item)->Next;
		}
	}
	else
	{
		if (p_item->Next == NULL)
		{
			if (Cast<AInventory>(p_item)->Prev != NULL)
			{
				Cast<AInventory>(p_item)->Prev->Next = NULL;
			}
		}
		else
		{
			if (p_item->Next != NULL)
			{
				Cast<AInventory>(p_item)->Next->Prev = Cast<AInventory>(p_item)->Prev;
			}
			if (Cast<AInventory>(p_item)->Prev != NULL)
			{
				Cast<AInventory>(p_item)->Prev->Next =(Cast<AInventory>(p_item))->Next;
			}
		}
	}
	_iUsedCapacity--;
	if (_iUsedCapacity == 0)
	{
		_headItem = NULL;
		_currentItem = NULL;
	}
	if (p_item == _currentItem)
	{
		_currentItem = _headItem;
	}
	Cast<AInventory>(p_item)->Next = NULL;
	Cast<AInventory>(p_item)->Prev = NULL;
	//if (Owner != None)
	//{
	//	Pawn(Owner).ChangeInventoryWeight(-p_item.fWeight);
	//}
	*/
	return true;
	
}
void AInvContainer::dropCurrentItem()
{
	/*
	local Pickup Pickup;
	if (_currentItem == nullptr)
	{
		Return;
	}
	if (_currentItem.IsA('Weapon'))
	{
		_currentItem.DropFrom(Owner.Location + 72 * Vector(Owner.Rotation) + vect(0 0 1) * 15);
		DeleteItem(_currentItem);
		Return;
	}
	Pickup = Spawn(_currentItem.PickupClass, , 'None', Owner.Location + 72 * Vector(Rotation) + vect(0 0 1) * 15);
	if (Pickup == nullptr)
	{
		if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
		{
			ScreenPrint("InvContainer:dropCurrentItem failed fabrication.");
		}
	}
	else
	{
		if (Self.DeleteItem(_currentItem))
		{
			ScreenPrint("Current item spawned to world and deleted.");
			Pickup.Inventory = _currentItem;
		}
		else
		{
			ScreenPrint("Current item spawned but failed delete.  Destroying spawn.");
			Pickup.Destroy();
		}
	}
	if (Pickup.IsA('Ammo'))
	{
		Ammo(Pickup).AmmoAmount = Ammunition(_currentItem).AmmoAmount;
	}
	*/
}

/* ======================================================================================
* AGP function ItemAllowable
* This is the internal test for whether this Inventory item could
* possibly be contained by this container.  Doesn't say whether
* the container is full or not.
* input:    Inventory item
* output:   boolean true if it could be contained
* effects:  none
* last modified by:  capps
* ======================================================================================
*/
bool AInvContainer::ItemAllowable(TSubclassOf<AInventory> p_item)
{
	return true;
}

// helper func that checks whether the container has space for the given item
bool AInvContainer::FindInventorySpace(TSubclassOf<AInventory> p_item)
{
	//return (ItemAllowable(p_item) && !p_item->isHandsOnly() && !(isFull()));
	return false;			//Fake   /ELiZ
}
bool AInvContainer::addItem(TSubclassOf<AInventory> p_item)
{
	if (Cast<AAA2_WorldSettings>(GetWorldSettings())->debugInventory)
	{
		UE_LOG(LogTemp, Log, TEXT("InvContainer::addItem( %s )"), p_item);
	}
	if (p_item == NULL)
	{
		return false;
	}
	if (!FindInventorySpace(p_item))
	{
		return false;
	}
	else
	{
		if (isEmpty())
		{
			p_item->Next = NULL;
			//p_item->Prev = NULL;
			_headItem = p_item;
		}
		else
		{
			p_item->Next = _headItem;
			//_headItem->Prev = p_item;
			//p_item->Prev = NULL;
			_headItem = p_item;
		}
		_iUsedCapacity++;
		if (_currentItem == NULL)
		{
			_currentItem = p_item;
		}
		//p_item->SetOwner(Owner);
		//if (Owner != NULL)
		//{
		//	Pawn(Owner)->ChangeInventoryWeight(p_item->fWeight);
		//}
		return true;
	}
}
bool AInvContainer::swapItems(TSubclassOf<AInventory> new_item, TSubclassOf<AInventory> old_item)
{
	int32 preswap = 0;
	int32 postswap = 0;
	preswap = CountItems();
	if (old_item == nullptr)
	{
		return false;
	}
	if (old_item == new_item)
	{
		return false;
	}
	/*
	new_item.Next = old_item.Next;
	new_item.Prev = old_item.Prev;
	if (new_item.Next != nullptr)
	{
		new_item.Next.Prev = new_item;
	}
	if (new_item.Prev != nullptr)
	{
		new_item.Prev.Next = new_item;
	}
	if (_headItem == old_item)
	{
		_headItem = new_item;
		new_item.Prev = nullptr;
	}
	old_item.Prev = nullptr;
	old_item.Next = nullptr;
	postswap = CountItems();
	if (preswap != postswap)
	{
		Log("ERROR - swapItems ERROR");
	}
	if (Owner != nullptr)
	{
		Pawn(Owner).ChangeInventoryWeight(new_item.fWeight - old_item.fWeight);
	}
	*/
	return true;
}
int32 AInvContainer::CountItems()
{
	/*
	local Inventory Item;
	local int i;
	i = 0;
	Item = _headItem;
	if (Item != None)
	{
		i++;
		Item = Item.Next;
	}
	Return i;
	*/

	TSubclassOf<AInventory> Item=NULL;
	int32 index=0;
	while (Item != NULL)
	{
		index++;
		Item = Cast<AInventory>(Item)->Next;
	}
	return index;
}
void AInvContainer::addLastItem(TSubclassOf<AInventory> p_item)
{
	/*
	local Inventory last_item;
	if (!FindInventorySpace(p_item))
	{
		Return False;
	}
	else
	{
		if (isEmpty())
		{
			p_item.Next = None;
			p_item.Prev = None;
			_headItem = p_item;
		}
		else
		{
			last_item = getItemAtIndex(getUsedCapacity() - 1);
			last_item.Next = p_item;
			p_item.Prev = last_item;
			p_item.Next = None;
		}
		_iUsedCapacity++;
		if (Owner != None)
		{
			Pawn(Owner).ChangeInventoryWeight(p_item.fWeight);
		}
		p_item.SetOwner(Owner);
		Return True;
	}
	*/
}

// =====================================================
// AGP function NextInventoryItem
//
// This function moves the 'current' pointer to the next
// in the chain.
//
// effects:  moves the 'current' pointer. containers that
// use this information (like hands, for weapons) should
// be careful to override properly
//
// by:  capps 
// =====================================================

void AInvContainer::NextInventoryItem()
{
	if (_currentItem->Next == NULL)
	{
		_currentItem = _headItem;
	}
	else
	{
		_currentItem = Cast<AInventory>(_currentItem)->Next;
	}
}
void AInvContainer::FindInventoryType(TSubclassOf<AInventory>  invtype)
{
	/*
	AInventory* curritem;
	if (isEmpty())
	{
		return NULL;
	}
	curritem = _headItem;
	if (curritem == NULL)
	{
		GOTO JL0066;
	}
	if (curritem.IsA(invtype.Name))
	{
		Return curritem;
	}
	curritem = curritem.Next;
	if (curritem == None)
		JL0066:
	{
		Return None;
	}
	*/
}
void AInvContainer::CountInventoryType(TSubclassOf<AInventory> invtype)
{
	/*
	local Inventory curritem;
	local int Count;
	if (isEmpty())
	{
		Return 0;
	}
	Count = 0;
	curritem = _headItem;
	if (curritem == None)
	{
		GOTO JL006E;
	}
	if (curritem.IsA(invtype.Name))
	{
		Count++;
	}
	curritem = curritem.Next;
	if (curritem == None)
		JL006E:
	{
		Return Count;
	}
	*/
}
int32 AInvContainer::AbsorbDamage(int32 Damage, UaDamageType DamageType, FVector HitLocation)
{
	return Damage;
}
void AInvContainer::FindAmmo(AAmmunition*  Ammo)
{
	/*
	local Inventory curritem;
	local Ammunition bestsofar;
	if (isEmpty())
	{
		Return None;
	}
	curritem = _headItem;
	if (curritem == None)
	{
		GOTO JL00A3;
	}
	if (curritem.IsA(Ammo.Name))
	{
		if (bestsofar == None || bestsofar.AmmoAmount < Ammunition(curritem).AmmoAmount)
		{
			bestsofar = Ammunition(curritem);
		}
	}
	curritem = curritem.Next;
	if (curritem == None)
		JL00A3:
	{
		if (bestsofar != None)
		{
			if (bestsofar.AmmoAmount == 0)
			{
				bestsofar = None;
			}
		}
		Return bestsofar;
	}
	*/
}
void AInvContainer::toString()
{
	/*
	local Inventory curritem;
	local string retval;
	local string Temp;
	local int i;
	retval = "";
	if (isEmpty())
	{
		Return "Empty";
	}
	curritem = _headItem;
	for (i = 0; i < _iUsedCapacity; i++)
	{
		if (curritem == None)
		{
		}
		Temp = curritem.Name;
		if (curritem == Self.getCurrentItem())
		{
			retval = retval @ " -- [" @ Temp @ "]";
		}
		else
		{
			retval = retval @ " -- " @ Temp;
		}
		curritem = curritem.Next;
	}
	Return retval;
	*/
}
void AInvContainer::SetMaxCapacity(int32 capacity)
{
	_iMaxCapacity = capacity;
}
float AInvContainer::GetWeight()
{
	TSubclassOf<AInventory> Item;
	float Weight;
	Weight = 0;
	Item = getFirstItem();
	if (Item != NULL)
	{
		Weight += Cast<AInventory>(Item)->fWeight;
		Item = getNextItem();
	}
	return Weight;
}
void AInvContainer::DumpContainer()
{
	/*
	Log("Dumping InvContainer... " $ Self);
	Log("thename= " $ thename $ " owner= " $ Owner);
	Log("_iMaxCapacity= " $ _iMaxCapacity $ " _iUsedCapacity= " $ _iUsedCapacity);
	Log("_currentItem= " $ _currentItem $ " _headItem= " $ _headItem);
	*/
}
