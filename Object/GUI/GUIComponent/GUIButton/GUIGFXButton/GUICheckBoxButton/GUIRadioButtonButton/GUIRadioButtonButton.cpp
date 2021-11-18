// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/GUIRadioButtonButton/GUIRadioButtonButton.h"

UGUIRadioButtonButton::UGUIRadioButtonButton()
{
	CheckedOverlay = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL)
	};
	Position = EIconPosition::ICP_Center;
}


bool UGUIRadioButtonButton::InternalOnClick(UGUIComponent* Sender)
{
	/*
	if (bCheckBox && Group != nullptr)
	{
		Group->ButtonClicked(Sender);
	}
	*/
	return true;
}