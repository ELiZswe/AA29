// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAIRCEntry/STY_AAIRCEntry.h"

USTY_AAIRCEntry::USTY_AAIRCEntry()
{
	KeyName = "IRCEntry";
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
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
}
