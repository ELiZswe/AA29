// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAFooter/STY_AAHeader/STY_AAHeader.h"

USTY_AAHeader::USTY_AAHeader()
{
	KeyName = "Header";
	FontNames[0] = "AADefaultFont";
	FontNames[1] = "AADefaultFont";
	FontNames[2] = "AADefaultFont";
	FontNames[3] = "AADefaultFont";
	FontNames[4] = "AADefaultFont";
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
	FontColors[1] = FColor(0, 200, 230, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[1] = 4;
	BorderOffsets[3] = 4;
}
