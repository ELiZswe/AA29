// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AATabButton/STY_AATabButton.h"

USTY_AATabButton::USTY_AATabButton()
{
	KeyName = "TabButton";
	FontNames[0] = "AAFontMainMenuButton";
	FontNames[1] = "AAFontMainMenuButton";
	FontNames[2] = "AAFontMainMenuButton";
	FontNames[3] = "AAFontMainMenuButton";
	FontNames[4] = "AAFontMainMenuButton";
	FontNames[5] = "AAFontMainMenuButton";
	FontNames[6] = "AAFontMainMenuButton";
	FontNames[7] = "AAFontMainMenuButton";
	FontNames[8] = "AAFontMainMenuButton";
	FontNames[9] = "AAFontMainMenuButton";
	FontNames[10] = "AAFontMainMenuButton";
	FontNames[11] = "AAFontMainMenuButton";
	FontNames[12] = "AAFontMainMenuButton";
	FontNames[13] = "AAFontMainMenuButton";
	FontNames[14] = "AAFontMainMenuButton";
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[1] = FColor(229, 248, 251, 255);
	FontColors[2] = FColor(52, 180, 217, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_tab_standard_Mat.t_ui_gui_tab_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_tab_highlighted_Mat.t_ui_gui_tab_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_tab_highlighted_Mat.t_ui_gui_tab_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_tab_highlighted_Mat.t_ui_gui_tab_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_tab_standard_Mat.t_ui_gui_tab_standard_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[1] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[2] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[3] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[4] = EImgStyle::ISTY_PartialScaled;
}
