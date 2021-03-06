// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moRadioButtonGroup/moRadioButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIRadioButtonGroup/GUIRadioButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moRadioButton/moRadioButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UmoRadioButtonGroup::UmoRadioButtonGroup()
{
	ComponentClassName = "XInterface.GUIRadioButtonGroup";
}

void UmoRadioButtonGroup::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	MyRadioButtonGroup = Cast<UGUIRadioButtonGroup>(MyComponent);
	//MyRadioButtonGroup->GroupNameTag = GroupNameTag;
}
