// All the original content belonged to the US Army


#include "AA29/Object/Actor/HudOverlay/ScriptedHudOverlay/ScriptedHudOverlay.h"

AScriptedHudOverlay::AScriptedHudOverlay()
{

}

void AScriptedHudOverlay::Render(UCanvas* C)
{
	float X = 0;
	float Y = 0;
	float W = 0;
	float H = 0;
	/*
	if (HUDMaterial == None)
	{
		return;
	}
	if (PosX <= 1)
	{
		X = (C.ClipX * PosX);
	}
	else
	{
		X = PosX;
	}
	if (PosY <= 1)
	{
		Y = (C.ClipY * PosY);
	}
	else
	{
		Y = PosY;
	}
	if (Width <= 1)
	{
		W = (C.ClipX * Width);
	}
	else
	{
		W = Width;
	}
	if (Height <= 1)
	{
		H = (C.ClipY * Height);
	}
	else
	{
		H = Height;
	}
	C.DrawColor = Class'HUD'.Default.WhiteColor;
	C.SetPos(X, Y);
	C.DrawTile(HUDMaterial, W, H, 0, 0, float(HUDMaterial.MaterialUSize()), float(HUDMaterial.MaterialVSize()));
	*/
}

