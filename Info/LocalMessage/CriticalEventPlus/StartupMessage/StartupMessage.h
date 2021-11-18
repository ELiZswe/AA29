// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "StartupMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AStartupMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:

	AStartupMessage();

	UPROPERTY()			USoundBase* Riff;				//var Sound Riff;
	UPROPERTY()			FString SinglePlayer;			//var localized string SinglePlayer;
	UPROPERTY()			FString NotReady;				//var localized string NotReady;
	UPROPERTY()			TArray<FString> Stage;			//var localized string Stage;

	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
};
