// All the original content belonged to the US Army

#include "AA29/Object/Actor/Pickup/AGP_WeaponPickup/Pickup_Javelin_BST_CLU/Pickup_Javelin_BST_CLU.h"
#include "AA29/Object/Actor/Inventory/Weapon/AGP_Weapon/RocketWeapon/WEAPON_Javelin/Javelin_BST_CLU/Javelin_BST_CLU.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"

APickup_Javelin_BST_CLU::APickup_Javelin_BST_CLU()
{

	InventoryType			= AJavelin_BST_CLU::StaticClass();
	PickupMessage			= FString("You found a Javelin CLU for the BST.");
	EnemyPickupClass		= APickup_Javelin_BST_CLU::StaticClass();
	DrawType				= EDrawType::DT_StaticMesh;
	VisibleStaticMesh->SetStaticMesh(LoadObject<class UStaticMesh>(NULL, TEXT("/Game/AmericasArmy/Meshes/M_AAO_Armory/Javelin/clu.clu"), NULL, LOAD_None, NULL));
	Rotation				= FRotator(0, -90, 0);
	LandedRotationOffset	= FRotator(25.83984375, 0, 0);
	bShouldFallOnSide		= false;
	DrawScale				= 1.13;
}

AInventory* APickup_Javelin_BST_CLU::SpawnCopy(APawn* Other, bool bRealInventory)
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
		Copy = Spawn(SpawnType, Other, , , FRotator(0 0 0));
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
	bVirtual = Copy.bVirtualInventory && !bRealInventory;
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
void APickup_Javelin_BST_CLU::AnnouncePickup(APawn* Receiver)
{
	/*
	if (EventLab != nullptr)
	{
		EventLab.ActorNotify(this, 2, Receiver, "PickedCLU");
	}
	Receiver.HandlePickup(this);
	PlaySound(PickupSound, 1, 0.5, false, 40, , true, false);
	*/
}
