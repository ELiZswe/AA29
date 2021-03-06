// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "TimerMessage.generated.h"

UCLASS()
class ATimerMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	ATimerMessage();

	UPROPERTY(EditAnywhere)		FString			CountDownTrailer;		//var() localized string CountDownTrailer;
	UPROPERTY()					TArray<FName>	CountDown;				//var name CountDown;
	UPROPERTY(EditAnywhere)		TArray<USoundBase*>		CountDownSounds;		//var() Sound CountDownSounds;

	FString GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
};
