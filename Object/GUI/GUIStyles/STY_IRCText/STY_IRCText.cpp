// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_IRCText/STY_IRCText.h"

USTY_IRCText::USTY_IRCText()
{
	KeyName = "IRCText";
	FontNames[0] = "UT2IRCFont";
	FontNames[1] = "UT2IRCFont";
	FontNames[2] = "UT2IRCFont";
	FontNames[3] = "UT2IRCFont";
	FontNames[4] = "UT2IRCFont";
	FontNames[5] = "UT2IRCFont";
	FontNames[6] = "UT2IRCFont";
	FontNames[7] = "UT2IRCFont";
	FontNames[8] = "UT2IRCFont";
	FontNames[9] = "UT2IRCFont";
	FontNames[10] = "UT2IRCFont";
	FontNames[11] = "UT2IRCFont";
	FontNames[12] = "UT2IRCFont";
	FontNames[13] = "UT2IRCFont";
	FontNames[14] = "UT2IRCFont";
	FontColors[0] = FColor(160, 160, 160, 255);
	FontColors[1] = FColor(160, 160, 160, 255);
	FontColors[2] = FColor(160, 160, 160, 255);
	FontColors[3] = FColor(160, 160, 160, 255);
	ImgColors[0] = FColor(255, 255, 255, 180);
	ImgColors[1] = FColor(255, 255, 255, 180);
	ImgColors[2] = FColor(255, 255, 255, 180);
	ImgColors[3] = FColor(255, 255, 255, 180);
	ImgColors[4] = FColor(255, 255, 255, 180);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 5;
	BorderOffsets[1] = 5;
	BorderOffsets[2] = 5;
	BorderOffsets[3] = 5;
}
