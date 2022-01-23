// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_ScrollZone/STY_ScrollZone.h"

USTY_ScrollZone::USTY_ScrollZone()
{
	KeyName = "ScrollZone";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[3] = FColor(255, 255, 255, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA2_Mat.BorderBoxA2_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA2_Mat.BorderBoxA2_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA2_Mat.BorderBoxA2_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxA2_Mat.BorderBoxA2_Mat'"), NULL, LOAD_None, NULL);
}
