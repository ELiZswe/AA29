// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "ActionMessage.generated.h"

UCLASS()
class AActionMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	AActionMessage();

	UPROPERTY()			TArray<FString> Messages;						//var localized string Messages;

	FString GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
};
