// All the original content belonged to the US Army

#include "AA29/Object/Actor/HudOverlay/BRM_HudOverlay/BRM_HudOverlay.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "AA29/Object/Actor/EventLab/EL_BRM/EL_BRM.h"
#include "Engine/Canvas.h"

ABRM_HudOverlay::ABRM_HudOverlay()
{

}

void ABRM_HudOverlay::Render(UCanvas* C)
{
	FString S = "";
	int32 XPos = 0;
	int32 YPos = 0;
	float XL = 0;
	float YL = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	AAGP_HUD* PlayerHUD = nullptr;
	int32 Hit = 0;
	int32 miss = 0;
	/*
	if ((BRMLab == nullptr) || bHidden)
	{
		return;
	}
	PlayerHUD = Cast<AAGP_HUD>(BRMLab.Controller.myHUD);
	Hit = BRMLab.ProneSupportedTM._ScoreKeeper.TotalScore.nShot;
	(Hit += BRMLab.ProneUnsupportedTM._ScoreKeeper.TotalScore.nShot);
	(Hit += BRMLab.CrouchedTM._ScoreKeeper.TotalScore.nShot);
	miss = BRMLab.ProneSupportedTM._ScoreKeeper.TotalScore.nMissed;
	(miss += BRMLab.ProneUnsupportedTM._ScoreKeeper.TotalScore.nMissed);
	(miss += BRMLab.CrouchedTM._ScoreKeeper.TotalScore.nMissed);
	OldColor = C.DrawColor;
	C.DrawColor = PlayerHUD.HUDColor;
	C.TextSize("TEST", XL, YL);
	XPos = 30;
	YPos = 30;
	C.SetPos(float(XPos), float(YPos));
	S = "Targets Hit:" @ FString::FromInt(Hit);
	C.DrawText(S);
	(YPos += int(YL));
	C.SetPos(float(XPos), float(YPos));
	S = "Targets Missed:" @ FString::FromInt(miss);
	C.DrawText(S);
	C.DrawColor = OldColor;
	*/
}
