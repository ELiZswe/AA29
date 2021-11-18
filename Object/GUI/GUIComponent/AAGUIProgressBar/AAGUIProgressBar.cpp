// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIComponent/AAGUIProgressBar/AAGUIProgressBar.h"



UAAGUIProgressBar::UAAGUIProgressBar()
{
	BarColor = FColor(255, 255, 255, 255);
	BackgroundMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/backgroundfill_Mat.backgroundfill_Mat'"), NULL, LOAD_None, NULL);
	BarMaterial = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/Engine/WhiteSquareTexture_Mat.WhiteSquareTexture_Mat'"), NULL, LOAD_None, NULL);
	CurrentValue = 1;
	MaxValue = 1;
}