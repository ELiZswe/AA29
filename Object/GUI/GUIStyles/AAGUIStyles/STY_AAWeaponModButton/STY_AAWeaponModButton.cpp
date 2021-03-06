// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AAWeaponModButton/STY_AAWeaponModButton.h"

USTY_AAWeaponModButton::USTY_AAWeaponModButton()
{
	KeyName = "WeaponModButton";
	FontNames[0] = "AAFontHeader";
	FontNames[1] = "AAFontHeader";
	FontNames[4] = "AAFontHeader";
	FontColors[0] = FColor(148, 190, 196, 255);
	FontColors[1] = FColor(0, 200, 230, 255);
	FontColors[4] = FColor(229, 242, 244, 255);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AAO_UI/GUI/t_ui_gui_button_standard_Mat.t_ui_gui_button_standard_Mat'"), NULL, LOAD_None, NULL);
	ImgStyle[4] = EImgStyle::ISTY_Scaled;
}
