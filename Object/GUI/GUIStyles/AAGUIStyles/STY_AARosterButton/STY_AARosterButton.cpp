// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARosterButton/STY_AARosterButton.h"

USTY_AARosterButton::USTY_AARosterButton()
{
	KeyName = "RosterButton";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ButtonWatched_Mat.ButtonWatched_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 2;
	BorderOffsets[1] = 2;
	BorderOffsets[2] = 2;
	BorderOffsets[3] = 2;
}
