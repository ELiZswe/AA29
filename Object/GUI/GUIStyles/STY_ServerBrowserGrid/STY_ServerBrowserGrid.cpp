// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_ServerBrowserGrid/STY_ServerBrowserGrid.h"

USTY_ServerBrowserGrid::USTY_ServerBrowserGrid()
{
	KeyName = "ServerBrowserGrid";
	FontNames[0] = "UT2ServerListFont";
	FontNames[1] = "UT2ServerListFont";
	FontNames[2] = "UT2ServerListFont";
	FontNames[3] = "UT2ServerListFont";
	FontNames[4] = "UT2ServerListFont";
	KeyName = "ServerBrowserGrid";
	FontColors = {
		FColor(160, 160, 160, 255),
		FColor(160, 160, 160, 255),
		FColor(160, 160, 160, 255),
		FColor(160, 160, 160, 255)
	};
	ImgColors = {
		FColor(255, 255, 255, 180),
		FColor(255, 255, 255, 180),
		FColor(255, 255, 255, 180),
		FColor(255, 255, 255, 180),
		FColor(255, 255, 255, 180)
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL),
	LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxF_Mat.BorderBoxF_Mat'"), NULL, LOAD_None, NULL)
	};
	BorderOffsets = {
		5,
		5,
		5,
		5
	};
}
