// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUILabel/GUILabelButton/GUILabelButton.h"

UGUILabelButton::UGUILabelButton()
{
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
	OnClickSound = EClickSound::CS_Click;
	//__OnKeyEvent__Delegate = "GUILabelButton.InternalOnKeyEvent";
}

bool UGUILabelButton::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	if (Key == 13 || Key == 32 && State == 1)
	{
		//OnClick(this);
		return true;
	}
	return false;
}