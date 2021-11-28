// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/StringMessagePlus/TeamSayMessagePlus/TeamSayMessagePlus.h"

ATeamSayMessagePlus::ATeamSayMessagePlus()
{
	bBeep = true;
	Lifetime = 6;
	DrawColor = FColor(128, 255, 128, 255);
}




void RenderComplexMessage(UCanvas* Canvas, float &XL, float &YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	local string LocationName;
	if (RelatedPRI_1 == None)
	{
		Return;
	}
	Canvas.SetDrawColor(0, 255, 0);
	Canvas.DrawText(RelatedPRI_1.PlayerName $ " ", false);
	Canvas.SetPos(Canvas.CurX, Canvas.CurY - YL);
	LocationName = RelatedPRI_1.GetLocationName();
	if (LocationName != "")
	{
		Canvas.SetDrawColor(0, 128, 255);
		Canvas.DrawText(" (" $ LocationName $ "):", false);
	}
	else
	{
		Canvas.DrawText(": ", false);
	}
	Canvas.SetPos(Canvas.CurX, Canvas.CurY - YL);
	Canvas.SetDrawColor(0, 128, 0);
	Canvas.DrawText(MessageString, false);
	*/
}
void AssembleString(AHUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString)
{
	/*
	local string LocationName;
	if (RelatedPRI_1 == None)
	{
		Return "";
	}
	LocationName = RelatedPRI_1.GetLocationName();
	if (LocationName == "")
	{
		Return RelatedPRI_1.PlayerName @ ":" @ MessageString;
	}
	else
	{
		Return RelatedPRI_1.PlayerName $ "  (" $ LocationName $ "): " $ MessageString;
	}
	*/
}
