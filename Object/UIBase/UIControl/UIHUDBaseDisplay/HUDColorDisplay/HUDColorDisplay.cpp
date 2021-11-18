// All the original content belonged to the US Army


#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDColorDisplay/HUDColorDisplay.h"


UHUDColorDisplay::UHUDColorDisplay()
{

}

void UHUDColorDisplay::Destroyed()
{
	Super::Destroyed();
	_Texture = nullptr;
}

void UHUDColorDisplay::CreateTexture()
{
	if (_Texture == nullptr)
	{
		//_Texture = Texture(DynamicLoadObject("T_AA2_UI.menu.hud_menu_hudcolorfg", Class'Texture'));
	}
}

void UHUDColorDisplay::Draw(UCanvas* Canvas)
{
	/*
	local int oldstyle;
	local Object.Color OldColor;
	if (Canvas == None || cFrame == None || cFrame.cActor == None || cFrame.cActor.Level == None || cFrame.cActor.bDeleteMe || cFrame.cActor.Level.bDeleteMe)
	{
		Return;
	}
	if (_Texture != None)
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = 6;
		Canvas.DrawColor = AGP_HUD(cFrame.cHUD).HUDColor;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _ScaledPos.W, _ScaledPos.H);
		Canvas.Style = oldstyle;
		Canvas.DrawColor = OldColor;
	}
	*/
}