// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAScrollZone/STY_AAScrollZone.h"

USTY_AAScrollZone::USTY_AAScrollZone()
{
	KeyName = "ScrollZone";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_Scaled;
	ImgStyle[1] = EImgStyle::ISTY_Scaled;
	ImgStyle[2] = EImgStyle::ISTY_Scaled;
	ImgStyle[3] = EImgStyle::ISTY_Scaled;
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
}
