// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImage.h"

UGUIImage::UGUIImage()
{
	ImageColor = FColor(255, 255, 255, 255);
	ImageRenderStyle = EMenuRenderStyle::MSTY_Alpha;
	X1 = -1;
	Y1 = -1;
	X2 = -1;
	Y2 = -1;
	X3 = -1;
	Y3 = -1;
	RenderWeight = 0.1;
}


FString UGUIImage::AdditionalDebugString()
{
	FString EnumAsString = "";
	return (" IS:" + EnumAsString);
}