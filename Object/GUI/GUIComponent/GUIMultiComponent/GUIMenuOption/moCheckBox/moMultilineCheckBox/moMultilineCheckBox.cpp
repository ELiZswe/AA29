// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moCheckBox/moMultilineCheckBox/moMultilineCheckBox.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UmoMultilineCheckBox::UmoMultilineCheckBox()
{
	bAutoSizeCaption = false;
	bSquare = false;
	bStandardized = false;
}

void UmoMultilineCheckBox::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyLabel.bMultiLine = true;
	MyLabel.bStandardized = false;
	MyComponent.bStandardized = true;
	*/
}
