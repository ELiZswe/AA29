// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAIRCText/STY_AAIRCText.h"

USTY_AAIRCText::USTY_AAIRCText()
{
	KeyName = "IRCText";
	FontNames[0] = "AAFontIRC";
	FontNames[1] = "AAFontIRC";
	FontNames[2] = "AAFontIRC";
	FontNames[3] = "AAFontIRC";
	FontNames[4] = "AAFontIRC";
	FontNames[5] = "AAFontIRC";
	FontNames[6] = "AAFontIRC";
	FontNames[7] = "AAFontIRC";
	FontNames[8] = "AAFontIRC";
	FontNames[9] = "AAFontIRC";
	FontNames[10] = "AAFontIRC";
	FontNames[11] = "AAFontIRC";
	FontNames[12] = "AAFontIRC";
	FontNames[13] = "AAFontIRC";
	FontNames[14] = "AAFontIRC";
	FontColors[0] = FColor(160, 160, 160, 255);
	FontColors[1] = FColor(160, 160, 160, 255);
	FontColors[2] = FColor(160, 160, 160, 255);
	FontColors[3] = FColor(160, 160, 160, 255);
	ImgColors[4] = FColor(255, 255, 255, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_translucent_Mat.field_translucent_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 5;
	BorderOffsets[1] = 10;
	BorderOffsets[2] = 5;
	BorderOffsets[3] = 10;
}
