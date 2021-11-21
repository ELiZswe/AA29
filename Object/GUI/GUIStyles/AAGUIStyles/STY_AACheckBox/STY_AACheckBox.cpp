// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AACheckBox/STY_AACheckBox.h"

USTY_AACheckBox::USTY_AACheckBox()
{
	KeyName = "CheckBox";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_Mat.box_check_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_rollover_Mat.box_check_rollover_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_Mat.box_check_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_Mat.box_check_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/box_check_nonavailable_Mat.box_check_nonavailable_Mat'"), NULL, LOAD_None, NULL)
	};
}