// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/InventoryAttachment/ItemAttachment/Attch_Hat_Attachment/Attch_Hat_Attachment.h"
#include "Attch_AirCap.generated.h"

UCLASS()
class AAttch_AirCap : public AAttch_Hat_Attachment
{
	GENERATED_BODY()
public:
	AAttch_AirCap();

	void PostBeginPlay();
};
