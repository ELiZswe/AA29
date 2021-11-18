// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDAlphaBar/HUDAlphaBar.h"

UHUDAlphaBar::UHUDAlphaBar()
{

}

void UHUDAlphaBar::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}
void UHUDAlphaBar::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (_bEnabled && _Texture != None)
	{
		oldstyle = Canvas.Style;
		Canvas.Style = 1;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 200, 0, 1, 1);
		Canvas.Style = oldstyle;
	}
	*/
}
void UHUDAlphaBar::SetTexture(UMaterialInstance* Tex)
{
	_Texture = Tex;
}