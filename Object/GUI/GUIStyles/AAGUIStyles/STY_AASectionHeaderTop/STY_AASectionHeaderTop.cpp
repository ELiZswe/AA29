// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASectionHeaderTop/STY_AASectionHeaderTop.h"

USTY_AASectionHeaderTop::USTY_AASectionHeaderTop()
{
	KeyName = "SectionHeaderTop";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_PartialScaled,
	EImgStyle::ISTY_PartialScaled,
	EImgStyle::ISTY_PartialScaled,
	EImgStyle::ISTY_PartialScaled,
	EImgStyle::ISTY_PartialScaled
	};
}
