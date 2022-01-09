// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/ItemAttachment.h"
#include "Attch_Bullseye.generated.h"

class AInventory;
UCLASS()
class AAttch_Bullseye : public AItemAttachment
{
	GENERATED_BODY()
public:
	AAttch_Bullseye();

	FName GetAttachBoneFor(AInventory* Inv);
};
