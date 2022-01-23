// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASquareButton/STY_AASquareMenuButton/STY_AAGUITreeListCategory/STY_AAGUITreeListCategory.h"

USTY_AAGUITreeListCategory::USTY_AAGUITreeListCategory()
{
	KeyName = "AAGUITreeListCategory";
	FontColors[1] = FColor(156, 201, 168, 255);
	FontColors[2] = FColor(156, 201, 168, 255);
	FontColors[3] = FColor(156, 201, 168, 255);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
}
