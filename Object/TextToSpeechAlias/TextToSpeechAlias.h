// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "AA29/AA29.h"
#include "TextToSpeechAlias.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API UTextToSpeechAlias : public UObject
{
	GENERATED_BODY()
public:
	UTextToSpeechAlias();

	UPROPERTY()										FString RemoveCharacters;					//var config string RemoveCharacters;
	UPROPERTY()										TArray<FSpeechReplacement> Aliases;			//var config array<SpeechReplacement> Aliases;
	
};
