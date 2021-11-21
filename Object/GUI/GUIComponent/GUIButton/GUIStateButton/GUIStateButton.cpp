// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIStateButton/GUIStateButton.h"

UGUIStateButton::UGUIStateButton()
{
	SelectedStyleName = "ATLButtonSelected";
	bNeverFocus = true;
}

void UGUIStateButton::SetSelected(bool bSelected)
{
	/*
	if (bSelected)
	{
		Style = Controller.GetStyle(SelectedStyleName, FontScale);
	}
	else
	{
		Style = Controller.GetStyle(StyleName, FontScale);
	}
	*/
}
