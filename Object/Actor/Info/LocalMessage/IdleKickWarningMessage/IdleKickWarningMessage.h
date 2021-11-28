// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "IdleKickWarningMessage.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AIdleKickWarningMessage : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AIdleKickWarningMessage();


	void GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText);

};
