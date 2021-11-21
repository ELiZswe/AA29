// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorderC/UIBorderC.h"

UUIBorderC::UUIBorderC()
{

}

void Draw(UCanvas* Canvas)
{
	/*
	int32 oldstyle = 0;
	oldstyle = Canvas.Style;
	if (_iParams == 0)
	{
		Canvas.Style = ERenderStyle.STY_Normal;
	}
	else
	{
		if (_iParams == 1)
		{
			Canvas.Style = ERenderStyle.STY_Translucent;
		}
		else
		{
			if (_iParams == 2)
			{
				Canvas.Style = ERenderStyle.STY_Alpha;
			}
		}
	}
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ string(_Texture));
	}
	if (_Texture2 != None)
	{
		Canvas.SetPos(float(_ScaledPos.X), float(_ScaledPos.Y));
		if (_Texture2 != None)
		{
			Canvas.DrawTile(_Texture2, float(_ScaledPos.W), float(_ScaledPos.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		}
	}
	if (_Texture != None)
	{
		Canvas.SetPos(float(_BorderLeft.X), float(_BorderLeft.Y));
		Canvas.DrawTile(_Texture, float(_BorderLeft.W), float(_BorderLeft.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderRight.X), float(_BorderRight.Y));
		Canvas.DrawTile(_Texture, float(_BorderRight.W), float(_BorderRight.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderTop.X), float(_BorderTop.Y));
		Canvas.DrawTile(_Texture, float(_BorderTop.W), float(_BorderTop.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
		Canvas.SetPos(float(_BorderBottom.X), float(_BorderBottom.Y));
		Canvas.DrawTile(_Texture, float(_BorderBottom.W), float(_BorderBottom.H), float(_iTexDim.X), float(_iTexDim.Y), float(_iTexDim.W), float(_iTexDim.H));
	}
	Canvas.Style = byte(oldstyle);
	*/
}