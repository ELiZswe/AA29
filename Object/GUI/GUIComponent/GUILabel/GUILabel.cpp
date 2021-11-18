// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabel.h"

UGUILabel::UGUILabel()
{
	TextColor = FColor(64, 0, 0, 255);
	FocusedTextColor = FColor(80, 32, 32, 255);
	TextStyle = EMenuRenderStyle::MSTY_Normal;
	TextFont = "UT2MenuFont";
	bTransparent = true;
	BackColor = FColor(0, 0, 0, 255);
	ShadowColor = FColor(0, 0, 0, 196);
	HilightColor = FColor(255, 255, 255, 196);
	WinHeight = 0.06;
	RenderWeight = 0.4;
}