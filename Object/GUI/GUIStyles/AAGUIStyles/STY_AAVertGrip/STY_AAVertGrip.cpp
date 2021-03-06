// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAVertGrip/STY_AAVertGrip.h"

USTY_AAVertGrip::USTY_AAVertGrip()
{
	KeyName = "VertGrip";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_pressed_Mat.scroll_slider_pressed_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_slider_Mat.scroll_slider_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[1] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[2] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[3] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[4] = EImgStyle::ISTY_PartialScaled;
	ImgWidths[0] = 11;
	ImgWidths[1] = 11;
	ImgWidths[2] = 11;
	ImgWidths[3] = 11;
	ImgWidths[4] = 11;
	ImgHeights[0] = 19;
	ImgHeights[1] = 19;
	ImgHeights[2] = 19;
	ImgHeights[3] = 19;
	ImgHeights[4] = 19;
}
