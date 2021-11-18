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
	/*
	local float XPos;
	local float YPos;
	local Object.Color HUDColor;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (FillPercentage < 0 || EndTime < cFrame.cActor.Level.TimeSeconds)
	{
		Return;
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