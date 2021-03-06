// All the original content belonged to the US Army

#include "AA29/Object/Actor/Inventory/AGP_ObjectiveInventory/AGP_ObjectiveInventory.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/AGP_ObjectiveAttachment/AGP_ObjectiveAttachment.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/Pawn/AGP_Pawn/AGP_Pawn.h"

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
		Objective.SetLocationProxy(Cast<APawn>(GetOwner())->PlayerReplicationInfo);
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
	Log("Dropped from, PlacedPickup is " + FString::FromInt(PlacedPickup) + " instigator: " + FString::FromInt(Instigator) + " health: " + FString::FromInt(Instigator.Health) + " is dead: " + FString::FromInt(Instigator.bIsDead));
	if (Instigator != nullptr)
	{
		PC = Cast<APlayerController>(Instigator.Controller);
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
		DebugLog(DEBUG_Warn, FString::FromInt(this) + " PlacedPickup doesn't exist, big trouble!");
		return nullptr;
	}
	Log("Velocity of dropped carryable objective is " + FString::FromInt(Velocity) + " -> " + FString::FromInt(VSize(Velocity)));
	Velocity = FVector(0, 0, 0);
	PlacedPickup.Velocity = Velocity;
	PlacedPickup.InitDroppedPickupFor(this, bAttach);
	Velocity = FVector(0, 0, 0);
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
	AAGP_ObjectiveInventory* OInv = nullptr;
	Super::InitFor(Inv);
	OInv = Cast<AAGP_ObjectiveInventory>(Inv);
	/*
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
	Cast<AAGP_ObjectiveAttachment>(ThirdPersonActor)->SetPlacedPickup(PlacedPickup);
}

AInvContainer* AAGP_ObjectiveInventory::GetSwapContainer()
{
	//return Cast<AAGP_Pawn>(Instigator).getInvContainerUtility();
	return nullptr;   //FAKE   /EliZ
}
