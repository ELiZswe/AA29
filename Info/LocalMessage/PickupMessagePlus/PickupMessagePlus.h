// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/aLocalMessage.h"
#include "PickupMessagePlus.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API APickupMessagePlus : public AaLocalMessage
{
	GENERATED_BODY()
public:
	APickupMessagePlus();

	void ClientReceive(APlayerController*, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);
};
