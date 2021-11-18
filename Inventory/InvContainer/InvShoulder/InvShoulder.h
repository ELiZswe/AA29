// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/InvContainer/InvContainer.h"
#include "InvShoulder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvShoulder : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvShoulder();

	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;
	void NextInventoryItem() override;
};
