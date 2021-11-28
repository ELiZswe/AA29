// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/CriticalEventPlus/CriticalEventPlus.h"
#include "LastSecondMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ALastSecondMessage : public ACriticalEventPlus
{
	GENERATED_BODY()
public:
	ALastSecondMessage();
	UPROPERTY(EditAnywhere, Category = "Message")			FString LastSecondBlue;			//var(Message) localized string LastSecondBlue;
	UPROPERTY(EditAnywhere, Category = "Message")			FString LastSecondRed;			//var(Message) localized string LastSecondRed;



	void ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);

};
