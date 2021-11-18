// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUD_RadarDot/UIHUD_RadarDot.h"

UUIHUD_RadarDot::UUIHUD_RadarDot()
{
	//_tPlayerDot = Texture'T_AA2_UI.HUD.hud_group_army';
	dot_size = 32;
}

void UUIHUD_RadarDot::SetMyRadar (UUIHUD_Radar* NewRadar)
{
	MyRadar=NewRadar;
}
void UUIHUD_RadarDot::Draw (UCanvas* C)
{
	if (bVisible)
	{
		UpdatePlayerDot();
		DrawPlayerDot(C);
	}
}
void UUIHUD_RadarDot::DrawPlayerDot (UCanvas* C)
{
	/*
	C.SetPos(PlayerXY.X,PlayerXY.Y);
	C.DrawTile(_tPlayerDot,PlayerXY.W,PlayerXY.H,0,0,_tPlayerDot.MaterialUSize(),_tPlayerDot.MaterialVSize());
	*/
}
void UUIHUD_RadarDot::UpdatePlayerDot ()
{
	/*
	local float draw_x;
	local float draw_y;
	local float draw_size;
	local float screen_x;
	local float screen_y;
	local float Size;
	local float size_squared;
	local float Range;
	Range=MyRadar.CurrentRange;
	draw_size=dot_size * 1 - Range / MyRadar.GridRange.Max;
	draw_size=FMax(draw_size,8);
	size_squared=GetDistanceSquared();
	if (size_squared > Range * Range)
	{
		Size=Sqrt(size_squared);
		draw_x=X / Size * Range;
		draw_y=Y / Size * Range;
		draw_size *= 1.5;
	}
	else
	{
		draw_x=X;
		draw_y=Y;
	}
	screen_x=- draw_y / Range + 1 / 2;
	screen_y=draw_x / Range + 1 / 2;
	PlayerXY.W=draw_size;
	PlayerXY.H=draw_size;
	PlayerXY.X=_ScaledPos.X + _ScaledPos.W * screen_x - draw_size / 2;
	PlayerXY.Y=_ScaledPos.Y + _ScaledPos.H * screen_y - draw_size / 2;
	*/
}
void UUIHUD_RadarDot::SetRadarDotXY (float new_x, float new_y)
{
	X=new_x;
	Y=new_y;
}
float UUIHUD_RadarDot::GetDistanceSquared ()
{
	return X * X + Y * Y;
}
