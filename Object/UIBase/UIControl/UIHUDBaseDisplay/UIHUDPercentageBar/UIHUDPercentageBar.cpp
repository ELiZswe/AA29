// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/UIHUDPercentageBar/UIHUDPercentageBar.h"

UUIHUDPercentageBar::UUIHUDPercentageBar()
{
	//Bracket = Texture'T_AA2_UI.HUD.hud_goal_edge';
	//FillBar = Texture'T_AA2_UI.HUD.hud_goal_fill';
	FillPercentage = -1;
	EndTime = -1;
}

void UUIHUDPercentageBar::SetFillPercentage(float new_fill_p)
{
	FillPercentage = new_fill_p;
}

void UUIHUDPercentageBar::SetEndTime(float new_end_time)
{
	EndTime = new_end_time;
}

void UUIHUDPercentageBar::Draw(UCanvas* Canvas)
{
	float XPos = 0;
	float YPos = 0;
	FColor HUDColor = FColor(0,0,0);
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	if (FillPercentage < 0 || EndTime < cFrame->cActor.GetWorld()->GetTimeSeconds())
	{
		return;
	}
	Canvas.Style = 6;
	XPos = _ScaledPos.X - _ScaledPos.W / 2;
	YPos = _ScaledPos.Y - _ScaledPos.H / 2;
	HUDColor = Canvas.DrawColor;
	if (FillPercentage > 66)
	{
		Canvas.SetDrawColor(255, 0, 0, HUDColor.A);
	}
	else
	{
		if (FillPercentage > 33)
		{
			Canvas.SetDrawColor(255, 255, 0, HUDColor.A);
		}
		else
		{
			Canvas.SetDrawColor(0, 255, 0, HUDColor.A);
		}
	}
	Canvas.SetPos(XPos, YPos);
	Canvas.DrawTile(FillBar, _ScaledPos.W * FillPercentage / 100, _ScaledPos.H, 0, 0, FillBar.USize, FillBar.VSize);
	Canvas.DrawColor = HUDColor;
	Canvas.SetPos(XPos, YPos);
	Canvas.DrawTile(Bracket, _ScaledPos.W, _ScaledPos.H, 0, 0, Bracket.USize, Bracket.VSize);
	*/
}
