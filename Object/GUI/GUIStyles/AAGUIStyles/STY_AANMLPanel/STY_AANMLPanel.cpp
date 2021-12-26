// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AANMLPanel/STY_AANMLPanel.h"

USTY_AANMLPanel::USTY_AANMLPanel()
{
	KeyName = "NMLPanel";
	FontColors = {
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(255, 255, 255, 255),
		FColor(90, 0, 0, 255)
	};
	Images = {
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL),
		LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL)
	};
	BorderOffsets = {
		20,
		20,
		20,
		20
	};
}
