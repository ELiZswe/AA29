// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIBorder/GUITitleBar/GUIHeader/GUIHeader.h"

UGUIHeader::UGUIHeader()
{
	DockAlign = EePageAlign::PGA_Top;
	bUseTextHeight = false;
	FontScale = EFontScale::FNS_Small;
	StyleName = "Header";
	WinHeight = 25;
}