// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDItem/UIHUDItem.h"

UUIHUDItem::UUIHUDItem()
{

}

void UUIHUDItem::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UUIHUDItem::Draw(UCanvas* Canvas)
{
	/*
	if (!_bEnabled)
	{
		Return;
	}
	if (_bDebug)
	{
		Canvas.DrawText("_Texture = " $ _Texture);
	}
	if (_Texture != None)
	{
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _Pos.W, _Pos.H);
	}
	*/
}

void UUIHUDItem::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}