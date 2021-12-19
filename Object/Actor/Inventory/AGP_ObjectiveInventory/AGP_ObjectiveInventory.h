// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/Inventory.h"
#include "AA29/Object/Actor/Keypoint/BaseObjective/AGP_Objective/AGP_Objective.h"
#include "AGP_ObjectiveInventory.generated.h"

UCLASS()
class AA29_API AAGP_ObjectiveInventory : public AInventory
{
	GENERATED_BODY()
public:
	AAGP_ObjectiveInventory();
	
	UPROPERTY()		AAGP_ObjectivePickup*	PlacedPickup;	//var AGP_ObjectivePickup PlacedPickup;
	UPROPERTY()		AAGP_Objective*			Objective;		//var AGP_Objective Objective;

	void setObjective(AAGP_Objective* new_objective);
	APickup* DropFrom(FVector StartLocation, bool bAttach);
	void InitFor(AInventory* Inv);
	void SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup);
	void AttachToPawn(APawn* p);
	AInvContainer* GetSwapContainer();
};
