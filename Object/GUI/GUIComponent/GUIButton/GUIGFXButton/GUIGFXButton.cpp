// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUIGFXButton.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/Interactions/Interaction/BaseGUIController/GUIController/GUIController.h"

UGUIGFXButton::UGUIGFXButton()
{
	bTabStop = false;
}

void UGUIGFXButton::InitComponent(UGUIController* MyController, UGUIComponent* MyOwner)
{
	Super::InitComponent(MyController, MyOwner);
	if (bCheckBox)
	{
		//__OnClick__Delegate = InternalOnClick;
	}
	if (Graphic == nullptr && ImageIndex >= 0 && ImageIndex < MyController->ImageList.Num())
	{
		Graphic = MyController->ImageList[ImageIndex];
	}
}

void UGUIGFXButton::SetChecked(bool bNewChecked)
{
	if (bCheckBox)
	{
		bChecked = bNewChecked;
		OnChange(this);
	}
}

bool UGUIGFXButton::InternalOnClick(UGUIComponent* Sender)
{
	if (bCheckBox)
	{
		bChecked = !bChecked;
	}
	OnChange(this);
	return true;
}
