// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAEditBox/STY_AAEditBox.h"

USTY_AAEditBox::USTY_AAEditBox()
{
	KeyName = "EditBox";
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
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 10;
}
