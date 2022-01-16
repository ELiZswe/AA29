// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARosterButton/STY_AARosterButton.h"

USTY_AARosterButton::USTY_AARosterButton()
{
	KeyName="RosterButton";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/ButtonWatched_Mat.ButtonWatched_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/BorderBoxD_Mat.BorderBoxD_Mat'"), NULL, LOAD_None, NULL)
	};
	BorderOffsets = {
		2,
		2,
		2,
		2
	};
}
