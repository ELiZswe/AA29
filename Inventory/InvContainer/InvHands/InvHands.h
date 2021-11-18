// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/InvContainer/InvContainer.h"
#include "InvHands.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvHands : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvHands();

	bool FindInventorySpace(TSubclassOf<AInventory> p_item) override;
	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;
	bool IsContainerAvailable(TSubclassOf<AInventory> p_item);
	void NextInventoryItem() override;

};
