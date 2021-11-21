// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAButton/STY_AAButton.h"

USTY_AAButton::USTY_AAButton()
{
	KeyName = "Button";
	FontColors = {
		FColor(212, 212, 212, 255),
		FColor(40, 186, 220, 255),
		FColor(155, 252, 185, 255),
		FColor(212, 212, 212, 255),
		FColor(212, 212, 212, 255)
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