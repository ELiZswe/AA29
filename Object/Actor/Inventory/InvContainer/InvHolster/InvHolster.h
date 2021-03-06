// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "InvHolster.generated.h"

UCLASS()
class AInvHolster : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvHolster();

	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;
};
