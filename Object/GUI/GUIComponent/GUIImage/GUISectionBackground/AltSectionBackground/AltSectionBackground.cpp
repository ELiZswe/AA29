// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIImage/GUISectionBackground/AltSectionBackground/AltSectionBackground.h"

UAltSectionBackground::UAltSectionBackground()
{
	AltCaptionOffset = { 40,8,40,25 };
	AltCaptionAlign = ETextAlign::TXTA_Center;
	bAltCaption = true;
	ImageOffset = {0, 32, 0, 32};
	FontScale = EFontScale::FNS_Medium;
}