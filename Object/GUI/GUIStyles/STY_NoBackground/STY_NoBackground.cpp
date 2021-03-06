// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_NoBackground/STY_NoBackground.h"

USTY_NoBackground::USTY_NoBackground()
{
	KeyName = "NoBackground";
	FontNames[0] = "UT2MenuFont";
	FontNames[1] = "UT2MenuFont";
	FontNames[2] = "UT2MenuFont";
	FontNames[3] = "UT2MenuFont";
	FontNames[4] = "UT2MenuFont";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[1] = FColor(255, 255, 255, 255);
	FontColors[2] = FColor(255, 255, 255, 255);
	FontColors[3] = FColor(255, 255, 255, 255);
	FontColors[4] = FColor(255, 255, 255, 255);
	RStyles[0] = EMenuRenderStyle::MSTY_None;
	RStyles[1] = EMenuRenderStyle::MSTY_None;
	RStyles[2] = EMenuRenderStyle::MSTY_None;
	RStyles[3] = EMenuRenderStyle::MSTY_None;
	RStyles[4] = EMenuRenderStyle::MSTY_None;
	BorderOffsets[0] = 0;
	BorderOffsets[1] = 0;
	BorderOffsets[2] = 0;
	BorderOffsets[3] = 0;
}
