// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAFooter/STY_NMLHeader/STY_NMLHeader.h"

USTY_NMLHeader::USTY_NMLHeader()
{
	KeyName = "NMLHeader";
	FontNames[0] = "NMLFontSmallHeader";
	FontNames[1] = "NMLFontSmallHeader";
	FontNames[2] = "NMLFontSmallHeader";
	FontNames[3] = "NMLFontSmallHeader";
	FontNames[4] = "NMLFontSmallHeader";
	FontNames[5] = "NMLFontSmallHeader";
	FontNames[6] = "NMLFontSmallHeader";
	FontNames[7] = "NMLFontSmallHeader";
	FontNames[8] = "NMLFontSmallHeader";
	FontNames[9] = "NMLFontSmallHeader";
	FontNames[10] = "NMLFontSmallHeader";
	FontNames[11] = "NMLFontSmallHeader";
	FontNames[12] = "NMLFontSmallHeader";
	FontNames[13] = "NMLFontSmallHeader";
	FontNames[14] = "NMLFontSmallHeader";
	FontColors[0] = FColor(61, 175, 204, 255);
	FontColors[1] = FColor(82, 180, 204, 255);
	FontColors[2] = FColor(82, 180, 204, 255);
	FontColors[3] = FColor(82, 180, 204, 255);
	FontColors[4] = FColor(82, 180, 204, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 10;
}
