// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASliderBack/STY_AASliderBack.h"

USTY_AASliderBack::USTY_AASliderBack()
{
	KeyName = "SliderBack";
	FontNames[0] = "AAFontSmallHeader";
	FontNames[1] = "AAFontSmallHeader";
	FontNames[2] = "AAFontSmallHeader";
	FontNames[3] = "AAFontSmallHeader";
	FontNames[4] = "AAFontSmallHeader";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[1] = FColor(255, 255, 255, 255);
	FontColors[2] = FColor(0, 200, 230, 255);
	FontColors[3] = FColor(0, 0, 0, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
}
