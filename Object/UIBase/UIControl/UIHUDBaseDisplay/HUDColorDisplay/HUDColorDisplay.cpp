// All the original content belonged to the US Army

#include "AA29/Object/UIBase/UIControl/UIHUDBaseDisplay/HUDColorDisplay/HUDColorDisplay.h"
#include "AA29/Object/Actor/HUD/AGP_HUD/AGP_HUD.h"
#include "Engine/Canvas.h"

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
	int32 oldstyle = 0;
	FColor OldColor = FColor(0,0,0,0);
	/*
	if (Canvas == nullptr || cFrame == nullptr || cFrame->cActor == nullptr || cFrame->cActor.Level == nullptr || cFrame->cActor.bDeleteMe || cFrame->cActor.Level.bDeleteMe)
	{
		return;
	}
	if (_Texture != nullptr)
	{
		oldstyle = Canvas.Style;
		OldColor = Canvas.DrawColor;
		Canvas.Style = 6;
		Canvas.DrawColor = Cast<AAGP_HUD>(cFrame->cHUD).HUDColor;
		Canvas.SetPos(_ScaledPos.X, _ScaledPos.Y);
		Canvas.DrawTile(_Texture, _ScaledPos.W, _ScaledPos.H, 0, 0, _ScaledPos.W, _ScaledPos.H);
		Canvas.Style = oldstyle;
		Canvas.DrawColor = OldColor;
	}
	*/
}
