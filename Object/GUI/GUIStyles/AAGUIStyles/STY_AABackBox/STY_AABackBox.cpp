// All the original content belonged to the US Army


#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AABackBox/STY_AABackBox.h"

USTY_AABackBox::USTY_AABackBox()
{
	KeyName = "BackBox";
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);

}