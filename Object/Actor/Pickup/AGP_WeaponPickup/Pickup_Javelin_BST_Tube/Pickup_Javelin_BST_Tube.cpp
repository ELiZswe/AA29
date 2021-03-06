// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_BST_Tube/Pickup_Javelin_BST_Tube.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/Javelin_Tube/Javelin_BST_Tube/Javelin_BST_Tube.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

APickup_Javelin_BST_Tube::APickup_Javelin_BST_Tube()
{
	InventoryType			= AJavelin_BST_Tube::StaticClass();
	PickupMessage			= FString("You found a Javelin tube.");
	EnemyPickupClass		= APickup_Javelin_BST_Tube::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/Tube3P.Tube3P"), NULL, LOAD_None, NULL));
	Rotation				= FRotator(0, -90, 0);
	LandedRotationOffset	= FRotator(0, 0, 0);
	bShouldFallOnSide		= false;
	DrawScale				= 1.13;
}

AInventory* APickup_Javelin_BST_Tube::SpawnCopy(APawn* Other, bool bRealInventory)
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

void APickup_Javelin_BST_Tube::AnnouncePickup(APawn* Receiver)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, ET_PickedUp, Receiver, "PickedJT");
	}
	Receiver.HandlePickup(this);
	PlaySound(PickupSound, 1, 0.5, false, 40, , true, false);
	*/
}
