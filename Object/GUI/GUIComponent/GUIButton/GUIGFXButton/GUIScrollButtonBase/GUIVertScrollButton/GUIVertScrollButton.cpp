// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIVertScrollButton.h"

UGUIVertScrollButton::UGUIVertScrollButton()
{
	ImageIndex = 6;
	StyleName = "VertUpButton";
}


void UGUIVertScrollButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	if (bIncreaseButton)
	{
		StyleName = "VertDownButton";
		ImageIndex = 7;
	}
	Super::InitComponent(MyController, MyOwner);
}