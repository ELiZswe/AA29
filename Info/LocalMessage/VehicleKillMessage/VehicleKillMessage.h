// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/aLocalMessage.h"
#include "VehicleKillMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AVehicleKillMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AVehicleKillMessage();

	UPROPERTY()			TArray<FName> KillSound;					//var name KillSound;
	UPROPERTY()			TArray<FString> KillString;					//var localized string KillString;

	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);

};
