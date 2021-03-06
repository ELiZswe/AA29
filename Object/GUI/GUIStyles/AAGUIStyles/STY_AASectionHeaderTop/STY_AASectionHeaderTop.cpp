// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AASectionHeaderTop/STY_AASectionHeaderTop.h"

USTY_AASectionHeaderTop::USTY_AASectionHeaderTop()
{
	KeyName = "SectionHeaderTop";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/Header_Mat.Header_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[0] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[1] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[2] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[3] = EImgStyle::ISTY_PartialScaled;
	ImgStyle[4] = EImgStyle::ISTY_PartialScaled;
}
