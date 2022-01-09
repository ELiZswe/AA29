// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASectionHeaderBar/STY_AASectionHeaderBar.h"

USTY_AASectionHeaderBar::USTY_AASectionHeaderBar()
{
	KeyName = "SectionHeaderBar";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Section_header_Mat.Section_header_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = {
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled,
		EImgStyle::ISTY_PartialScaled
	};
}
