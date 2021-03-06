// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGripButtonBase/GUIVertGripButton/GUIVertGripButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIVertGripButton::UGUIVertGripButton()
{
	StyleName = "VertGrip";
}

void UGUIVertGripButton::InitComponent(UGUIController* MyController, UGUIComponent* MyComponent)
{
	Super::InitComponent(MyController, MyComponent);
}
