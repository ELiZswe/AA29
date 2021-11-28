// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIImage/GUIImageButton/GUIImageButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIToolTip/GUIToolTip.h"

UGUIImageButton::UGUIImageButton()
{
	UGUIToolTip* GUIButtonToolTip = NewObject<UGUIToolTip>(UGUIToolTip::StaticClass());
	bTabStop = true;
	bAcceptsInput = true;
	bCaptureMouse = true;
	ToolTip = GUIButtonToolTip;
	//OnKeyEvent = GUIImageButton.InternalOnKeyEvent;
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