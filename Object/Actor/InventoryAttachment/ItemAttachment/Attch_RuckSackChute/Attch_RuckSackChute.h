// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_RuckSackChute.generated.h"

class AInventory;
UCLASS()
class AAttch_RuckSackChute : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_RuckSackChute();

	FName GetAttachBoneFor(AInventory* Inv);
};
