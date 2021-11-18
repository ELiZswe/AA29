// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "ActionMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AActionMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	AActionMessage();

	UPROPERTY()			TArray<FString> Messages;						//var localized string Messages;
};
