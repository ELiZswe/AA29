// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBorder/UIBorder.h"

UUIBorder::UUIBorder()
{

}

void UUIBorder::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
	_Texture2 = nullptr;
}

void UUIBorder::ProcessParams()
{
	/*
	if (_iParams == 1)
	{
		_bDrawBack = true;
	}
	*/
}

bool UUIBorder::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}

void UUIBorder::Draw(UCanvas* Canvas)
{
	/*
	local int old_style;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_BorderLeft.X, _BorderLeft.Y);
		Canvas.DrawTile(_Texture, _BorderLeft.W, _BorderLeft.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderRight.X, _BorderRight.Y);
		Canvas.DrawTile(_Texture, _BorderRight.W, _BorderRight.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderTop.X, _BorderTop.Y);
		Canvas.DrawTile(_Texture, _BorderTop.W, _BorderTop.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		Canvas.SetPos(_BorderBottom.X, _BorderBottom.Y);
		Canvas.DrawTile(_Texture, _BorderBottom.W, _BorderBottom.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
	}
	if (_bDrawBack && _Texture2 != None)
	{
		old_style = Canvas.Style;
		Canvas.Style = 3;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		if (_Texture2 != None)
		{
			Canvas.DrawTile(_Texture2, _ScaledPos.W, _ScaledPos.H, _iTexDim.X, _iTexDim.Y, _iTexDim.W, _iTexDim.H);
		}
		Canvas.Style = old_style;
	}
	*/
}
void UUIBorder::SetTextureDimensions(FPosition dim)
{
	/*
	_iTexDim.X = dim.X;
	_iTexDim.Y = dim.Y;
	_iTexDim.W = dim.W;
	_iTexDim.H = dim.H;
	*/
}
void UUIBorder::ScaleControl(UCanvas* Canvas)
{
	/*
	ScaleControl(Canvas);
	_BorderLeft.X = _ScaledPos.X;
	_BorderLeft.Y = _ScaledPos.Y;
	_BorderLeft.W = 1;
	_BorderLeft.H = _ScaledPos.H;
	_BorderRight.X = _ScaledPos.X + _ScaledPos.W - 1;
	_BorderRight.Y = _ScaledPos.Y;
	_BorderRight.W = 1;
	_BorderRight.H = _ScaledPos.H;
	_BorderTop.X = _ScaledPos.X;
	_BorderTop.Y = _ScaledPos.Y;
	_BorderTop.W = _ScaledPos.W;
	_BorderTop.H = 1;
	_BorderBottom.X = _ScaledPos.X;
	_BorderBottom.Y = _ScaledPos.Y + _ScaledPos.H - 1;
	_BorderBottom.W = _ScaledPos.W;
	_BorderBottom.H = 1;
	*/
}
void UUIBorder::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}
void UUIBorder::SetTexture2(UMaterialInstance* Tex)
{
	_Texture2 = Tex;
}