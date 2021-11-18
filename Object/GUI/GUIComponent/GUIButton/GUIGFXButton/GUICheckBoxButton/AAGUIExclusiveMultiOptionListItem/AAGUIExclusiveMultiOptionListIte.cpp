// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/GUIButton/GUIGFXButton/GUICheckBoxButton/AAGUIExclusiveMultiOptionListItem/AAGUIExclusiveMultiOptionListIte.h"

UAAGUIExclusiveMultiOptionListIte::UAAGUIExclusiveMultiOptionListIte()
{
	CheckedOverlay = {
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_selected_Mat.button_radio_selected_Mat'"), NULL, LOAD_None, NULL)
	};
		StyleName = "RadioButton";
}