// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"

UGUIImageButton::UGUIImageButton()
{
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
	//ToolTip = GUIToolTip'AGP_Interface.GUIImageButton.GUIButtonToolTip';
	//__OnKeyEvent__Delegate = "GUIImageButton.InternalOnKeyEvent";
}

void UGUIImageButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	/*
	if (ToolTip->Controller == nullptr)
	{
		ToolTip.InitComponent(MyController, this);
		SetToolTipText(Hint);
	}
	*/
}
bool UGUIImageButton::InternalOnKeyEvent(uint8 &Key, uint8 &State, float Delta)
{
	if (Key == 13 || Key == 32 && State == 1)
	{
		//OnClick(Self);
		return true;
	}
	return false;
}