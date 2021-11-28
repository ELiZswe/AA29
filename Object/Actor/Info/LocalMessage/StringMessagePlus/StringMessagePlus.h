// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "StringMessagePlus.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API AStringMessagePlus : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AStringMessagePlus();

	FString AssembleString(AHUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString);
};
