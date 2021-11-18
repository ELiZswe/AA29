// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"

UGUIGFXButton::UGUIGFXButton()
{
	bTabStop = false;
}
void UGUIGFXButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	InitComponent(MyController, MyOwner);
	if (bCheckBox)
	{
		__OnClick__Delegate = InternalOnClick;
	}
	if (Graphic == None && ImageIndex >= 0 && ImageIndex < MyController.ImageList.Length)
	{
		Graphic = MyController.ImageList[ImageIndex];
	}
	*/
}
void UGUIGFXButton::SetChecked(bool bNewChecked)
{
	if (bCheckBox)
	{
		bChecked = bNewChecked;
		//OnChange(Self);
	}
}
bool UGUIGFXButton::InternalOnClick(UGUIComponent* Sender)
{
	if (bCheckBox)
	{
		bChecked = !bChecked;
	}
	//OnChange(Self);
	return true;
}