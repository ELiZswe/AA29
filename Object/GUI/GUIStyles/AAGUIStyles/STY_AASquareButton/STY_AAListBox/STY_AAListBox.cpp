// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASquareButton/STY_AAListBox/STY_AAListBox.h"

USTY_AAListBox::USTY_AAListBox()
{
	KeyName = "ListBox";
	FontNames[10] = "AAFontHeader";
	FontNames[11] = "AAFontHeader";
	FontNames[12] = "AAFontHeader";
	FontNames[13] = "AAFontHeader";
	FontNames[14] = "AAFontHeader";
	FontColors[0] = FColor(52, 180, 217, 255);
	FontColors[1] = FColor(52, 180, 217, 255);
	FontColors[2] = FColor(229, 248, 251, 255);
	FontColors[3] = FColor(229, 248, 251, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_entry_Mat.box_entry_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 3;
	BorderOffsets[1] = 3;
	BorderOffsets[2] = 3;
	BorderOffsets[3] = 3;
}
