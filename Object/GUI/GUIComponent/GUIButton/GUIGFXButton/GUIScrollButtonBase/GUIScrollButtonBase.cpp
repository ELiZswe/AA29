// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIScrollButtonBase.h"

UGUIScrollButtonBase::UGUIScrollButtonBase()
{
	Position = EIconPosition::ICP_Scaled;
	StyleName = "RoundScaledButton";
	bNeverFocus = true;
	bRepeatClick = true;
}