// All the original content belonged to the US Army

#include "AA29/Object/Actor/NavigationPoint/SmallNavigationPoint/InventorySpot/InventorySpot.h"
#include "AA29/Object/Actor/Controller/AIController/aAIController.h"
#include "AA29/Object/Actor/Pickup/Pickup.h"
#include "AA29/Object/Actor/xPickUpBase/xPickUpBase.h"

AInventorySpot::AInventorySpot()
{
	bCollideWhenPlacing = false;
	//bHiddenEd = true;
}

AActor* AInventorySpot::GetMoveTargetFor(AaAIController* B, float MaxWait)
{
	if (markedItem != nullptr && markedItem->ReadyToPickup(MaxWait) && B->Desireability(markedItem) > 0)
	{
		return markedItem;	    //markedItem is a Pickup
	}
	return this;
}
float AInventorySpot::DetourWeight(APawn* Other, float PathWeight)
{ 
	/*
	if (markedItem != nullptr && markedItem->ReadyToPickup(0))
	{
		return markedItem->DetourWeight(Other, PathWeight);
	}
	*/
	return 0;    //FAKE   /ELiZ
}
