// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAButtonSelected/STY_AAButtonSelected.h"

USTY_AAButtonSelected::USTY_AAButtonSelected()
{
	KeyName = "ButtonSelected";
	FontColors[0] = FColor(155, 252, 185, 255);
	FontColors[1] = FColor(155, 252, 185, 255);
	FontColors[2] = FColor(155, 252, 185, 255);
	FontColors[3] = FColor(155, 252, 185, 255);
	FontColors[4] = FColor(155, 252, 185, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 9;
	BorderOffsets[1] = 9;
	BorderOffsets[2] = 9;
	BorderOffsets[3] = 9;
}
