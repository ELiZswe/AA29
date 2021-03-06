// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/BaseModAttachment/BaseModAttachment.h"
#include "AttachMod_Harris_Bipod.generated.h"

UCLASS()
class AAttachMod_Harris_Bipod : public ABaseModAttachment
{
	GENERATED_BODY()
public:
	AAttachMod_Harris_Bipod();

	UPROPERTY(EditAnywhere)								bool bSupported;									//var bool bSupported;

	void NotifyAttachmentAnimation(uint8 AnimState);
};
