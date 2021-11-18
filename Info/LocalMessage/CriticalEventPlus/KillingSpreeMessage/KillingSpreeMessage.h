// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "KillingSpreeMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AKillingSpreeMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	AKillingSpreeMessage();

	UPROPERTY()			FString EndSpreeNoteTrailer;			//var localized string EndSpreeNoteTrailer;
	UPROPERTY()			TArray <FName> SpreeSoundName;			//var name SpreeSoundName;
	UPROPERTY()			USoundBase* SpreeSound;					//var Sound SpreeSound;
	UPROPERTY()			TArray < FString> SelfSpreeNote;		//var localized string SelfSpreeNote;
	UPROPERTY()			TArray<FString> SpreeNote;				//var localized string SpreeNote;
	UPROPERTY()			FString MultiKillString;				//var localized string MultiKillString;
	UPROPERTY()			FString EndFemaleSpree;					//var localized string EndFemaleSpree;
	UPROPERTY()			FString EndSelfSpree;					//var localized string EndSelfSpree;
	UPROPERTY()			FString EndSpreeNote;					//var localized string EndSpreeNote;


	void GetFontSize(int32 Switch, AAA2_PlayerState* RelatedPRI1, AAA2_PlayerState* RelatedPRI2, AAA2_PlayerState* LocalPlayer);
	void GetRelatedString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);


};
