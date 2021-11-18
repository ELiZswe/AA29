// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/InvContainer/InvContainer.h"
#include "InvAltShoulder.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvAltShoulder : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvAltShoulder();

	virtual bool ItemAllowable(TSubclassOf<AInventory> p_item) ;
	virtual bool IsContainerAvailable();
	virtual void NextInventoryItem() override;
};
