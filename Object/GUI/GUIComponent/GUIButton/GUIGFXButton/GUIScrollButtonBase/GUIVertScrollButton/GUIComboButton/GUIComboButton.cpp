// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIScrollButtonBase/GUIVertScrollButton/GUIComboButton/GUIComboButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIComboButton::UGUIComboButton()
{
	ImageIndex = 7;
	StyleName = "ComboButton";
	bRepeatClick = false;
	OnClickSound = EClickSound::CS_Edit;
}

void UGUIComboButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
}
