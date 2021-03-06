// All the original content belonged to the US Army

#include "AA29/Object/GUI/GUIStyles/AAGUIStyles/STY_AANMLPanel/STY_AANMLPanel.h"

USTY_AANMLPanel::USTY_AANMLPanel()
{
	KeyName = "NMLPanel";
	FontColors[0] = FColor(255, 255, 255, 255);
	FontColors[1] = FColor(255, 255, 255, 255);
	FontColors[2] = FColor(255, 255, 255, 255);
	FontColors[3] = FColor(255, 255, 255, 255);
	FontColors[4] = FColor(90, 0, 0, 255);
	Images[0] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[1] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[2] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[3] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	Images[4] = LoadObject<UMaterialInstance>(NULL, TEXT("MaterialInstanceConstant'/Game/AmericasArmy/Textures/T_AA2_UI/Menu/field_tabwindow_Mat.field_tabwindow_Mat'"), NULL, LOAD_None, NULL);
	BorderOffsets[0] = 20;
	BorderOffsets[1] = 20;
	BorderOffsets[2] = 20;
	BorderOffsets[3] = 20;
}
