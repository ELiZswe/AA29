// All the original content belonged to the US Army

#include "AA29/Object/Actor/HUD/AGP_HUD/CROWS_Hud/FSTS_CROWS_HUD/FSTS_CROWS_HUD.h"
#include "AA29/Object/Actor/ScoreKeeper/ScoreKeeper.h"
#include "Engine/Canvas.h"

AFSTS_CROWS_HUD::AFSTS_CROWS_HUD(const FObjectInitializer& ObjectInitializer) :Super(ObjectInitializer)
{

}

void AFSTS_CROWS_HUD::SetMessage(FString Message)
{
	HudMessage = Message;
	PosX = 0;
	PosY = 0;
}

void AFSTS_CROWS_HUD::SetScore(AScoreKeeper* keeper, int32 totalTargets)
{
	MaxTargets = totalTargets;
	ScoreKeeper = keeper;
	bShowScore = true;
}

void AFSTS_CROWS_HUD::SetCoords(UCanvas* C)
{
	float Width = 0;
	float Height = 0;
	//C.Font = _cHUDFrame.GetProperSizeFont(C);
	//C.TextSize(HudMessage, Width, Height);
	//PosX = ((C.ClipX / 2) - (Width / 2));
	//PosY = (C.ClipY - (2 * Height));
}

void AFSTS_CROWS_HUD::DrawMessage(UCanvas* C)
{
	if ((PosX == 0) && (PosY == 0))
	{
		SetCoords(C);
	}
	//C.Font = _cHUDFrame.GetProperSizeFont(C);
	//C.SetDrawColor(0, 255, 0);
	//C.SetPos(PosX, PosY);
	//C.DrawText(HudMessage);
}

void AFSTS_CROWS_HUD::DrawScore(UCanvas* C)
{
	//C.Font = _cHUDFrame.GetProperSizeFont(C);
	//C.SetDrawColor(255, 255, 0);
	//C.SetPos(20, 20);
	//C.DrawText("Targets Hit:  " + FString::FromInt(ScoreKeeper.TotalScore.nShot) + " / " + FString::FromInt(MaxTargets));
}

void AFSTS_CROWS_HUD::PostRender_Stage2(UCanvas* C)
{
	Super::PostRender_Stage2(C);
	if (bShowScore)
	{
		DrawScore(C);
	}
	if (bShowMessage)
	{
		DrawMessage(C);
	}
}
