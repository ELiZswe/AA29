// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Inventory/InvContainer/InvContainer.h"
#include "InvHip.generated.h"

UCLASS()
class AInvHip : public AInvContainer
{
	GENERATED_BODY()
public:
	AInvHip();

	bool ItemAllowable(TSubclassOf<AInventory> p_item) override;
	void NextInventoryItem() override;

};
