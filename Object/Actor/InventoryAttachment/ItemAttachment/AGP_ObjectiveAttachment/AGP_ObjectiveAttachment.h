// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "AA29/Object/Actor/Pickup/AGP_ObjectivePickup/AGP_ObjectivePickup.h"
#include "AGP_ObjectiveAttachment.generated.h"

class AAGP_ObjectivePickup;
UCLASS()
class AAGP_ObjectiveAttachment : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAGP_ObjectiveAttachment();

	UPROPERTY()		AAGP_ObjectivePickup*	PlacedPickup;			//var AGP_ObjectivePickup PlacedPickup;

	void SetPlacedPickup(AAGP_ObjectivePickup* new_placed_pickup);
	bool IsReplicationComplete();
	void NotifyReplicationComplete();
	void SetMesh();
};
