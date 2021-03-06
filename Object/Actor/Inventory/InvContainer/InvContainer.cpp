// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Inventory/Ammunition/Ammunition.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Inventory/Weapon/Weapon.h"
#include "AA29/Object/Actor/Pickup/Ammo/Ammo.h"

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
	AInventory* dprev = nullptr;
	AInventory* dnext = nullptr;
	/*
	DebugLog(DEBUG_Inv, "IC::D()	Destroying . . . " + Self);
	dprev = getFirstItem();
	if (dprev != nullptr)
	{
		DebugLog(DEBUG_Inv, "IC::D()	" + this @ Prev);
		dnext = dprev.Next;
		dprev.Destroy();
		dprev = Next;
	}
	_currentItem = nullptr;
	_headItem = nullptr;
	nextContainer = nullptr;
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
		return nullptr;
	}
	if (_currentItem->Next == NULL)
	{
		return nullptr;
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
		return nullptr;
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
	//if (Owner != nullptr)
	//{
	//	Cast<APawn>(GetOwner())->ChangeInventoryWeight(-p_item.fWeight);
	//}
	*/
	return true;
}

void AInvContainer::dropCurrentItem()
{
	APickup* Pickup = nullptr;
	/*
	if (_currentItem == nullptr)
	{
		return;
	}
	if (_currentItem->IsA(AWeapon::StaticClass()))
	{
		_currentItem.DropFrom(Owner.Location + 72 * Vector(Owner.Rotation) + FVector(0 0 1) * 15);
		DeleteItem(_currentItem);
		return;
	}
	Pickup = Spawn(_currentItem.PickupClass, , "None", Owner.Location + 72 * Vector(Rotation) + FVector(0 0 1) * 15);
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
	if (Pickup->IsA(AAmmo::StaticClass()))
	{
		Cast<AAmmo>(Pickup).AmmoAmount = Cast<AAmmunition>(_currentItem).AmmoAmount;
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
		//p_item->SetOwner(GetOwner());
		//if (Owner != NULL)
		//{
		//	Cast<APawn>(GetOwner())->ChangeInventoryWeight(p_item->fWeight);
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
		Cast<APawn>(GetOwner())->ChangeInventoryWeight(new_item.fWeight - old_item.fWeight);
	}
	*/
	return true;
}

int32 AInvContainer::CountItems()
{
	AInventory* Item = nullptr;
	int32 i = 0;
	i = 0;
	/*
	for (Item = _headItem; Item != nullptr; Item = Item->Next)
	{
		i++;
	}
	*/
	return i;
}

bool AInvContainer::addLastItem(TSubclassOf<AInventory> p_item)
{
	AInventory* last_item = nullptr;
	/*
	if (!FindInventorySpace(p_item))
	{
		return false;
	}
	else
	{
		if (isEmpty())
		{
			p_item.Next = nullptr;
			p_item.Prev = nullptr;
			_headItem = p_item;
		}
		else
		{
			last_item = getItemAtIndex(getUsedCapacity() - 1);
			last_item.Next = p_item;
			p_item.Prev = last_item;
			p_item.Next = nullptr;
		}
		_iUsedCapacity++;
		if (Owner != nullptr)
		{
			Cast<APawn>(GetOwner())->ChangeInventoryWeight(p_item.fWeight);
		}
		p_item.SetOwner(GetOwner());
		return true;
	}
	*/
	return false;    //FAKE  /EliZ
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

AInventory* AInvContainer::FindInventoryType(TSubclassOf<AInventory>  invtype)
{
	AInventory* curritem = nullptr;
	if (isEmpty())
	{
		return nullptr;
	}
	/*
	curritem = _headItem;
	if (curritem == NULL)
	{
		GOTO JL0066;
	}
	if (curritem->IsA(invtype.Name))
	{
		return curritem;
	}
	curritem = curritem.Next;
	if (curritem == nullptr)
		JL0066:
	{
		return nullptr;
	}
	*/
	return nullptr;    //FAKE  /ELiZ
}

int32 AInvContainer::CountInventoryType(TSubclassOf<AInventory> invtype)
{
	AInventory* curritem = nullptr;
	int32 Count = 0;
	if (isEmpty())
	{
		return 0;
	}
	Count = 0;
	/*
	curritem = _headItem;
	if (curritem == nullptr)
	{
		GOTO JL006E;
	}
	if (curritem->IsA(invtype.Name))
	{
		Count++;
	}
	curritem = curritem.Next;
	if (curritem == nullptr)
		JL006E:
	{
		return Count;
	}
	*/
	return 0;    //FAKE   /ELiZ
}

int32 AInvContainer::AbsorbDamage(int32 Damage, UaDamageType DamageType, FVector HitLocation)
{
	return Damage;
}

void AInvContainer::FindAmmo(AAmmunition*  Ammo)
{
	AInventory* curritem = nullptr;
	AAmmunition* bestsofar = nullptr;
	/*
	if (isEmpty())
	{
		return nullptr;
	}
	curritem = _headItem;
	if (curritem == nullptr)
	{
		GOTO JL00A3;
	}
	if (curritem->IsA(Ammo.Name))
	{
		if (bestsofar == nullptr || bestsofar.AmmoAmount < Ammunition(curritem).AmmoAmount)
		{
			bestsofar = Cast<AAmmunition>(curritem);
		}
	}
	curritem = curritem.Next;
	if (curritem == nullptr)
		JL00A3:
	{
		if (bestsofar != nullptr)
		{
			if (bestsofar.AmmoAmount == 0)
			{
				bestsofar = nullptr;
			}
		}
		return bestsofar;
	}
	*/
}

FString AInvContainer::toString()
{
	AInventory* curritem = nullptr;
	FString retval = "";
	FString Temp = "";
	int32 i = 0;
	retval = "";
	if (isEmpty())
	{
		return "Empty";
	}
	/*
	curritem = _headItem;
	for (i = 0; i < _iUsedCapacity; i++)
	{
		if (curritem == nullptr)
		{
		}
		Temp = curritem.Name;
		if (curritem == this.getCurrentItem())
		{
			retval = retval @ " -- [" @ Temp @ "]";
		}
		else
		{
			retval = retval @ " -- " @ Temp;
		}
		curritem = curritem.Next;
	}
	*/
	return retval;
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
	Log("Dumping InvContainer... " + Self);
	Log("thename= " + thename + " owner= " + Owner);
	Log("_iMaxCapacity= " + _iMaxCapacity + " _iUsedCapacity= " + _iUsedCapacity);
	Log("_currentItem= " + _currentItem + " _headItem= " + _headItem);
	*/
}
