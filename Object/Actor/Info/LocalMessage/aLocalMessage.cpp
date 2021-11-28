// All the original content belonged to the US Army


#include "AA29/Object/Actor/Info/LocalMessage/aLocalMessage.h"
#include "AA29/AA2_PlayerState.h"

AaLocalMessage::AaLocalMessage()
{
	bIsSpecial = true;
	bIsConsoleMessage = true;
	Lifetime = 20;
	DrawColor = FColor(255, 255, 255, 255);
	DrawPivot = EDrawPivot::DP_MiddleMiddle;
	PosX = 0.5;
	PosY = 0.83;
}

void AaLocalMessage::RenderComplexMessage(UCanvas* Canvas, float &XL, float &YL, FString MessageString, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
}
void AaLocalMessage::GetRelatedString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject)
{
	/*
	Return GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	*/
}
void AaLocalMessage::GetString(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	if (class<Actor>(OptionalObject) != None)
	{
		Return class<Actor>(OptionalObject).GetLocalString(Switch, RelatedPRI_1, RelatedPRI_2);
	}
	Return "";
	*/
}
FString AaLocalMessage::AssembleString(AHUD* MyHUD, int32 Switch, AAA2_PlayerState* RelatedPRI_1, FString MessageString)
{
	return "";
}
void AaLocalMessage::ClientReceive(APlayerController* p, int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2, UObject* OptionalObject, FString ExtraText)
{
	/*
	local Object.Color Color;
	local string sMessageText;
	if (p.MyHUD != None)
	{
		p.MyHUD.LocalizedMessage(Default.Class, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	}
	if (p.DemoViewer != None)
	{
		p.DemoViewer.MyHUD.LocalizedMessage(Default.Class, Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject);
	}
	if (IsConsoleMessage(Switch) && p.Player != None && p.Player.Console != None)
	{
		if (RelatedPRI_1 != None && RelatedPRI_1.Team != None && RelatedPRI_1.Team == p.PlayerReplicationInfo.Team)
		{
			Color.R = 180;
			Color.G = 0;
			Color.B = 0;
			Color.A = 255;
		}
		else
		{
			Color.R = 0;
			Color.G = 0;
			Color.B = 180;
			Color.A = 255;
		}
		sMessageText = p.ApplyFilters(GetString(Switch, RelatedPRI_1, RelatedPRI_2, OptionalObject));
		p.Player.Console.Message(sMessageText, Default.Lifetime, Color);
	}
	*/
}
void AaLocalMessage::GetConsoleColor(AAA2_PlayerState* RelatedPRI_1)
{
	/*
	Return Default.DrawColor;
	*/
}
void AaLocalMessage::GetColor(int32 Switch, AAA2_PlayerState* RelatedPRI_1, AAA2_PlayerState* RelatedPRI_2)
{
	/*
	Return Default.DrawColor;
	*/
}
void AaLocalMessage::GetPos(int32 Switch, EDrawPivot &OutDrawPivot, EStackMode &OutStackMode, float &OutPosX, float &OutPosY)
{
	/*
	OutDrawPivot = Default.DrawPivot;
	OutStackMode = Default.StackMode;
	OutPosX = Default.PosX;
	OutPosY = Default.PosY;
	*/
}
void AaLocalMessage::GetFontSize(int32 Switch, AAA2_PlayerState* RelatedPRI1, AAA2_PlayerState* RelatedPRI2, AAA2_PlayerState* LocalPlayer)
{
	/*
	Return Default.FontSize;
	*/
}
void AaLocalMessage::GetLifeTime(int32 Switch)
{
	/*
	Return Default.Lifetime;
	*/
}
bool AaLocalMessage::IsConsoleMessage(int32 Switch)
{
	
	return GetDefault<AaLocalMessage>()->bIsConsoleMessage;
	
}
void AaLocalMessage::GetOffset(int32 Switch, float YL, float ClipY)
{
	/*
	Return Default.PosY;
	*/
}
void AaLocalMessage::ReportLocation(int32 Switch)
{
}