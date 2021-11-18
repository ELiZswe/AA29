// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/InvContainer/InvContainer.h"
#include "InvHip.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvHip : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvHip();

	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;
	void NextInventoryItem() override;

};
