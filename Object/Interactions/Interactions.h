// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/MyEnums.h"
#include "Interactions.generated.h"

UCLASS()
class UInteractions : public UObject
{
	GENERATED_BODY()
public:
	UInteractions();

	FString GetFriendlyName(EInputKey iKey);
};
