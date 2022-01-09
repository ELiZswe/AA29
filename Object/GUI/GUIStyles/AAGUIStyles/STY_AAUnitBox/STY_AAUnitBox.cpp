// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAUnitBox/STY_AAUnitBox.h"

USTY_AAUnitBox::USTY_AAUnitBox()
{
	KeyName = "AAUnitBox";
	FontColors[0] = FColor(156, 201, 168, 255);
	FontColors[2] = FColor(52, 180, 217, 255);
	FontColors[3] = FColor(229, 248, 251, 255);
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_sliderbar_border_Mat.scroll_sliderbar_border_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_sliderbar_border_Mat.scroll_sliderbar_border_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_sliderbar_border_Mat.scroll_sliderbar_border_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_sliderbar_border_Mat.scroll_sliderbar_border_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_sliderbar_border_Mat.scroll_sliderbar_border_Mat'"), NULL, LOAD_None, NULL)
	};
	BorderOffsets = {
		12,
		12,
		12,
		12
	};
}
