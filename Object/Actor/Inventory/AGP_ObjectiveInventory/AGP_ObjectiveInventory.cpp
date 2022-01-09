// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/AGP_ObjectiveAttachment/AGP_ObjectiveAttachment.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"

AAGP_ObjectiveInventory::AAGP_ObjectiveInventory()
{
	PickupClass			= AAGP_ObjectivePickup::StaticClass();
	bUseAttachment		= true;
	AttachmentClass		= { AAGP_ObjectiveAttachment::StaticClass() };
}
/*
replication
{
	reliable if (((bNetOwner && bNetDirty) && (Role == ROLE_Authority)))
		Objective;
}
*/

void AAGP_ObjectiveInventory::setObjective(AAGP_Objective* new_objective)
{
	/*
	Objective = new_objective;
	if (Objective != nullptr)
	{
		Objective.SetLocationProxy(Pawn(Owner).PlayerReplicationInfo);
	}
	else
	{
		DebugLog(DEBUG_Warn, "AGP_ObjectiveInventory::SetObjective()	Could not find an Objective!");
	}
	*/
}

APickup* AAGP_ObjectiveInventory::DropFrom(FVector StartLocation, bool bAttach)
{
	/*
	APlayerController* PC = nullptr;
	Log("Dropped from, PlacedPickup is " $ string(PlacedPickup) $ " instigator: " $ string(Instigator) $ " health: " $ string(Instigator.Health) $ " is dead: " $ string(Instigator.bIsDead));
	if (Instigator != nullptr)
	{
		PC = PlayerController(Instigator.Controller);
		if ((((Instigator.Health <= 0) && (PC != nullptr)) && (Level.Game.Stats != nullptr)) && (PC.PlayerStatsIndex >= 0))
		{
			Level.Game.Stats.PlayerStats[PC.PlayerStatsIndex].StatEvent_ObjectiveDeath();
		}
		DetachFromPawn(Instigator);
		Instigator.DeleteInventory(this);
	}
	if (PlacedPickup == nullptr)
	{
		SetDrawType(DT_None);
		DebugLog(DEBUG_Warn, string(this) $ " PlacedPickup doesn't exist, big trouble!");
		return None;
	}
	Log("Velocity of dropped carryable objective is " $ string(Velocity) $ " -> " $ string(VSize(Velocity)));
	Velocity = vect(0, 0, 0);
	PlacedPickup.Velocity = Velocity;
	PlacedPickup.InitDroppedPickupFor(Self, bAttach);
	Velocity = vect(0, 0, 0);
	SetDefaultDisplayProperties();
	Inventory = nullptr;
	Instigator = nullptr;
	GotoState("None");
	Destroy();
	return PlacedPickup;
	*/
	return nullptr;   //FAKE   /EliZ
}

void AAGP_ObjectiveInventory::InitFor(AInventory* Inv)
{
	/*
	local AGP_ObjectiveInventory OInv;
	Super::InitFor(Inv);
	OInv = AGP_ObjectiveInventory(Inv);
	if (OInv != nullptr)
	{
		setObjective(OInv.Objective);
		SetPlacedPickup(OInv.PlacedPickup);
	}
	*/
}

void AAGP_ObjectiveInventory::SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup)
{
	//PlacedPickup = new_placed_pickup;
}

void AAGP_ObjectiveInventory::AttachToPawn(APawn* p)
{
	//Super::AttachToPawn(p);
	//AGP_ObjectiveAttachment(ThirdPersonActor).SetPlacedPickup(PlacedPickup);
}

AInvContainer* AAGP_ObjectiveInventory::GetSwapContainer()
{
	//return AGP_Pawn(Instigator).getInvContainerUtility();
	return nullptr;   //FAKE   /EliZ
}
