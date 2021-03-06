// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAGameMenuButton/STY_AAGameMenuButton.h"

USTY_AAGameMenuButton::USTY_AAGameMenuButton()
{
	KeyName = "GameMenuButton";
	FontNames[0] = "AAFontSmallHeader";
	FontNames[1] = "AAFontSmallHeader";
	FontNames[2] = "AAFontSmallHeader";
	FontNames[3] = "AAFontSmallHeader";
	FontNames[4] = "AAFontSmallHeader";
	FontNames[5] = "AAFontSmallHeader";
	FontNames[6] = "AAFontSmallHeader";
	FontNames[7] = "AAFontSmallHeader";
	FontNames[8] = "AAFontSmallHeader";
	FontNames[9] = "AAFontSmallHeader";
	FontNames[10] = "AAFontSmallHeader";
	FontNames[11] = "AAFontSmallHeader";
	FontNames[12] = "AAFontSmallHeader";
	FontNames[13] = "AAFontSmallHeader";
	FontNames[14] = "AAFontSmallHeader";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[1] = FColor(255, 255, 255, 255);
	FontColors[2] = FColor(0, 200, 230, 255);
	FontColors[3] = FColor(0, 200, 230, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_highlighted_Mat.t_ui_gui_button_highlighted_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[1] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[2] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[3] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[4] = EImgStyle::ISTY_PartialScaled;
}
