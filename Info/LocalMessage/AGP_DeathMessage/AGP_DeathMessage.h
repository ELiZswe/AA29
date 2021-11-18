// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/aLocalMessage.h"
#include "AGP_DeathMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AAGP_DeathMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AAGP_DeathMessage();

	UPROPERTY()			FString SomeoneString;				//var localized string SomeoneString;
	UPROPERTY()			FString KilledString;				//var localized string KilledString;


	FString GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);

};
