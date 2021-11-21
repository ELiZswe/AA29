// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AACheckBox/STY_AARadioButton/STY_AARadioButton.h"

USTY_AARadioButton::USTY_AARadioButton()
{
	KeyName = "RadioButton";
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_rollover_Mat.button_radio_rollover_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/button_radio_Mat.button_radio_Mat'"), NULL, LOAD_None, NULL)
	};
	ImgStyle = { EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled,EImgStyle::ISTY_Scaled };
}