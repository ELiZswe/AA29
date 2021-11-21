// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIProgressBar/GUIProgressBar.h"

UGUIProgressBar::UGUIProgressBar()
{
	BarColor = FColor(0, 203, 255, 255);
	High = 100;
	CaptionWidth = 0.45;
	ValueRightAlign = EeTextAlign::TXTA_Right;
	FontName = "UT2MenuFont";
	ValueRightWidth = 0.2;
	bShowValue = true;
}
