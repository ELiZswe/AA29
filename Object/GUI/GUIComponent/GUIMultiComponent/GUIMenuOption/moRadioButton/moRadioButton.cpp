// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIMenuOption/moRadioButton/moRadioButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUIRadioButtonButton/GUIRadioButtonButton.h"


UmoRadioButton::UmoRadioButton()
{
	ComponentClassName = "XInterface.GUIRadioButtonButton";
}

void UmoRadioButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	/*
	Super::InitComponent(MyController, MyOwner);
	MyRadioButton = GUIRadioButtonButton(MyComponent);
	MyRadioButton.bChecked = bSelected;
	MyRadioButton.Group = Group.MyRadioButtonGroup;
	Group.MyRadioButtonGroup.AppendComponent(MyRadioButton);
	*/
}

bool UmoRadioButton::IsSelected()
{
	return MyRadioButton->bChecked;
}

bool UmoRadioButton::Select(bool S)
{

	MyRadioButton->bChecked = S;
	bSelected = S;
	//OnChange(Self);
	return true;
}