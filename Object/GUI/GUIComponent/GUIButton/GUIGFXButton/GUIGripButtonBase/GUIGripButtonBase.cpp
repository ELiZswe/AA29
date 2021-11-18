// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIGripButtonBase.h"

UGUIGripButtonBase::UGUIGripButtonBase()
{
	Position = EIconPosition::ICP_Bound;
	StyleName = "RoundButton";
	bNeverFocus = true;
	bRequireReleaseClick = true;
}
