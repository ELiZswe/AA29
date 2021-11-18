// All the original content belonged to the US Army


#include "AA29/Info/LocalMessage/StringMessagePlus/SayMessagePlus/SayMessagePlus.h"

ASayMessagePlus::ASayMessagePlus()
{
	RedTeamColor = FColor(64, 64, 255, 255);
	BlueTeamColor = FColor(255, 192, 64, 255);
	bBeep = true;
	Lifetime = 6;
	DrawColor = FColor(0, 255, 255, 255);
}

void ASayMessagePlus::RenderComplexMessage(UCanvas* Canvas, float &XL, float &YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	if (RelatedPRI_1 == None)
	{
		Return;
	}
	Canvas.SetDrawColor(0, 255, 0);
	Canvas.DrawText(RelatedPRI_1.PlayerName $ ": ", false);
	Canvas.SetPos(Canvas.CurX, Canvas.CurY - YL);
	Canvas.SetDrawColor(0, 128, 0);
	Canvas.DrawText(MessageString, false);
	*/
}
void ASayMessagePlus::AssembleString(AHUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString)
{
	/*
	if (RelatedPRI_1 == None)
	{
		Return "";
	}
	if (RelatedPRI_1.PlayerName == "")
	{
		Return "";
	}
	Return RelatedPRI_1.PlayerName $ ": " @ MessageString;
	*/
}
void ASayMessagePlus::GetConsoleColor(AAA2_PlayerState* RelatedPRI_1)
{
	/*
	if (RelatedPRI_1 == None || RelatedPRI_1.Team == None)
	{
		Return Default.DrawColor;
	}
	if (RelatedPRI_1.Team.TeamIndex == 0)
	{
		Return Default.RedTeamColor;
	}
	else
	{
		Return Default.BlueTeamColor;
	}
	*/
}