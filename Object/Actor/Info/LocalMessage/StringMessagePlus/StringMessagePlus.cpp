// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/StringMessagePlus/StringMessagePlus.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"

AStringMessagePlus::AStringMessagePlus()
{
	bIsSpecial = false;
}

FString AStringMessagePlus::AssembleString(AAA2_HUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString)
{
	return MessageString;
}
