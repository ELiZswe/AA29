// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAMouseOver/STY_AAMouseOver.h"

USTY_AAMouseOver::USTY_AAMouseOver()
{
	KeyName = "MouseOver";
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
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[3] = FColor(156, 201, 168, 255);
	FontColors[4] = FColor(156, 201, 168, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 6;
	BorderOffsets[1] = 8;
	BorderOffsets[2] = 6;
	BorderOffsets[3] = 6;
}
