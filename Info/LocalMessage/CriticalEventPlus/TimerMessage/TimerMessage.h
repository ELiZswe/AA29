// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "TimerMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATimerMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	ATimerMessage();

	UPROPERTY()			FString CountDownTrailer;				//var() localized string CountDownTrailer;
	UPROPERTY()			TArray<FName> CountDown;				//var name CountDown;
	UPROPERTY()			USoundBase* CountDownSounds;			//var() Sound CountDownSounds;


	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);

};
