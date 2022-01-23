// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASquareButton/STY_AAEyeCatcherSquareButton/STY_AAEyeCatcherSquareButton.h"

USTY_AAEyeCatcherSquareButton::USTY_AAEyeCatcherSquareButton()
{
	KeyName = "EyeCatcherSquareButton";
	FontColors[0] = FColor(52, 180, 217, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
}
