// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Info/LocalMessage/StringMessagePlus/StringMessagePlus.h"
#include "TeamSayMessagePlus.generated.h"

/**
 * 
 */
UCLASS()
class AA29_API ATeamSayMessagePlus : public AStringMessagePlus
{
	GENERATED_BODY()
public:
	ATeamSayMessagePlus();

	void RenderComplexMessage(UCanvas* Canvas, float& XL, float& YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	void AssembleString(AHUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString);
};
