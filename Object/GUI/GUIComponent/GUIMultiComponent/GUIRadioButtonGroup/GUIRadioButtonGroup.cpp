// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIComponent/GUIMultiComponent/GUIRadioButtonGroup/GUIRadioButtonGroup.h"
#include "AA29/Object/GUI/GUIComponent/GUIComponent.h"
#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUIRadioButtonButton/GUIRadioButtonButton.h"

UGUIRadioButtonGroup::UGUIRadioButtonGroup()
{

}

void UGUIRadioButtonGroup::OnSelectedButtonChange()
{
}

bool UGUIRadioButtonGroup::ButtonClicked(UGUIComponent* Sender)
{
	/*
	int32 i = 0;
	if (GUIRadioButtonButton(Sender) != nullptr)
	{
		SelectedButton = GUIRadioButtonButton(Sender);
		GUIRadioButtonButton(Sender).bChecked = true;
		Sender.OnChange(Sender);
		OnSelectedButtonChange();
	}
	for (i = 0; i < Controls.Num(); i++)
	{
		if ((GUIRadioButtonButton(Controls[i]) != nullptr) && (GUIRadioButtonButton(Controls[i]) != GUIRadioButtonButton(Sender)))
		{
			GUIRadioButtonButton(Controls[i]).bChecked = false;
			Sender.OnChange(Controls[i]);
		}
	}
	*/
	return true;
}
