// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Inventory/InvContainer/InvContainer.h"
#include "InvUtility.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AInvUtility : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvUtility();

	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;

};
