// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIDynamicBitmap/UIDynamicBitmap.h"

UUIDynamicBitmap::UUIDynamicBitmap()
{

}

void UUIDynamicBitmap::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}

void UUIDynamicBitmap::ProcessParams()
{
	if (_iParams == 1)
	{
		_bAlpha = true;
	}
}
bool UUIDynamicBitmap::ProcessKeyEvent(int32 Key, int32 Action, float Delta)
{
	return false;
}

void UUIDynamicBitmap::Draw(UCanvas* Canvas)
{
	int32 oldstyle = 0;
	if (_bDebug)
	{
		//Canvas.DrawText("_Texture = " + _Texture);
	}
	if (_Texture != nullptr)
	{
		//oldstyle = Canvas.Style;
		//Canvas.Style = _iDrawType;
		//Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		//Canvas.DrawTile(_Texture, _iUSize, _iVSize, 0, 0, _iUSize, _iVSize);
		//Canvas.Style = oldstyle;
	}
}

void UUIDynamicBitmap::SetTexture(FString Tex, int32 U, int32 V, int32 DrawType)
{
	if (Tex == "")
	{
		_Texture = nullptr;
		return;
	}
	if (_Texture != nullptr)
	{
		_Texture = nullptr;
	}
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject(Tex, Class'Texture'));
	}
	if (_Texture == nullptr)
	{
		//Log("UIDynamicBitmap::SetTexture(" + Tex + ") failed!");
	}
	_iUSize = U;
	_iVSize = V;
	_iDrawType = DrawType;
}
