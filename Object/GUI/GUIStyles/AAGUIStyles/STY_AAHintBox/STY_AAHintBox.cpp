// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAHintBox/STY_AAHintBox.h"

USTY_AAHintBox::USTY_AAHintBox()
{
	KeyName = "HintBox";
	FontNames[5] = "AAFontSmall";
	FontNames[6] = "AAFontSmall";
	FontNames[7] = "AAFontSmall";
	FontNames[8] = "AAFontSmall";
	FontNames[9] = "AAFontSmall";
	FontNames[10] = "AAFontSmall";
	FontNames[11] = "AAFontSmall";
	FontNames[12] = "AAFontSmall";
	FontNames[13] = "AAFontSmall";
	FontNames[14] = "AAFontSmall";
	FontColors[0] = FColor(97, 137, 119, 255);
	FontColors[1] = FColor(97, 137, 119, 255);
	FontColors[2] = FColor(97, 137, 119, 255);
	FontColors[3] = FColor(97, 137, 119, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_info_Mat.box_info_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_info_Mat.box_info_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_info_Mat.box_info_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_info_Mat.box_info_Mat'"), NULL, LOAD_None, NULL);
}
