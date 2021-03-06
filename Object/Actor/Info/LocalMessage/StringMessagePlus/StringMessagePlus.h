// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "StringMessagePlus.generated.h"

class AAA2_HUD;

UCLASS()
class AStringMessagePlus : public AaLocalMessage
{
	GENERATED_BODY()
public:
	AStringMessagePlus();

	FString AssembleString(AAA2_HUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString);
};
