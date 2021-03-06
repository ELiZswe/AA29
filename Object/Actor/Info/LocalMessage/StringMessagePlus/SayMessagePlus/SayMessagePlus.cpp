// All the original content belonged to the US Army

#include "AA29/Object/Actor/Info/LocalMessage/StringMessagePlus/SayMessagePlus/SayMessagePlus.h"
#include "AA29/Object/Actor/Info/ReplicationInfo/TeamInfo/TeamInfo.h"
#include "AA29/AA2_PlayerState.h"
#include "AA29/Object/Actor/HUD/AA2_HUD.h"

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
	if (RelatedPRI_1 == nullptr)
	{
		return;
	}
	Canvas.SetDrawColor(0, 255, 0);
	Canvas.DrawText(RelatedPRI_1.PlayerName + ": ", false);
	Canvas.SetPos(Canvas.CurX, Canvas.CurY - YL);
	Canvas.SetDrawColor(0, 128, 0);
	Canvas.DrawText(MessageString, false);
	*/
}

FString ASayMessagePlus::AssembleString(AAA2_HUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString)
{
	/*
	if (RelatedPRI_1 == nullptr)
	{
		return "";
	}
	if (RelatedPRI_1.PlayerName == "")
	{
		return "";
	}
	return RelatedPRI_1.PlayerName + ": " @ MessageString;
	*/
	return "FAKE";   //FAKE   /ELiZ
}

FColor ASayMessagePlus::GetConsoleColor(AAA2_PlayerState* RelatedPRI_1)
{
	if (RelatedPRI_1 == nullptr || RelatedPRI_1->Team == nullptr)
	{
		return GetDefault<ASayMessagePlus>()->DrawColor;
	}
	if (RelatedPRI_1->Team->TeamIndex == 0)
	{
		return GetDefault<ASayMessagePlus>()->RedTeamColor;
	}
	else
	{
		return GetDefault<ASayMessagePlus>()->BlueTeamColor;
	}
}
