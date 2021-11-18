// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/Inventory.h"
#include "AA29/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_ObjectiveInventory.generated.h"

/**
 * 
 */


UCLASS()
class AA29_API AAGP_ObjectiveInventory : public AInventory
{
	GENERATED_BODY()
public:
	AAGP_ObjectiveInventory();

	
	UPROPERTY()		AAGP_ObjectivePickup*	PlacedPickup;	//var AGP_ObjectivePickup PlacedPickup;
	UPROPERTY()		AAGP_Objective*			Objective;		//var AGP_Objective Objective;



	virtual void setObjective();						//Function setObjective (AGP_Objective new_objective)
	virtual void DropFrom();							//Function DropFrom(FVector StartLocation, optional bool bAttach)
	virtual void InitFor();								//Function InitFor(Inventory Inv)
	virtual void SetPlacedPickup();						//Function SetPlacedPickup(AGP_ObjectivePickup new_placed_pickup)
	virtual void AttachToPawn();						//Function AttachToPawn(Pawn p)
	virtual void GetSwapContainer();					//Function GetSwapContainer()
};
