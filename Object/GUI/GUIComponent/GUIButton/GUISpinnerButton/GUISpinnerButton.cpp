// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUISpinnerButton/GUISpinnerButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"

UGUISpinnerButton::UGUISpinnerButton()
{
	StyleName = "SpinnerButton";
	bNeverFocus = true;
	bRepeatClick = true;
	bRequiresStyle = true;
	//__OnClick__Delegate = "GUISpinnerButton.InternalOnClick";
}

bool UGUISpinnerButton::OnPlusClick(UGUIComponent* Sender)
{
	return false;
}
bool UGUISpinnerButton::OnMinusClick(UGUIComponent* Sender)
{
	return false;
}
bool UGUISpinnerButton::InternalOnClick(UGUIComponent* Sender)
{
	/*
	float X;
	float Y;
	X = Controller->MouseX - ActualLeft();
	Y = Controller->MouseY - ActualTop();
	if (Y <= ActualHeight() / 2)
	{
		return OnPlusClick(Sender);
	}
	else
	{
		return OnMinusClick(Sender);
	}
	*/
	return false;		//FAKE   /ELiZ
}
