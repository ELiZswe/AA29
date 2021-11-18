// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/BaseModAttachment/BaseModAttachment.h"
#include "AttachMod_Harris_Bipod.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAttachMod_Harris_Bipod : public ABaseModAttachment
{
	GENERATED_BODY()
public:
	AAttachMod_Harris_Bipod();

	UPROPERTY(EditAnywhere, BlueprintReadWrite)								bool bSupported;									//var bool bSupported;
};
