// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAVertGrip/STY_AAVertGrip.h"

USTY_AAVertGrip::USTY_AAVertGrip()
{
	KeyName = "VertGrip";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_pressed_Mat.scroll_slider_pressed_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled
	};
	ImgWidths = {
		11,
		11,
		11,
		11,
		11
	};
	ImgHeights = {
		19,
		19,
		19,
		19,
		19
	};
}
