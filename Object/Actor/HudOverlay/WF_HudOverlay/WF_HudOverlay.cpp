// All the original content belonged to the US Army


#include "AA29/Object/Actor/HudOverlay/WF_HudOverlay/WF_HudOverlay.h"

AWF_HudOverlay::AWF_HudOverlay()
{
	ScoreColor = FColor(0, 255, 0, 255);
}

void AWF_HudOverlay::Render(UCanvas* C)
{
	/*
	int32 XPos = 0;
	int32 YPos = 0;
	float XL = 0;
	float YL = 0;
	FColor OldColor = FColor(0, 0, 0, 0);
	if (TargetManager == None)
	{
		return;
	}
	OldColor = C.DrawColor;
	C.DrawColor = ScoreColor;
	C.TextSize("TEST", XL, YL);
	XPos = 30;
	YPos = 30;
	C.SetPos(float(XPos), float(YPos));
	C.DrawText("Targets Hit:" @ string(TargetManager._ScoreKeeper.TotalScore.nShot));
	(YPos += int(YL));
	C.SetPos(float(XPos), float(YPos));
	C.DrawText("Targets Missed:" @ string(TargetManager._ScoreKeeper.TotalScore.nMissed));
	C.DrawColor = OldColor;
	*/
}
