// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_ReserveChute.generated.h"

class AInventory;
UCLASS()
class AAttch_ReserveChute : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_ReserveChute();

	FName GetAttachBoneFor(AInventory* Inv);
};
