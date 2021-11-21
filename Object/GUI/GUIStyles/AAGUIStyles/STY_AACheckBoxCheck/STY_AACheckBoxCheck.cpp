// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AACheckBoxCheck/STY_AACheckBoxCheck.h"

USTY_AACheckBoxCheck::USTY_AACheckBoxCheck()
{
	KeyName = "CheckBoxCheck";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_selected_Mat.box_check_selected_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = { EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled };
}