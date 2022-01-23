// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/STY_RoundButton/STY_SquareBar/STY_SquareBar.h"

USTY_SquareBar::USTY_SquareBar()
{
	KeyName = "SquareBar";
	FontColors[0] = FColor(160, 160, 160, 255);
	FontColors[1] = FColor(160, 160, 160, 255);
	FontColors[2] = FColor(160, 160, 160, 255);
	FontColors[3] = FColor(160, 160, 160, 255);
	FontColors[4] = FColor(160, 160, 160, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SquareBoxA_Mat.SquareBoxA_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/InterfaceContent/Menu/SquareBoxA_Mat.SquareBoxA_Mat'"), NULL, LOAD_None, NULL);
}
