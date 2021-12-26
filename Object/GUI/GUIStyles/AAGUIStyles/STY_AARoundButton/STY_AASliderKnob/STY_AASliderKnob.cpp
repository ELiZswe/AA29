// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AARoundButton/STY_AASliderKnob/STY_AASliderKnob.h"

USTY_AASliderKnob::USTY_AASliderKnob()
{
	KeyName = "SliderKnob";
	RStyles = {
		EMenuRenderStyle::MSTY_Alpha,
		EMenuRenderStyle::MSTY_Alpha,
		EMenuRenderStyle::MSTY_Alpha,
		EMenuRenderStyle::MSTY_Alpha,
		EMenuRenderStyle::MSTY_Alpha
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/slider_box_Mat.slider_box_Mat'"), NULL, LOAD_None, NULL),
	nullptr
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
	ImgWidths = {
		26,
		26,
		26,
		26,
		26
	};
	ImgHeights = {
		13,
		13,
		13,
		13,
		13
	};
}
