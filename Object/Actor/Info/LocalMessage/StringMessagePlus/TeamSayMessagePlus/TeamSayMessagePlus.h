// All the original content belonged to the US Army

#pragma once

#include "CoreMinimal.h"
#include "AA29/Object/Actor/Info/LocalMessage/StringMessagePlus/StringMessagePlus.h"
#include "TeamSayMessagePlus.generated.h"

class AAA2_HUD;

UCLASS()
class ATeamSayMessagePlus : public AStringMessagePlus
{
	GENERATED_BODY()
public:
	ATeamSayMessagePlus();

	void RenderComplexMessage(UCanvas* Canvas, float& XL, float& YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject);
	FString AssembleString(AAA2_HUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString);
};
