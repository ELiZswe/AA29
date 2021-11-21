// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAButtonSelected/STY_AAButtonSelected.h"

USTY_AAButtonSelected::USTY_AAButtonSelected()
{
	KeyName = "ButtonSelected";
	FontColors = {
		FColor(155, 252, 185, 255),
		FColor(155, 252, 185, 255),
		FColor(155, 252, 185, 255),
		FColor(155, 252, 185, 255),
		FColor(155, 252, 185, 255)
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL)
	};
	BorderOffsets = { 9,9,9,9 };
}