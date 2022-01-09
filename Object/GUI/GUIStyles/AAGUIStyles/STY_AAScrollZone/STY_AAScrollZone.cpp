// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAScrollZone/STY_AAScrollZone.h"

USTY_AAScrollZone::USTY_AAScrollZone()
{
	KeyName = "ScrollZone";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/scroll_mid_Mat.scroll_mid_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled,
		EImgStyle::ISTY_Scaled
	};
}
