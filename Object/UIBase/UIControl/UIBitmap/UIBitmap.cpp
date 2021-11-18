// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIBitmap/UIBitmap.h"

UUIBitmap::UUIBitmap()
{

}


void UUIBitmap::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIBitmap::ProcessParams()
{
	/*
	if (_iParams == 1)
	{
		_bAlpha = true;
	}
	*/
}
bool UUIBitmap::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}
void UUIBitmap::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_bAlpha)
	{
		oldstyle = Canvas.Style;
		Canvas.Style = 3;
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	if (_bAlpha)
	{
		Canvas.Style = oldstyle;
	}
	*/
}
void UUIBitmap::SetTexture(FString Tex)
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_Texture == nullptr)
	{
		//Log("UIBitmap::SetTexture(" $ Tex $ ") failed!");
	}
}
