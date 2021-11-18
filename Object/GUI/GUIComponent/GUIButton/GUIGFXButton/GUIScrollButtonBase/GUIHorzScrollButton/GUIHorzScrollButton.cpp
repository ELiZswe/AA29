// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIHorzScrollButton/GUIHorzScrollButton.h"

UGUIHorzScrollButton::UGUIHorzScrollButton()
{
	ImageIndex = 2;
}

void UGUIHorzScrollButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	if (bIncreaseButton)
	{
		ImageIndex = 3;
	}
	Super::InitComponent(MyController, MyOwner);
}