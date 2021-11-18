// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmapB/UIBitmapB.h"

UUIBitmapB::UUIBitmapB()
{

}



void UUIBitmapB::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	if (!_bEnabled)
	{
		Return;
	}
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	OldColor = Canvas.DrawColor;
	Canvas.SetDrawColor(255, 255, 255);
	if (_bAlpha)
	{
		oldstyle = Canvas.Style;
		Canvas.Style = 6;
	}
	else
	{
		oldstyle = Canvas.Style;
		Canvas.Style = 1;
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	Canvas.DrawColor = OldColor;
	Canvas.Style = oldstyle;
	*/
}
void UUIBitmapB::SetTextureDimensions(FPosition dim)
{
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
}