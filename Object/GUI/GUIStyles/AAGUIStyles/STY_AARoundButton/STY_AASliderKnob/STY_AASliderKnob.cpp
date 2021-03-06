// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AASliderKnob/STY_AASliderKnob.h"

USTY_AASliderKnob::USTY_AASliderKnob()
{
	KeyName = "SliderKnob";
	RStyles[0] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[1] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[2] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[3] = EMenuRenderStyle::MSTY_Alpha;
	RStyles[4] = EMenuRenderStyle::MSTY_Alpha;
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = nullptr;
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
	ImgWidths[0] = 26;
	ImgWidths[1] = 26;
	ImgWidths[2] = 26;
	ImgWidths[3] = 26;
	ImgWidths[4] = 26;
	ImgHeights[0] = 13;
	ImgHeights[1] = 13;
	ImgHeights[2] = 13;
	ImgHeights[3] = 13;
	ImgHeights[4] = 13;
}
