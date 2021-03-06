// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/PickupW_Javelin/Pickup_Javelin_LF_CLU/Pickup_Javelin_LF_CLU.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/Javelin_LF_CLU/Javelin_LF_CLU.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

APickup_Javelin_LF_CLU::APickup_Javelin_LF_CLU()
{
	InventoryType	= AJavelin_LF_CLU::StaticClass();
	Rotation		= FRotator(0, -90, 0);
}

AInventory* APickup_Javelin_LF_CLU::SpawnCopy(APawn* Other, bool bRealInventory)
{
	AInventory* Copy = nullptr;
	AInventory* SpawnType = nullptr;
	bool bVirtual = false;
	/*
	SpawnType = GetInventoryClassFor(Other);
	if (false)
	{
		Copy = Inventory;
		Inventory = nullptr;
	}
	else
	{
		Copy = Spawn(SpawnType, Other, , , FRotator(0, 0, 0));
		Copy.InitFor(Inventory);
		if (EventLab != nullptr)
		{
			Copy.SetEventLab(EventLab);
		}
		if (Inventory != nullptr)
		{
			Inventory.Destroy();
			Inventory = nullptr;
		}
	}
	bVirtual = (Copy.bVirtualInventory && (!bRealInventory));
	if (!bCanPickUp)
	{
		Instigator = nullptr;
		Inventory = Copy;
		Copy = nullptr;
	}
	else
	{
		if (Other.CanPickupItem(Copy, bVirtual))
		{
			AnnouncePickup(Other);
			if (bVirtual)
			{
				Other.CreateVirtualInventory(Copy.Class);
				Copy.Destroy();
			}
			else
			{
				SetupCopy(Copy, Other);
				Copy.GiveTo(Other, this);
				Copy.PickupFunction(Other);
			}
			Instigator = Other;
		}
		else
		{
			Instigator = nullptr;
			Inventory = Copy;
			Copy = nullptr;
		}
	}
	*/
	return Copy;
}

void APickup_Javelin_LF_CLU::AnnouncePickup(APawn* Receiver)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, ET_PickedUp, Receiver, "PickedLFCLU");
	}
	Super::AnnouncePickup(Receiver);
	*/
}
