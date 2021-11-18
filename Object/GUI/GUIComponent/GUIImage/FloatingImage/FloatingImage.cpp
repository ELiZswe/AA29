// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIImage/FloatingImage/FloatingImage.h"

UFloatingImage::UFloatingImage()
{
	ImageStyle = EImgStyle::ISTY_PartialScaled;
	DropShadowX = 6;
	DropShadowY = 6;
	WinTop = 0.375;
	WinLeft = 0.25;
	WinWidth = 0.5;
	WinHeight = 0.35;
	RenderWeight = 0.000001;
	bBoundToParent = true;
	bScaleToParent = true;
}